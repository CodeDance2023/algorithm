#include <iostream>
using namespace std;
long long quick_power(long long a, long long b, long long p)
{
    long long res = 1;    //这一步别丢，不然后面的结果全是0
    a = a % p;       //防止第一次当b是偶数时进入a=a*a%p的“a*a”溢出，例如：a = 2547862溢出了
    while (b != 0)
    {
        if (b & 1)
        {
            res = res * a % p;
        }
        a = a * a % p;  //如果a比较大，a是int的话，a*a就可能会溢出，解决方法：1.a用long long型
                           //2.开始快速幂之前先对a取一次模
        b >>= 1;
    }
    return res;
}

int main()
{
    long long a, b, p;
    cin >> a >> b >> p;
    long long ret = quick_power(a,b,p);
    cout << a << "^" << b << " mod " << p << "=" << ret;
    return 0;
}