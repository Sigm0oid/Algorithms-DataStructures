#include <bits/stdc++.h>

using namespace std;
int pgcd(int a,int b){
while((a*b)!=0){
if(a>b)
{a=(a-b);}
else{b=(b-a);}
}
if(a==0){return b;}
else
 return (a);
}

int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        int x=pgcd(a,b);
        cout<<x<<" "<<((a/x)*(b/x))<<endl;

    }
    return 0;
}
