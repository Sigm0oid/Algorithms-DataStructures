#include <bits/stdc++.h>

using namespace std;
int killed[200010];
int n;
string s;
bool check(){
int nbd=0,nbr=0;
for(int i=0;i<n;i++){
    if(killed[i])
    continue;

    if(s[i]=='D')
    nbd++;
    else
    nbr++;
    if(nbr&&nbd) return 1;

}
return 0;
}
int main()
{
    memset(killed,0,sizeof killed);

    cin>>n;

    cin>>s;
    priority_queue<int,vector<int>,greater<int> > R,D;

    for(int i=0;i<n;i++){
    if(s[i]=='D'){
    D.push(i);
    }
    else{
    R.push(i);

    }
    }
    while(!R.empty()&&!D.empty()){
    int frontd=D.top();
    D.pop();
    int frontr=R.top();
    R.pop();
    if(frontd<frontr)
        D.push(n+frontd);
        else
        R.push(n+frontr);

    }


    if(R.empty())
    cout<<"D"<<endl;
    else
    cout<<"R"<<endl;

    return 0;
}
