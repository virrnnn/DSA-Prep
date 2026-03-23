#include<bits/stdc++.h>
using namespace std;

void findalldup(vector <int> &a,int size)
{
    for(int i=0;i<size;i++)
    {
        int idx = abs(a[i]);
        if(a[i]<0){
            cout<<"Duplicate" << idx<<endl;
        }
        else{
            a[i] = -a[i];
        }
    }
}
void alldup(vector <int> &a,int size)
{
    unordered_set<int> seen;
    unordered_set<int> already;
    for(int i=0;i<size;i++)
    {
        if(seen.count(a[i]))
        {
            if(!already.count(a[i]))
            {
                already.insert(a[i]);
                cout<<"duplicate :"<<a[i]<<endl;
            }
        }
        else {
            seen.insert(a[i]);
        }
    }
}

int main(){
    vector<int>vec = {1,2,3,4,2,3,4,5};
    alldup(vec,8);
}