class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it : roads)
        {
          adj[it[0]].push_back({it[1], it[2]});
          adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<int> path(n,0);
        vector<long long> dist(n, LLONG_MAX);
        pq.push({0,0});
        dist[0]=0;
        path[0]=1;
        int mod=(int)(1e9+7);
        while(!pq.empty())
        {
            auto fr=pq.top();
            pq.pop();
            long long d=fr.first;
            int node=fr.second;
            if(d>dist[node]) continue;
            for(auto it : adj[node])
            {
              int v=it.first;
              int wt=it.second;
              if(dist[node]+wt<dist[v])
              {
                dist[v]=dist[node]+wt;
                path[v]=path[node];
                pq.push({dist[v],v});
              }
              else if(dist[node]+wt==dist[v])
              {
                path[v]=(path[v]+path[node])%mod;
              }
            }
        }
        return path[n-1]%mod;
    }
};
