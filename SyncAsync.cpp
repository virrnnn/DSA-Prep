#include <bits/stdc++.h>
using namespace std;
int compute() {
    cout<<this_thread::get_id()<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    return 42;
}

int main() {
    cout<<this_thread::get_id()<<endl;
    auto result = async(compute);//auto here is future<int> 
    cout << result.get();
    return 0;
}