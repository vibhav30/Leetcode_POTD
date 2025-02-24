class Solution {
public:
    vector<vector<int>> adj;
    vector<int>parent,depth;

    void dfs(int node, int par, int d)
    {
       depth[node]=d;
       parent[node]=par;
       for(auto it : adj[node])
       {
        if(it!=par) dfs(it,node,d+1);
       }
    }
 
    int dfs2(int node, int par, vector<int>& amount)
    {
       int total=amount[node],ans=INT_MIN;
       for(auto it : adj[node])
       {
        if(it!=par) ans=max(ans,dfs2(it,node,amount));
       }
       return ans==INT_MIN?total:total+ans;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        adj.resize(n);
        parent.resize(n);
        depth.resize(n);
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,-1,0);
        int curr=bob,bobDepth=0;
        while(curr!=-1)
        {
           if(depth[curr]>bobDepth) amount[curr]=0;
           else if(depth[curr]==bobDepth) amount[curr]/=2;
           curr=parent[curr];
           bobDepth++;
        }
        return dfs2(0,-1,amount);
    }
};
