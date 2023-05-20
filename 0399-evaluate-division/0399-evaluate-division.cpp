class Solution {
public:
    void dfs(string s, string d, map<string, vector<pair<string, double>>> &m, set<string> v, double &ans, double temp)
    {
        if(v.find(s) != v.end())
            return;
        
        else
        {
            v.insert(s);
            
            if(s == d)
            {
                ans = temp;
                return;
            }
            else
            {
                for(auto a : m[s])
                {
                    dfs(a.first, d, m, v, ans, temp*a.second);
                }
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        map<string, vector<pair<string, double>>> m;
        int e = equations.size();
        int q = queries.size();
        
        for(int i=0 ; i<e ; i++)
        {
            m[equations[i][0]].push_back({equations[i][1], values[i]});
            m[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        
        vector<double> res;
        
        for(int i=0 ; i<q ; i++)
        {
            string s = queries[i][0];
            string d = queries[i][1];
            
            set<string> visited;
            
            double ans = -1.0;
            
            if(m.find(s) != m.end())
                dfs(s, d, m, visited, ans, 1.0);
            res.push_back(ans);
        }
        
        return res;
    }
};