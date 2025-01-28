class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<vector<bool>> reach(numCourses, vector<bool>(numCourses,false));
        for(auto it : prerequisites)
        {
            reach[it[0]][it[1]]=true;
        }
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    reach[i][j]=reach[i][j]||(reach[i][k]&&reach[k][j]);
                }
            }
        }
        vector<bool> ans;
        for(auto q : queries)
        {
            ans.push_back(reach[q[0]][q[1]]);
        }
        return ans;
    }
};
