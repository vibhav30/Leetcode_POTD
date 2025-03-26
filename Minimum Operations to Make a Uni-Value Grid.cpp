class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size(), n=grid[0].size();
        vector<int> v;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
               if((grid[0][0]%x)==(grid[i][j]%x)) v.push_back(grid[i][j]);
               else return -1;
            }
        }
        sort(v.begin(),v.end());
        int mid=((m*n)/2), cnt=0;
        for(int i=0; i<m*n; i++)
        {
            cnt+=(abs(v[i]-v[mid])/x);
        }
        return cnt;
    }
};
