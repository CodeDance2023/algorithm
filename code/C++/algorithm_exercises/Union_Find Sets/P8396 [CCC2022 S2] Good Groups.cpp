#include <iostream>
#include <vector>
using namespace std;
const int MaxN = 1e7;
int fa[MaxN];
void init(int n)
{
    for (int i = 0; i < n; ++i)
    {
        fa[i] = i;
    }
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
    }
}
int v(char c)
{
    if (c >= 'a' && c <= 'z') //1~26
    {
        return c - 'a' + 1;
    }
    else if (c >= 'A' && c <= 'Z')  //27~52
    {
        return c - 'A' + 27;
    }
    else  //数字0 ~ 9：53~62
    {
        return c - '0' + 53;
    }
}
unsigned long long Hash(string s)
{
    unsigned long long ans = v(s[0]);
    for (int i = 1; i < s.size(); ++i)
    {
        ans = (ans * 13113 + v(s[i])) % MaxN;  //结果%1e7,方便确定fa[]的大小,最终选到13113避免了“碰撞”
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false); //加速c++的输入输出
    cin.tie(0);
    cout.tie(0);

    init(MaxN);  //初始化并查集
    int x, y, g,cnt = 0;
    cin >> x;
    vector<vector<string>> sx(x,vector<string>(2));  //一定在同一个小组的人的数组
    for (int i = 0; i < x; ++i)     //输入在一个小组的人
    {
        cin >> sx[i][0];
        cin >> sx[i][1];
    }
    cin >> y;
    vector<vector<string>> sy(y,vector<string>(2));  //一定不在同一小组的人的数组
    for (int j = 0; j < y; ++j)     //输入不在一个小组的人
    {
        cin >> sy[j][0] >> sy[j][1]; 
    }
    cin >> g;
    for (int k = 0; k < g; ++k)  //输入并合并现在在同一个小组的人
    {
        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        join( Hash(s1), Hash(s2));
        join( Hash(s2), Hash(s3));
    }
    for (int i = 0; i < x; ++i)
    {
        if (find(Hash(sx[i][0])) != find(Hash(sx[i][1])))
        {
            cnt++;
        }
    }
    for (int j = 0; j < y; ++j)
    {
        if (find(Hash(sy[j][0])) == find(Hash(sy[j][1])))
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}