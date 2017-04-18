#include<bits/stdc++.h>
using namespace std;
void getnumbers(int t[10],long n){
do{
int x=n%10;
//cout<<x<<" ";
if(t[x]==0){
t[x]++;}
n=n/10;
}while(n>0);
//cout<<endl;
}

bool done(int t[10]){
bool b=true;
for(int j=0;j<10;j++){
if(t[j]==0)
{b=false;}
}
return b;}
int main()
{
freopen("A-large.in","r",stdin);
freopen("A-large.out","w",stdout);
int T;
cin>>T;
for(int i=0;i<T;i++){
int p=2;
long long  n;
cin>>n;
long long res=-1;
int t[10]={0};
getnumbers(t,n);
if(done(t)){
res=n;
}
else {
long long aux=n;
while ((p<100)&&(!done(t))){
getnumbers(t,n);
//for(int k=0;k<10;k++){
//cout<<t[k]<<" ";}
//cout<<endl;
if((res==-1)&&(done(t))){
res=n;
}
n=n+aux;
//cout<<n<<endl;
p++;
}}

if(res!=-1){
cout<<"Case #"<<i+1<<": "<<res<<endl;}
else{
cout<<"Case #"<<i+1<<": INSOMNIA"<<endl;}

}
  fclose (stdout);

return 0;}
