#include <iostream>
using namespace std;
int n,q,k,cnt = 0;
int prime[10000000];
int main()
{
    cin >> n >> q;
    bool* not_prime = new bool[n];
    not_prime[1] = true;
    for (int i = 2; i <= n; ++i)
    {
        if (!not_prime[i])
        {
            prime[cnt++] = i;
        }
        int t;
            for (int j = 0; j < cnt && (t = (i * prime[j])) <= n; ++j)
            {
                not_prime[t] = true;
                if (i % prime[j] == 0)
                {
                    break;
                }
            }
        
    }
    for (int i = 1; i <= q; ++i)
    {
        cin >> k;
        cout << prime[k - 1] << endl;
    }
    delete[] not_prime;
    return 0;
}
