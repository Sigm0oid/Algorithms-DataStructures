#include <bits/stdc++.h>

using namespace std;

int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++){
string ch1,ch2;
cin>>ch1>>ch2;

//if(ch1.length()>ch2.length()){
//string perm=ch1;
//ch1=ch2;
//ch2=perm;}
long long  res=0;
for(int j=0;j<ch1.length();j++){
//cout<<ch1<<" "<<ch2<<endl;
bool found=false;
for(int k=0;k<ch2.length();k++){
//cout<<((ch2[k]==ch1[j])&&(found==false))<<endl;
if((ch2[k]==ch1[j])&&(found==false)){
found=true;
ch2[k]='?';
}
}
//cout<<found<<endl;
if(found==false){
res++;
}
//cout<<ch1<<" "<<ch2<<endl;

}
res+=ch2.length();
for(int j=0;j<ch2.length();j++){
if(ch2[j]=='?')
res--;}
cout<<res<<endl;

}    return 0;
}
