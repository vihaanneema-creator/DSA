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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupTail = &dummy;

        int groupSize = 1;

        while (prevGroupTail->next) {
            // 1. Count actual nodes available in this group (up to groupSize)
            int count = 0;
            ListNode* curr = prevGroupTail->next;
            while (curr && count < groupSize) {
                curr = curr->next;
                count++;
            }

            // 2. Decide action based on actual count
            if (count % 2 == 0) {
                // Even length: reverse this group
                ListNode* groupHead = prevGroupTail->next;
                ListNode* nextGroupHead = curr; // curr is at the start of the next group

                ListNode* prev = nextGroupHead;
                ListNode* node = groupHead;

                while (node != nextGroupHead) {
                    ListNode* temp = node->next;
                    node->next = prev;
                    prev = node;
                    node = temp;
                }

                // Connect previous group tail to the new head of reversed group (prev)
                prevGroupTail->next = prev;

                // Move prevGroupTail to the end of this group (which is groupHead)
                prevGroupTail = groupHead;
            } else {
                // Odd length: do not reverse, simply skip forward
                for (int i = 0; i < count; i++) {
                    prevGroupTail = prevGroupTail->next;
                }
            }

            // Increment expected size for next group
            groupSize++;
        }

        return dummy.next;
    }
};