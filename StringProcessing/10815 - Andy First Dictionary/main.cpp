#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
map<string,int> dict;
string s;
string  make_normale(string s){

string s1="";
for(int i=0;i<s.length();i++){
if(isalpha(s[i])){
s1+=tolower(s[i]);
}
}
//cout<<s<<" "<<s1<<endl;
return s1;
}
int main()
{
freopen("in.in","r",stdin);
freopen("out.out","w",stdout);
while(cin>>s){
string s1="";
for(int i=0;i<s.length();i++){
if(isalpha(s[i])){
s1+=s[i];


}

else{
s1=make_normale(s1);
if(s1.length()>0){
dict[s1]++;
}
s1="";
}
}

s1=make_normale(s1);
if(s1.length()>0){
dict[s1]++;
}
s1="";
}
vector<string> res;
for(map<string,int>::iterator it=dict.begin();it!=dict.end();it++){
res.push_back(it->first);
}
sort(res.begin(),res.end());
for(int i=0;i<res.size();i++){
cout<<res[i]<<endl;
}
    return 0;
}
