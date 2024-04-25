// P2440 木材加工
#include <iostream>
#include <vector>
using namespace std;
vector<int> woods;
int n, k, Max, cnt; // n:原木的数量 k:需要得到的小段的数量
int ans;   //储存可能的答案
bool check(int x)  //x(mid)为可能的长度
{
    cnt = 0;  ///可以切出来的木材的段数
    for (int i = 1; i <= n; ++i)
    {
        cnt += woods[i] / x;    
    }
    if (cnt >= k)
    {
        ans = x;   //保存一个答案
        return true;
    }
    return false;
}
int main()
{
    ans = 0;  //重置ans的值，不干扰下一个测试用例
    cin >> n >> k;
    woods.resize(n);  //开辟木材数组的空间

    for (int i = 1; i <= n; ++i)
    {
        int temp;
        cin >> temp;
        woods[i] = temp;  //输入木材的长度
        Max = max(Max, woods[i]);  //得到木材的最大值长度
    }

    int mid, l = 1, r = Max; 
    while (l <= r)
    {
        mid = l + ((r - l) >> 1);
        if (check(mid))
        {
            l = mid + 1;   
        }
        else
        {
            r = mid - 1;
        }
    }
    if (ans < 1)   //如果连1cm的小段都切不出来就输出0
    { 
        cout << 0;
    }
    else
    {
        cout << ans;
    }
    return 0;
}