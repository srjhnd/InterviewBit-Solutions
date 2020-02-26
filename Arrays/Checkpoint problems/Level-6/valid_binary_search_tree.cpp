/* 
Problem statement: 
    Given a binary tree, determine if it is a valid binary search tree (BST).

    Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node’s key.
    The right subtree of a node contains only nodes with keys greater than the node’s key.
    Both the left and right subtrees must also be binary search trees.
    Example :

    Input : 
        1
      /  \
    2    3

    Output : 0 or False

    Input : 
       2
      / \
     1   3

    Output : 1 or True 
    Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Solution:
    O(N): time
    O(N): space
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void getVals(TreeNode* root, vector<int>& vals) {
    if (root == nullptr)
        return;
    getVals(root->left, vals);    
    vals.push_back(root->val);
    getVals(root->right, vals);
}
 
int Solution::isValidBST(TreeNode* A) {
    vector<int> vals;
    getVals(A, vals);
 
    // for (int i : vals)
    //     cout << " " << i;
    // cout << endl;
    for (int i = 1; i < vals.size(); i++) {
        if (vals[i] <= vals[i-1]) {
            return 0;
        }
    }
 
    return 1;
}