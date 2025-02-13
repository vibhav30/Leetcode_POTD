class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(auto it : nums) pq.push(it);
        int cnt=0;
        while(!pq.empty())
        {
            long long x=pq.top();
            pq.pop();
            if(x>=k) break;
            long long y=-1;
            if(!pq.empty())
            {
               y=pq.top();
               pq.pop();
            }
            if(y==-1) break;
            cnt++;
            pq.push(min(x,y)*2+max(x,y));
        }
        return cnt;
    }
};
