#include <iostream>
using namespace std;
class Student
{
    private:
        string name;
        string tele;
        int age;
    public:
        Student(){};
        ~Student()  //析构函数
        {
            cout << name << "被释放" << endl;
        }
        void setname(string name)
        {
            this->name = name;
        }
        void getname()
        {
            cout << name << endl;
        }
        void settele(string tele)
        {
            this->tele = tele;
        }
        void gettele()
        {
            cout << tele << endl;
        }
        void setage(int age)
        {
            this->age = age;
        }
        void getage()
        {
            cout << age << endl;
        }

};