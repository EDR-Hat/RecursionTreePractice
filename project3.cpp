// project3.cpp
// created by Evan Hatton on September 22, 2020


#ifndef PROJ3_CPP
#define PROJ3_CPP
#include "project3.hpp"

void read_numbers(std::string fileName, std::vector<int> &v){
	std::ifstream reader;
	reader.open(fileName);
	std::string num;
	char digit;
	while (reader.get(digit)){
		if ((int) digit == 9 || (int) digit == 20 || (int) digit == 10)
			num = "";
		else
			num.push_back(digit);
		digit = reader.peek();
		if ( (int) digit == 9 || (int) digit == 20 || (int) digit == 10)
			v.push_back(std::stoi(num));
		if (digit == EOF)
			break;
	}
	reader.close();
}

int count_inversions_iterative(const std::vector<int> &numbers){
	int inverts = 0;
	for(int i = 1; i < numbers.size(); i++)
		if ( numbers[i] > numbers[ i-1 ] )
			inverts++;
	return inverts;
}

int largest_iterative_helper(const std::vector<int> &numbers, int start){
	for (int i = start - 1; i > -1; i--)
		if (numbers[i] > numbers[start])
			return i;
	return -1;
}


void largest_left_iterative(const std::vector<int> &numbers, std::vector<int> &result){
	int largest_index, i = 1;
	largest_index = 0;
	result.push_back(0);
	do{
		largest_index = largest_iterative_helper(numbers, i);
		if ( largest_index == -1){
			result.push_back(0);
		} else{
			result.push_back(numbers[largest_index]);
		}
		i++;
	} while (i < numbers.size());
}

int left_arrow(const std::vector<int> &numbers, int idx, int val){
	while (--idx > -1) // decrement and check
		if (numbers[idx] > val)
			return numbers[idx];
	return 0;
}

int right_arrow(const std::vector<int> &numbers, int idx, int val){
	while (++idx < numbers.size()) // increment and check
		if (numbers[idx] > val)
			return numbers[idx];
	return 0;
}
	

void larger_left_right_iterative(const std::vector<int> &numbers, std::vector<int> &result){
	int a, b; // holder variables
	for (int i = 0; i < numbers.size(); i++){ // outer loop
		a = left_arrow(numbers, i, numbers[i]);
		b = right_arrow(numbers, i, numbers[i]);
		if (a > b) // if the left arrow has the larger weight
			result.push_back(a);
		else
			result.push_back(b);
	}
}

int increasing_sequences_iterative(std::vector<int> &numbers){
	int val = 0, tmp = 0, large = numbers[0], idx = 0;
	while (idx < numbers.size()){
		if (numbers[idx++] > large){
			tmp++;
			large = numbers[idx-1];
		} else {
			if (val < tmp)
				val = tmp;
			tmp = 0;
			large = 0;
		}
	}
	return val;
}


int increasing_sequences_recursive(std::vector<int> &numbers, int startIdx){
	if ( startIdx == numbers.size() - 1){
		numbers.push_back(1);
		return 1;
	} else {
		int count = increasing_sequences_recursive(numbers, startIdx + 1);
		// this has to be here so that it calls from idx = numbers.size()

		if ( numbers[startIdx] <= numbers[startIdx + 1])
			count++;
		else
			count = 1;

		if ( count > numbers.back() )
			numbers.back() = count;

		if (startIdx == 0){
			if ( count < numbers.back() )
				count = numbers.back();
			numbers.pop_back();
		}

		return count;
	}
}

void larger_left_right_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n){
	if ( n == 0){
		if ( *(result.end() - 1) == *(result.end() - 2) && *(result.end() - 1) == -1){
			// no larger value found in the vector (n-1 is at the largest value in sequence)
			result.pop_back();
			result.pop_back();
			result.push_back(0);
		} else{ 
			if ( *(result.end() - 1) > *(result.end() - 2) ) // is left or right getting erase?
				result.erase( result.end() - 2);
			else
				result.pop_back();
		}

		if ( result.size() != numbers.size() ) // the true terminating condition of the recursive call
			larger_left_right_recursive(numbers, result, numbers.size());


	} else { 
		if ( numbers.size() == n ){ // the result vector is used like a stack, the last two numbers are
			// holding places for the respective left and right larger numbers
			result.push_back(-1);
			result.push_back(-1);
	  	}

		if ( n - 1 > result.size() - 2 ) // these check whether n is to the left or right of the number
			// being compared. - 2 is necessary due to the vector having those holding numbers
			if ( numbers[n - 1] > numbers[result.size() - 2] ){
				*(result.end() - 1) = numbers[n - 1];
			}

		if ( n - 1 < result.size() - 2 )
			// the ((current cell) - (n-1)) - 1 calculation makes the index of n mirrored
			// so when it's at 0, n is the largest value
			if ( numbers[ ((result.size() - 2) - (n - 1)) - 1 ] > numbers[result.size() - 2] ){
				*(result.end() - 2) = numbers[ ((result.size() - 2) - ( n - 1)) - 1];
			}

		larger_left_right_recursive(numbers, result, n - 1 );
	}
}


void largest_left_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n){
	if (n == 0 || n == 1 && result.size() == 0){
		if (! n)
			result.pop_back();
		result.push_back(0);
	} else if (n > 0) {
		if (result.size() > n){
			if (numbers[n - 1] > result.back()){
				result.pop_back();
				result.push_back(numbers[n - 1]);
				n = -1;
			} 
		} else if ( result.size() < n){
			largest_left_recursive(numbers, result, n - 1);
			result.push_back(numbers[n - 1]);
		}
		largest_left_recursive(numbers, result, n - 1);
	}
}

int count_inversions_recursive(const std::vector<int> &numbers, int n){
	if (n == 1)
		return 0;
	return (int) (numbers[n - 1] < numbers[n - 2]) + count_inversions_recursive(numbers, n - 1);
}
#endif
