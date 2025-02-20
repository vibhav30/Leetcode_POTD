class Solution {
public:
    int cnt=0;
    void solve(string&tiles,vector<bool>&used,string&s)
    {
      for(int i=0; i<tiles.size(); i++)
      {
         if(used[i]) continue;
         if(i>0 && tiles[i]==tiles[i-1] && !used[i-1]) continue;
         used[i]=true; s+=(tiles[i]); cnt++;
         solve(tiles,used,s); used[i]=false; s.pop_back();
      }
    }

    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        vector<bool> used(tiles.size(),false);
        string s=""; solve(tiles,used,s);
        return cnt;
    }
};
