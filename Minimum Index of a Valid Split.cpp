class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size(), cand=nums[0], cnt=0, totCnt=0;
        for(int num : nums)
        {
            if(num==cand) cnt++;
            else cnt--;
            if(cnt==0)
            {
                cand=num; cnt=1;
            }
        }
        for(int num : nums) if(num==cand) totCnt++;
        int preCnt=0;
        for(int i=0; i<n; i++)
        {
          if(nums[i]==cand) preCnt++;
          if(((i+1)<2*preCnt) && ((n-i-1)<2*(totCnt-preCnt)))
          return i;
        }
        return -1;
    }
};
