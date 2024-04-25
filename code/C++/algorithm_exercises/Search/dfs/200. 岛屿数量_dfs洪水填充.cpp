class Solution
{
public:
    int cnt;
    int dx[4] = { 0,1,0,-1 };
    int dy[4] = { 1,0,-1,0 };
public:
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')  //dfs退出的条件
        {
            return;     //终止条件，结束递归，条件为：越界或者遇到不为1的格子
        }
        grid[i][j] = '0';   //标记为已访问，不用再取消标记，因为要用0来表示这个被访问的状态（区分别的一片岛屿），在dfs里面和主函数里面都不要标记为0，否则会因为被改为0不是1而直接退出函数
        for (int k = 0; k < 4; ++k)    //否则，就四个方向开始感染别的1
        {
            int tx, ty;
            tx = i + dx[k];
            ty = j + dy[k];
            dfs(grid, tx, ty);     //继续感染其他的1

        }
    }
    int numIslands(vector<vector<char>>& grid)
    {
        cnt = 0;       //每一次开始重置岛屿数量
        int row = (int)grid.size();
        int col = (int)grid[0].size();
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == '1')      //遍历二维地图，找到一个1就开始感染它周围的1
                {
                    cnt++;  //岛屿数加1           //遇到一个1，就可以用dfs来填充(感染)它周围的一片；如果dfs结束，说明已经找到了连在一起的一片1
                    dfs(grid, i, j);    //开始洪水填充算法,dfs遍历
                }
            }
        }
        return cnt;
    }
};