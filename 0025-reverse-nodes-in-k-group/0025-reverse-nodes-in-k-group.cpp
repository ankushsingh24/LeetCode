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
    int lengthOfLL(ListNode *head)
    {
        int cnt = 0;
        ListNode *p = head;
        
        while(p != NULL)
        {
            p = p->next;
            cnt++;
        }
        
        return cnt;
    }
    
    ListNode* helper(ListNode* head, int k, int len)
    {
        if(len < k)
            return head;
        
        int cnt = 0;
        ListNode *prev = NULL, *nex = NULL, *curr = head;
        
        while(cnt < k && curr != NULL)
        {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            cnt++;
        }
        
        if(nex != NULL)
            head->next = helper(nex, k, len - k);
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k)  
    {
        int len = lengthOfLL(head);
        return helper(head, k, len);
    }
};