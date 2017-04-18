#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1;string s2;
    cin>>s1>>s2;
    bool possible=true;
    int dict[26];
    int cmp=0;
    memset(dict,-1,sizeof dict);
    for(int i=0;i<s1.length();i++)
    {

             if(dict[s1[i]-'a']==-1&&dict[s2[i]-'a']==-1){
             dict[s1[i]-'a']=(s2[i]-'a');
             dict[s2[i]-'a']=(s1[i]-'a');

             if(s1[i]!=s2[i])
             cmp++;
             }
             else{
             if(dict[s1[i]-'a']!=(s2[i]-'a')||dict[s2[i]-'a']!=(s1[i]-'a'))
             {
                possible=false;
                break;
             }
             }


    }
    if(possible==false)
    cout<<"-1"<<endl;
    else if(cmp==0)
    cout<<"0"<<endl;
    else{
    cout<<cmp<<endl;
    for(int i=0;i<26;i++){
    if(dict[i]!=-1&&dict[i]!=i){
    cout<<(char)('a'+i)<<" "<<(char)('a'+dict[i])<<endl;;
    dict[dict[i]]=-1;
    }
    }
    }
    return 0;
}
