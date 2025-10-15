class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n=mat.size();
        stack<int> s;
        for(int i=0; i<n; i++){
            s.push(i);
        }
        int i, j;
        while(s.size()>1){
            i=s.top();
            s.pop();
            j=s.top();
            s.pop();
            if(mat[i][j]==0){
                s.push(i);
            }else{
                s.push(j);
            }
        }
        for(int i=0; i<n; i++){
            if(i!=s.top() && (mat[i][s.top()]==0 || mat[s.top()][i]==1)) return -1;
        }
        return s.top();
    }
};S