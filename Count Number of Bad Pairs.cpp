class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long cnt=0; int n=nums.size();
        for(int i=0; i<n; i++)
        {
            int x=nums[i]-i;
            cnt+=mp[x];    
            mp[x]++;
        }
        long long totPairs=(1ll*n*(n-1))/2;
        return totPairs-cnt;
    }
};
