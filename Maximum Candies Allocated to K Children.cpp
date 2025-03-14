class Solution {
public:
    bool solve(vector<int>& candies, long long k, int x)
    {
       long long cnt=0;
       for(int it : candies) cnt+=(it/x);
       return cnt>=k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size(), ans=0;
        int l=1, r=*max_element(candies.begin(),candies.end());
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(solve(candies,k,mid))
            {
              l=mid+1; ans=mid; 
            }
            else r=mid-1;
        }
        return ans;
    }
};
