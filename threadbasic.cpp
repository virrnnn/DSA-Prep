#include<bits/stdc++.h>
using namespace std;

mutex m;
int n=10000;
void func(){
    lock_guard<mutex> lock(m);
    while(n){  // N IS CRITICAL As it can be accessed by any thread so it comes under crtical section 
        cout<<n--<<","; // Critical section 
    }
}

int main(){
thread t1(func);
thread t2(func);
t1.join();
t2.join();
//t1.detach();
}