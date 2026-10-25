#include <iostream>
using namespace std;

class base {
    public :
    /*virtual*/ void display () {
        cout << "base"<<endl;
    }
};
class derived : public  base {
    public :
    void display () {
        cout << "derived " <<endl;

    }
};

int main () {
    base *bptr;
    base b ;
    derived *dptr;
    derived d;

    bptr = &b;
    bptr->display();
    bptr = &d;
    bptr -> display();
   
    dptr = &d;
    dptr->display();
    
}
