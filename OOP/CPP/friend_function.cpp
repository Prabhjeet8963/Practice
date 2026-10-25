#include <iostream>
using namespace std;

class base{
    private:
    int val;
    int display_from_base(int val){
        cout << val;
        return 0;
    }
    friend class derived;

};
class derived {
    public :
    int display_from_derived (base obj) {
        obj.val=100;
         return obj.display_from_base(obj.val);
    }
};
int main(){
    base B;
    derived D;
    D.display_from_derived(B);
    return 0;
}