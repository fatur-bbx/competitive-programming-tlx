#include <iostream>
using namespace std;
int main()
{
    int p,q;
    cin>>p>>q;
    int calc=(p*p+q*q+1);
    if(calc%4 == 0){
        calc=calc/4;
    }else{
        calc=-1;
    }
    cout<<calc;
}