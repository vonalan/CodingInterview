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


int PartionOld(int *nums, int start, int end){
    Swap(nums, start, end - 1); 
    // Show(nums, start, end); 

    int pivot = start - 1; 
    for(int i = start; i < end - 1; ++i){
        if(nums[i] < nums[end-1]){
            pivot++; 
            if(pivot != i) Swap(nums, pivot, i); 
            // Show(nums, start, end); 
        }
    }

    pivot++; 
    Swap(nums, pivot, end - 1); 
    // Show(nums, start, end); 

    return pivot; 
}


int Partion(int *nums, int start, int end){
    int low = start, high = end; 

    int pivot = nums[start]; 
    while(start < (end - 1)){
        while(start < (end - 1) && nums[end - 1] >= pivot) end--; 
        nums[start] = nums[end-1]; 
        // cout << start << " " << end - 1 << endl; 
        // Show(nums, low, high); 

        while(start < (end - 1) && nums[start] <= pivot) start++; 
        nums[end-1] = nums[start]; 
        // cout << start << " " << end - 1 << endl; 
        // Show(nums, low, high); 
    }

    nums[start] = pivot; 
    // Show(nums, low, high); 

    return start; 
}


int QuickPartion(vector<int> &nums, int sidx , int eidx) {
    // 快排的核心算法: 根据pivot切分数组, 返回切割点
    /* 快排的最坏情况
    *  左侧元素作为枢纽, 数组正序排过序; 右侧元素作为枢纽, 数组倒序排过序; 所有元素相同
    *  由于每次只能处理一个元素, 时间复杂度是O(N**2)
    *  随机选择pivot可以减少这种情况的出现, 除非选中了数组最大或者最小的元素
    */
    if (sidx >= eidx) {return -1; }

    int pivot = nums[sidx];
    int lft = sidx, rht = eidx - 1;
    while (lft < rht) {
        // 从右往左找到第一个小于等于pivot的数
        while (lft < rht && nums[rht] > pivot) {
            rht--;
        }
        nums[lft] = nums[rht];

        // 从左往右找到第一个大于pivot的数
        while(lft < rht && nums[lft] <= pivot) {
            lft++;
        }
        nums[rht] = nums[lft];
    }
    nums[lft] = pivot;

    return lft;
}


// Quick Sort, a enhancement version of Bubble Sort; 
// The implementation of C++ std::sort(); 
void QuickSort(int *nums, int start, int end){
    if(start >= end - 1) return ;

    // int pivot = PartionOld(nums, start, end);
    int pivot = Partion(nums, start, end);

    QuickSort(nums, start, pivot - 1 + 1); 
    QuickSort(nums, pivot + 1, end); 
}


int main(int argc, char **argv){
    int N = 10; 
    int nums[N] = {49,27,13,76,97,65,38,49,26,89}; 
    Show(nums, 0, N); 
    QuickSort(nums, 0, N); 
    Show(nums, 0, N); 

    return 0; 
}