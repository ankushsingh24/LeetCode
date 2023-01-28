class SummaryRanges {
public:
    set<int> values;
    
    SummaryRanges() {}
    
    void addNum(int value) 
    {
        values.insert(value);    
    }
    
    vector<vector<int>> getIntervals() 
    {
        vector<vector<int>> ans;
        int left = -1, right = -1;
        
        for(auto value: values)
        {
            if(left < 0 && right < 0)
                left = right = value;
            
            else if(value == right + 1)
                right = value;
            
            else
            {
                ans.push_back({left, right});
                left = right = value;
            }
        }
        
        ans.push_back({left, right});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */