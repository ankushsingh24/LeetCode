class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int tor = nums[0];
        int hare = nums[0];
        
        // intersection
        do 
        {
            tor = nums[tor];
            hare = nums[nums[hare]];
        }while(tor != hare);
        
        // entrance of intersection
        tor = nums[0];
        while(tor != hare)
        {
            tor = nums[tor];
            hare = nums[hare];
        }
        
        return hare;
    }
};