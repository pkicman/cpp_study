/*
 * my_graphs.hpp
 *
 *  Created on: 09-04-2012
 *      Author: User
 */

#ifndef MY_GRAPHS_HPP_
#define MY_GRAPHS_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class edge;

class vertex
{
public:
	vector <int> myV;		// indices of the points that this node is connected with
	vector <int> myE;

	vertex();
	vertex(int Enum);
};

class edge
{
public:
	int myV[2];	// indices of the vertices that this edge connects
};

class graph
{
public:
	vector <vertex> V;		// list of vertices
	vector <edge> E;		// list of edges

		graph();
		graph(int n, int m);
		~graph();

int inline V_size() {return V.size();}
int inline E_size() {return E.size();}
void	add_node();
void 	add_edge(int V1, int V2);
void	remove_edge(int E1);
void	remove_node(int VE);
void 	copy(graph &A);

int contraction();

void disp_vertex(int i);
void disp_graph();

};

#endif /* MY_GRAPHS_HPP_ */
