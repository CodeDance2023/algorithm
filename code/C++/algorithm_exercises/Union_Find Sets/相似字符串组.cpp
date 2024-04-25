#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
    int fa[308];
    int set;
    void init(int size) //初始化
    {
        for (int i = 0; i < size; ++i)
        {
            fa[i] = i;
        }
    }
    int find(int x) //查找函数
    {
        if (fa[x] == x) return x;
        else
        {
            return fa[x] = find(fa[x]);
        }
    }
    void join(int x, int y)  //合并函数
    {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy)
        {
            fa[fx] = fy;
            set--;        //只有连个字符串符合check函数且不在同一个集合才合并，集合数在这时才能减1
        }
    }
    bool check(string str1, string str2)  //检查两个字符串是否在同一组的函数
    {
        int dif = 0;
        for (int i = 0 ; i < str1.size() && dif < 3; ++i)
        {
            if (str1[i] != str2[i])
            {
                dif++;
            }
        }
        if (dif == 0 || dif == 2)     //只有两个不同或者全部相同（dif = 0）,既可以在一组
        {
            return true;
        }
        else return false;
    }
    int numSimilarGroups(vector<string>& strs)
     {
        init(strs.size());
        set = strs.size();    //刚开始所有的元素看成一个独立的集合
        for (int i = 0; i < strs.size() - 1; ++i)
        {
            for (int j = i + 1; j < strs.size(); ++j)
            {
                if ( check(strs[i], strs[j]) )
                {
                    join(i,j);    //如果两个字符串在一组则合并
                    
                }
            }
        }
       return set;
    }
};
