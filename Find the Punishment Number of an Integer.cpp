class Solution {
public:
    bool canPart(string &s,int idx,int tar)
    {
        if(idx==s.size()) return tar==0;
        int sum=0;
        for(int i=idx;i<s.size();i++)
        {
          sum=sum*10+(s[i]-'0');
          if(sum>tar) break;
          if(canPart(s,i+1,tar-sum)) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int totSum=0;
        for(int i=1;i<=n;i++)
        {
          int sq=i*i;
          string str=to_string(sq);
          if(canPart(str,0,i)) totSum+=sq;
        }          
        return totSum;
    }
};