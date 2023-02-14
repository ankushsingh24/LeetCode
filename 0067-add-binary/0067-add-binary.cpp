class Solution {
public:
    string addBinary(string a, string b) 
    {
        string result;
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        while(i >= 0 || j >= 0)
        {
            int a_bit = i >= 0 ? a[i--] - '0' : 0;
            int b_bit = j >= 0 ? b[j--] - '0': 0;
            
            int sum = a_bit + b_bit + carry;
            result.insert(result.begin(), sum % 2 + '0');
            carry = sum / 2;
        }
        
        if(carry == 1)
            result.insert(result.begin(), 1 + '0');
        
        return result;
    }
};