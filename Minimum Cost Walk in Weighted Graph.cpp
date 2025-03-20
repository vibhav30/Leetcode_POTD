class Solution {
public:
    unordered_map<int,int> mp;
    void bfs(vector<vector<pair<int,int>>> &adj,  vector<int> &v, int cmp){
       queue<pair<int,int>> q;
       q.push({cmp,INT_MAX});
       int And=INT_MAX;
       while(!q.empty()){
        auto src = q.front();
        q.pop();
        v[src.first]=cmp;
        And&=(src.second);
        for(auto it : adj[src.first]){
            if(v[it.first]==-1){
                q.push(it);
            }
        }
       }
       mp[cmp]=And;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> v(n,-1);
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges){
          adj[it[0]].push_back({it[1], it[2]});
          adj[it[1]].push_back({it[0], it[2]});
        }
        for(int i=0; i<n; i++){
            if(v[i]==-1) bfs(adj,v,i);
        }
        vector<int> ans;
        for(auto it : query){
            if(v[it[0]]==v[it[1]]){
                ans.push_back(mp[v[it[0]]]);
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};
