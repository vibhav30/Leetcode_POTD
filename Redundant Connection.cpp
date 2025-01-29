class Dsu{
    public :
    vector<int> size,rank,par;
    Dsu(int n){
        size.resize(n+1);
        rank.resize(n+1,0);
        par.resize(n+1);
        for(int i=0; i<=n; i++) par[i]=i;
    }
    
    int findPar(int x) {
        if(x==par[x]) return x;
        return par[x]=findPar(par[x]);
    }
    
    void unionByRank(int u, int v) {
        int upu=findPar(u);
        int upv=findPar(v);
        if(upu==upv) return;
        if(rank[upu]<rank[upv]){
            par[upu]=upv;
        }
        else if(rank[upv]<rank[upu]){
            par[upv]=upu;
        }
        else{
            par[upv]=upu;
            rank[upu]++;
        }
    }

    void unionBySize(int u, int v) {
        int upu=findPar(u);
        int upv=findPar(v);
        if(upu==upv) return;
        if(size[upu]<size[upv]){
            par[upu]=upv;
            size[upv]+=size[upu];
        }
        else{
            par[upv]=upu;
            size[upu]+=size[upv];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        Dsu ds(n+1);
        int u1,v1;
        for(auto it : edges)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findPar(u)!=ds.findPar(v))
            {
                ds.unionBySize(u,v);
            }
            else
            {
              u1=u; v1=v;
            }
        }
        return {u1,v1};
    }
};
