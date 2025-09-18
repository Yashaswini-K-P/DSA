#include<iostream>
#include<string>
using namespace std;
bool pali(string s1, string s2){
    if(s1.length()==s2.length()){
        for(int i=0; i<s1.length(); i++){
            if(s1[i]!=s2[i]){
                return false;
            } 
        }
        return true;
    }
    return false;
}
int main(){
    string s1= "Yashu";
    string s2= "Yashu";
    if(pali(s1, s2)){
        cout<<"Yes"<<endl;
    } else{
        cout<<"No"<<endl;
    }
    return 0;
}