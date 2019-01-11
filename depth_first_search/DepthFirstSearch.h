#ifndef DEPTHFIRSTSEARCH_H
#define DEPTHFIRSTSEARCH_H
#include<vector>
#include<list>

class Graph {

private:

	int num_of_vertices;

	std::list<int> *v;

	void AddVertices(const int vertices);

	void SearchByDFS(const int vertices, std::vector<bool> &is_visited);

public:

	Graph(const int num_of_vertices);
	~Graph();

	void AddEdge(const int vertices_a, const int vertices_b);

	void DFS(const int vertices);
};

#endif
