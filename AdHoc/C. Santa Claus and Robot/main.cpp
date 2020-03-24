#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
//map<ii,int> points;
bool shortest_path(int x1,int y1,int x2,int y2,int current){
return((abs(x1-x2)+abs(y1-y2))==current);
}
int main()
{
        ll n;
        cin>>n;
        int current_x=0,current_y=0;
        int current=0;
        int x=0,y=0;
        int tmp_x=0,tmp_y=0;
        ll res=0;
        string s;
        cin>>s;
        for(ll i=0;i<n;i++){
        current++;
        char c;
        c=s[i];
        tmp_x=x;
        tmp_y=y;
        if(c=='R'){
        x+=1;
        }
        if(c=='L'){
        x-=1;
        }
        if(c=='U'){
        y+=1;
        }
        if(c=='D'){
        y-=1;
        }
        if(!shortest_path(0,0,x,y,current)){
        res++;
        x=0;y=0;
        current=0;
        i--;
        }



        }
        cout<<res+1<<endl;

    return 0;
}
