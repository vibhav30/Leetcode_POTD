class Solution {
public:
    typedef pair<int,pair<int,int>> ppi;
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
         int m=grid.size(), n=grid[0].size(), k=queries.size(), cnt=0;
         vector<vector<int>> vis(m, vector<int>(n,0));
         vector<int> ans(k);
         vector<pair<int,int>> qs;
         for(int i=0; i<k; i++) qs.push_back({queries[i],i});
         sort(qs.begin(), qs.end());
         priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
         pq.push({grid[0][0],{0,0}});
         vis[0][0]=1;
         int row[]={1,0,0,-1};
         int col[]={0,1,-1,0};
         for(auto &[q,idx] : qs)
         {
            while(!pq.empty() && pq.top().first<q)
            {
               auto [val, pos]=pq.top(); pq.pop();
               cnt++;  int r=pos.first; int c=pos.second;
               for(int i=0; i<4; i++)
               {
                    int nrow=r+row[i];
                    int ncol=c+col[i];
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol])
                    {
                        pq.push({grid[nrow][ncol],{nrow, ncol}});
                        vis[nrow][ncol]=1;
                    }
               }
            }
            ans[idx]=cnt;
         }
         return ans;
    }
};
