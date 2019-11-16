/*
    Problem:
    Remove Duplicates from Sorted List
    Given a sorted linked list, delete all duplicates such that each element appear only once.

    For example,
    Given 1->1->2, return 1->2.
    Given 1->1->2->3->3, return 1->2->3.
*/

/* 
    Solution:
    Time: O(N)
    Space: O(1)

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::deleteDuplicates(ListNode* A) {
    if (A == nullptr || A->next == nullptr)
        return A;
    ListNode* a = A;
    ListNode* b = A->next;
    
    while (a->next != nullptr && b != nullptr) {
        if(a->val != b->val) {
            a = a->next;
            b = b->next;
            continue;
        }

        while (b->next != nullptr && a->val == b->val)
            b = b->next;

        if (b->next != nullptr) {
            a->next = b;
            b = b->next;
            a = a->next;
        } else
            a->next = nullptr;
    }
    return A;
}
