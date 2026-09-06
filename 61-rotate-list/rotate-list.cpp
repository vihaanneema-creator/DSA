/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        // 1. Calculate length and find the existing tail
        int length = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        // 2. Reduce k
        k = k % length;
        if (k == 0) {
            return head;
        }

        // 3. Connect tail to head to form a circular ring
        tail->next = head;

        // 4. Find the new tail: (length - k) steps from head
        int stepsToNewTail = length - k;
        ListNode* newTail = tail; // starting from tail takes us to step (length - k)
        while (stepsToNewTail > 0) {
            newTail = newTail->next;
            stepsToNewTail--;
        }

        // 5. Break the ring and set the new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};