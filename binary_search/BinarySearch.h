#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include<vector>

class BinarySearch {
private:
	std::vector<int> data;

	void Split(const std::vector<int> &data, const int tar_val, const int left_index, const int right_index, const bool is_ascend, int &arr_idx);

public:

	BinarySearch(const int *input_data, const int data_length);

	BinarySearch(const std::vector<int> &input_data);

	int FindValue(const int val, const bool is_ascend);
};

#endif
