#include<bits/stdc++.h>
using namespace std;
int main()
{
//freopen("A-large.in","r",stdin);
//freopen("A-large.out","w",stdout);
int T;
cin>>T;
for(int i=0;i<T;i++){
string s;
cin>>s;
string befor="",after="";
char c=s[0];
for(int j=1;j<s.length();j++){
if((s[j]>=befor[0])&&(s[j]>=c)){
befor=s[j]+befor;
}
else
{
    after+=s[j];
}
}
cout<<befor+c+after<<endl;
}
return 0;
}
