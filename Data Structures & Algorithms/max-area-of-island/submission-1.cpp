class Solution {
private:
    vector<vector<int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& grid,int r,int c,int &ans){
        if(r < 0 || c < 0 || r >= grid.size() ||c >= grid[0].size() || grid[r][c] == 0){
            return;
        }

        ans++;
        grid[r][c] = 0;
        for(int i =0;i < 4;i++){
            dfs(grid,r + direction[i][0],c + direction[i][1],ans);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;

        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
            int temp = 0;
            if (grid[r][c] == 1) {
                dfs(grid, r, c,temp);
                ans = max(temp,ans);
            }
            }
        }
        return ans;
    }
};
