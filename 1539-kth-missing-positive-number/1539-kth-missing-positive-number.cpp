class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int l = 0;
        int h = arr.size() - 1;
        
        while(l <= h)
        {
            int mid = (l + h) / 2;
            
            if(arr[mid] - (1 + mid) < k) // //A[m]-(m+1)   --> This gives number of missing number before m'th index
                l = mid + 1;
            else
                h = mid - 1;
        }
        
        return l + k;
    }
};