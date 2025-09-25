#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &a, int m, vector<int> &b, int n){
    int idx=m-1, i=m-n-1, j=n-1;
    while(i>=0 && j>=0){
        if(a[i]>=b[j]){
            a[idx--]=a[i--];
        } else {
            a[idx--]=b[j--];
        }
    }
    while(j>=0){
        a[idx--]=b[j--];
    }
}
int main(){
    vector<int> a={2, 3, 7, 13, 14, 0, 0, 0, 0, 0};
    vector<int> b={4, 8, 10, 15, 18};
    int m= a.size(); 
    int n= b.size();
    merge(a, m, b, n);
    for(int i: a){
        cout<<i<<" ";
    }
    return 0;
}