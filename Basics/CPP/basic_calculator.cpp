#include <iostream>
using namespace std;

 int main(){ 
    int choice=0,a=0,b=0;
    cout<<"pick an option : \n1. Add\n2. substract\n3. multiply\n4. divide\n5. Quit\n";
    cin>>choice;
    cout<<"Enter the two numbers";
    cin>>a>>b;
    switch(choice)
    {
        case 1: cout<<"the addition is "<<(a+b);
        break;
        case 2: cout<<"the sub is "<<(a-b);
        break;
        case 3:cout<<"the multi is "<<(a*b);
        break;
        case 4:cout<<"the division"<<(a/b);
        break;
        case 5: exit(0);
        break;
        default : cout<< "invalid choice";
    }
}