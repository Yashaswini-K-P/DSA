#include<iostream>
using namespace std;
class CircularQueue{
    int* arr;
    int currsize, cap;
    int f, r;
public:
    CircularQueue(int size){
        cap=size;
        arr =new int[cap];
        currsize=0;
        f=0; r=-1;
    }

    void push(int data){
        if(currsize==cap){
            cout<<"CircularQueue is Full\n";
            return;
        }
        r=(r+1)%cap;
        arr[r]=data;
        currsize++;
    }

    void pop(){
        if(empty()){
            cout<<"CircularQueue is empty\n";
            return;
        }
        f=(f+1)%cap;
        currsize--;
    }

    int front(){
        if(empty()){
            cout<<"CircularQueue is empty\n";
            return -1;
        }
        return arr[f];
    }
    bool empty(){
        return currsize==0;
    }
    void display(){
        for(int i=0; i<cap; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void dispalyorder(){
        int i=f, tcap=0;
        while(tcap!=cap){
            if(i==cap){
                i=0;
                cout<<arr[i]<<"<->";
            }else{
                cout<<arr[i]<<"<->";
            }
            i++;
            tcap++;
        }
    }
};


int main(){
    CircularQueue cq(5);
    cq.push(10);
    cq.push(60);
    cq.pop();
    cq.push(30);
    cq.push(80);
    cq.push(40);
    cq.push(320);
    cq.push(30);
    cq.display();
    cq.dispalyorder();
    return 0;
}