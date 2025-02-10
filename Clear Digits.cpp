class Solution {
public:
    string clearDigits(string s) {
        int n=s.size(); 
        string str=""; str+=s[0];
        for(int i=1;i<n;i++)
        {
          if(str.size()>0 && !isdigit(str.back()) && isdigit(s[i]))
          {
            str.pop_back();
          }
          else if(!isdigit(s[i])) str+=s[i];
        }
        return str;
    }
};
