#include<bits/stdc++.h>
using namespace std;
//finding duplicate in the an array having values from 1 to n-1
void finddip(int arr[],int size)
{
    int dup=0;
    for(int i=0;i<size;i++)
    {
        dup ^=arr[i];
    }
    for(int i=1;i<size-1;i++)
    {
        dup ^=i;
    }
    cout<<"duplicate element is "<<dup<<endl;
}
//this method is only when one duplicate is there
int main(){

}