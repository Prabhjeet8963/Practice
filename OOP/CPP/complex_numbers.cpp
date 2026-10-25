#include <iostream>
using namespace std;
class complex {
    public :
    int r;
    int i;
    complex(){
        r=0;
        i=0;
    }
    complex (int x,int y){
        r=x;
        i=y;
    }
    complex  operator +  (complex obj){ 
    complex res ;
    res.r= r+ obj.r;
    res.i +i + obj.i;
    return res;
    }

   
};
int main (){
      complex a(2,5);
      complex b(3,1);
      complex c;

      c = a + b;
      int d = 5+ 2;
      cout << c.r<< "  + "<< c.i<<"i"<<endl;
      cout << d;
      return 0;

}