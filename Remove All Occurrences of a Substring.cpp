class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans="";
        int n=part.size();
        for(auto it : s)
        {
            ans.push_back(it);
            if(ans.size()>=n && ans.substr(ans.size()-n)==part)
            ans.erase(ans.size()-n);
        }
        return ans;
    }
};
