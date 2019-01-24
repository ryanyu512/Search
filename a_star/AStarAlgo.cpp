#include "AStarAlgoh.h"

AStarSearch::AStarSearch(const int rows, const int cols) {
	this->map_rows = rows;
	this->map_cols = cols;
}

AStarSearch::~AStarSearch() {
	Reset();
}

void AStarSearch::Reset() {
	queue.clear();
	shortest_path.clear();
	is_visit.clear(); is_visit.shrink_to_fit();
	cost_map.clear(); cost_map.shrink_to_fit();
	scores_map.clear(); scores_map.shrink_to_fit();
}

std::list<std::pair<int, int>> AStarSearch::Search(const std::vector<std::vector<int>> &map, const std::pair<int, int> src, const std::pair<int, int> tar) {

	Reset();

	is_visit.resize(map_rows);
	for (int i = 0; i < is_visit.size(); i++)
		is_visit[i].resize(map_cols, false);

	scores_map.resize(map_rows);
	for (int i = 0; i < scores_map.size(); i++)
		scores_map[i].resize(map_cols, INT_MAX);

	cost_map.resize(map_rows);
	for (int i = 0; i < cost_map.size(); i++)
		cost_map[i].resize(map_cols, INT_MAX);

	std::pair<int, int> cur_pos = src;
	is_visit[cur_pos.second][cur_pos.first] = true;
	cost_map[cur_pos.second][cur_pos.first] = 0;

	while (cur_pos.first != tar.first || cur_pos.second != tar.second) {

		std::vector<std::pair<int, int>> neighbors = FindNeighbors(cur_pos);
		std::vector<int> scores = GetScores(map, neighbors, cur_pos, tar);

		for (int i = 0; i < scores.size(); i++) {

			if (neighbors[i].first < 0 || neighbors[i].first >= this->map_cols || neighbors[i].second < 0 || neighbors[i].second >= this->map_rows)
				continue;

			if (!is_visit[neighbors[i].second][neighbors[i].first] && scores[i] != INT_MAX)
				queue.push_back(std::pair<std::pair<int, int>, int>(neighbors[i], scores[i]));

			scores_map[neighbors[i].second][neighbors[i].first] = scores[i];
		}

		int min_scores = INT_MAX, min_idx, idx = 0;
		std::list<std::pair<std::pair<int, int>, int>>::iterator itr = queue.begin();
		std::list<std::pair<std::pair<int, int>, int>>::iterator itr2;

		for (; itr != queue.end(); ++itr) {
			if (min_scores > itr->second) {
				min_scores = itr->second;
				min_idx = idx;
				itr2 = itr;
			}
			idx++;
		}

		cur_pos = itr2->first;
		is_visit[cur_pos.second][cur_pos.first] = true;
		queue.remove(*itr2);
	}

	FindShortestPath(map, src, tar);

	return shortest_path;
}

std::vector<std::pair<int, int>> AStarSearch::FindNeighbors(const std::pair<int, int> cur_pos) {

	std::vector<std::pair<int, int>> neighbors(4);

	int move_x[] = { 1, -1, 0,  0 };
	int move_y[] = { 0,  0, 1, -1 };

	for (int i = 0; i < neighbors.size(); i++) {
		neighbors[i].first = move_x[i] + cur_pos.first;
		neighbors[i].second = move_y[i] + cur_pos.second;
	}

	return neighbors;
}

std::vector<int> AStarSearch::GetScores(const std::vector<std::vector<int>> &map, const std::vector<std::pair<int, int>> neighbors, const std::pair<int, int> cur_pos, const std::pair<int, int> tar_pos) {

	std::vector<int> scores(neighbors.size());

	for (int i = 0; i < neighbors.size(); i++) {
		if (neighbors[i].first < 0 ||
			neighbors[i].first >= this->map_cols ||
			neighbors[i].second < 0 ||
			neighbors[i].second >= this->map_rows ||
			map[neighbors[i].second][neighbors[i].first] == 0) {
			scores[i] = INT_MAX;
			continue;
		}

		if (cost_map[cur_pos.second][cur_pos.first] + 1 < cost_map[neighbors[i].second][neighbors[i].first])
			cost_map[neighbors[i].second][neighbors[i].first] = cost_map[cur_pos.second][cur_pos.first] + 1;

		float h = std::sqrt(std::pow((tar_pos.first - neighbors[i].first), 2) + std::pow((tar_pos.second - neighbors[i].second), 2));

		scores[i] = cost_map[neighbors[i].second][neighbors[i].first] + std::round(h);
	}

	return scores;
}

void AStarSearch::FindShortestPath(const std::vector<std::vector<int>> &map, const std::pair<int, int> src, const std::pair<int, int> tar) {

	std::pair<int, int> cur_pos = tar;
	std::vector<std::pair<int, int>> neighbors;

	int min_idx;

	shortest_path.push_front(tar);

	for (int i = 0; i < is_visit.size(); i++)
		for (int j = 0; j < is_visit[i].size(); j++)
			is_visit[i][j] = false;

	is_visit[cur_pos.second][cur_pos.first] = true;

	while (cur_pos.first != src.first || cur_pos.second != src.second) {

		float min_scores = std::numeric_limits<float>::infinity();

		neighbors = FindNeighbors(cur_pos);

		for (int i = 0; i < neighbors.size(); i++) {

			if (neighbors[i].first < 0 || neighbors[i].first >= this->map_cols || neighbors[i].second < 0 || neighbors[i].second >= this->map_rows)
				continue;

			if (min_scores > scores_map[neighbors[i].second][neighbors[i].first] && !is_visit[neighbors[i].second][neighbors[i].first] && map[neighbors[i].second][neighbors[i].first] != 0) {
				min_scores = scores_map[neighbors[i].second][neighbors[i].first];
				cur_pos = neighbors[i];
			}
		}

		is_visit[cur_pos.second][cur_pos.first] = true;
		shortest_path.push_front(cur_pos);
	}

	return;
}