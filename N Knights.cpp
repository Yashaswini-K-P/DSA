#include<iostream>
#include<vector>
using namespace std;
bool issafe(int n, int row, int col, vector<string>& path){
    int r[]={1, 2, -1, -2, 1, 2, -1, -2};
    int c[]={2, 1, -2, -1, -2, -1, 2, 1};

    for(int i=0; i<8; i++){
        int nr=row+r[i];
        int nc=col+c[i];
        if(nr>=0 && nc>=0 && nr<n && nc<n && path[nr][nc]=='.') return true;
    }
    return false;
}
void helper(int n, int row, vector<string>& path, vector<vector<string>>& ans){
    if(row==n){
        ans.push_back(path);
    }
    for(int i=0; i<n; i++){
        if (issafe(n, row, i, path)){
            path[row][i]='K';
            helper(n, row+1, path, ans);
            path[row][i]='.';
        }
    }
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<vector<string>> ans;
    vector<string> path(n, string(n, '.'));
    helper(n, 0, path, ans);
    for(vector<string> s: ans){
        for(string m: s){
            cout<<m<<" ";
        }
        cout<<endl;
    }
    return 0;
}
