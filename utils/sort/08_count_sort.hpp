#include <iostream>
#include <vector>
#include "../LikeCode/utils/vector_utils.hpp"

using namespace std;


void count_sort(vector<int> &nums) {
    if (nums.empty()) {return; }
    show_vector(nums);
    
    int min_val = nums[0], max_val = nums[0];
    for (int i = 0; i < nums.size(); ++i) {
        min_val = nums[i] < min_val ? nums[i] : min_val;
        max_val = nums[i] > max_val ? nums[i] : max_val;
    }

    // (max_val - min_val + 1) - 1 不能超过size_t
    vector<int> buckets(max_val - min_val + 1, 0);
    for (int i = 0; i < nums.size(); ++i) {
        buckets[nums[i] - min_val]++;
    }

    int bkt_idx = 0, dst_idx = 0;
    while (bkt_idx < buckets.size() && dst_idx < nums.size()) {
        int src_idx = 0;
        while (src_idx++ < buckets[bkt_idx] && dst_idx < nums.size()) {
            nums[dst_idx++] = bkt_idx + min_val;
        }
        bkt_idx++;
    }
    show_vector(nums);
}


// int main() {
//     vector<int> nums = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
//     count_sort(nums);

//     return 0;
// }