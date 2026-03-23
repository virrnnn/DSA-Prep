#include<bits/stdc++.h>
using namespace std;

class Shape{   // Abstract class as it has virtual function and its object cannot be instantiated
    public:
    virtual void draw() = 0;
};
class Circle : public Shape{
    public:
    void draw(){
        cout<<"Drwaing Circle"<<endl;
    }
};
class Square : public Shape{
    public:
    void draw(){
        cout<<"Drwaing Square"<<endl;
    }
};

int main(){
    Shape *cir;
    Circle c;
    Square s;
    cir = &c;
    cir->draw();
    cir = &s;
    cir->draw();
    return 0;
}