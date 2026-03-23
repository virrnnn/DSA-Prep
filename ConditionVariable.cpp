#include <bits/stdc++.h>
using namespace std;

mutex m;
condition_variable cv;
queue<int> q;

void consumer(){
    while(true){
        unique_lock<mutex> lock(m);

        cv.wait(lock, [](){ return !q.empty(); });

        int value = q.front();
        q.pop();

        lock.unlock();

        cout << value << endl;
    }
}

void producer(){
    unique_lock<mutex> lock(m);
    static int counter = 0;
    q.push(++counter);
    lock.unlock();
    cv.notify_one();
}

int main(){
    vector<thread> producers;
    vector<thread> consumers;

    for(int i=0;i<10;i++)
        producers.emplace_back(producer);

    for(int i=0;i<10;i++)
        consumers.emplace_back(consumer);

    for(auto &t : producers)
        t.join();

    for(auto &t : consumers)
        t.join();
}