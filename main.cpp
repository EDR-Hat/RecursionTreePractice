// main.cpp
// created by Evan Hatton on September 22nd 2020
//

#include <iostream>
#include <vector>
#include <fstream>


#include "project3.hpp"

int main (int argc, char *argv[]){
	if (argc != 3 || std::stoi(argv[2]) > 7 || std::stoi(argv[2]) < 0){
		std::cout << "Usage: " << argv[0] << " inputFile functionChoice*" << std::endl;
		std::cout << "functionChoice is an integer from 0 to 7. 0: count_inversions_recursive, 1: count_inversions_iterative, 2: largest_left_recursive, 3: largest_left_iterative, 4: larger_left_right_recursive, 5: larger_left_right_iterative, 6: increasing_sequences_recursive, 7: increasing_sequences_iterative" << std::endl;
		exit(1);
	}

	std::fstream file;
	file.open(argv[1]);
	if (! file.is_open()){
		std::cout << "File: " << argv[1] << " does not work." << std::endl;
		exit(2);
	}
	file.close();
	std::vector<int> nums;
	read_numbers(argv[1], nums);
	std::vector<int> out;

	switch (std::stoi(argv[2])){
		case 0:
			std::cout << count_inversions_recursive(nums, nums.size()) << std::endl;
			break;
		case 1:
			std::cout << count_inversions_iterative(nums) << std::endl;
			break;
		case 2:
			largest_left_recursive(nums, out, nums.size());
			for ( auto i : out)
				std::cout << i << std::endl;
			break;
		case 3:
			largest_left_iterative(nums, out);
			for ( auto i : out)
				std::cout << i << std::endl;
			break;
		case 4:
			larger_left_right_recursive(nums, out, nums.size());
			for ( auto i : out)
				std::cout << i << std::endl;
			break;
		case 5:
			larger_left_right_iterative(nums, out);
			for ( auto i : out)
				std::cout << i << std::endl;
			break;
		case 6:
			std::cout << increasing_sequences_recursive(nums, 0) << std::endl;
			break;
		case 7:
			std::cout << increasing_sequences_iterative(nums) << std::endl;
			break;
	}


	return 0;
}
