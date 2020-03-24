#include <bits/stdc++.h>

using namespace std;
string s;
int print(int wheelpos ,int pos,int cmp){
if(pos>s.length())
{
    return 0;
}
else{

if((s[pos]-'a')>wheelpos){
//cout<<s[pos]<<" greater than "<<char('a'+wheelpos)<<endl;
return cmp+min(print((s[pos]-'a'),pos+1,(s[pos]-'a')-wheelpos),print(s[pos]-'a',pos+1,abs(wheelpos-(s[pos]-'a')+26)));
}
else{

return cmp+min(print(s[pos]-'a',pos+1,wheelpos-(s[pos]-'a')),print(s[pos]-'a',pos+1,abs((s[pos]-'a')-wheelpos+26)));
}
}
}
int main()
{

    cin>>s;
    int cmp=0;
    //cout<<print(0,0,0);
    int wheelpos=0;
    for(int pos=0;pos<s.length();pos++){
    if((s[pos]-'a')>wheelpos){
    //cout<<s[pos]<<" greater than "<<char('a'+wheelpos)<<endl;
     cmp+=min((s[pos]-'a')-wheelpos,abs(wheelpos-(s[pos]-'a')+26));
    }
    else{

     cmp+=min(wheelpos-(s[pos]-'a'),abs((s[pos]-'a')-wheelpos+26));
    }
    wheelpos=s[pos]-'a';

    }
    cout<<cmp<<endl;
    return 0;
}
