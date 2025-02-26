class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
       int n=nums.size();
       int ans=INT_MIN, nMax=0, pMax=0, pre=0;
       for(int i=0; i<n; i++)
       {
         pre+=nums[i];
         if(nums[i]>=0)
         {
            ans=max(ans,abs(pre-nMax));
            pMax=max(pMax,pre);
         }
         else
         {
            ans=max(ans,abs(pre-pMax));
            nMax=min(nMax,pre);
         }
       }
       return ans;
    }
};
