#include"DijkstraAlgo.h"

Graph::Graph(const int num_of_vertices) {

	this->num_of_vertices = num_of_vertices;
	v.resize(num_of_vertices);
}

Graph::~Graph() {
	dist.clear(); dist.shrink_to_fit();
	v.clear(); v.shrink_to_fit();
	is_visit.clear(); is_visit.shrink_to_fit();
}

void Graph::Reset() {
	dist.resize(num_of_vertices, INT_MAX);
	is_visit.resize(num_of_vertices, false);
}

void Graph::AddEdge(const int vertice_a, const int vertice_b, const int weight) {

	if (vertice_a >= this->num_of_vertices)
		AddVertices(vertice_a);
	else if (vertice_b >= this->num_of_vertices)
		AddVertices(vertice_b);

	v[vertice_a].push_back(std::pair<int, int>(vertice_b, weight));
}

void Graph::AddVertices(const int vertice) {

	std::vector<std::vector<std::pair<int, int>>> old_v = v;

	this->num_of_vertices = vertice + 1;

	v.resize(this->num_of_vertices);
	for (int i = 0; i < old_v.size(); i++)
		v[i] = old_v[i];


}

void Graph::DijkstraAlgor(const int src_vertice) {

	Reset();

	this->src_vertice = src_vertice;

	dist[src_vertice] = 0;
	is_visit[src_vertice] = true;

	int src_idx = src_vertice;
	for (int j = 0; j < num_of_vertices; j++) {
		for (int i = 0; i < v[src_idx].size(); i++) {
			int tar_idx = v[src_idx][i].first;
			int weight = v[src_idx][i].second;

			if (dist[src_idx] + weight < dist[tar_idx]) {
				dist[tar_idx] = dist[src_idx] + weight;
			}

		}

		int min_dist = INT_MAX;
		for (int i = 0; i < dist.size(); i++) {
			if (!is_visit[i] && dist[i] < min_dist) {
				min_dist = dist[i];
				src_idx = i;
			}
		}
		is_visit[src_idx] = true;
	}

}

void Graph::PrintDistRel2Src() {
	for (int i = 0; i < dist.size(); i++)
		std::cout << "relative distance of vertice " << i << " from source vertice " << this->src_vertice << " is " << dist[i] << " " << std::endl;
}