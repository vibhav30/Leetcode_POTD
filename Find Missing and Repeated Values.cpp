class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size(); int sum=0, x=-1;
        int totSum=((n*n)*((n*n)+1))/2;
        vector<int> cnt((n*n)+1,0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) 
            {
                sum+=grid[i][j];
                if(cnt[grid[i][j]]) x=grid[i][j];
                cnt[grid[i][j]]++;
            }
        }
        sum-=x; totSum-=sum;
        return {x,totSum};
    }
};
