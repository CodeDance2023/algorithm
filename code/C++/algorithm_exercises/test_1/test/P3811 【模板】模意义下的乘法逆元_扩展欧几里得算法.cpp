#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll exgcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y ,x);
    y -= (a / b) * x;     
    return d;        //为了将这个最大公约数返回出去，不写就返回不出去
}
int main()
{

    ll n,p,x,y;
    scanf("%lld %lld", &n, &p);
    printf("%d\n",1);
    for (int i = 2; i <= n; ++i)
    {
        exgcd(i,p,x,y);        //ax + by = kd ,d = gcd(b,p);
        x = (x % p + p) % p;
        printf("%lld\n",x);
    }
    return 0;
}