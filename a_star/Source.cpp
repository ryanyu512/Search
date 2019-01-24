#include<iostream>
#include"AStarAlgoh.h"

int main() {

	const int rows = 7;
	const int cols = 7;

	//1 = connected, 0 = blocked
	int map_array[rows][cols] = { { 1, 1, 1, 0, 0, 0, 0 },
								  { 1, 0, 1, 0, 0, 0, 0 },
								  { 1, 0, 1, 1, 1, 1, 1 },
								  { 1, 0, 1, 0, 0, 0, 1 },
								  { 1, 0, 1, 0, 1, 1, 1 },
								  { 1, 0, 1, 0, 1, 0, 0 },
								  { 1, 1, 1, 1, 1, 1, 1 } };

	std::vector<std::vector<int>> map(rows);
	for (int i = 0; i < map.size(); i++){
		map[i].resize(cols);
		for (int j = 0; j < map[i].size(); j++) {
			map[i][j] = map_array[i][j];
		}
	}


	AStarSearch a_star(rows, cols);
	std::list<std::pair<int, int>> shortest_path = a_star.Search(map, std::pair<int, int>(2, 2), std::pair<int, int>(6, 6));

	std::list<std::pair<int, int>>::iterator itr = shortest_path.begin();
	for (; itr != shortest_path.end(); ++itr) {
		std::cout << itr->first << " " << itr->second << std::endl;
	}

	std::getchar(); std::getchar();
	return 0;
}

