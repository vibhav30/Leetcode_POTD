class Solution {
public:
    bool checkH(int n, vector<vector<int>>& rectangles)
    {
       vector<vector<int>> v1;
       for(auto it : rectangles) v1.push_back({it[1],it[3]});
       sort(v1.begin(), v1.end());
       vector<vector<int>> v2;
       v2.push_back(v1[0]);
       for(int i=1; i<v1.size(); i++)
       {
        vector<int> &t=v2.back();
        if(t[1]>v1[i][0]) t[1]=max(t[1],v1[i][1]);
        else v2.push_back(v1[i]);
        if(v2.size()>=3) return true;
       }
       return v2.size()>=3;
    }

    bool checkV(int n, vector<vector<int>>& rectangles)
    {
       vector<vector<int>> v1;
       for(auto it : rectangles) v1.push_back({it[0],it[2]});
       sort(v1.begin(), v1.end());
       vector<vector<int>> v2;
       v2.push_back(v1[0]);
       for(int i=1; i<v1.size(); i++)
       {
        vector<int> &t=v2.back();
        if(t[1]>v1[i][0]) t[1]=max(t[1],v1[i][1]);
        else v2.push_back(v1[i]);
        if(v2.size()>=3) return true;
       }
       return v2.size()>=3;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return (checkH(n, rectangles)||checkV(n, rectangles));
    }
};
