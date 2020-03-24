#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s1,s2;
    cin>>s1>>s2;
    cin>>n;
    cout<<s1<<" "<<s2<<endl;
    while(n--){
    string a,b;
    cin>>a>>b;
    if(a==s1)
    s1=b;
    else
    s2=b;
    cout<<s1<<" "<<s2<<endl;


    }
    return 0;
}
