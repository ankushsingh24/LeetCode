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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode *first = head;
        
        while(--k)
        {
            first = first->next;
        }
        
        ListNode *second = head, *back = first;
        
        while(back->next != NULL)
        {
            second = second->next;
            back = back->next;
        }
        
        swap(first->val, second->val);
        
        return head;
    }
};