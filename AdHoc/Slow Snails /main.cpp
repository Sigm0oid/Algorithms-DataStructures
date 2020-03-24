#include <bits/stdc++.h>

using namespace std;

int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++){
int n;
int h;
float pi;
cin>>pi;
cout<<setprecision(4)<<pi<<endl;
cin>>n>>h;
int res=0;
if(n==1){
res=0;}
else{
if(n%2==0){
float a=(2*n);
float b=(1/a);
float x=(h-b);
res++;
//cout<<res<<endl;
a=(float)1/n;
b=x/a;
//cout<<b<<endl;
res+=b;
//cout<<res<<endl;
res*=n/2;
}
else{
float a=(2*n);
float b=(1/a);
float x=(h-2*b);
res=2;
//cout<<x<<endl;
a=(float)1/n;
b=x/a;
res+=b;
//cout<<res<<endl;
res*=n/2;
}
}
cout<<0<<" "<<res<<endl;


}



    return 0;
}
