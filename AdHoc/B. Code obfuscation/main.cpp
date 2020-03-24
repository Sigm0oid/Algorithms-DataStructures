#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int cmp=0;
    bool found =false;
    for(int i=0;i<s.length();i++){
    if((s[i]-'a')>cmp)
    {
        found=true;
        break;
    }
    else if((s[i]-'a')==cmp){
    cmp++;
    }
    }
    if(found)
    cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;

    return 0;
}
