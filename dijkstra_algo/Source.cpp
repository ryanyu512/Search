#include"DijkstraAlgo.h"

int main() {

	//initialize graph
	Graph graph(7);

	//add vertices
	graph.AddEdge(0, 1, 2);
	graph.AddEdge(0, 2, 5);

	graph.AddEdge(1, 0, 2);
	graph.AddEdge(1, 2, 6);
	graph.AddEdge(1, 3, 1);
	graph.AddEdge(1, 4, 3);
	
	graph.AddEdge(2, 0, 5);
	graph.AddEdge(2, 1, 6);
	graph.AddEdge(2, 5, 8);
	
	graph.AddEdge(3, 1, 1);
	graph.AddEdge(3, 4, 4);

	graph.AddEdge(4, 1, 3);
	graph.AddEdge(4, 3, 4);
	graph.AddEdge(4, 6, 9);

	graph.AddEdge(5, 2, 8);
	graph.AddEdge(5, 6, 7);

	graph.AddEdge(6, 4, 9);
	graph.AddEdge(6, 5, 7);
	graph.AddEdge(6, 10, 2);

	graph.AddEdge(10, 6, 2);


	//conduct Dijkstra's algo
	graph.DijkstraAlgor(0);

	//print out the shortest distance relative to source
	graph.PrintDistRel2Src();

	//find shortest path
	std::list<int> shortest_path = graph.FindShortestPath(5);

	std::list<int>::iterator itr = shortest_path.begin();

	for (; itr != shortest_path.end(); ++itr) {
		std::cout << *itr << " ";
	}
	std::cout << std::endl;

	std::getchar(); std::getchar();
	return 0;
}

