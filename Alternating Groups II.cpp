class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size(), cnt=0, maxLen=1;
        for(int i=0; i<n+k-2; i++)
        {
            if(colors[i%n]!=colors[(i-1+n)%n]) maxLen++;
            else maxLen=1;
            if(maxLen>=k) cnt++;
        }
        return cnt;
    }
};
