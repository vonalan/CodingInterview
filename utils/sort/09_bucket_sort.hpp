#include <iostream>
#include <vector>
#include "../vector_utils.hpp"
#include <algorithm>

using namespace std;


void bucket_sort(vector<int> &nums, int num_buckets) {
    throw "use bucket_sort_opt! ";
    if (nums.empty()) {return; }
    show_vector(nums);
    
    int min_val = nums[0], max_val = nums[0];
    for (int i = 0; i < nums.size(); ++i) {
        min_val = nums[i] < min_val ? nums[i] : min_val;
        max_val = nums[i] > max_val ? nums[i] : max_val;
    }
    cout << "min_val " << min_val << " max_val " << max_val << endl;

    // 至少有1个数 || 至少有1个bucket || interval至少为1
    int interval = (max_val - min_val + 1) % num_buckets == 0 ? 
        (max_val - min_val + 1) / num_buckets : (max_val - min_val + 1) / num_buckets + 1;
    cout << "num_buckets " << num_buckets <<  " iterval " << interval << endl;

    vector<vector<int>> buckets(num_buckets + 1);
    for (int i = 0; i < nums.size(); ++i) {
        buckets[(nums[i] - min_val) / interval].push_back(nums[i]);
    }
    show_matrix(buckets);

    int bkt_idx = 0, dst_idx = 0;
    while (bkt_idx < buckets.size() && dst_idx < nums.size()) {
        // 桶内原位排序 || 使用自己写的代码替换？
        sort(buckets[bkt_idx].begin(), buckets[bkt_idx].end());

        // 使用std::copy替换？
        int src_idx = 0;
        while (src_idx < buckets[bkt_idx].size() && dst_idx < nums.size()) {
            nums[dst_idx++] = buckets[bkt_idx][src_idx++];
        }

        bkt_idx++;
    }
    show_vector(nums);
}


void bucket_sort_opt(vector<int> &nums, int num_buckets) {
    // 时间复杂度：桶内排序： 基于比较排序O(4N + N * log(interval)) || 基数排序O(4N + N)
    // 空间复杂度：O(2N)
    if (nums.empty()) {return; }
    // show_vector(nums);

    int min_val = nums[0], max_val = nums[0];
    for (int i = 0; i < nums.size(); ++i) {
        min_val = nums[i] < min_val ? nums[i] : min_val;
        max_val = nums[i] > max_val ? nums[i] : max_val;
    }
    cout << "min_val " << min_val << " max_val " << max_val << endl;

    // 至少有1个数 || 至少有1个bucket || interval至少为1
    int interval = (max_val - min_val + 1) % num_buckets == 0 ? 
        (max_val - min_val + 1) / num_buckets : (max_val - min_val + 1) / num_buckets + 1;
    cout << "num_buckets " << num_buckets <<  " iterval " << interval << endl;

    // vector<vector<int>> buckets(num_buckets + 1);
    vector<int> buckets(num_buckets + 1, 0);
    for (int i = 0; i < nums.size(); ++i) {
        buckets[(nums[i] - min_val) / interval]++;
    }
    // show_vector(buckets);

    for (int i = 1; i < buckets.size(); ++i) {
        // 分配pos_buckets[i]占temp的起止点
        buckets[i] += buckets[i - 1];
    }
    // show_vector(buckets);

    vector<int> temp(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        temp[buckets[(nums[i] - min_val) / interval] - 1] = nums[i];
        buckets[(nums[i] - min_val) / interval]--;
    }
    
    // 桶内原位排序 || 使用自己写的代码替换？
    for (int i = 0; i < buckets.size(); ++i) {
        if (i == 0) {
            sort(temp.begin() + 0, temp.begin() + buckets[i]);
        } else {
            sort(temp.begin() + buckets[i - 1], temp.begin() + buckets[i]);
        }
    }

    for (int i = 0; i < nums.size(); ++i) {nums[i] = temp[i]; }
}

// int main() {
//     vector<int> nums = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
//     bucket_sort_opt(nums, nums.size() / 2);

//     return 0;
// }