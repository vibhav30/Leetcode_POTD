class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans(1), inc(1), dec(1);
        int n=nums.size();
        for(int i=1; i<n; i++)
        {
            if(nums[i-1]>nums[i])
            {
               dec++; inc=1;
            }
            else if(nums[i-1]<nums[i])
            {
               inc++; dec=1;
            }
            else 
            {
                inc=1, dec=1;
            }
            ans=max({ans,inc,dec});
        }
        return ans;
    }
};
