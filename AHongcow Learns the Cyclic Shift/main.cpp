#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    map<string,int> dict;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
    dict[s.substr(i+1,s.size()-i-1)+s.substr(0,i+1)]++;
    //cout<<s.substr(i+1,s.size()-i-1)+s.substr(0,i+1)<<endl;
    }cout<<dict.size()<<endl;

    return 0;
}
