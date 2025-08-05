#include <iostream>
using namespace std;

class C {
  static void f() {
    cout << "Here is i: " << i << endl;
  }
  static int i;
  int j;
public:
  // static int j;
  C(int firstj){ 
  j=firstj;
  }
  void printall();
};

void C::printall() {
  cout << "Here is j: " << j << endl;
  i=65;
  f();
}

int C::i = 3;
// int C::j;

int main() {
  C obj_C(10);
  obj_C.printall();
}

