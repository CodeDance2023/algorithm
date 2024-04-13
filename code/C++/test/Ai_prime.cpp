// #include <iostream>  //2.445s
// #include <ctime>
// using namespace std;
// int not_prime[10001],cnt = 0;
// int main()
// {
//     clock_t start,end;
//     double s;
//     start = clock();
//     not_prime[1] = true;
//     int n;
//     cout << "please enter n: ";
//     cin >> n;
//     for (int i = 2; i * i <= n; ++i)
//     {
//         if (!not_prime[i])
//         {
//             for (int j = i + i; j <= n; j+=i)
//             {
//                 not_prime[j] = true;
//             }
//         }
//     }
//     for (int i = 2; i <= n; ++i)
//     {
//         if (!not_prime[i])

//         {
//             cout << i << " ";
//             cnt++;
//         }
//     }
//     cout << endl << "The number of prime is: " << cnt;
//     end = clock();
//     s = (double)(end - start)/CLOCKS_PER_SEC;
//     cout << endl << s;
// }


#include <iostream>   //4.447
#include <ctime>
using namespace std;
int is_prime[10001],cnt = 0;
int main()
{
    clock_t start,end;
    double s;
    int n;
    start = clock();
    cout << "please enter n: ";
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        is_prime[i] = true;
    }
    is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i + i; j <= n; j+=i)
            {
                is_prime[j] =false;
            }
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            cout << i << " ";
            cnt++;
        }
    }
    cout << endl << "The number of prime is: " << cnt;
    end = clock();
    s = (double)(end - start)/ CLOCKS_PER_SEC;
    cout << endl << s;
}
