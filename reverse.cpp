#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int> &a,int n)
{
    int i=0,j=n-1;
    while(i<j){
        a[i]=a[i]+a[j];
        a[j]=a[i]-a[j];
        a[i]=a[i]-a[j];
        i++;
        j--;
    }
}

int main(){
    vector<int>vec={1,4,6,7,8,3};
    reverse(vec,6);
    for(int i=0;i<6;i++){
        cout<<vec[i]<<endl;
    }
}