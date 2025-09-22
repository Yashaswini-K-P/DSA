#include<iostream>
#include<vector>
using namespace std;
void bubblesort(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        bool isswap=false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                isswap=true;
            }
        }
        if(!isswap){
            return;
        }
    }
}
int main(){
    int c=3;
    vector<int> arr={1, 2, 8, 4, 9};
    int n= arr.size();
    bubblesort(arr, n);
    for(int i: arr){
        cout<<i<<" ";
    }
    return 0;
}