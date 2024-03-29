/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *slow = head, *fast = head;
        
        if(!head)
            return 0;
        if(!head->next)
            return 0;
        
        else
        {
            while(fast->next && fast->next->next)
            {
                slow = slow->next;
                fast = fast->next->next;
                
                if(slow == fast)
                {
                    fast = head;
                    while(slow != fast)
                    {
                        slow = slow->next;
                        fast = fast->next;
                    }
                    return slow;
                }
            }
            return 0;
        }
    }
};