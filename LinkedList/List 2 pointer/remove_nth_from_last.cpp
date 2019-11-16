/*
    Problem:
    Remove Nth Node from List End:

    Given a linked list, remove the nth node from the end of list and return its
    head.

    For example,
    Given linked list: 1->2->3->4->5, and n = 2.
    After removing the second node from the end, the linked list becomes
    1->2->3->5.

    Note:
    If n is greater than the size of the list, remove the first node of the
    list. Try doing it using constant additional space.
*/

/*
    Solution:
    Time: O(N)
    Space: O(1)
    Approach:
    First get the lenght of the array in O(N). During this process track a
    second pointer that begins traversal at (len > B+1) which makes the second
    pointer point to one node before the node to be deleted, by the time the
    traversal ends.

    Eg:   Consider 3 -> 5 -> 9 -> 7 and N = 2
          we begin by traversing the list with "first" -> 3 and "second" -> 3
          when we end the while loop and "first" points to null, "second" will
          be pointing to N-2-1 node i.e., "second" -> 5
          
          Then simply delete "second->next" and return.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *Solution::removeNthFromEnd(ListNode *A, int B) {
  if (A == nullptr || B <= 0)
    return A;
  int len = 0;
  ListNode *first = A;
  ListNode *second = A;
  while (first != nullptr) {
    first = first->next;
    len++;
    if (len > B + 1)
      second = second->next;
  }

  if (len <= B)
    return A->next;

  if (second->next != nullptr)
	second->next = second->next->next;

  return A;
}
