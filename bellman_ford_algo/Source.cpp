#include"BellmanFordSearch.h"

int main() {

	Graph graph(7, 24);

	graph.AddEdge(0,  0, 1, 9);
	graph.AddEdge(1,  0, 2, 2);

	graph.AddEdge(2,  1, 0, 9);
	graph.AddEdge(3,  1, 2, 6);
	graph.AddEdge(4,  1, 3, 3);
	graph.AddEdge(5,  1, 4, 1);
	
	graph.AddEdge(6,  2, 0, 2);
	graph.AddEdge(7,  2, 3, 2);
	graph.AddEdge(8,  2, 5, 9);
	graph.AddEdge(9,  2, 1, 6);
	
	graph.AddEdge(10,  3, 1, 3);
	graph.AddEdge(11,  3, 2, 2);
	graph.AddEdge(12, 3, 4, 5);
	graph.AddEdge(13, 3, 5, 6);

	graph.AddEdge(14, 4, 3, 5);
	graph.AddEdge(15, 4, 1, 1);
	graph.AddEdge(16, 4, 6, 7);
	graph.AddEdge(17, 4, 5, 3);

	graph.AddEdge(18, 5, 2, 9);
	graph.AddEdge(19, 5, 3, 6);
	graph.AddEdge(20, 5, 4, 3);
	graph.AddEdge(21, 5, 6, 4);

	graph.AddEdge(22, 6, 4, 7);
	graph.AddEdge(23, 6, 5, 4);

	graph.BellmanFordAlgor(0);
	graph.PrintDistRel2Src();

	std::getchar(); std::getchar();
	return 0;
}

