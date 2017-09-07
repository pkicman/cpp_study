/*
 * my_graphs.cpp
 *
 *  Created on: 09-04-2012
 *      Author: User
 */


#include "my_graphs.hpp"

graph::graph()
{
	srand((unsigned)time(0));
}

graph::graph(int n, int m)
{
	srand((unsigned)time(0));
}

graph::~graph()
{

}

void graph::add_node()
{
	vertex tmp;

	V.push_back(tmp);
}

void 	graph::copy(graph &A)
{
	for(int i = 0; i < this->V.size(); i++)
	{
		vertex tmp;

		for(int j = 0; j < this->V[i].myV.size(); j++)
		{
			tmp.myV.push_back(this->V[i].myV[j]);
		}
		for(int j = 0; j < this->V[i].myE.size(); j++)
		{
			tmp.myE.push_back(this->V[i].myE[j]);
		}
		A.V.push_back(tmp);
	}

	for(int i = 0; i < this->E.size(); i++)
	{
		edge tmp;
		tmp.myV[0] = this->E[i].myV[0];
		tmp.myV[1] = this->E[i].myV[1];
		A.E.push_back(tmp);
	}
}


void graph::add_edge(int V1, int V2)
{
	V[V1].myV.push_back(V2);
	V[V2].myV.push_back(V1);

	edge tmp;
	tmp.myV[0] = V1;
	tmp.myV[1] = V2;

	E.push_back(tmp);
	V[V1].myE.push_back(E.size() - 1);
	V[V2].myE.push_back(E.size() - 1);
}

void graph::remove_node(int VE)
{
	V.erase(V.begin() + VE);
	// update indexes of the vertices in the edges
	for(int j = 0; j < E.size(); j++)
	{
		if(E[j].myV[0] > VE)	E[j].myV[0] = E[j].myV[0] - 1;
		if(E[j].myV[1] > VE)	E[j].myV[1] = E[j].myV[1] - 1;
	}
}


void	graph::remove_edge(int E1)
{
	// Remove connections to vertices created by this edge
	for(int i = 0; i < V[E[E1].myV[0]].myV.size(); i++)
	{
		if(V[E[E1].myV[0]].myV[i] == E[E1].myV[1])
		{
			V[E[E1].myV[0]].myV.erase(V[E[E1].myV[0]].myV.begin() + i);
			break; // Remove only one instance
		}
	}
	for(int i = 0; i < V[E[E1].myV[1]].myV.size(); i++)
	{
		if(V[E[E1].myV[1]].myV[i] == E[E1].myV[0])
		{
				V[E[E1].myV[1]].myV.erase(V[E[E1].myV[1]].myV.begin() + i);
				break;   // Remove only one instance
		}
	}
	//cout << "E size: " << E.size() << " " << E1 << endl;
	E.erase(E.begin() + E1);

	for(int k = 0; k < V.size(); k++)
	{
		//cout << k + 1 << " ";
		int l;
		for(l = 0; l < V[k].myE.size(); l++)
		{
			//cout << " " << l << endl;
			if(V[k].myE[l] == E1) V[k].myE.erase(V[k].myE.begin() + l);
			if(V[k].myE[l] > E1) V[k].myE[l]--;
		}
		//cout << l << endl;
	}
}

void graph::disp_vertex(int i)
{
	cout << "Vertex number: " << i + 1 << endl;
	cout << "Connected with: ";
	for(int j = 0; j < this->V[i].myV.size(); j++)
	{
		cout << this->V[i].myV[j]+1 << " ";
	}
	cout << endl;
	cout << "Has edges: " << endl;
	for(int j = 0; j < this->V[i].myE.size(); j++)
	{
		cout << this->V[i].myE[j] << ":(" << this->E[(this->V[i].myE[j])].myV[0] + 1 << ","<< this->E[(this->V[i].myE[j])].myV[1] + 1 << ") "<< endl;
	}
	cout << endl;
}

void graph::disp_graph()
{
	cout << "Number of nodes: " << V.size() << endl;
	cout << "Number of edges: " << E.size() << endl;
	for(int i = 0; i < V.size(); i++)
	{
		disp_vertex(i);
	}
}

int graph::contraction()
{
int i, V1, V2;

while(this->V_size() > 2)
{
	i = rand() % this->E_size();
	//cout << "**********" << endl;
	//cout << "Number of edges: " << this->E_size() << endl;
	//cout << "Chosen edge: " << i << " " << endl;
	//cout << "Vertices count: " << this->V_size() << endl;

	V1 = E[i].myV[0];
	V2 = E[i].myV[1];

	//cout << "Vertices merged: " << V1 + 1<< " " << V2 + 1 << endl;
	if(V1 == V2)
	{
		cout << "CRASH!" << endl;
	}
	else
	{

	/* Merge V1 and V2 */
	// Copy all edges from V2 to V1
	//cout << "1 ";
	for(int j = 0; j < (int)V[V2].myE.size(); j++)
	{
		if(E[V[V2].myE[j]].myV[0] == V2)
		{
			E[V[V2].myE[j]].myV[0] = V1;
		}
		else
		{
			E[V[V2].myE[j]].myV[1] = V1;
		}

		bool is_already = false;

		for(int k = 0; k < V[V1].myE.size(); k++)
			if(V[V1].myE[k] == V[V2].myE[j]) is_already = true;

		if(!is_already) //V[V2].myE[j] != i)
		{
			//cout << i << " " << V[V2].myE[j] << " " << V[V2].myE.size() << " " << V1 << " " << V2<<endl;
			V[V1].myE.push_back(V[V2].myE[j]);
		}
	}
	/*cout << "i: " << i << ", ";
	for(int j = 0; j < V[V1].myE.size(); j++)
	{
		cout << V[V1].myE[j] << " ";
	}
	cout << endl;*/
	/* Remove V2 */
	//cout << "Removed vertex: " << V2 + 1 << endl;

	//cout << endl;

	//cout << "2 ";

	// Remove self-loops

	vector <int> sl;
	for(int j = 0; j < E.size(); j++)
	{
		if(E[j].myV[0] == E[j].myV[1] )
		{
			//cout << "Removing self loop: "<< V[V1].myE[j] <<  endl;
			sl.push_back(j);
		}
	}
	//cout << "2.5 ";
	//cout << endl << "SL size: " << sl.size() << endl;
	sort(sl.begin(), sl.end(), greater<int>());
	for(int j = 0; j < sl.size(); j++)
	{
		//cout << "SL elem: " << j << ": "<< sl[j] << " "<< endl;
		bool done = false;
		for(int k = 0; k < 0; k++)
			if(sl[j] == sl[k]) done = true;
		if(!done)	remove_edge(sl[j]);
	}
	//cout << "i: " << i <<  ", ";
	for(int j = 0; j < V[V1].myE.size(); j++)
	{
		//cout << V[V1].myE[j] << " ";
	}
	//cout << endl;

	//cout << "3 ";
	remove_node(V2);

	//cout << "4" << endl;
	}
}

return this->E_size();
}

vertex::vertex()
{


}

vertex::vertex(int Enum)
{
	// Enum = number of edges that this node will have

}
