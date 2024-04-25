#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int sets = 0;
    vector<int> fa;
public:
    int find(int x)
    {
        if (fa[x] == x) return x;
        else
        {
            return fa[x] = find(fa[x]);
        }
    }
    void join(int x, int y)
    {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy)
        {
            fa[fx] = fy;
            sets--;      //可以合并，总集合数就减去1
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();   //行
        int n = grid[0].size();  //列：每一行的列数大小都一样
        fa.resize(n * m);   //重新分配数组的大小
        for (int i = 0; i < m * n; ++I)
        {
            fa[i] = i;
        }
        for (int i = 0; i < m; ++i)  //统计1的个数
        {
            for (int j = 0; j < n; ++j)
            {
                if ( grid[i][j] == '1' )
                {
                    sets++;    //一开始把每一个1看成一个独立的集合
                }
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                    if ( j + 1 < n && grid[i][j + 1] == '1')
                    {
                        join( (i * n + j) , (i * n + j + 1) );  //用序号来区分每一个1，即i * n(有ji'lie) * j
                    }   
                    else if (i + 1 < m  && grid[i + 1][j] == '1')
                    {
                        join ( i * n + j , (i + 1) * n + j );
                    }
            }
        }
        return sets;
    }
};