// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std; 
template <typename T>
class functor{
    public:
        bool operator()(T a, T b){
            return a<b;
        }
};

int main() {
    vector<int>v = {2,5,7,45,3,0};
    sort(v.begin(),v.end(),functor<int>());
    for(auto &it : v){
        cout<<it<<endl;
    }
    cout<<"------------------------------"<<endl;
    sort(v.begin(),v.end(),[](int a,int b){ return a>b;});
    for(auto &it : v){
        cout<<it<<endl;
    }
}