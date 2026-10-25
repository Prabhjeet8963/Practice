#include <iostream>
using namespace std;

class overload {
    public:
    void display (int a ){
        cout <<"int :"<<a<<endl;

    }
    void display (double b){
        cout<<"display :" <<b<<endl;

    }
    void display (int a, int b){
        cout<<"Int 1:"<<a<<"Int 2 "<<b<<endl;

    }
};
int main (){
    overload x;
    x.display(2);
    x.display(2.4);
    x.display(4,4);
    return 0;
}