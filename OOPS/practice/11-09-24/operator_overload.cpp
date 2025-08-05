#include<iostream>
using namespace std;
class complex{
    public:
    double re,im;//it must be private for friend and public for global function
    public:
    complex(double a=0,double b=0){re = a; im = b;}//constructor
    void show();
};

void complex :: show()
{
    cout<<re<<" + "<<im<<"i"<<endl;
}
int main()
{
    complex c1;
    cin>>c1;
    c1.show();
    // c1.show();
    cout<<c1<<endl;
    // c1.show();
}
// friend complex operator+(complex a,complex b)//it non member friend function need two argument it can access private member
    // {
    //     complex sum;
    //     sum.re = a.re + b.re;
    //     sum.im = a.im + b.im;
    //     return sum;
    // }
// complex operator+(complex a)//it member function allow only one argument it can access private member
    // {
    //     complex sum;
    //     sum.re = this->re + a.re;
    //     sum.im = this->im + a.im;
    //     return sum;
    // }
// complex operator+(complex a,complex b) //non member global functionit needs two argument it can not access private without set and get function                                        
//     {
//         complex sum;
//         sum.re = a.re + b.re;
//         sum.im = a.im + b.im;
//          return sum;
//     }
// friend complex operator+(complex &a,int b)//using friend function i overload operator when one argument is not the object of class
//     {
//         complex sum;
//         sum.re = a.re + b;
//         sum.im = a.im;
//         return sum;
//     }
// friend complex operator+(int a,complex &b)//using friend function i overload operator when one argument is not the object of class
//     {
//         complex sum;
//         sum.re = a + b.re;
//         sum.im = b.im;
//         return sum;
//     }
// complex operator+(int b)// its not works for work for 6+c1 because 6 is not an object of complex it can't invoke fun
//     {
//         complex sum;
//         sum.re = this->re + b;
//         sum.im = this->im;
//         return sum;
//     }
// global member function work properly but its break the encapsulation(privacy) of base class.

// complex operator++(int)//post increment
//     {
//         complex t = *this;
//         this->re++;
//         this->im++;
//         return t;
//     }
// complex& operator++() //pre increment
//     {
//         this->re++;
//         this->im++;
//         return *this;
//     }

// friend istream& operator>>(istream &is,complex &a)
//     {
//         is>>a.re>>a.im;
//         return is;
//     }
// friend ostream& operator<<(ostream &os,complex &a)//overloaded ostream (cout)
//     {
//         os<<a.re<<" + "<<a.im<<"i"<<endl;
//         return os;
//     }

