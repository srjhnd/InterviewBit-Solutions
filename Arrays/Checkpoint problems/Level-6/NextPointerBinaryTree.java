/* 
Problem statement: 
    Given a binary tree, determine if it is a valid binary search tree (BST).

    Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

    Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

    Initially, all next pointers are set to NULL.

    Note:
    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
    Example :

    Given the following perfect binary tree,

         1
       /  \
      2    5
     / \  / \
    3  4  6  7

    After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 5 -> NULL
     / \  / \
    3->4->6->7 -> NULL

    Note that using recursion has memory overhead and does not qualify for constant space.

Solution:
    O(N): time
    O(N): space
*/



/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        if (root == null || (root.left == null && root.right == null))
            return root;
        
        LinkedList<TreeLinkNode> list = new LinkedList<>();
        list.add(root);
        
        while (list.size() > 0) {
            int lvl_size = list.size()
            TreeLinkNode prev = null;
            while (lvl_size > 0) {
                if (prev != null) {
                    prev.next = list.pollFirst();
                    prev = prev.next;
                } else {
                    prev = list.pollFirst();
                }
                if (prev.left != null) list.addLast(prev.left);
                if (prev.right != null) list.addLast(prev.right);
                lvl_size--;
            }
        }
    }
}
