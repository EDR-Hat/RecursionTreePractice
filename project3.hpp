// project3.hpp
// created by Evan Hatton on September 22, 2020
//

#include <vector>
#include <string>
#include <iostream>
#include <fstream>


#ifndef PROJ3_HPP
#define PROJ3_HPP

// readnums
void read_numbers(std::string fileName, std::vector<int> &v);

// recursive function headers
int count_inversions_recursive(const std::vector<int> &numbers, int n);
void largest_left_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n);
void larger_left_right_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n);
int increasing_sequences_recursive(std::vector<int> &numbers, int startIdx);

// iterative function headers
int count_inversions_iterative(const std::vector<int> &numbers);
void largest_left_iterative(const std::vector<int> &numbers, std::vector<int> &result);
void larger_left_right_iterative(const std::vector<int> &numbers, std::vector<int> &result);
int increasing_sequences_iterative(std::vector<int> &numbers);

// helper functions
int right_arrow(const std::vector<int> &numbers, int idx, int val);
int left_arrow(const std::vector<int> &numbers, int idx, int val);
int largest_iterative_helper(const std::vector<int> &numbers, int start);

#endif
