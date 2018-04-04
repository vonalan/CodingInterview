#include <iostream> 
#include <vector> 

using namespace std; 

// Given a sorted array may contrain duplicates, 
// return lower bound and upper bound of a given integer; 

void searchBound(vector<int> &nums, vector<int> &index, int target, int start, int end){
    if(start > end) return; 
    
    int mid = (start + end) / 2; 
    if(nums[mid] == target){
        index[0] = mid < index[0] ? mid : index[0]; 
        index[1] = mid > index[1] ? mid : index[1]; 
    }
    
    // right 
    if(nums[mid] <= target)
        searchBound(nums, index, target, mid + 1, end); 
    
    // left 
    if(nums[mid] >= target)
        searchBound(nums, index, target, start, mid - 1); 
}

vector<int> searchBound(vector<int> &nums, int target){
    vector<int> index = {nums.size(), -1}; 
    searchBound(nums, index, target, 0, nums.size() - 1); 
    
    if(index[0] > index[1]){
        cout << "Invalid Input! " << endl; 
        return vector<int>(); 
    }
    else{
        for(auto &i : index)
            cout << i << " ";
        return index; 
    }
}

int main(int argc, char **argv){
    vector<int> nums = {1,2,3,3,3,3,6}; 
    vector<int> res1 = searchBound(nums, 1); 
    cout << endl; 
    vector<int> res2 = searchBound(nums, 2); 
    cout << endl; 
    vector<int> res3 = searchBound(nums, 3);
    cout << endl; 
    vector<int> res4 = searchBound(nums, 6); 
    cout << endl; 
    vector<int> res5 = searchBound(nums, 7); 
    return 0; 
}