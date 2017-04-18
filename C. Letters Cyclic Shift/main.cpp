#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll ,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;



int main()
{
string s;
cin>>s;
//cout<<s<<endl;
int debut=-1;
int fin=-1;
for(int i=0;i<s.length();i++)
{
    if(s[i]!='a'&&debut==-1){
    debut=i;
    fin=i;
    s[i]=s[i]-1;
    for(int j=i+1;j<s.length();j++)
    if(s[j]!='a')
    {
    fin=j;
    s[j]=s[j]-1;
    }
    else
    break;

    }
}
if(debut==-1)
s[s.length()-1]='z';
cout<<s<<endl;


  return 0;
}
