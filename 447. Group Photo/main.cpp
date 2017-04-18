
#include <bits/stdc++.h>
using namespace std;
int n;
//vector<int> a;
//vector<int> b;
bool check(vector<int> a ,vector<int> b){
for(int i=0;i<n;i++)
if(a[i]!=b[i])
return false;
return true;
}
int min_swap(vector<int> a ,vector<int> b){

if(check(a,b)){
return 0;
}
int res=INT_MAX;
for(int i=0;i<n;i++){
if(a[i]!=b[i]){
    for(int j=0;j<n;j++){
        if(b[j]==a[i]&&a[i]!=a[j]){
            swap(a[i],a[j]);
            res=min(res,1+min_swap(a,b));
            swap(a[i],a[j]);
        }
    }
}

}
return res;


}

int main()
{
    int t;
    cin>>t;
    while(t--){
    vector<int> a,b;

    cin>>n;
    for(int i=0;i<n;i++){
    int x;
    cin>>x;
    a.push_back(x);
    }
    for(int i=0;i<n;i++){
    int x;
    cin>>x;
    b.push_back(x);
    }
    cout<<min_swap(a,b)<<endl;

    }
    return 0;
}
