class Solution {
public:
    int maxVowels(string s, int k) 
    {
        int cur = 0;
        int ans = 0;
        
        bool vowels[26] = {false};
        
        vowels['a' - 'a'] = true;
        vowels['e' - 'a'] = true;
        vowels['i' - 'a'] = true;
        vowels['o' - 'a'] = true;
        vowels['u' - 'a'] = true;
        
        for(int i=0 ; i<s.size() ; i++)
        {
            if(i >= k && vowels[s[i-k] - 'a'])  // if any vowel is removed from left-> decrement
                cur -= 1;
            
            if(vowels[s[i] - 'a'])  // if any vowel is inserted from right-> increment
                cur += 1;
            
            ans = max(ans, cur);
        }
        
        return ans;
    }
};