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
    bool isPalindrome(ListNode* head) 
    {
        stack<int> end;
        queue<int> start;
        ListNode *p = head;
        
        while(p != NULL)
        {
            end.push(p->val);
            start.push(p->val);
            p = p->next;
        }
        
        while(!end.empty() && !start.empty())
        {
            if(end.top() != start.front())
                return false;
            end.pop();
            start.pop();
        }
        
        return true;
    }
};