class Solution {
public:
    int bfs(vector<vector<int>>&adj,int src, int n)
    {
        vector<int> dist(n+1,-1);
        queue<int> q;
        q.push(src);
        dist[src]=1;
        int maxi=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it : adj[node])
            {
                if(dist[it]==-1)
                {
                    dist[it]=dist[node]+1;
                    q.push(it);
                    maxi=max(maxi,dist[it]);
                }
            }
        }
        return maxi;
    }

    void dfs(vector<vector<int>>&adj,vector<int>&col,vector<int>&conn,bool &isBipartite,int src,int color)
    {
      col[src]=color;
      conn.push_back(src);
      for(auto it : adj[src])
      {
        if(!col[it])
        {
           dfs(adj,col,conn,isBipartite,it,3-color);
        }
        else if(col[it]==col[src]) isBipartite=false;
      }
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> col(n+1,0);
        vector<vector<int>> adj(n+1);
        bool isBipartite;
        vector<int> conn;
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(!col[i])
            {
                conn.clear();
                isBipartite=true;
                dfs(adj,col,conn,isBipartite,i,1);
                if(!isBipartite) return -1;
                int maxi=0;
                for(auto it : conn)
                {
                    maxi=max(maxi,bfs(adj,it,n));
                }
                ans+=maxi;
            }
        }
        return ans;
    }
};
