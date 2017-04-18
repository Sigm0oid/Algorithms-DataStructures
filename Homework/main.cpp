#include <bits/stdc++.h>

using namespace std;

int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++){
string ch;
cin>>ch;
char cur=0;
int cmp=1;
string res="";
for(int j=1;j<ch.length();j++){
if(ch[j]!=ch[cur]){
     ostringstream ss;
     ss << cmp;
      ss.str();
res=res+ch[cur]+ss.str();
cur=j;
cmp=1;
}
else{
cmp++;
}

}
ostringstream ss;
     ss << cmp;
      ss.str();
res+=ch[cur]+ss.str();
cout<<res<<endl;

}

    return 0;
}
