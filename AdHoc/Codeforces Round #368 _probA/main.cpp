#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000


int main()
{
    std::ios::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    int cnt=0;
    for(int i=0;i<n;i++){
                for(int i=0;i<m;i++){
                char x;
                cin>>x;
                if((x!='W')&&(x!='B')&&(x!='G')){
                    cnt++;
                    }
                }
    }
    if(cnt>0){
        cout<<"#Color"<<endl;
    }
    else{
            cout<<"#Black&White"<<endl;

    }
          return 0;
}
