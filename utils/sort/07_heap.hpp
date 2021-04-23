#include <vector>

namespace heap{
    /* 堆
     * 逻辑上是近似完全二叉树; 物理结构是顺序表
     * ???时间复杂度: 建堆, 插入元素, 删除元素
    */
    void push_heap(std::vector<int> &nums, int start, int end);
    void pop_heap(std::vector<int> &nums, int start, int end);
    void sort_heap(std::vector<int> &nums, int start, int end);
    int is_heap(std::vector<int> &nums, int start, int end); 
}

void PushTopKHeap(std::vector<int> &nums, int start, int end, int k, int num); 
