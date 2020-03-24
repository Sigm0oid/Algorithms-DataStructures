#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    int n=5;
    vector<int> tab;
    while(n--){
    int x;
    cin>>x;
    tab.push_back(x);
    }
    sort(tab.begin(),tab.end());
    cout<<(tab[4]*tab[3])<<endl;

    }

    return 0;
}
