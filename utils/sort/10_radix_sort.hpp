#include <iostream>
#include <vector>
#include "../vector_utils.hpp"
#include <algorithm>

using namespace std;


void radix_sort(vector<int> &nums) {
    throw "use radix_sort_opt_dev! ";
    if (nums.empty()) {return; }
    show_vector(nums);
    
    int min_val = nums[0], max_val = nums[0];
    for (int i = 0; i < nums.size(); ++i) {
        min_val = nums[i] < min_val ? nums[i] : min_val;
        max_val = nums[i] > max_val ? nums[i] : max_val;
    }
    cout << "min_val " << min_val << " max_val " << max_val << endl;

    // 如果有负数怎么解决？
    if (min_val < 0) {throw "minimum value error! "; }

    // 十进制 | 二进制 | char等
    // MDS -- 高位优先 | LDS -- 低位优先
    // dev = base ** exp
    int base = 10, exp = 0, dev = 1;
    while (max_val >= dev) {
        vector<vector<int>> buckets(base);
        for (int i = 0; i < nums.size(); ++i) {
            // 移位取模
            buckets[(nums[i] / dev) % base].push_back(nums[i]);
        }

        int bkt_idx = 0, dst_idx = 0;
        while (bkt_idx < buckets.size() && dst_idx < nums.size()) {
            // 使用std::copy替换？
            int src_idx = 0;
            while (src_idx < buckets[bkt_idx].size() && dst_idx < nums.size()) {
                nums[dst_idx++] = buckets[bkt_idx][src_idx++];
            }
            bkt_idx++;
        }
        show_vector(nums);

        dev *= base;
        exp += 1;
    }
}


void radix_sort_opt(vector<int> &nums) {
    throw "use radix_sort_opt_dev! ";
    if (nums.empty()) {return; }
    show_vector(nums);
    
    int min_val = nums[0], max_val = nums[0];
    for (int i = 0; i < nums.size(); ++i) {
        min_val = nums[i] < min_val ? nums[i] : min_val;
        max_val = nums[i] > max_val ? nums[i] : max_val;
    }
    cout << "min_val " << min_val << " max_val " << max_val << endl;

    // 如果有负数怎么解决？
    if (min_val < 0) {throw "minimum value error! "; }

    // 十进制 | 二进制 | char等
    // MDS -- 高位优先 | LDS -- 低位优先
    // dev = base ** exp
    int base = 10, exp = 0, dev = 1;
    vector<int> temp(nums.size());
    while (max_val >= dev) {
        vector<int> buckets(base, 0);
        for (int i = 0; i < nums.size(); ++i) {
            // 移位取模
            buckets[(nums[i] / dev) % base]++;
        }

        for (int i = 1; i < buckets.size(); ++i) {
            // 分配buckets[i]占temp的起止点
            buckets[i] += buckets[i - 1];
        }

        // 由于nums变得按位有序，只能逆序写入
        for (int i = nums.size() - 1; i >= 0; --i) {
            // 将nums[i]分配到temp中对应的位置
            int tmp_idx = buckets[(nums[i] / dev) % base];
            temp[tmp_idx - 1] = nums[i];
            buckets[(nums[i] / dev) % base]--;
        }

        // copy(temp.begin(), temp.end(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {nums[i] = temp[i]; }
        show_vector(nums);

        dev *= base;
        exp += 1;
    }
}


void radix_sort_opt_dev(vector<int> &nums) {
    // 时间复杂度：O(log(base, log(base, max(max_val, -min_val))) * 4N)
    // 空间复杂度：O(2N)
    if (nums.empty()) {return; }
    // show_vector(nums);
    
    int min_val = nums[0], max_val = nums[0];
    for (int i = 0; i < nums.size(); ++i) {
        min_val = nums[i] < min_val ? nums[i] : min_val;
        max_val = nums[i] > max_val ? nums[i] : max_val;
    }
    // cout << "min_val " << min_val << " max_val " << max_val << endl;

    // 十进制 | 二进制 | char等
    // MDS -- 高位优先 | LDS -- 低位优先
    // dev = base ** exp
    // 使用位运算符判断正负？？？负数移位还是负数？？？
    int base = 10, exp = 0, dev = 1;
    vector<int> temp(nums.size());
    while (max(max_val, -min_val) >= dev) {
        vector<int> pos_buckets(base, 0);
        vector<int> neg_buckets(base, 0);
        for (int i = 0; i < nums.size(); ++i) {
            // 移位取模
            if (nums[i] >= 0) {
                // cout << " i " << i << " val " << nums[i] << " pos " << (nums[i] / dev) % base << endl;
                pos_buckets[(nums[i] / dev) % base]++;
            } else {
                // cout << " i " << i << " val " << nums[i] << " pos " << (-nums[i] / dev) % base << endl;
                neg_buckets[(-nums[i] / dev) % base]++;
            }
        }
        // cout << "pos_buckets" << endl;
        // show_vector(pos_buckets);
        // cout << "neg_buckets" << endl;
        // show_vector(neg_buckets);

        // 对于neg_buckets，需要明确0->9的优先级
        for (int i = neg_buckets.size() - 2; i >= 0; --i) {
            // neg_buckets[i]占temp的起止点
            neg_buckets[i] += neg_buckets[i + 1];
        }
        pos_buckets[0] += neg_buckets[0];
        for (int i = 1; i < pos_buckets.size(); ++i) {
            // 分配pos_buckets[i]占temp的起止点
            pos_buckets[i] += pos_buckets[i - 1];
        }
        // cout << "pos_buckets" << endl;
        // show_vector(pos_buckets);
        // cout << "neg_buckets" << endl;
        // show_vector(neg_buckets);

        // 由于nums变得按位有序，只能逆序查找
        // 比如上一次排序的结果：[[-48, -28, -78], [-47, -27, -77]]
        // 那么这一次排序的结果：[[-78, -77], [-48, -47], [-28, -27]]
        for (int i = nums.size() - 1; i >= 0; --i) {
            // 将nums[i]分配到temp中对应的位置
            int tmp_idx = -1;
            if (nums[i] >= 0) {
                tmp_idx = pos_buckets[(nums[i] / dev) % base];
                pos_buckets[(nums[i] / dev) % base]--;
            } else {
                tmp_idx = neg_buckets[(-nums[i] / dev) % base];
                neg_buckets[(-nums[i] / dev) % base]--;
            }
            // cout << "tmp_idx " << tmp_idx - 1 << endl;
            temp[tmp_idx - 1] = nums[i];
        }

        // copy(temp.begin(), temp.end(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {nums[i] = temp[i]; }
        // show_vector(nums);

        dev *= base;
        exp += 1;
    }
}


// int main() {
//     vector<int> nums = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
//     // radix_sort(nums);
//     radix_sort_opt(nums);

//     return 0;
// }