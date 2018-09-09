#include <iostream> 

/*
 * Tree
 * BFS, DFS, ...
 * inorder, preorder, postorder, ...
 */
 
struct TreeNode {
    int val; 
    TreeNode *left; 
    TreeNode *right; 
    
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
}
