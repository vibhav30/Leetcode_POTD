class Solution {
public:
    int solve(int n)
    {
       int sum=0;
       while(n>0)
       {
        sum+=(n%10);
        n/=10;
       }
       return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int,pair<int,int>> mp;
        for(auto it : nums)
        {
          int sum=solve(it);
          if(mp.find(sum)==mp.end()) mp[sum]={it,0};
          else
          {
            if(mp[sum].first<it)
            {
               mp[sum].second=mp[sum].first;
               mp[sum].first=it;
            }
            else if(mp[sum].second<it) mp[sum].second=it;
          }
        }
        int maxi=-1;
        for(auto it : mp)
        {
            if(it.second.second>0)
            maxi=max(maxi,(it.second.first)+(it.second.second));
        }
        return maxi;
    }
};
