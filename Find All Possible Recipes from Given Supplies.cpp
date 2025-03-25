class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> adj;
        unordered_map<string,int> ind;
        int n=recipes.size();
        for(int i=0; i<n; i++)
        {
            for(auto it : ingredients[i])
            {
              adj[it].push_back(recipes[i]);
              ind[recipes[i]]++;
            }
        }
        queue<string> q;
        for(auto it : supplies) q.push(it);
        unordered_set<string> st;
        while(!q.empty())
        {
            string s=q.front(); q.pop();
            for(auto it : adj[s])
            {
               ind[it]--;
               if(ind[it]==0)
               {
                q.push(it); st.insert(it);
               }
            }
        }
        vector<string> v(st.begin(), st.end());
        return v;
    }
};
