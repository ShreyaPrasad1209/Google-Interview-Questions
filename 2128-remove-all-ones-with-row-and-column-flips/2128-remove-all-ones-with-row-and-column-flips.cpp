class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> comp(m);
        comp=grid[0];
        for(int i=0;i<m;i++){
            comp[i]^=1;
        }
        for(auto x:grid){
            if((x!=grid[0])&&(x!=comp)){
                return false;
            }
        }
        return true;
    }
};