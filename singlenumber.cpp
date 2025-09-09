#include<iostream>
using namespace std;
void unique(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(j!=i){
                if(arr[i]==arr[j]){
                    break;
                } else if(j==size-1){
                    cout<<arr[i]<<" ";
                } 
            } 
        }
    }
}

int main() {
    int arr[]= {7,9,3,4,5,3,5};
    int size =sizeof(arr)/sizeof(int);
    unique(arr, size);
}