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
    int pairSum(ListNode* head) 
    {
        vector<int> val;
        ListNode *cur = head;
        
        while(cur)
        {
            val.push_back(cur->val);
            cur = cur->next;
        }
        
        int i = 0, j = val.size() - 1;
        int maxi = 0;
        
        while(i < j)
        {
            maxi = max(maxi, val[i] + val[j]);
            i++;
            j--;
        }
        
        return maxi;
    }
};