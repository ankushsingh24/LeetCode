class Solution {
public:
    double average(vector<int>& salary) 
    {
        int n = salary.size();
        
        sort(salary.begin(), salary.end());
        
        return (double)(accumulate(salary.begin(), salary.end(), 0) - salary[0] - salary[n-1]) / (n-2);
    }
};