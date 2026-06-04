/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* left_connection = dummy;
        for (int i = 1; i < left; i++) {
            left_connection = left_connection->next;
        }
        
        ListNode* sub_list_head = left_connection->next;
        
        ListNode* prev = nullptr;
        ListNode* curr = sub_list_head;
        for (int i = 0; i <= right - left; i++) {
            ListNode* next_node = curr->next; 
            curr->next = prev;          
            prev = curr;     
            curr = next_node;
        }
        
        left_connection->next = prev; 
        sub_list_head->next = curr;
        
        ListNode* new_head = dummy->next;
        delete dummy; // Clean up memory
        return new_head;
    }
};