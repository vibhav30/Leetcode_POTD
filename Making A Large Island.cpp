class Dsu{
    public :
    vector<int> size,rank,par;
    Dsu(int n){
        size.resize(n+1,1);
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

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        Dsu ds(n*n); int ans=0;
        int row[]={1,0,0,-1};
        int col[]={0,-1,1,0};
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
              int node=i*n+j;
              if(grid[i][j])
              {
                 for(int k=0; k<4; k++)
                 {
                    int nrow=i+row[k];
                    int ncol=j+col[k];
                    int adjNode=nrow*n+ncol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] && ds.findPar(node)!=ds.findPar(adjNode))
                    {
                       ds.unionBySize(adjNode,node);
                    }
                 }
              }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!grid[i][j])
                {
                    set<int> st;
                    int cnt(1);
                    for(int k=0; k<4; k++)
                    {
                        int nrow=i+row[k];
                        int ncol=j+col[k];
                        int adjNode=nrow*n+ncol;
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol])
                        {
                           int par=ds.findPar(adjNode);
                           st.insert(par);
                        }
                    }
                    for(auto it : st)
                    {
                        int sz=ds.size[it];
                        cnt+=(sz);
                    }
                    ans=max(ans,cnt);
                }
            }
        }
        for(int i=0; i<n*n; i++)
        {
            if(ds.findPar(i)==i) ans=max(ans, ds.size[i]);
        }
        return ans;
    }
};
