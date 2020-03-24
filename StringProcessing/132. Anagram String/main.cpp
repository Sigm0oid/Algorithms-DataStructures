#include <bits//stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
    vector<int> tab1(26);
    vector<int> tab2(26);
    string ch1,ch2;
    cin>>ch1>>ch2;
    for(int i=0;i<ch1.length();i++){
    tab1[ch1[i]-'a']++;
    }
    for(int i=0;i<ch2.length();i++){
    tab2[ch2[i]-'a']++;
    }
    long long res=0;
    for(int i=0;i<26;i++){
    res+=abs(tab1[i]-tab2[i]);
    }
    cout<<res<<endl;
    }
    return 0;
}
