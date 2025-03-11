class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int n=s.length(), ans=0, i=0;
        for(int j=0; j<n; j++)
        {
            mp[s[j]]++;
            while(mp['a'] && mp['b'] && mp['c'])
            {
               ans+=(n-j);
               mp[s[i++]]--;
            }
        }
        return ans;
    }
};
