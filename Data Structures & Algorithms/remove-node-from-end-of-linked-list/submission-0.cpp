class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int stepsToTake = length - n;
        current = dummy;

        for (int i = 0; i < stepsToTake; i++) {
            current = current->next;
        }
        
        ListNode* nodeToDelete = current->next;
        current->next = current->next->next;
        delete nodeToDelete;
        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};