#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H

#include<vector>
#include<list>

class Graph {

private:

	int num_of_vertices;

	std::list<int> *v;

	void AddVertices(const int vertices);

public:

	Graph(const int num_of_vertices);
	~Graph();

	void AddEdge(const int vertices_a, const int vertices_b);

	void BFS(const int vertices);
};
#endif
