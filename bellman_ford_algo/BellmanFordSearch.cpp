#include"BellmanFordSearch.h"

#include<iostream>
#include<numeric>

Graph::Graph(const int num_of_vertices, const int num_of_edges) {

	edge = new Edge[num_of_edges];

	this->num_of_vertices = num_of_vertices;

	this->num_of_edges = num_of_edges;

	dist.resize(num_of_vertices, INT_MAX);
}

Graph::~Graph() {

	delete[]edge;

	dist.clear(); dist.shrink_to_fit();
}

void Graph::AddEdge(const int edge_idx, const int src, const int des, const int weight) {

	if (edge_idx >= num_of_edges)
		return;

	edge[edge_idx].src = src;
	edge[edge_idx].des = des;
	edge[edge_idx].weight = weight;

	return;
}

void Graph::BellmanFordAlgor(const int src_vertice) {

	if (src_vertice >= num_of_vertices)
		return;

	dist[src_vertice] = 0;

	this->src_vertice = src_vertice;

	for (int i = 0; i < num_of_vertices - 1; i++) {
		for (int j = 0; j < num_of_edges; j++) {
			int src = edge[j].src;
			int des = edge[j].des;
			int weight = edge[j].weight;

			if (dist[src] != INT_MAX && dist[src] + weight < dist[des])
				dist[des] = dist[src] + weight;
		}
	}

	for (int i = 0; i < num_of_edges; i++) {
		int src = edge[i].src;
		int des = edge[i].des;
		int weight = edge[i].weight;

		if (dist[src] != INT_MAX && dist[src] + weight < dist[des])
			std::cout << "it is a negative weight cycle!" << std::endl;
	}
}

void Graph::PrintDistRel2Src() {

	for (int i = 0; i < dist.size(); i++) {
		std::cout << "distance of target vertices " << i << " relative to source vertices " << src_vertice << " is " << dist[i] << std::endl;
	}

}