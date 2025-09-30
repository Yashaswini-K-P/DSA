#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int val){
           data=val; 
           next=NULL;
        }
};
class List{
    Node* head;
    Node* tail;
    public:
        List(){
            head=tail=NULL;
        }
        void push_front(int val){
            Node* newNode = new Node(val);
            if(head==NULL){
                head=tail=newNode;
            }else{
                newNode->next=head;
                head=newNode;
            }
        }
        void push_back(int val){
            Node* newNode= new Node(val);
            if(head==NULL){
                head=tail=newNode;
            }else{
                tail->next=newNode;
                tail=newNode;
            }
        }
        void pop_front(){
            if(head==NULL){
                cout<<"The list is empty"<<endl;
                return;
            }
                Node* temp=head;
                head=head->next;
                temp->next=NULL;
                delete temp;
        }
        void pop_back(){
            if(head==NULL){
                cout<<"Lst is empty";
                return;
            }
            Node* temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            temp->next=NULL;
            delete tail;
            tail=temp;
        }
        void insert(int val, int pos){
            if(pos<0){
                cout<<"invalid position\n";
                return;
            }
            if(pos==0){
                push_front(val);
                return;
            }
            Node* temp=head;
            for(int i=0; i<pos-1;i++){
                if(temp==NULL){
                    cout<<"invalid position\n";
                    return;
                }
                temp=temp->next;
            }
            Node* newNode=new Node(val);
            newNode->next=temp->next;
            temp->next=newNode;
        }
        int search(int key){
            Node* temp=head;
            int idx=0;
            while(temp!=NULL){
                if(temp->data==key) return idx;
                temp=temp->next;
                idx++;
            }
            return -1;
        }
        void printll(){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
};
int main(){
    List ll;
    ll.pop_front();
    ll.push_front(2);
    ll.pop_front();
    ll.push_back(5);
    ll.push_front(3);
    ll.pop_back();
    ll.push_front(6);
    ll.insert(3, 1);
    cout<<ll.search(6)<<endl;

    ll.printll();
    return 0;
}