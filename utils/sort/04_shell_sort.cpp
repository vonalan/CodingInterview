#include <iostream>
#include <vector>

using namespace std;


void show_vector(vector<int> &nums, int start, int end){
    for(int i = start; i < end; ++i){
        cout << nums[i] << " "; 
    }
    cout << endl; 
}

void ShellSort(vector<int> &nums, int sidx, int eidx) {
    /* 希尔排序
     * 递减增量排序算法，是插入排序的一种更高效的改进版本。但希尔排序是非稳定排序算法。
    */
    int gap = (eidx - sidx) / 2;

    while (gap > 0) {
        cout << "gap " << gap << end;

        for (int offset = sidx; offset < sidx + gap; ++offset) {
            // i左半部分是排好序的
            // 每次将i插入到左半部分合适的位置
            for (int i = 0; offset + i * gap < eidx; ++i) {
                for (int j = i; j > i && nums[offset + j * gap] < nums[offset + (j - 1) * gap]; --j) {
                    temp = nums[offset + (j - 1) * gap];
                    nums[offset + (j - 1) * gap] = nums[offset + j * gap];
                    nums[offset + j * gap] = temp;
                }
            }
            show_vector(nums, sidx, eidx);
        }
        gap >> 1;
    }
}


int main () {
    vector<int> nums = {49,27,13,76,97,65,38,49,26,89};
    ShellSort(vector, 0, nums.size());

    return 0;
}