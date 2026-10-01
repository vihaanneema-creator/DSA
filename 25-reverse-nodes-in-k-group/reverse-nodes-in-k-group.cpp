
class Solution {
public:
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        // 1. Stack-allocated dummy node (no pointer asterisk here)
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupprev = &dummy;

        while (true) {
            // 2. Proper function call without type signature or extra braces
            ListNode* kth = getKthNode(groupprev, k);
            if (!kth) break;

            ListNode* groupnext = kth->next;

            ListNode* prev = groupnext;
            ListNode* curr = groupprev->next; 

            while (curr != groupnext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // 3. Connect previous group to the new head of this group
            ListNode* newGroupTail = groupprev->next; 
            groupprev->next = kth;

            // 4. Advance groupprev for the next iteration
            groupprev = newGroupTail;
        }

        return dummy.next;
    }
};