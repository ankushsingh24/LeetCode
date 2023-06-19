class Solution {
public:
    void setPerm(vector<int> &v, string &ans, int n, int k, vector<int> &fac)
    {
        if(n == 1)
        {
            ans += to_string(v.back());
            return;
        }
        
        // We are calculating the required index.  factVal[n-1] means for n =  4 => factVal[3] = 6.
        // 15 / 6 = 2 will the index for k =15 and n = 4.
        int idx = (k / fac[n-1]);
        
        // if k is a multiple of elements of partition then decrement the index (Corner case I was talking               // about)
        if(k % fac[n-1] == 0)
            idx--;
        
        ans+= to_string(v[idx]);  // add value to string
        v.erase(v.begin() + idx);  // remove element from array
        k -= fac[n-1] * idx;   // adjust value of k; k = 15 - 6*2 = 3.
		// Recursive call with n=n-1 as one element is added we need remaing.
        
        setPerm(v, ans, n-1, k, fac);
    }
    
    string getPermutation(int n, int k) 
    {
        if(n == 1)
            return "1";
        
        vector<int> fac = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        string ans = "";
        vector<int> v;
        
        for(int i=1 ; i<=n ; i++)
            v.emplace_back(i);
        
        setPerm(v, ans, n, k, fac);
        return ans;
    }
};