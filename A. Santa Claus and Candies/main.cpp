#include <bits/stdc++.h>

using namespace std;
int k=0;
vector<int> res;
void divide(int current,int n){
if((n-current)<=current){
    res.push_back(n);
    return ;

}
else{
    res.push_back(current);
    divide(current+1,n-current);

}



}

int main()
{
    int n ;
    cin>>n;
    divide(1,n);
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
