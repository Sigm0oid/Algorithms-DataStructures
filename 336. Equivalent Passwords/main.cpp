#include <bits/stdc++.h>

using namespace std;
bool kif(vector<string> &t,long long cmp,string test){
bool res=true;
if(t[cmp].length()!=test.length())
{
res=false;
}

else{
string test2=t[cmp];
int diff1=abs(((int)test2[0])-((int)test[0]));
for (int l=1;l<test.length();l++){
int diff2=abs(((int)test2[l])-((int)test[l]));

if(diff1!=diff2)
{res=false;}
}



}
return res;

}
int main()
{
    int k;
cin>>k;
for(int i=0;i<k;i++){

long long n;
cin>>n;
vector<string> t;
for(long long j=0;j<n;j++){
    string ch ;
    cin>>ch;
    t.push_back(ch);

}
long long resultat=0;
bool g=true;
while((t.size()>1)&&(g==true)){
long long old=t.size();
resultat++;
string test=t[0];
long long  cmp=1;
while (cmp<t.size()){
if(kif(t,cmp,test)){
t.erase(t.begin()+cmp);
cmp--;

}
cmp++;
}
if(((t.size()))==old){
g=false;
resultat+=t.size()-1;
}
t.erase(t.begin());


}
if(t.size()==1){resultat++;}
cout<<"Case "<<i+1<<": "<<resultat<<endl;




}
        return 0;
}
