/*
 * main.cpp
 *
 *  Created on: 09-04-2012
 *      Author: User
 */


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "my_graphs.hpp"

using namespace std;

int main()
{
	ifstream fG("kargerAdj.txt");

	graph G(0,0);

	string nLine;
	stringstream ss;
	int tmp, nn;

	while(!fG.eof())
	{
		ss.clear();
		ss.str("");
		getline(fG, nLine);
		ss << nLine;
		ss >> nn;
		G.add_node();
		while(ss >> tmp)
		{
			if(tmp < nn)
			{
				G.add_edge(nn-1, tmp-1);
			}
		}
	}
	fG.close();

	//G.disp_graph();
	int min_c = 100;
	int n = 100000;
	tmp = 100;
	srand((unsigned)time(0));
	for(int i = 0; i < n; i++)
	{
		graph *G1;
		G1 = new graph;
		G.copy(*G1);

		tmp = G1->contraction();
		cout << tmp << " ";
		if(tmp < min_c) min_c = tmp;

		delete G1;
	}
	cout << "Min cut after " << n << " trials: " << min_c << endl;
	return 0;
}
