class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> v; int cnt=0;
        v.push_back(meetings[0]);
        for(int i=1; i<meetings.size(); i++)
        {
          vector<int>& t=v.back();
          if(t[1]>=meetings[i][0]) t[1]=max(t[1],meetings[i][1]);
          else v.push_back(meetings[i]);
        }
        for(auto it : v) cnt+=(it[1]-it[0]+1);
        return days-cnt;
    }
};
