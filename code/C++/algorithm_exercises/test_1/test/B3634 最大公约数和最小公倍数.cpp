#include <iostream>
using namespace std;
int main()
{
    long long a,b,r;
    cin >> a >> b;
    long long oa = a, ob = b;  //保存a,b原来的数据用来求最小公倍数，因为求gcd是a,b原来的数据已经被改变了
    if (a < b) swap(a,b);
    while (r = a % b)
    {
        a = b;
        b = r;
    }
    long long max = oa > ob ? oa : ob;
    long long i = max;
    while (1)
    {
        if ( i % oa == 0 && i % ob == 0)
        {
            break;
        }
        i += max;
    }
    cout << b << " " << i;
    return 0;
}