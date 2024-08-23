#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,t;
    cin>>n;
    int userId[n],balance[n];
    for(int i=0;i<n;i++){
        cin>>userId[i]>>balance[i];
    }
    cin>>t;
    for(int i=0;i<t;i++){
        int u1,u2,amount;
        cin>>u1>>u2>>amount;
        int user1=0,user2=0;
        for(int j=0;j<n;j++){
            if(userId[j]==u1){
                user1=j;
            }
            else if(userId[j]==u2){
                user2=j;
            }
        }
        if(balance[user1]>=amount){
            balance[user1]=balance[user1]-amount;
            balance[user2]=balance[user2]+amount;
            cout<<"Success"<<endl;
        }
        else{
            cout<<"Failure"<<endl;
        }
    }
    cout<<endl;
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++){
        vec.push_back(make_pair(userId[i],balance[i]));
    }
    sort(vec.begin(),vec.end(),[](const pair<int,int>&a,const pair<int,int>&b){
        return a.second<b.second;
    });
    for(const auto&p:vec){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}
