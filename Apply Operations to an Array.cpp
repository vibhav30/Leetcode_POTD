class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=1; i<n; i++)
        {
            if(nums[i-1]==nums[i])
            {
                nums[i-1]*=2;
                nums[i]=0;
            }
        }
        vector<int> ans(n,0);
        int j=0;
        for(int i=0; i<n; i++)
        {
           if(nums[i]!=0) 
           {
             ans[j]=nums[i]; j++;
           }
        }
        return ans;
    }
};
