#include <iostream>
#include <vector>
using namespace std;
int main()
{

    return 0;
}

class Solution
{
public:
    vector<vector<bool>> vis;
    vector<vector<char>> board;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

public:
    void dfs(int x, int y, vector<vector<char>>& board)
    {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'O' || vis[x][y] != false)  //不满足条件
        {
            return;
        }
        vis[x][y] = true;   //设置为已经访问
        board[x][y] = 'F';  //从边缘dfs找到的O都不能被改为X,先改为F
        for (int k = 0; k < 4; ++k)  //四个方向进行dfs
        {
            int tx, ty;
            tx = x + dx[k];
            ty = y + dy[k];
            dfs(tx,ty,board);
        }
    }

    void solve(vector<vector<char>>& board)
    {
        ios::sync_with_stdio(false);  //加速输入输出
        cin.tie(0);
        cout.tie(0);

        int row = board.size();   //拿出board的行和列
        int col = board[0].size();
        board.resize(row, vector<char>(col));  //动态开辟空间
        vis.resize(row, vector<bool>(col));
        for (int j = 0; j < col; ++j)  //从边缘的O开始进行洪水填充dfs感染
        {
            if (board[0][j] == 'O' && vis[0][j] == false)  //边缘：第一行
            {
                dfs(0, j, board);
            }
            if (board[row - 1][j] == 'O' && vis[row-1][j] == false) //边缘：最后一行
            {
                dfs(row - 1, j, board);
            }
        }
        for (int i = 0; i < row; ++i)
        {
            if (board[i][0] == 'O' && vis[i][0] == false) // 边缘：最左边一列
            {
                dfs(i, 0, board);
            }
            if (board[i][col-1] == 'O' && vis[i][col-1] == false) // 边缘： 最右边一列
            {
                dfs(i, col - 1, board);
            }
        }

            for (int i = 0; i < row; ++i) // 进行洪水填充后，所有的从边缘开始被感染的O都不是可以被修改为X的O
            {
                for (int j = 0; j < col; ++j)
                {
                    if (board[i][j] == 'O') // 现在遍历整个地图，再遇到O就一定是被X围绕着的O
                    {
                        board[i][j] = 'X'; // 将这些O改为X
                    }
                    else if (board[i][j] == 'F')
                    {
                        board[i][j] = 'O'; // 将F改回O
                    }
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
    }
};