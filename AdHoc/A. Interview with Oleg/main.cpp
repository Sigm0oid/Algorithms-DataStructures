#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n-2;i++){
    if(s[i]=='o'&&s[i+1]=='g'&&s[i+2]=='o'){
    s[i]='*';
    s[i+1]='*';
    s[i+2]='*';
    int j=i+3;
    while(j<n-1&&s[j]=='g'&&s[j+1]=='o'){
//        s.erase(s.begin()+j);
//        s.erase(s.begin()+j+1);
    s[j]='0';
    s[j+1]='0';
    j+=2;
    }
    }
    }
    for(int i=0;i<n;i++)
    if(s[i]!='0')
    cout<<s[i];
    cout<<endl;
    return 0;
}
