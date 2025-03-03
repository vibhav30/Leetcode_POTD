class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int i=0,j=n-1,start=0,end=n-1;
        vector<int> ans(n);
        while(j>=0 || i<n)
        {
           if(i<n && nums[i]<pivot)
           {
             ans[start++]=nums[i];
           }
           if(j>=0 && nums[j]>pivot)
           {
             ans[end--]=nums[j];
           }
           i++; j--;
        }
        while(start<=end) ans[start++]=pivot;
        return ans;
    }
};
