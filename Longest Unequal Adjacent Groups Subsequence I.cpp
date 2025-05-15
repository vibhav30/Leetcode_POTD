class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=groups.size();
        vector<string> v;
        for(int i=0; i<n-1; i++)
        {
            if(groups[i]^groups[i+1]) v.push_back(words[i]);
        }
        v.push_back(words[n-1]);
        return v;
    }
};
