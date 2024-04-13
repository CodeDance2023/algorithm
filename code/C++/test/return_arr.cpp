#include <iostream>
using namespace std;
int* fun(int a[]);
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int* p = fun(arr);
    for (int i = 0; i < 10; ++i)
    {
        cout << p[i] << " ";
    }
    return 0;
}
int* fun(int a[])
{
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[6] = 0;
    a[5] = 0;
    return a;
}

