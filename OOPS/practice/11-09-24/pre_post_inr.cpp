#include<iostream>
using namespace std;
class myclass
{
    int data;
    public:
    myclass(int d=0)
    {
        data = d;
    }
    myclass& operator++()  //they are member function 
    {
        cout<<"After pre increment"<<endl;
        ++data;
        return *this;
    }
    myclass operator++(int)
    {
        cout<<"After post increment"<<endl;
        myclass t(data);//here we have to store previous data;
        ++data;
        return t;
    }
    void show();
};
void myclass :: show()
{
    cout<<" Data : "<<data<<endl;
}
int main()
{
    myclass obj1(8),obj2;
    cout<<"Before increment"<<endl;
    obj1.show();
    obj2 = obj1++;
    obj2.show();
    obj2 = ++obj1;
    obj2.show();
}