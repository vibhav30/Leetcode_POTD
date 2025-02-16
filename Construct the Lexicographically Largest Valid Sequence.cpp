class Solution {
public:
    bool solve(vector<int>&seq,vector<bool>&used,int idx,int n)
    {
      if(idx==seq.size()) return true;
      if(seq[idx]!=0) return solve(seq,used,idx+1,n);
      for(int i=n;i>=1;i--)
      {
        int nxtIdx=(i==1)?idx:idx+i;
        if(used[i]||(i>1&&(nxtIdx>=seq.size()||seq[nxtIdx]!=0)))
        continue;
        seq[idx]=seq[nxtIdx]=i;
        used[i]=true;
        if(solve(seq,used,idx+1,n)) return true;
        seq[idx]=seq[nxtIdx]=0;
        used[i]=false;
      }
      return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> seq(2*n-1,0);
        vector<bool> used(n+1,false);
        solve(seq,used,0,n);
        return seq;
    }
};