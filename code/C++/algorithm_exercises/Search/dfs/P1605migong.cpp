#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> grid;
vector<vector<bool>> vis;
int cnt, sx, sy, fx, fy;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void dfs(int x, int y, int r, int c)  //r为行，c为宽
{
    if (x == fx && y == fy )
    {
        cnt++;
        return;
    }
    for (int k = 0; k < 4; ++k)
    {
        int tx,ty;
        tx = x + dx[k];
        ty = y + dy[k];
        if (tx < 1 || tx > r || ty < 1 || ty > c || grid[tx][ty] != 0 || vis[tx][ty] != false)  //不满足条件
        {
            continue;
        }
        vis[tx][ty] = true;
        dfs(tx,ty,r,c);  //继续dfs
        vis[tx][ty] = false;  //重新设置为未访问
    }
}
int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    grid.resize(n+1,vector<int>(m+1));   //开辟地图空间（默认为0，作为空地）, 从下标为1开始，不要下标0的行和列，因此n+1,m+1
    vis.resize(n+1, vector<bool>(m+1));  //开辟访问数组（默认为false）
    cin >> sx >> sy >> fx >> fy;
    for (int i = 1; i <= t; ++i)
    {
       int row, col;   //障碍物的坐标
       cin >> row >> col;
       grid[row][col] = 1;    //障碍物设置为1
    }
    vis[sx][sy] = true;   //设置为已经访问
    dfs(sx,sy,n,m);    //开始dfs
    cout << cnt;
    return 0;
}