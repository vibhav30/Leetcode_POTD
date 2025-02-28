class Solution {
public:
    void lcs(string str1, string str2, vector<vector<int>>& dp)
    {
       int m=str1.size(), n=str2.size();
       for(int i=m-1;i>=0; i--)
       {
          int same=0,diff1=0,diff2=0;
          for(int j=n-1; j>=0; j--)
          {
             if(str1[i]==str2[j]) same=1+dp[i+1][j+1];
             else
             {
                 diff1=dp[i+1][j];
                 diff2=dp[i][j+1];
             }
             dp[i][j]=max({same,diff1,diff2});
          }
       }
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size(), n=str2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        lcs(str1,str2,dp);
        string ans=""; int i=0, j=0;
        while(i<m && j<n)
        {
            if(str1[i]==str2[j])
            {
                ans+=str1[i];
                i++, j++;
            }
            else if(dp[i+1][j]>dp[i][j+1])
            {
               ans+=str1[i]; i++;
            }
            else
            {
               ans+=str2[j]; j++;
            }
        }
        while(i<m)
        {
            ans+=str1[i]; i++;
        }
        while(j<n)
        {
            ans+=str2[j]; j++;
        }
        return ans;
    }
};
