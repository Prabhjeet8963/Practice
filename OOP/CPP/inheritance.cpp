#include <iostream>
using namespace std;
class shape{
    public:
    int getAreasquare(int side ){
        if (side <=0){
            return -1;
        }
    return side*side;

    }
} ;

class square : public shape{
    public :
    int side;
};
int main(){
    square a;
    a.side=22;
    cout << a.getAreasquare(a.side);
}