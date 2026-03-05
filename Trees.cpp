#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void preOrder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void InOrder(Node* root){
    if(root==NULL) return ;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
void postOrder(Node* root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        Node* curr=q.front();
        q.pop();
        if(curr==NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
}

int height(Node* root){
    if(root==NULL) return 0;
    return max(height(root->left),height(root->right))+1;
}

int count(Node* root){
    if(root==NULL) return 0;
    return count(root->left)+count(root->right)+1;
}

int sumOfNodes(Node* root){
    if(root==NULL) return 0;
    return sumOfNodes(root->left)+sumOfNodes(root->right)+root->data;
}

void topView(Node* root){
    queue<pair<Node*, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while(!q.empty()){
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();
        if(m.find(currHD)==m.end()){
            m[currHD]=curr->data;
        }
        if(curr->left!=NULL){
            q.push({curr->left, currHD-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right, currHD+1});
        }
    }
    for(auto i: m){
        cout<<i.second<<" ";
    }
    cout<<endl;
}

void bottomView(Node* root){
    queue<pair<Node*, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while(!q.empty()){
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();
        m[currHD]=curr->data;
        if(curr->left!=NULL){
            q.push({curr->left, currHD-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right, currHD+1});
        }
    }
    for(auto i: m){
        cout<<i.second<<" ";
    }
    cout<<endl;
}

void Kthlevel(Node* root, int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    Kthlevel(root->left, k-1);
    Kthlevel(root->right, k-1);
}

int sumTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);
    root->data+=leftSum +rightSum;
    return root->data;
}

int main(){
    vector<int> preorder={1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root=buildTree(preorder);
    preOrder(root);
    cout<<endl;
    InOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    levelOrder(root);
    cout<<endl;
    cout<<height(root);
    cout<<endl;
    cout<<count(root);
    cout<<endl;
    cout<<sumOfNodes(root)<<endl;
    topView(root);
    bottomView(root);
    Kthlevel(root, 3);
    return 0;
}
