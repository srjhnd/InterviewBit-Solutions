/* 
Problem statement: 
    Given a singly linked list, modify the value of first half nodes such that :

    1st node’s new value = the last node’s value - first node’s current value
    2nd node’s new value = the second last node’s value - 2nd node’s current value,
    and so on …

    NOTE :
    If the length L of linked list is odd, then the first half implies at first floor(L/2) nodes. So, if L = 5, the first half refers to first 2 nodes.
    If the length L of linked list is even, then the first half implies at first L/2 nodes. So, if L = 4, the first half refers to first 2 nodes.
    Example :

    Given linked list 1 -> 2 -> 3 -> 4 -> 5,

    You should return 4 -> 2 -> 3 -> 4 -> 5
    as

    for first node, 5 - 1 = 4
    for second node, 4 - 2 = 2
    Try to solve the problem using constant extra space.


Solution:
    O(N): time
    O(N/2): space
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::subtract(ListNode* A) {
    int i = 0;
    int len = 0;
    ListNode* trav = A;
    stack<int> stk;
    
    while (trav != nullptr) {
        len++;
        trav = trav->next;
    }
    
    trav = A;
    
    while (i < len/2) {
        trav = trav->next;
        i++;
    }

    if (len % 2 != 0)
        trav = trav->next;
        
    // pushing the second half into stack
    while (trav != nullptr) {
        stk.push(trav->val);
        trav = trav->next;
    }
    
    trav = A; // reset pointer
    i = 0;
    
    while (!stk.empty() && trav != nullptr) {
        trav->val = stk.top() - trav->val;
        trav = trav->next;
        stk.pop();
    }
    return A;
}
