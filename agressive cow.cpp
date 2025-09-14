#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ispossible(vector<int> &arr, int n, int c, int di){
    int cows=1, fp=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]-fp>=di){
            cows++;
            fp=arr[i];
        }
        if(cows>=c){
            return true;
        }
    }
    return false;
}
int getdistance(vector<int> &arr, int n, int c){
    int st=0, end=arr[n-1]-arr[0], mid, ans=-1;
    while(st<=end){
        mid= st+(end-st)/2;
        if(ispossible(arr, n, c, mid)){
            ans=mid;
            st=mid+1;
        }else {
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    int c=3;
    vector<int> arr={1, 2, 8, 4, 9};
    int n= arr.size();
    sort(arr.begin(), arr.end());
    cout<<getdistance(arr, n, c)<<endl;
    return 0;
}