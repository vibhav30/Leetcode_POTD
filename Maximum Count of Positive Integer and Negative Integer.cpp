class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int pos1=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        int  pos2=lower_bound(nums.begin(),nums.end(),1)-nums.begin();
        return max(pos1,n-pos2);
    }
};
