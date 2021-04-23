class Solution {
    // 求逆序对的个数
    // 模拟二分归并排序
public:
    int merge(vector<int>& nums, int sidx, int eidx, int mid, vector<int> &temp) {
        // [sidx, eidx)
        // 为了保持左半部分和右半部分大小不超过1, mid属于左半部分
        // ???有空请重写这段代码
        int res = 0;
        int lft_max_idx = mid, rht_max_idx = eidx - 1;
        int tmp_max_idx = eidx - 1;
        while (lft_max_idx >= sidx || rht_max_idx >= mid + 1) {
            if (lft_max_idx < sidx) {
                temp[tmp_max_idx--] = nums[rht_max_idx--];
                continue;
            }
            if (rht_max_idx < mid + 1) {
                temp[tmp_max_idx--] = nums[lft_max_idx--];
                continue;
            }
            if (nums[lft_max_idx] > nums[rht_max_idx]) {
                // 归并排序基础上增加的语句
                res += (rht_max_idx - (mid + 1) + 1);
                temp[tmp_max_idx--] = nums[lft_max_idx--];
            } else {
                temp[tmp_max_idx--] = nums[rht_max_idx--];
            }
        }
        for (int i = sidx; i < eidx; ++i) {nums[i] = temp[i]; }

        return res;
    }

    int partion_and_merge(vector<int>& nums, int sidx, int eidx, vector<int> &temp) {
        // [sidx, eidx)
        // 为了保持左半部分和右半部分大小不超过1, mid属于左半部分
        if (eidx - sidx <= 1) {return 0; }

        int lft = sidx, rht = eidx - 1;
        int midx = lft + (rht - lft) / 2;
        int lft_res = partion_and_merge(nums, sidx, midx + 1, temp);
        int rht_res = partion_and_merge(nums, midx + 1, eidx, temp);
        int cur_res = merge(nums, sidx, eidx, midx, temp);

        return lft_res + rht_res + cur_res;
    }

    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums);
        return partion_and_merge(nums, 0, nums.size(), temp);
    }
};