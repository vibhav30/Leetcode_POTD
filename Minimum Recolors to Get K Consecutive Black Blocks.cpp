class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int ans=k, cnt=0, start=0;
        for(int end=0; end<n; end++)
        {
          if(blocks[end]=='W') cnt++;
          if(end-start+1==k)
          {
            ans=min(ans,cnt);
            if(blocks[start++]=='W') cnt--;
          }
        }
        return ans;
    }
};
