class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size(), cnt=0;
        int p1=0,p2=0;
        for(int i=0; i<n; i++)
        {
            if(s1[i]!=s2[i])
            {
                cnt++;
                if(cnt==1) p1=i;
                if(cnt==2) p2=i;
            }
        }
        if(cnt==2) swap(s1[p1],s1[p2]);
        return (s1==s2)?true:false;
    }
};
