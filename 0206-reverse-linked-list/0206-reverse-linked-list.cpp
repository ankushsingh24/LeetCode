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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *first = NULL, *second = NULL;
                
        while(head != NULL)
        {
            first = second;
            second = head;
            head = head->next;
            
            second->next = first;
        }
        
        head = second;
        
        return head;
    }
};