class Solution {
public:
    bool count(vector<int> &buildings)
    {
        for(auto b : buildings)
        {
            if(b != 0)
                return false;
        }
        return true;
    }
    
    void calPosReq(int n, int &posReq, int reqCount, vector<vector<int>>& requests, vector<int> buildings)
    {
        if(count(buildings))
            posReq = max(posReq, reqCount);
        
        if(n == requests.size())
            return;
        
        int buildLeave = requests[n][0], buildEnter = requests[n][1];
        
        buildings[buildLeave]--;
        buildings[buildEnter]++;
        
        calPosReq(n+1, posReq, reqCount+1, requests, buildings);
        
        buildings[buildLeave]++;
        buildings[buildEnter]--;
        
        calPosReq(n+1, posReq, reqCount, requests, buildings);
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) 
    {
        int posReq = 0;
        vector<int> buildings(n, 0);
        calPosReq(0, posReq, 0, requests, buildings);
        return posReq;
    }
};