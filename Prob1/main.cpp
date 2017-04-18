#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
vector<vector<vector<ii> > > Adjlist;
vector<string> strings;
ll n,q;
int main()
{
	//freopen("apersonal.in","r",stdin) ;
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){

    cin>>n;
    Adjlist.clear();
    Adjlist.resize(n);
    strings.clear();
    for(ll i=0;i<n;i++){
				string s;
				cin>>s;
				strings.push_back(s);
				Adjlist[i].resize(26);
                for(ll  j=0;j<s.length();j++){
                    Adjlist[i][s[j]-'a'].push_back(ii(j,1));
                }
		}
	cin>>q;
	while(q--){
	ll res=0;
	ll a,b;
	string sb;
	cin>>a>>b>>sb;
	a--;
	b--;
    for(ll i=a;i<=b;i++){
        for(ll j=0;j<Adjlist[i][sb[0]-'a'].size();j++){
                ii v=Adjlist[i][sb[0]-'a'][j];
                ll k;
        for( k=0;k<sb.length()&& k+v.first<strings[i].length()&&sb[k]==strings[i][v.first+k];k++);
                if(k==sb.length())
                res++;

			}
    }
    cout<<res<<endl;}


	}


     return 0;
}
