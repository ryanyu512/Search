#include<iostream>
#include"DepthFirstSearch.h"

int main() {

	Graph g(11);

	g.AddEdge(0, 1);
	g.AddEdge(0, 2);
	g.AddEdge(0, 3);
	g.AddEdge(1, 4);
	g.AddEdge(1, 5);
	g.AddEdge(2, 6);
	g.AddEdge(3, 7);
	g.AddEdge(3, 8);
	g.AddEdge(4, 9);
	g.AddEdge(6, 10);
	g.AddEdge(8, 11);

	g.DFS(0);

	std::getchar(); std::getchar();
	return 0;
}

