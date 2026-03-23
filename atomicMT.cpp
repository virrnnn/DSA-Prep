#include<bits/stdc++.h>
using namespace std;

atomic<int> counter;

void func(){
    cout<<counter++<<endl;
}

int main(){
    thread t1(func);
    thread t2(func);

    t1.join();
    t2.join();
}