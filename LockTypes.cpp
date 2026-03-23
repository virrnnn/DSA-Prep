#include<bits/stdc++.h>
using namespace std;
//unique_lock
//lock Guard
//shared lock
//spin lock - it is a custom lock which does not go to sleep and it keeps on checking until the lock is freed
int a=0;
mutex m;
void readfunc(){
    shared_lock<mutex> lock(m);//shared_lock
    cout<<a<<endl;
}
void writefunc(){
    unique_lock<mutex> lock(m);//unique_lock
    //lock_guard<mutex> lock(m);//lock_guard
    a=50;
    lock.unlock();
}
int main(){
    thread t2(writefunc);
    vector<thread> vec;
    for(int i=0;i<100;i++)
        vec.push_back(thread(readfunc));
    for(int i=0;i<100;i++)
        vec[i].join();
    t2.join();
}