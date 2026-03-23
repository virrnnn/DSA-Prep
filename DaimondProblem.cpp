#include<bits/stdc++.h>
using namespace std;

class baseA{
    public:
        baseA(int a){
            cout<<a<<" Constructor A called:"<<endl;
        }
};
class baseB: virtual public baseA{
    public:
        baseB() : baseA(10){}
};
class baseC: virtual public baseA{
    public:
        baseC() : baseA(20){}
};
class derivedD: public baseB,public baseC{
    public:
        derivedD() : baseA(30){}
};

int main(){
    derivedD a;
}