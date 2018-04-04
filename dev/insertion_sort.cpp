#include <iostream> 

using namespace std; 

void Show(int *nums, int start, int end){
    for(int i = start; i < end; ++i){
        cout << nums[i] << " "; 
    }
    cout << endl; 
}

// Straight Insertion Sort; 
void StraightInsertSort(int *nums, int start, int end){
    // Show(nums, start, end); 

    int temp = 0; 
    for(int i = start; i < end; ++i){
        for(int j = i; j > 0 && nums[j] < nums[j-1]; --j){
            temp = nums[j]; 
            nums[j] = nums[j-1]; 
            nums[j-1] = temp; 

            // Show(nums, start, end); 
        }
    }
}

int main(int argc, char **argv){
    int N = 10; 
    int nums[N] = {49,27,13,76,97,65,38,49,26,89}; 
    StraightInsertSort(nums, 0, N); 
    
    return 0; 
}
