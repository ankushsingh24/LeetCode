class Solution {
public:
    
    bool checkOrder(string &a, string &b, unordered_map<char, int> hash)
    {
        int i = 0;
        while(i < a.size() && i < b.size())
        {
            if(hash[a[i] - 'a'] != hash[b[i] - 'a'])
                return hash[a[i] - 'a'] < hash[b[i] - 'a'];
            i++;
        }
        
        return a.size() <= b.size();
    }
    
    bool isAlienSorted(vector<string>& words, string order) 
    {           
        unordered_map<char, int> hash;

        for(int i=0 ; i<order.size() ; i++)
            hash[order[i] - 'a'] = i;
        
        for(int i=0 ; i<words.size()-1 ; i++)
            if(!checkOrder(words[i], words[i+1], hash))
                return false;
        
        return true;
    }
};