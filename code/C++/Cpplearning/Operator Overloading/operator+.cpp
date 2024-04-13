#include <iostream>
using namespace std;
//1.通过成员函数进行重载
class Integer{
    public:
        int num;
    // public:
    //     Integer operator+(Integer& other)
    //     {
    //         Integer temp;
    //         temp.num = num + other.num;
    //         return temp;
    //     }
};

//2.通过全局函数进行重载
Integer operator+(Integer& one, Integer& other) //这是没有成员函数的加持，就要传入两个参数
{
    Integer res;
    res.num = one.num + other.num;
    return res;
}
int main()
{
    Integer int1;
    int1.num = 2;
    Integer int2;
    int2.num = 2;
    Integer res;
    // res = int1.operator+(int2); //一般形式 --- 定义运算符重载就像定义一个函数重载一样
    // cout << res.num << endl;
    // res = int1 + int2; //简化形式 ------  定义了operator+ 函数后就可以进行简化，为int1 + int2的形式
    // cout << res.num << endl;
    res = operator+(int1,int2); //通过全局函数实现的重载
    cout << res.num << endl;
    res = int1 + int2;//简化形式 ------  定义了operator+ 函数后就可以进行简化，为int1 + int2的形式
    cout << res.num << endl;
    
}