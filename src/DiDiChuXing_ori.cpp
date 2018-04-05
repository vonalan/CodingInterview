#include <iostream>
#include <vector>

using namespace std; 

/*
����һ��vector��vector�е����ְ����ϸ��������У���������ͬ���֣����������x�������vector�е�lower_bound��upper_bound����֤vector�д���������֡�
���磬vector��Ϊ1��2��3��3��6����x = 3ʹ������±�2��3��
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