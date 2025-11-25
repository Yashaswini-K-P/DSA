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
class Circularlist{
    Node* head;
    Node* tail;
    public:
        Circularlist(){
            head=tail=NULL;
        }
        void push_front(int val){
            Node* newNode = new Node(val);
            if(head==NULL){
                head=tail=newNode;
                tail->next=head;
            }else{
                newNode->next=head;
                head=newNode;
                tail->next=head;
            }
        }
        void push_back(int val){
            Node* newNode= new Node(val);
            if(head==NULL){
                head=tail=newNode;
                tail->next = head;
            }else{
                newNode->next=tail;
                tail->next=newNode;
                tail=newNode;
            }
        }
        void pop_front(){
            if(head==NULL) return;
             else if(head==tail){
                delete head;
                head=tail=NULL;
             }else{
                Node* temp=head;
                head=head->next;
                tail->next=head;
                temp->next=NULL;
                delete temp;
             }
        }
        void pop_back(){
            if(head==NULL) return;
            else if(head==tail){
                delete tail;
                head=tail=NULL;
            }else{
                Node* temp=tail;
                Node* prev=head;
                while(prev->next!=tail){
                    prev=prev->next;
                }
                tail=prev;
                tail->next=head;
                temp->next=NULL;
                delete temp;
            }
        }
        void print(){
            if(head==NULL) return;
            cout<<head->data<<"->";
            Node* temp=head->next;
            while(temp!=head){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<temp->data<<endl;
        }
};
int main(){
    Circularlist cll;
    cll.pop_front();
    cll.push_front(2);
    cll.pop_front();
    cll.push_back(5);
    cll.push_front(3);
    cll.pop_back();
    cll.push_front(6);
    
    cll.print();
    return 0;
}