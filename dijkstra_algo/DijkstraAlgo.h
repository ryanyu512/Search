#ifndef DIJKSTRA_ALGO_H
#define DIJKSTRA_ALGO_H

#include<iostream>
#include<vector>

class Graph {

private:

	int num_of_vertices;

	int src_vertice;

	std::vector<std::vector<std::pair<int, int>>> v;

	std::vector<int> dist;

	std::vector<bool> is_visit;

private:

	void Reset();

	void AddVertices(const int vertice);

public:

	Graph(const int num_of_vertices);

	~Graph();

	void AddEdge(const int vertice_a, const int vertice_b, const int weight);

	void DijkstraAlgor(const int src_vertice);

	void PrintDistRel2Src();
};

#endif
