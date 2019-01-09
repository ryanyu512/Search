#include"BinarySearch.h"

BinarySearch::BinarySearch(const int *input_data, const int data_length) {

	data.resize(data_length);

	for (int i = 0; i < data.size(); i++)
		data[i] = input_data[i];

	return;
}

BinarySearch::BinarySearch(const std::vector<int> &input_data) :data(input_data) {
}

int BinarySearch::FindValue(const int val, const bool is_ascend) {

	int arr_idx = -1;

	Split(data, val, 0, data.size() - 1, is_ascend, arr_idx);

	return arr_idx;
}

void BinarySearch::Split(const std::vector<int> &data, const int tar_val, const int left_index, const int right_index, const bool is_ascend, int &arr_idx) {

	int mid_idx = (left_index + right_index) / 2;

	if (data[mid_idx] != tar_val && left_index == right_index)
		return;
	else if (data[mid_idx] == tar_val) {
		arr_idx = mid_idx;
		return;
	}

	if (is_ascend) {
		if (data[mid_idx] < tar_val)
			Split(data, tar_val, mid_idx + 1, right_index, is_ascend, arr_idx);
		else if (data[mid_idx] > tar_val)
			Split(data, tar_val, left_index, mid_idx - 1, is_ascend, arr_idx);
	}
	else {
		if (data[mid_idx] < tar_val)
			Split(data, tar_val, left_index, mid_idx - 1, is_ascend, arr_idx);
		else if (data[mid_idx] > tar_val)
			Split(data, tar_val, mid_idx + 1, right_index, is_ascend, arr_idx);
	}

	return;
}