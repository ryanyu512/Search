#include<iostream>
#include"BreadthFirstSearch.h"

int main() {

	Graph g(4);

	g.AddEdge(0, 1);
	g.AddEdge(0, 2);
	g.AddEdge(1, 2);
	g.AddEdge(2, 0);
	g.AddEdge(2, 3);
	g.AddEdge(3, 10);
	g.AddEdge(10, 10);
	g.BFS(2);

	std::getchar(); std::getchar();
	return 0;
}

