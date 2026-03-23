#include<bits/stdc++.h>
using namespace std;

mutex m;

void helloworld(){
    lock_guard<mutex> lock(m);
    cout<<"Worker Thread ID : "<<this_thread::get_id()<<endl;
}

int main(){
    cout<<"Thread ID : "<<this_thread::get_id()<<endl;
    cout<<"Thread available at hardware level(This gives number of cores available (approx).) : "<<thread::hardware_concurrency()<<endl;
    vector<thread> vec;
    for(int i=0;i<5;i++){
        vec.push_back(thread(helloworld));
    }
    for(int i=0;i<5;i++){
        vec[i].join();
    }
    //thread t1(helloworld);
    //t1.join();
    return 0;
}