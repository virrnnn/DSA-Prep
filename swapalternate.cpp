#include<bits/stdc++.h>

using namespace std;

void swapalternate(int arr[],int s)
{
    for(int i=0;i<s;i+2)
    {
        if(i+1<s)
        {
            swap(arr[i],arr[i+1]);
        }
    }
}

 int main()
 {

 }