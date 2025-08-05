#include<iostream>
using namespace std;
class test
{
    int a;
    public:
    test(int x){a=x;}
};
class test1
{
    int a;
    public:
    test1(int x){a=x;}
};
void operator>(test t1,test1 t2)
{
    
}
int mai()
{
    test t(5);
    test1 t1(6);
}