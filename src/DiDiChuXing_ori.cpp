#include <iostream>
#include <vector>

using namespace std; 

/*
给定一个vector，vector中的数字按照严格升序排列，可能有相同数字，求给定数字x的在这个vector中的lower_bound和upper_bound，保证vector中存在这个数字。
例如，vector中为1，2，3，3，6。当x = 3使，输出下标2，3。
*/

void searchIndexFromSortedArray(vector<int> &nums, vector<int> &results, int target, int start, int end) {
	if (start > end) return;
	if (start == end){
		if (nums[start] == target) {
			results[0] = start < results[0] ? start : results[0];
			results[1] = start > results[1] ? start : results[1];
		}
		return; // important! 
	}

	int middle = (start + end) / 2;
	if(nums[middle] <= target) searchIndexFromSortedArray(nums, results, target, start, middle);
	else searchIndexFromSortedArray(nums, results, target, middle + 1, end);
}

vector<int> searchIndexFromSortedArray(vector<int> &nums, int target) {
	int n = nums.size(); 
	vector<int> results = {n, -1}; 
	searchIndexFromSortedArray(nums, results, target, 0, n - 1);
	return results;
}

int main(int argc, char **argv) {
	vector<int> nums = { 1,2,6 };
	vector<int> results = searchIndexFromSortedArray(nums, 3);
	if (results.front() > results.back()) cout << "Invalid Input! " << endl; 
	else cout << results.front() << " " << results.back() << endl; 
	system("pause"); 
}