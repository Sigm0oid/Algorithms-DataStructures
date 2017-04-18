#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int b;
map<char,int> dict;
map<int,char> dictv;
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>b;
    for(int i=0;i<b;i++){
        char key;
        cin>>key;
        dict[key]=i;
        dictv[i]=key;
    }

   string n1,n2;
   cin>>n1;
   char pp;cin>>pp;
   cin>>n2;
   string res="";
   int r=0;
   for(ll i=0;i<max(n1.length(),n2.length());i++){
       int s=r;
       if((n1.length()-i-1)>=0) s+=dict[n1[n1.length()-i-1]];
       if((n2.length()-i-1)>=0) s+=dict[n2[n2.length()-i-1]];
       res=dictv[s%b]+res;
       r=s/b;

   }
   if(r>0)  res=dictv[r]+res;
    cout<<b<<" ";
    for(int i=0;i<b;i++) cout<<dictv[i]; cout<<endl;
    for(ll i=0;i<((ll)n2.length()-(ll)n1.length());i++) cout<<" ";cout<<" "<<n1<<endl;
    cout<<'+';
    for(ll i=0;i<((ll)n1.length()-(ll)n2.length());i++) cout<<" "; cout<<n2<<endl;
    for(ll i=0;i<max(n2.length()+1,n1.length()+1);i++) cout<<'-';cout<<endl;
    if(res.length()==max(n2.length(),n1.length())) cout<<" ";cout<<res<<endl;
    return 0;
}
