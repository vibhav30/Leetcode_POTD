class Solution {
public:
    void solve(vector<vector<int>> &adj, map<int, bool> &vis, vector<int> &comp, int src)
    {
       queue<int> q;
       q.push(src);
       while(!q.empty())
       {
        int fr=q.front();
        vis[fr]=true;
        comp.push_back(fr);
        q.pop();
        for(auto it : adj[fr])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it]=true;
            }
        }
       }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        map<int, bool> vis;
        int ans(0);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                vector<int> comp;
                solve(adj, vis, comp, i);
                int nodes=comp.size();
                int cnt(0);
                for(int it : comp)
                {
                    cnt+=adj[it].size();
                }
                cnt/=2;
                if(cnt==(nodes*(nodes-1)/2)) ans++;
            }
        }
        return ans;
    }
};
