#include <iostream>
using namespace std;

class mobile{
    public:
    int screen_size;
    int battery;
    string brand_name;

    void display(){
        cout<<"Brand :" <<brand_name<<"Display: "<<screen_size<<"Battery : "<<battery<<endl;
    }
};
int main(){
    mobile sam;
    mobile apple;

    sam.screen_size=5;
    sam.battery=5000;
    sam.brand_name="samsung";

    apple.screen_size=5;
    apple.battery=5000;
    apple.brand_name="apple";
    sam.display();
    apple.display();
    return 0;
}