#include"BreadthFirstSearch.h"
#include<iostream>

Graph::Graph(const int num_of_vertices) {

	this->num_of_vertices = num_of_vertices;

	v = new std::list<int>[num_of_vertices];

}

Graph::~Graph() {
	delete[]v;
}

void Graph::AddEdge(const int vertices_a, const int vertices_b) {

	if (vertices_a > num_of_vertices - 1 ||
		vertices_b > num_of_vertices - 1)
		return;

	v[vertices_a].push_back(vertices_b);

	return;
}

void Graph::BFS(const int vertices) {

	if (vertices > this->num_of_vertices - 1)
		return;

	std::list<int> queue;

	std::vector<bool> is_visited(num_of_vertices, false);

	is_visited[vertices] = true;
	queue.push_back(vertices);

	std::list<int>::iterator itr;

	while (!queue.empty()) {

		int idx = queue.front();
		std::cout << idx << " ";
		queue.pop_front();

		for (itr = v[idx].begin(); itr != v[idx].end(); ++itr) {
			if (!is_visited[*itr]) {
				queue.push_back(*itr);
				is_visited[*itr] = true;
			}
		}
	}
}