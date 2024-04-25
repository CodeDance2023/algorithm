//1162. 地图分析 -------- 多起点bfs
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int main()
{
    return 0;
}
//利用多起点bfs,每一个1都进行bfs,只有多个起点进行bfs所找到的距离的才是“海洋”距离最近的“陆地”最大的距离。
class Solution 
{
public:
    int seas;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0,-1, 0};
    struct point
    {
        int x;
        int y;
        int step;
    };
    bool vis[100][100];
    vector<vector<int>> grid;
    queue<point> q;
    point sp, fp, tp;

public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; ++i)   //设置vis数组的标记内容为false,不影响下一个测试用例的测试
        {
            for (int j = 0; j < col; ++j)
            {
                vis[i][j] = false;   //全部改为未访问
            }
        }

        grid.resize(row * col);   //动态开辟大小
        for (int i = 0; i < row; ++i)  //多起点bfs,先遍历一遍找扫全部的1，作为bfs的第一层
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 1)
                {
                    sp.x = i;
                    sp.y = j;
                    sp.step = 0;  //bfs的第一层为距离为0
                    q.push(sp);  //将找到的每一个1它的坐标和步数压入队列
                    vis[i][j] = true;  //设置为已经访问
                }
                else
                {
                    seas++;   //海洋数+1，为了全是海洋或者全是陆地的时候输出-1的特殊判断
                }
            }
        }
        if (seas == row * col || seas == 0)    
        {
            return -1;       //全是海洋或者全是陆地的时候输出-1的特殊判断
        }
        while (!q.empty())  //正式开始bfs
        {
            fp = q.front();  //拿出队头
            
            for (int k = 0; k < 4; ++k)  //队首可拓展的点入队,四个方向进行感染
            {
                int tx, ty;
                tx = fp.x + dx[k];
                ty = fp.y + dy[k];
                if (tx < 0 || tx >= row || ty < 0 || ty >= col || grid[tx][ty] != 0 || vis[tx][ty] != false)  //这个点不满足条件，直接跳过
                {
                    continue;
                }
                //满足条件
                tp.x = tx;
                tp.y = ty;
                tp.step = fp.step + 1;   //距离等于队首(dfs的上一层) + 1
                q.push(tp);     //队首可拓展的点入队
                vis[tx][ty] = true;   //设置为已访问
            }
            q.pop();   //弹出队首元素
        }
        return fp.step;   //返回最后的队首元素的step,即为答案
    }
};
