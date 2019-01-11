#ifndef BELLMANFORD_H
#define BELLMANFORD_H
#include<vector>

class Graph {

private:

	int num_of_vertices;

	int num_of_edges;

	int src_vertice;

	struct Edge {
		int src, des, weight;
	};

	Edge *edge;

	std::vector<int> dist;

public:

	Graph(const int num_of_vertices, const int num_of_edges);
	~Graph();

	void AddEdge(const int edge_idx, const int src, const int des, const int weight);

	void BellmanFordAlgor(const int vertices);

	void PrintDistRel2Src();
};

#endif