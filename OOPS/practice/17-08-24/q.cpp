// #include<iostream>
//  using namespace std;
// class MyClass {
// public:
//     void myFunction(); // Declaration
//     MyClass()
//     {
//         cout<<"CONSTRUCTER CALLED\n";
//     }
// };

// void MyClass::myFunction(){ // Definition
//     std::cout << "Function called!\n";
// }

// int main(){
//     MyClass obj,a;
//     obj.myFunction(); // Calls the functionreturn0;
//     a.myFunction();
//     }
// #include<iostream>
// using namespace std;
// inline int max(int a, int b)
// { 
//     return a>b ? a : b;
// } 
// int main() 
// { 
//     cout << max(10, 20); 
//     cout << " " << max(99, 88); 
//     return 0;
// }
// #include <iostream>
// using namespace std; 
// int square (int y) 
// {
//     cout<<"double square()"<<endl;
//     return y *y;
// }
// int a=5;
// double square (double y) 
// {
//     cout<<"int square()"<<endl; 
//     return y *y;
// } 
// int main( )
// {
//     cout << square(10) << endl; 
//     cout << square(10) << endl;
// }
// #include<iostream>
// using namespace std;
// void show(int a)
// {
//     cout<<"i am int "<<endl;
// }
// void show(char a)
// {
//     cout<<"i am char "<<endl;
// }
// void show(float b)
// {
//     cout<<"i am float "<<endl;
// }
// int main()
// {
//     int a=1;
//     show(97.0F);
// }
// #include <iostream> 
// using namespace std;  
// double calc_gross_pay(float,float,float);
// double calc_gross_pay(float basic, float da, float hra) 
// { 	
//     return basic + da/100 *basic + hra ; 
// } 
// double calc_gross_pay(float hr, float wg) 
// { 	
//     return hr * wg ;   
// }
// double calc_gross_pay(float pay)
// { 	
//     return pay ; 
// }
// int main()
// {
//     cout<<calc_gross_pay(5000)<<endl;
// }

// #include<iostream>
// using namespace std;
// int main()
// {
//    for(int i=0;i<5;i++)
//    {
//       static int a=1;
//       cout<<&a<<"  "<<endl;
//       cout<<a++<<endl;
//    }
// }

// #include <iostream> 
// using namespace std; class shared { static int a; // declare a 
// int b; 
// public:
// void set(int i, int j) {a=i; b=j;}
// void show();
// } ;
// int shared::a; // define a 
// void shared::show() { cout << "This is static a: " << a<<endl; 
//                       cout<< "adress of a" << &a;
//                       cout << "\nThis is non-static b: " << b; cout << "\t"<<&b; }
// int main() { shared x, y;

// x.set(1, 1); // set a to 1
// x.show();
// y.set(2, 2); // change a to 2
// y.show();
// x.show(); /* Here, a has been changed for both x and y because a is shared by both 
// objects.  return 0; 
// } 
