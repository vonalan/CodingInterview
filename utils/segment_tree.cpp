#include <vector>
#include <iostream>

using namespace std;


class SegmentTree {
    /* 线段树
     * 类似于堆: 物理结构数组; 逻辑结构近似完全二叉树
     */
public:
    SegmentTree(): left(nullptr), right(nullptr), sidx(-1), eidx(-1) {};
    ~SegmentTree() {
        if (left != nullptr) {delete left; }
        if (right != nullptr) {delete right; }
        // cout << " destructing SegmentTree... sidx " << sidx << " eidx " << eidx << " sum " << sum << endl;
    }

    void build(int s, int e, vector<int> &nums) {
        // 构建区间[s, e)的线段树
        if (s >= e) {
            cout << "range error! s >= e" << endl;
            throw "range error! s >= e";
        }
        sidx = s; eidx = e;

        if (s + 1 == e) {
            // [s, e)区间只有1个值时, sum即该值
            sum = nums[s];
        } else {
            int m = s + (e - s) / 2;
            left = new SegmentTree(); left->build(s, m, nums);
            right = new SegmentTree(); right->build(m, e, nums);
            sum = left->sum + right->sum;
        }
        // cout << " building SegmentTree... sidx " << s << " eidx " << e << " sum " << sum << endl;
    }

    int query(int s, int e) {
        if (s <= sidx && e >= eidx) {
            return sum;
        }
        if (left == nullptr || right == nullptr) {return 0; }

        int res = 0;
        if (s < left->eidx) {
            res += left->query(s, e);
        }
        if (e > right->sidx) {
            res += right->query(s, e);
        }
        return res;
    }

    void pull_up() {
        if (left == nullptr || right == nullptr) {return; }
        sum = left->sum + right->sum;
    }

    void modify(int s, int e, int t) {
        // if (left == nullptr || right == nullptr) {return; }
        if (s <= sidx && e >= eidx) {
            // [s, e)区间只有1个值时, sum即该值
            sum = t;
        }
        else {
            // push_down();
            if (s < left->eidx) {
                left->modify(s, e, t);
            }
            if (e > right->sidx) {
                right->modify(s, e, t);
            }
            pull_up();
        }
    }

    void update();
    void push_down();
private:
    // 线段树的基本状态
    SegmentTree *left;
    SegmentTree *right;
    int sidx;
    int eidx;

    // 自定义的额外状态
    int sum;
};


class NumArray {
    // 303. 区域和检索 - 数组不可变, https://leetcode-cn.com/problems/range-sum-query-immutable
    // 304. 二维区域和检索 - 矩阵不可变, https://leetcode-cn.com/problems/range-sum-query-2d-immutable
public:
    NumArray(vector<int>& nums) {
        size = nums.size();
        st.build(0, size, nums);
    }

    void update(int index, int val) {
        st.modify(index, index + 1, val);
    }

    int sumRange(int left, int right) {
        return st.query(left, right + 1);
    }
private:
    SegmentTree st;
    int size;
};


int main() {
    vector<int> nums = {1, 3, 5};
    NumArray na(nums);
    cout << na.sumRange(0, 2) << endl;
    na.update(1, 2);
    cout << na.sumRange(0, 2) << endl;

    return 0;
}
