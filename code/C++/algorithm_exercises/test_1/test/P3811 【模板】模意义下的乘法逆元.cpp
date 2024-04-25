 #include <iostream>
 #include <cstdio>
 using namespace std;
 int main()
 {
    int n, p;
    scanf("%d %d",&n, &p);
    long long* inv = new long long[n]; //记得用long long 类型，不然乘法运算时发生会溢出错误
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        inv[i] = -(p / i) * inv[p % i];  //递推公式 //x(inv) = -k * r(inv) --- p = kx + r
        inv[i] = (inv[i] % p + p);                          //注意：不是inv[i] = -(p / i) * inv[i - 1],这个不符合公式
    }
    printf("%d\n",1);    //输出1的乘法逆元为1
    for (int i = 2; i <= n; ++i)
    {
        printf("%lld\n",inv[i]);
    }
    return 0;
 }