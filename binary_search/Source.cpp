#include<iostream>
#include"BinarySearch.h"

int main() {

	//int data[] = { 1,2,3,4,5,6,7,8,9,10 };
	int data[] = { 10,9,8,7,6,5,4,3,2,1};
	int length = 10;

	BinarySearch binary_search(data, length);
	int idx = binary_search.FindValue(-1, false);

	if (idx >= 0)
		std::cout << "result: " << data[idx] << std::endl;
	else
		std::cout << "cannot find the value" << std::endl;

	std::getchar(); std::getchar();

	return 0;
}


