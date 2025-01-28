class Solution {
public:
    int bfs(vector<vector<int>>& grid,  vector<vector<int>>& vis, int i, int j)
    {
      int m=grid.size();
      int n=grid[0].size();
      vis[i][j]=1;
      queue<pair<int,int>> q;
      q.push({i,j});
      int row[]={1,0,0,-1};
      int col[]={0,1,-1,0};
      int sum(grid[i][j]);
      while(!q.empty())
      {
        int sr=q.front().first;
        int sc=q.front().second;
        q.pop();
        for(int k=0; k<4; k++)
        {
          int nrow=sr+row[k];
          int ncol=sc+col[k];
          if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol])
          {
            sum+=grid[nrow][ncol];
            vis[nrow][ncol]=1;
            q.push({nrow,ncol});
          }
        }
      }
      return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        int ans=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
               if(grid[i][j] && !vis[i][j]) ans=max(ans,bfs(grid,vis,i,j));
            }
        }
        return ans;
    }
};
