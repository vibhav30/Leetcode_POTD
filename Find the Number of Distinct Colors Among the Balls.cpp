class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> v;
        unordered_map<int,int> mp;
        vector<int> ans;
        int cnt=0;
        for(auto it : queries)
        {
            if(v.count(it[0]))
            {
                mp[v[it[0]]]--;
                if(mp[v[it[0]]]==0) cnt--;
            }
            v[it[0]]=it[1];
            mp[it[1]]++;
            if(mp[it[1]]==1) cnt++;
            ans.push_back(cnt);
        }
      return ans;
    }
};
