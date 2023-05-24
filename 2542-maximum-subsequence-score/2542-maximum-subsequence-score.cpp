class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<pair<int, int>> v;
        int n = nums1.size();
        
        for(int i=0 ; i<n ; i++)
            v.push_back({nums1[i], nums2[i]});
        
        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {return a.second > b.second;});
        
        priority_queue<int, vector<int>, greater<int>> pq;
        long long score = 0;
        for(int i=0 ; i<k ; i++)
        {
            score += (long long)v[i].first;
            pq.push(v[i].first);
        }
        
        long long ans = score * v[k-1].second;
        for(int i=k ; i<n ; i++)
        {
            score += (v[i].first - pq.top());
            pq.pop();
            pq.push(v[i].first);
            ans = max(ans, score * v[i].second);
        }
        
        return ans;
    }
};