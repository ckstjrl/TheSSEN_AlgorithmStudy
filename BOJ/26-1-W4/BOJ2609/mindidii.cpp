#include <iostream>
#include <algorithm>
using namespace std;

int divide(int a,int b){
    if(a%b == 0){ return b; }
    return divide(b, a % b);
}

int main(){
    int a,b,c=0;
    cin >> a >> b;
   
    if(a>=b){ c = divide(a,b); }
    else {c = divide(b,a);}
    
    cout << c <<"\n";
    cout << a*b/c<<"\n";
        
}