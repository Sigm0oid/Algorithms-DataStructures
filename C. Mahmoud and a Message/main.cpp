#include <iostream>
#include <string.h>
using namespace std;
#define mod 1000000007
string s;
int arr[26],dp[1005],dp2[1005];
int main()
{
	int n,l=0;
	cin >> n >> s;
	for (int i=0;i<26;i++)
	cin >> arr[i];
	dp[0]=1;
	dp2[0]=0;
	for (int i=1;i<=n;i++)
	{
	cout<<" i= "<<i<<endl;
		int f=0;
		dp2[i]=n;
		for (int x=i-1;x>=0;x--)
		{
			f=max(f,i-arr[s[x]-'a']);
			if (f>x){
			cout<<" f="<<f<<" and x="<<x<<" so continue "<<endl;
			continue;
			}
			dp[i]=(dp[i]+dp[x])%mod;
			cout<<" dp["<<i<<"]="<<dp[i]<<endl;

			dp2[i]=min(dp2[i],1+dp2[x]);
			cout<<" dp2["<<i<<"]="<<dp2[i]<<endl;
			l=max(l,i-x);
			cout<<"l= "<<l<<endl;
		}
	}
	cout << dp[n] << endl << l << endl << dp2[n] << endl;
}
