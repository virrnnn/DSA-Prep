#include<bits/stdc++.h>
using namespace std;

void selection(vector<int>&a){
    int n = a.size();
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        swap(a[i],a[min]);
    }
}

void bubble(vector<int>&a){
    int n = a.size();
    for(int i=0;i<n-1;i++){
        bool iswap=0;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                iswap=1;
                swap(a[j],a[j+1]);
            }
        }
        if(!iswap) return;
    }
}

void insertion(vector<int>&a){
    int n = a.size();
    for(int i=0;i<n-1;i++){
        int j=i+1;
        while(j>0 && a[j]<a[j-1]){
            swap(a[j],a[j-1]);
            j--;
        }
    }
}
void Merge(vector<int>&a,int low,int mid,int high){
    int left = low;
    int right = mid+1;
    vector<int> v;
    while(left<=mid && right<=high){
        if(a[left]<=a[right]){
            v.push_back(a[left]);
            left++;
        }
        else{
            v.push_back(a[right]);
            right++;
        }
    }
    while(left<=mid){
        v.push_back(a[left]);
        left++;
    }
    while(right<=high){
        v.push_back(a[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        a[i] = v[i-low];
    }
}
void MergeSort(vector<int>&a,int low,int high){
    if(low>=high) return;
    int mid = low+(high-low)/2;
    MergeSort(a,low,mid);
    MergeSort(a,mid+1,high);
    Merge(a,low,mid,high);
}
void SortMerge(vector<int>&v){
    MergeSort(v,0,v.size()-1);
}

int main(){
    vector<int> v = {3,5,6,7,43,2,1,1};
    insertion(v);
    for(auto it: v){
        cout<<it<<endl;
    }
}