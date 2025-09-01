#include<iostream>
#include<vector>
using namespace std;
void bubblesort(vector<int> &arr, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
void selectionsort(vector<int> &arr, int n){
    int small;
    for(int i=0; i<n; i++){
        small= i;
        for(int j=i+1; j<n; j++){
            if(arr[small]>arr[j]){
                small = j;
            }
            swap(arr[i], arr[small]);
        }
    }
}
void insertionsort(vector<int> &arr, int n){
    int curr, prev;
    for(int i=1; i<n; i++){
        curr =arr[i];
        prev =i-1;
        while(prev>=0 && curr<arr[prev]){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }
}
int main(){
    vector<int> arr= {4, 7, 1, 9, 13, 8, 1, 24, 15};
    int n=arr.size();
    insertionsort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}