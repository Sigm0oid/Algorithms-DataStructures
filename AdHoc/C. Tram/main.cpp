#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int s,from,to,train_pos,t1,t2,direction,x1,x2;
    cin>>s>>x1>>x2;
    cin>>t1>>t2;
    cin>>train_pos>>direction;
    int sense;
    if(x1>x2){
    sense=-1;
    }
    else{
    sense=1;}
    ll res=0;
    while(x1!=x2){
    int target;
    if(sense==-1)
    target=(x1-1);
    else
    target=x1+1;
    int time_train_to_me,time_with_train;
    if(direction==-1&&train_pos<x1||direction==1&&train_pos>x1){
    time_train_to_me=((s-abs(x1-train_pos))*t1);
    direction=(direction*-1);
    }
    else{
    time_train_to_me=((abs(x1-train_pos))*t1);
    }

    if(direction==-1&&train_pos<x2||direction==1&&train_pos>x2){
    time_with_train=((s-abs(x2-train_pos))*t1);
    direction*=-1;
    }
    else{
    time_with_train=((abs(x2-train_pos))*t1);
    }
    res+=min(abs(target-x1)*t2,time_train_to_me+time_with_train);
    x1=target;
    }
    cout<<res<<endl;

    return 0;
}
