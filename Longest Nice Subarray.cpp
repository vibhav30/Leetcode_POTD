class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n(nums.size()), mask(0), j(0), ans(0);
        for(int i=0; i<n; i++)
        {
            while(mask&nums[i])
            {
               mask^=nums[j]; j++;
            }
            mask+=nums[i];
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};
