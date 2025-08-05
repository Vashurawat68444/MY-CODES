#include<iostream>
using namespace std;
#include<string.h>
// int main()
// {
//     string line;
//     cout<<"ENTER YOUT STRING : ";
//     getline(cin,line);
//     cout<<"YOUR STRING WAS  : "<<line<<endl;
//     line.push_back('A');
//     cout<<"YOUR UPDATED STRING : "<<line<<endl;
//     line.pop_back();
//     cout<<"YOUR NEW STRING WAS : "<<line<<endl;
// }
// class A
// {
//     public:
//     void function_1()
//     {
//         cout<<"funtionc 1"<<endl;
//     }
// };
// class B :public virtual A
// {
//     public:
//     void function_2()
//     {
//         cout<<"funtionc 2"<<endl;
//     }
// };
// class C :public virtual A
// {
//     public:
//     void function_3()
//     {
//         cout<<"funtionc 3"<<endl;
//     }
// };
// class D :public C,public B
// {
//     public:
//     void function_4()
//     {
//         cout<<"funtionc 4"<<endl;
//     }
// };
// int main()
// {
//     class D o1;
//     o1.function_1();

    //o1.function_2();
// }
// class A{
//     public:
//     string line;
//     void get_a()
//     {
//         cout<<"ENTER YOUR FIRST NAME : ";
//         getline(cin,line);
//         cout<<"YOUR FIRST NAME WAS : "<<line<<endl;
//     }
// };
// class B:public A{
//     public:
//     string line;
//     void get_b()
//     {
//         cout<<"ENTER YOUT SECOND NAME : ";
//         getline(cin,line);
//         cout<<"YOUR SECOND NAME :"<<line<<endl;
//     }
// };
// int main()
// {
//     class B o1;
//     o1.get_a();
//     o1.get_b();

// }
class car{
    public:
    string name,date,model;
    car(string name,string date,string model)
    {
        this->name = name;
        this->date = date;
        this->model = model;
    }
    void getinfo()
    {
        cout<<"NAME OF CAR : "<<endl;
    }
};

int main()
{
    class car car1("fortuner","12/12/2014","cgf"),car2("audi","5/3/2015","xyz"),car3("BMW","04/06/2006","dfd");


}