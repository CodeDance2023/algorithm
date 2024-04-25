#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    return 0;
}

  //并查集技巧：给集合打上标签
  //思路：因为这题stones数组的值是两个坐标，且比较离散(stones数组最多只有1000个数据，但是坐标的范围为x,y <= 10000,
  //      较为离散，因此，我们采用一种“打标签”的方法：即申请两张表，一张行表，一张列表，记录这一行是否有遇到石头，有就合并，没有就插入键值对
  //      用最初的集合数量减去合并后减去的集合就是最多可以移走的石头
class Solution
{
public:
    int fa[1001],sets;
    unordered_map<int,int> rowFirst, colFirst;   //声明两个表，表示在第几行/列遇到的第一块石头
public:
//并查集模板
void init(int n)
{
    for (int i = 0; i <= n; ++i)
    {
        fa[i] = i;
    }
    sets = n;  //每一块石头看成一个独立的集合
}

int find(int x)
{
    if (fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        fa[fx] = fy;
        sets--;    //合并后，集合数就减1
    }
}
      int removeStones(vector<vector<int>>& stones) 
      {
        int sum = stones.size();   //石头的总数
        init(sum);  //并查集初始化
        rowFirst.clear();   //每一个测试用例开始之前都要清空上次的键值对数据：clear()方法为清理全部键值对的方法，erase(key)方法为清理key这一个键的键值对
        colFirst.clear();   //每一个测试用例开始之前都要清空上次的键值对数据
            for (int i = 0; i < stones.size(); ++i)
            {
                int row = stones[i][0];   //拿到每一块石头的行坐标
                int col = stones[i][1];   //拿到每一块石头的列坐标
                if (rowFirst.find(row) == rowFirst.end())   //find函数如果返回end,说明这个“键”没有对应的值，即这行还没有遇到石头
                {
                    rowFirst.insert(make_pair(row,i));   //插入键值对。row : i —— 为第row行遇到的第一块石头为i号石头
                }
                else
                {
                     join(rowFirst.at(row), i);   //如果遇到同一行的石头，就合并它们，at(row)为获得row这个键对应的值
                }
                   
                if (colFirst.find(col) == colFirst.end())  //同一列没有遇到石头
                {
                    colFirst.insert(make_pair(col,i));  //插入键值对：col:i 为第col列遇到的第一块石头为i号石头
                }
                else
                {
                    join(colFirst.at(col),i);  //如果遇到同一列的石头，就合并它们。at(col)为获得col这个键对应的值
                }
            }
            return sum - sets;

      }

};