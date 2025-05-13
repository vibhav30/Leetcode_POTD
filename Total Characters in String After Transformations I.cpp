class Solution {
public:
    #define MOD 1000000007
    int lengthAfterTransformations(string s, int t) {
        vector<long long> mp(26, 0);
        for (char ch : s) mp[ch - 'a']++;
        while (t--) 
        {
            vector<long long> temp(26, 0);
            for (int i = 0; i < 26; i++) 
            {
                if (i == 25) 
                {
                    temp[0] = (temp[0] + mp[25]) % MOD;
                    temp[1] = (temp[1] + mp[25]) % MOD;
                } 
                else
                {
                    temp[i + 1] = (temp[i + 1] + mp[i]) % MOD;
                }
            }
            mp = temp;
        }
        long long ans = 0;
        for (int i = 0; i < 26; i++) 
        {
            ans = (ans + mp[i]) % MOD;
        }
        return ans;
    }
};
