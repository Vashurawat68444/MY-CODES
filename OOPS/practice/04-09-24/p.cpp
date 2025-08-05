#include<iostream>
using namespace std;
// class stud //base class
// {
//     private:
//     int id;
//     string name;
//     public:
//     void putdetail(int id, string name)
//     {
//         this->id = id;
//         this->name = name;
//     }
//     void getdetail()
//     {
//         cout<<"details are:"<<endl;
//         cout<<"ID IS : "<<this->id<<endl;
//         cout<<"name is : "<<this->name<<endl;
//     }
// };
// class marks
// {
//     private:
//     int m1,m2,m3;
//     public:
//     void setmarks(int m1,int m2,int m3)
//     {
//         this -> m1 = m1;
//         this -> m2 = m2;
//         this -> m3 = m3;
//     }
//     void getmarks()
//     {
//         cout<<"MARKS ARE : \n"<<m1<<"\n"<<m2<<"\n"<<m3<<"\n";
//     }
//     void t()
//     {
//         cout<<"my total : "<<m1+m2+m3<<endl;
//         cout<<"my average : "<<(m1+m2+m3)/3<<endl;
//     }
// };
// class result : public stud,public marks  // here inheritence remains private in derived class by base class A
// {        
//     public:
//     void show()
//     {
//         t();
//     }
    
// };
// int main()
// {
//     result r;
//     r.setmarks(65,95,80);
//     r.putdetail(95,"vashu");
//     r.getdetail();
//     r.getmarks();
//     r.show();



// }




class account
{
    int ac_num,bal;
    string name;
};
class savings : public account
{

};
class current : public account
{

};
