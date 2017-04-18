#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int n,q;
    cin>>n>>q;
    int servers[n]={0};

    for(int i=0;i<q;i++){
    int servers_unoccupied=0;
    int ti,ki,di;
    cin>>ti>>ki>>di;

    for(int k=0;k<n;k++){
    if(servers[k]<ti){
    servers_unoccupied++;
    }
    }

    //cout<<" servers disp "<<servers_unoccupied<<endl;
    if(servers_unoccupied>=ki){
        ll res=0;
        int cmp=0;
        for(int j=0;j<n&&cmp<ki;j++){
        if(servers[j]<ti){
        cmp++;
        servers[j]=(ti+di-1);
        res+=j+1;
        }
        }
        cout<<res<<endl;
    }
    else{
    cout<<"-1"<<endl;
    }

    }
    return 0;
}
