#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    ios::sync_with_stdio(false);
	int T;
	cin >> T ;
	while(T--)
	{
		int n;
		cin >> n ;
		string s ;
		cin >> s ;
		int tab[10]={6,2,5,5,4,5,6,3,7,6};
		ll  res[10]={0};
		ll cmp = 0 ;

		///first make a number with 1111 only
		for (int i=0;i<s.length();i++)
		{
			cmp+=tab[s[i]-'0'] ;
			res[1]++;
			cmp-=2;
		}
        //cout<<cmp<<" i ahave ones "<<res[1]<<endl;
        ///turn 1 to 9 as much as i can
        for( ll i=0;cmp>3&&res[1]>0;i++){
            res[9]++;
            res[1]--;
            cmp-=4;

        }
      //  cout<<" cmp"<<cmp<<endl;

        ///turn the rest to 7 if possible
        for( ll j=0;cmp>0&&res[1]>0;j++){
            res[7]++;
            res[1]--;
            cmp--;
        }

        ///if i still have sticks turn 7 to 8
        for( ll j=0;cmp>3&&res[7]>0;j++){
            res[7]--;
            res[8]++;
            cmp-=4;
        }
        ///turn 7 to 5 as i can

        for( ll k=0;cmp>1&&res[7]>0;k++){
        res[5]++;
        res[7]--;
        cmp-=2;
        }
        ///turn 7 to 4

         for( ll l=0;cmp>0&&res[7]>0;l++){
        res[7]--;
        res[4]++;
        cmp--;
        }


        ///turn 9 to 8 i have no choice

        for(ll  j=0;cmp>0&&res[9]>0;j++){
        res[9]--;
        res[8]++;
        cmp--;
        }



        for(int i=9;i>=0;i--)
        while(res[i]>0){
        cout<<i;
        res[i]--;
        }
        cout<<endl;





		}




	return 0;
}

