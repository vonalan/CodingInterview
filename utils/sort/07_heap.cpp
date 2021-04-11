#include "heap.hpp"

#include <iostream> 
#include <algorithm>

using namespace std; 

// override 
// overloade 
// namespace 

void PushTopKHeap(vector<int> &nums, int start, int end, int k, int num){
    if(end - start < k){
        nums.push_back(num); 
        heap::push_heap(nums, start, nums.size()); 
    } else {
        // find the minimum of nums; 
        // sort_heap, O(logN); 
        // linear search, O(N); 

        // sort_heap, O(logN); 
        heap::sort_heap(nums, start, end); 
        if(nums[start] < num) nums[start] = num; 
        heap::push_heap(nums, start, end); 
    }
}

int heap::is_heap(vector<int> &nums, int start, int end){
    if(start >= end) return -1; // 0:false; 1: true; -1:error
    
    // int flag1 = 0, flag2 = 0; 
    int max_idx = start; 
    if(2 * start + 1 < end){
        int flag1 = is_heap(nums, 2 * start + 1, end); 
        if(flag1 != 1) return flag1; 

        max_idx = nums[max_idx] >= nums[2 * start + 1] ? max_idx : 2 * start + 1; 
    }

    if(2 * start + 2 < end){
        int flag2 = is_heap(nums, 2 * start + 2, end); 
        if(flag2 != 1) return flag2; 
        
        max_idx = nums[max_idx] >= nums[2 * start + 1] ? max_idx : 2 * start + 1; 
    }

    if(max_idx == start) return 1; 
    else return 0; 
}

void heap::push_heap(vector<int> &nums, int start, int end){
    if(start >= end) return ; 

    int max_idx = start; 
    if(2 * start + 1 < end){
        push_heap(nums, 2 * start + 1, end); 
        max_idx = nums[max_idx] >= nums[2 * start + 1] ? max_idx : 2 * start + 1; 
    }

    if(2 * start + 2 < end){
        push_heap(nums, 2 * start + 2, end); 
        max_idx = nums[max_idx] >= nums[2 * start + 2] ? max_idx : 2 * start + 2; 
    }

    if(max_idx != start){
        swap(nums[max_idx], nums[start]); 
        push_heap(nums, max_idx, end); 
    }
}

void heap::pop_heap(vector<int> &nums, int start, int end){
    if(start >= end) return ; 

    swap(nums[start], nums[end-1]); 
    push_heap(nums, 0, end - 1); 
}

void heap::sort_heap(vector<int> &nums, int start, int end){
    if(start >= end - 1) return ; 

    while(start < end - 1){
        pop_heap(nums, start, end--); 
        // for(auto &i : nums) cout << i << " ";
        // cout << endl;
    }
}

/* 
int main(int argc, char **argv){
    // int N = 10;
    vector<int> nums = {49,27,13,76,97,65,38,49,26,89}; 
    for(auto &i : nums) cout << i << " ";
    cout << endl;
    cout << heap::is_heap(nums, 0, nums.size()) << endl; 
    
    heap::push_heap(nums, 0, nums.size()); 
    for(auto &i : nums) cout << i << " ";
    cout << endl;
    cout << heap::is_heap(nums, 0, nums.size()) << endl; 

    heap::sort_heap(nums, 0, nums.size()); 
    for(auto &i : nums) cout << i << " ";
    cout << endl;
    cout << heap::is_heap(nums, 0, nums.size()) << endl; 

    vector<int> temp; 
    while(nums.size()){
        heap::pop_heap(nums, 0, nums.size()); 
        temp.push_back(nums.back()); 
        nums.pop_back(); 
        // for(auto &i : nums) cout << i << " ";
        // cout << endl;
    }
    
    reverse(temp.begin(), temp.end()); 
    while(temp.size()){
        nums.push_back(temp.back()); 
        heap::push_heap(nums, 0, nums.size()); 
        temp.pop_back(); 
        // for(auto &i : nums) cout << i << " ";
        // cout << endl;
    }

    heap::sort_heap(nums, 0, nums.size()); 
    for(auto &i : nums) cout << i << " ";
    cout << endl;
    cout << heap::is_heap(nums, 0, nums.size()) << endl; 

    vector<int> result; 
    for(int &i : nums){
        PushTopKHeap(result, 0, result.size(), 5, i); 
        for(int &j : result) cout << j << " ";
        cout << endl;
    }

    vector<int> test; 
    int num; 
    while(cin >> num){
        PushTopKHeap(test, 0, test.size(), 5, num); 
        for(int &j : test) cout << j << " ";
        cout << endl;
    }

    return 0; 
}
*/
