//    using the friend function we can access the private member using objects 
#include<iostream>
using namespace std;
//----------------------------------------------------------------------------------------------------
class sample2; // it must be declare first because i used in line number 7 to declare friend function
class sample1{
    int a;
    friend void print(sample1,sample2);
};
class sample2{
    int b;
    friend void print(sample1,sample2);
};
void print(sample1 s1,sample2 s2)
{
    s1.a = 10;
    s2.b = 20;
    if(s1.a>s2.b)
    cout<<"a is greater"<<endl;
    else
    cout<<"b is greater"<<endl;
}
//--------------------------------------------------------------------------------------------------------
// composotion
class test1 // container
{
    int a,b;
    public:
    friend class test2;
    void getab()
    {
        cout<<"Enter a,b : ";
        cin>>a>>b;
        // cin>>b;
    }
};
class test2  //content
{
    public:
        void putab(test1 t1)
        {
            cout<<"a = "<<t1.a<<endl;
            cout<<"b = "<<t1.b<<endl;
        }
};
//------------------------------------------------------------------------------------------
class author
{
    string aname;
    friend class book;
};
class book
{
    public:
    void getaname(author a)
    {
        cout<<"Enter your author name : ";
        cin>>a.aname;
        cout<<"Your author name is : "<<a.aname;
    }
};
//-------------------------------------------------------------------------------------------
class test 
{
    public:
    static int a;
    void get()
    {
        cout<<"Your value : "<<a<<endl;
    }
};
//--------------------------------------------------------------------------------------------
int count;
class A
{
    public:
    A()
    {
        count++;
    }
};
class B{
    public:
    B()
    {
        count++;
    }
};
class C
{
    public:
   C()
   {
        count++;
   }
};
//------------------------------------------------------------------------------------
// int test :: a=10;
int main()
{
    // test t;
    // test::a=100;
    // t.get();
    // author a;
    // book b;
    // b.getaname(a);
    // b.putaname(a);
    A a1;
    B b1;
    C c1;
    cout<<count;

}