#include <iostream> 

using namespace std; 

void Show(int *nums, int start, int end){
    for(int i = start; i < end; ++i){
        cout << nums[i] << " "; 
    }
    cout << endl; 
}

// Bubble Sort; 
void BubbleSortOld(int *nums, int start, int end){
    // Show(nums, start, end); 

    int temp; 
    for(int i = start; i < end; ++i){
        for(int j = start; j < end - 1 - i; ++j){
            if(nums[j] > nums[j+1]){
                temp = nums[j]; 
                nums[j] = nums[j+1]; 
                nums[j+1] = temp; 
            }
            // Show(nums, start, end); 
        }
    }
}

// Bubble Sort; 
void BubbleSort(int *nums, int start, int end){
    // Show(nums, start, end); 

    int temp, flag = 1; 
    for(int i = start; i < end; ++i){
        flag = 1; 
        for(int j = start; j < end - 1 - i; ++j){
            if(nums[j] > nums[j+1]){
                temp = nums[j]; 
                nums[j] = nums[j+1]; 
                nums[j+1] = temp; 

                flag = 0; 
                // Show(nums, start, end); 
            }
        }
        if(flag) break; 
    }
}

int main(int argc, char **argv){
    int N = 10; 
    int nums[N] = {49,27,13,76,97,65,38,49,26,89}; 
    Show(nums, 0, N); 
    BubbleSort(nums, 0, N); 
    Show(nums, 0, N); 
    
    return 0; 
}
