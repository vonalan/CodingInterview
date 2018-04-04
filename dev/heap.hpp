#include <vector>

namespace heap{
    void push_heap(std::vector<int> &nums, int start, int end);
    void pop_heap(std::vector<int> &nums, int start, int end);
    void sort_heap(std::vector<int> &nums, int start, int end);
    int is_heap(std::vector<int> &nums, int start, int end); 
}

void PushTopKHeap(std::vector<int> &nums, int start, int end, int k, int num); 
