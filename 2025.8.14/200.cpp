#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, int x, int y) {
    int m = grid.size(), n = grid[0].size();
    if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1') return;
    grid[x][y] = '2';
    dfs(grid, x, y-1);
    dfs(grid, x, y+1);
    dfs(grid, x+1, y);
    dfs(grid, x-1, y);
    return;
}
int numIslands(vector<vector<char>>& grid) {
    int result = 0;
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[0].size(); ++j) {
            if(grid[i][j] == '1') {
                dfs(grid,i,j);
                result++;
            }
        }
    }
    return result;
}

int main() {
    vector<vector<char>> grid = {{'1','1','1','1','0'},
                                 {'1','1','0','1','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','0','0','0'}};
    cout << numIslands(grid) << endl;
    return 0;
}