#ifndef ASTAR_ALGO_H
#define ASTAR_ALGO_H

#include<vector>
#include<list>

class AStarSearch {

private:

	int map_rows, map_cols;
	std::list<std::pair<std::pair<int, int>, int>> queue;
	std::vector<std::vector<bool>> is_visit;
	std::vector<std::vector<float>> cost_map;
	std::vector<std::vector<float>> scores_map;
	std::list<std::pair<int, int>> shortest_path;

private:

	void Reset();
	std::vector<std::pair<int, int>> FindNeighbors(const std::pair<int, int> cur_pos);
	std::vector<int> GetScores(const std::vector<std::vector<int>> &map, const std::vector<std::pair<int, int>> neighbors, const std::pair<int, int> src_pos, const std::pair<int, int> tar_pos);
	void FindShortestPath(const std::vector<std::vector<int>> &map, const std::pair<int, int> src, const std::pair<int, int> tar);

public:

	AStarSearch(const int rows, const int cols);

	~AStarSearch();

	std::list<std::pair<int, int>> Search(const std::vector<std::vector<int>> &map, const std::pair<int, int> src, const std::pair<int, int> tar);

};

#endif
