class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL)
            return head;

        ListNode* current = head;

        while(current != NULL && current->next != NULL)
        {
            if(current->val == current->next->val)
            {
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }

        return head;
    }
};