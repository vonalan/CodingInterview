// #include <unistd.h>

#include <iostream> 

using namespace std; 

void Show(int *nums, int start, int end){
    for(int i = start; i < end; ++i){
        cout << nums[i] << " "; 
    }
    cout << endl; 
}

void Swap(int *nums, int i, int j){
    int temp = nums[i]; 
    nums[i] = nums[j]; 
    nums[j] = temp; 
}

void Merge(int *nums, int *result, int start, int end, int middle){
    int i = start; 
    int j = start, k = middle + 1; 
    while(i < end && j < middle + 1 && k < end){
        if(nums[j] <= nums[k]) result[i++] = nums[j++]; 
        else result[i++] = nums[k++]; 
    }
    while(i < end && j < middle + 1) result[i++] = nums[j++]; 
    while(i < end && k < end) result[i++] = nums[k++]; 

    for(int i = start; i < end; ++i) nums[i] = result[i]; 
}

void MergeSort(int *nums, int *result, int start, int end){
    if(start >= end - 1) return ; 

    // Show(nums, start, end);
    // sleep(1); 

    // int middle = (start + end - 1) / 2; 
    int middle = (start + end - 1) >> 1; 
    // cout << middle << endl; 

    MergeSort(nums, result, start, middle + 1); 
    MergeSort(nums, result, middle + 1, end); 
    Merge(nums, result, start, end, middle); 
}

int main(int argc, char **argv){
    int N = 10; 
    int nums[N] = {49,27,13,76,97,65,38,49,26,89}; 
    // int N = 3; 
    // int nums[N] = {49,27,13};

    int result[N]; 
    for(int i = 0; i < N; ++i) result[i] = nums[i]; 

    Show(nums, 0, N); 
    MergeSort(nums, result, 0, N); 
    Show(nums, 0, N); 

    return 0; 
}
