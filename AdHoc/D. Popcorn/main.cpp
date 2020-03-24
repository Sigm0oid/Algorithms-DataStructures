#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fact(int x){
ll res=1;
while(x>1){
res*=x;
x--;
}
return res;
}
int main()
{
    freopen("popcorn.in","r",stdin);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    int a,b;
    cin>>a>>b;
    cout<<(fact(a)/(fact(b)*fact(a-b)))<<endl;
    }
    return 0;
}
