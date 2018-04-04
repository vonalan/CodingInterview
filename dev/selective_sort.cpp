#include <iostream> 

using namespace std; 

void Show(int *nums, int start, int end){
    for(int i = start; i < end; ++i){
        cout << nums[i] << " "; 
    }
    cout << endl; 
}

// Simple Selective Sort; 
void SimpleSelectiveSortOld(int *nums, int start, int end){
    // Show(nums, start, end); 

    int temp = 0; 
    for(int i = start; i < end - 1; ++i){
        for(int j = i + 1; j < end; ++j){
            if(nums[i] > nums[j]){
                temp = nums[i]; 
                nums[i] = nums[j]; 
                nums[j] = temp; 
            }
            // Show(nums, start, end); 
        }
    }
}

// Simple Selective Sort; Optimized! 
void SimpleSelectiveSort(int *nums, int start, int end){
    // Show(nums, start, end); 

    int temp = 0; 
    for(int i = start; i < end - 1; ++i){
        int min_idx = i; 
        for(int j = i + 1; j < end; ++j){
            if(nums[min_idx] > nums[j]){
                min_idx = j; 
            }
        }
        
        if(min_idx != i) {
            temp = nums[i]; 
            nums[i] = nums[min_idx]; 
            nums[min_idx] = temp; 
        } 
        
        // Show(nums, start, end); 
    }
}

int main(int argc, char **argv){
    int N = 10; 
    int nums[N] = {49,27,13,76,97,65,38,49,26,89}; 
    Show(nums, 0, N); 
    SimpleSelectiveSort(nums, 0, N); 
    Show(nums, 0, N); 
    
    return 0; 
}
