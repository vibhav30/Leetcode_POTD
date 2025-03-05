class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1;
        ans+=2LL*n*(n-1); 
        return ans;
    }
};
