class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        int n = answerKey.size();
        int ans = 0, T = 0, F = 0, j = 0;
        
        for(int i=0 ; i<n ; i++)
        {
            if(answerKey[i] == 'T')
                T++;
            else
                F++;
            
            if(min(T, F) > k)
            {
                if(answerKey[j] == 'T')
                    T--;
                else
                    F--;
                
                j++;
            }
            
            ans = max(ans, T + F);
        }
        
        return ans;
    }
};