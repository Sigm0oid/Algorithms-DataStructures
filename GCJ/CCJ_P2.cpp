#include<bits/stdc++.h>
using namespace std;


int main()
{
freopen("B-large.in","r",stdin);
freopen("B-large.out","w",stdout);
int T;
cin>>T;
for(int i=0;i<T;i++){
string s;
int nbr=1;
cin>>s;

char c=s[0];
for(int j=1;j<s.length();j++){
if (c!=s[j]){
c=s[j];
nbr++;}
}
if(s[s.length()-1]=='+'){
nbr--;}
//if(s[0]=='+'){
//nbr++;}

//while(notset(s)){
//int nbr_permut=0;
//}


cout<<"Case #"<<i+1<<": "<<nbr<<endl;
}


return 0;}
