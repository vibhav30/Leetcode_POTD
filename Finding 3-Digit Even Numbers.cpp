class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        set<int> st;
        for(int i=0; i<n; i++)
        {
          if(digits[i]==0) continue;
          for(int j=0; j<n; j++)
          {
            if(i==j) continue;
            for(int k=0; k<n; k++)
            {
              if(i==k || j==k || digits[k]&1) continue;
              int x=digits[i]*100+digits[j]*10+digits[k];
              st.insert(x);
            }
          }
        }
        vector<int> v;
        for(auto it : st) v.push_back(it);
        return v;
    }
};
