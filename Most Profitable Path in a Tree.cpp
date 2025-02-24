class Solution {
public:
    vector<vector<int>> adj;
    vector<int> dBob;
    int sBob;
    void dfs(int node, int par, int d, vector<int>& amount, int& ans)
    {
       int total=0;
       if(node==sBob) dBob[node]=0;
       else dBob[node]=1e5;
       int maxi=INT_MIN;
       for(auto it : adj[node])
       {
        if(it==par) continue;
        dfs(it,node,d+1,amount,maxi);
        dBob[node]=min(dBob[node],dBob[it]+1);
       }
       if(dBob[node]>d) total=amount[node];
       else if(dBob[node]==d) total=amount[node]/2;
       ans=max(ans,(maxi==INT_MIN?total:total+maxi));
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        adj.resize(n);
        dBob.resize(n);
        sBob=bob;
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=INT_MIN;
        dfs(0,-1,0,amount,ans);
        return ans;
    }
};
