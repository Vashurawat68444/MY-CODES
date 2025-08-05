#include<iostream>
#include<string.h>
using namespace std;
//int count = 0;
class library
{
    string id;
    string name_of_book,type_of_book,author_of_book,author;
    // int edition_of_book;
    float price;
    public:
    static int count;
    void add_book();
    void issue_book();
    void submit_book();
    library(string id,string name_of_book,string type_of_book,string author,float price)
    {
        count++;
        this->name_of_book = name_of_book;
        this->type_of_book = type_of_book;
        this->author = author;
        this->price = price;
    }
};
int library::count =0;

void library :: add_book()
{
    string name_of_book,type_of_book,author_of_book;
    float price;
    cout<<"ENTER BOOK NAME:";
    cin>> name_of_book;

    cout<<"ENTER THE TYPE OF BOOK :";
    cin>> type_of_book;
    
    cout<<"ENTER AUTHOR :";
    cin>>author_of_book;
    
    cout<<"ENTER PRICE OF BOOK" ;
    cin>> price;
    
    library b1(name_of_book, type_of_book, author_of_book, price);
}
void library :: issue_book(string id,string name_of_book,string type_of_book,string author,float price)
{
    count--;
    string name_of_book,type_of_book,author_of_book;
    float price;
    printf("ENTER BOOK NAME : ");
    scanf("%s",&name_of_book);
    printf("ENTER THE TYPE OF BOOK : ");
    scanf("%s",&type_of_book);
    printf("ENTER AUTHOR : ");
    scanf("%s",&author_of_book);
    printf("ENTER PRICE OF BOOK : ");
    scanf("%f",price);

}
void library :: submit_book(string id,string name_of_book,string type_of_book,string author,float price)
{
    count++;
    string name_of_book,type_of_book,author_of_book;
    float price;
    printf("ENTER BOOK NAME : ");
    scanf("%s",&name_of_book);
    printf("ENTER THE TYPE OF BOOK : ");
    scanf("%s",&type_of_book);
    printf("ENTER AUTHOR : ");
    scanf("%s",&author_of_book);
    printf("ENTER PRICE OF BOOK : ");
    scanf("%f",price);
}
int main()
{

}