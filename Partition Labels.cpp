class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        int n=s.size(), cnt=0, start=0,end=0;
        for(int i=0; i<n; i++) mp[s[i]]=i;
        vector<int> v;
        for(int i=0; i<n; i++)
        {
            if(mp[s[i]]>end) end=mp[s[i]];
            if(i==end) 
            {
                v.push_back(end-start+1);
                start=i+1; end=i+1;
            }
        }
        return v;
    }
};
