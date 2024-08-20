#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// 定义方向数组，分别表示右、下、左、上四个方向
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0,  -1, 0};
const int n=4;
 vector<vector<int>> visited(n, vector<int>(n, 0));
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

int main() {
   // int m, n;
   // cin >> m >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    grid={
        {0,0,1,1},
        {1,1,0,1},
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


/*
LYA 公司正在开发一款用于巡逻的无人机。这款无人机被部署在一个矩形区域内，该区域由 
m×n 个方格组成。每个方格要么是空地（用 0 表示），要么是障碍物（用 1 表示）。无人机从左上角（即坐标 

(0,0)）出发，初始朝向右侧。

无人机的飞行规则如下：

沿当前方向直线飞行，直到遇到边界或障碍物。
遇到边界或障碍物时，顺时针旋转 90 度。
重复步骤 1 和 2，直到无法继续飞行。
无人机经过的每个方格（包括起始位置）都被视为已巡逻。请计算无人机能够巡逻到的方格数量。

输入格式
第一行包含两个整数 
m 和 n，表示矩形区域的行数和列数。

接下来 
m 行，每行包含 
n 个整数（0 或 1），描述了整个区域的布局。其中 0 表示空地，1 表示障碍物。

输出格式
输出一个整数，表示无人机能够巡逻到的方格数量。


*/
