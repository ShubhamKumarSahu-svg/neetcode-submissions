class Solution {
int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

private:
    void bfs(vector<vector<char>>& grid,int r , int c){
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c] = '0';

        while(!q.empty()){
            auto front = q.front();
            int row = front.first;
            int col = front.second;
            q.pop();

            for(int i = 0 ;i < 4;i++){
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];

                if(nr >= 0 && nc >= 0 && nr < grid.size() && 
                    nc < grid[0].size() && grid[nr][nc] == '1'){
                    q.push({nr,nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    bfs(grid, r, c);
                    islands++;
                }
            }
        }

        return islands;
    }
};
