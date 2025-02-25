class Solution {
public:
    int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size(), even=1, odd=0, pre=0, ans=0;
        for(int i=0; i<n; i++)
        {
            pre+=arr[i];
            if(pre&1)
            {
              ans=(ans+even)%mod;
              odd++;
            }
            else
            {
               ans=(ans+odd)%mod;
               even++;
            }
        }
        return ans;
    }
};
