#include <iostream>
#include<vector>
using namespace std;
vector<int> unique(vector<int> nums){
    vector<int> ans;
    for(int i=0; i<=nums.size(); i++){
        for(int j=i; j<=nums.size(); j++){
            if(j!=i){
            if(nums[i]==nums[j]){
                break;
            } else if(j==nums.size()){
                ans.push_back(nums[i]);
            } 
        }
        }
    }
    return ans;
}

vector<int> inter(vector<int> nums1, vector<int> nums2){
    vector<int> section;
    for(int i: nums1){
        for(int j: nums2){
            if(i==j){
                section.push_back(i);
            }
        }
    }
    return section;
}
int main(){
    vector<int> nums1= {7,9,3,4,5,3,5};
    vector<int> nums2= {3,6,4,3,9,10,5,1,1};
    vector<int> uni1 = unique(nums1);
    vector<int> uni2 = unique(nums2);
     for(int i: uni1){
        cout<<i<<" ";
    }
    cout<<endl;
     for(int i: uni2){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int> ans = inter(uni1, uni2);
    for(int i: ans){
        cout<<i<<" ";
    }
    return 0;
}