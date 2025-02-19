class Solution {
public:
    string ans="";
    void solve(int n,int &k,string s)
    {
      if(s.size()==n)
      {
        k--; if(k==0) ans=s;
        return;
      }
      for(char ch ='a'; ch<='c'; ch++)
      {
        if(s.size()==0 || s.back()!=ch) solve(n,k,s+ch);
      }
    }

    string getHappyString(int n, int k) {
        solve(n,k,"");
        return ans;
    }
};
