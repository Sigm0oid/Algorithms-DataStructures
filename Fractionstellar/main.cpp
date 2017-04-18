#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
   ll a,b,c,d;
   cin>>a>>b>>c>>d;
   cout<<"1/"<<ppcm(b,d)<<" 1/"<<pgcd(b,c)<<endl;
    return 0;
}
