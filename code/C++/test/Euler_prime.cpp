// #include <iostream>
// using namespace std;
// bool is_prime[10000];
// int prime[10000];
// int main()
// {
//     int n,cnt = 0;
//     cout << "enter n:";
//     cin >> n;
//     for (int i = 2; i <= n; ++i)
//     {
//         is_prime[i] = true;
//     }
//     for (int i = 2; i <= n; ++i)
//     {
//         if (is_prime[i] == true)
//         {
//             cout << i << " ";
//             prime[cnt++] = i;
//         }   
//         int t;
//         for (int j = 0; j < cnt && ( t = i *  prime[j] ) <= n; ++j)
//         {
//             is_prime[t] = false;
//             if (i % prime[j] == 0)
//             {
//                 break;
//             }
//         }
//     }
//     cout << endl << "the number of prime is: " << cnt;
//     return 0;
// }

#include <iostream>
using namespace std;
bool is_prime[10001];
int prime[10001];
int main()
{
    
    int n,cnt = 0;
    cout << "please enter n:";
    cin >> n;
    is_prime[1] = true;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i] == false)
        {
            cout << i << " ";
            prime[cnt++] = i;
        }   
        int t;
        for (int j = 0; j < cnt && ( t = i *  prime[j] ) <= n; ++j)
        {
            is_prime[t] = true;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    cout << endl << "the number of prime is: " << cnt;
    return 0;
}