#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// 定义方向数组，分别表示上、右、下、左四个方向
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0,  1, 0, -1};
 vector<vector<int>> visited(m, vector<int>(n, 0));
int patrol_area(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
   
    int patrolled = 0;

    // 深度优先搜索函数
    function<void(int, int, int)> dfs = [&](int x, int y, int direction) {
        // 如果当前格子访问次数超过4次，停止搜索
        if (visited[x][y] >= 4) {
            return;
        }
        // 如果是第一次访问该格子，增加巡逻计数
        if (visited[x][y] == 0) {
            patrolled++;
        }
        visited[x][y]++;

        // 尝试四个方向
        for (int i = 0; i < 4; i++) {
            int new_dir = (direction + i) % 4;
            int nx = x + dx[new_dir],ny = y + dy[new_dir];
            // 如果新位置有效且为空地，继续搜索
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                dfs(nx, ny, new_dir);
                return;
            }
        }
    };

    // 从左上角开始，初始方向向右
    dfs(0, 0, 1);
    return patrolled;
}
const int n=4;
int main() {
   // int m, n;
   // cin >> m >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    grid={
        {0,1,1,1},
        {0,1,1,1},
        {0,1,0,1},
        {0,1,0,1},
    };
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cin >> grid[i][j];
    //     }
    // }

    int result = patrol_area(grid);
    cout << result << endl;

    return 0;
}
