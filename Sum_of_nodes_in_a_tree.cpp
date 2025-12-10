#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
static int idx=-1;
Node* buildTree(vector<int> preorder){
    idx++;
    if(preorder[idx]==-1) return NULL;
    Node* root = new Node(preorder[idx]);
    root->left=buildTree(preorder);
    root->right=buildTree(preorder);
    return root;
}
int sumOfNodes(Node* root){
    if(root==NULL) return 0;
    return sumOfNodes(root->left)+sumOfNodes(root->right)+root->data;
}
int main(){
    vector<int> preorder={1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root=buildTree(preorder);
    cout<<sumOfNodes(root);
    return 0;
}
