class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();++i){
        int j=grid[i].size()-1;
        while(j>=0){
            if(grid[i][j]<0)cnt++;
            j--;
        }       
        }
        return cnt;
    }
};