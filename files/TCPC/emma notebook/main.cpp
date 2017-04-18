#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin >> t;
    int pas=2;
    long long  res=1;
    bool two=true;
    for(long long  i=1;i<t;i++){
    res+=pas;
    two=!two;
    if(two==true){
    pas+=1;}
    //cout<<res<<endl;

        }
    cout<<res<<endl;
     return 0;
}
