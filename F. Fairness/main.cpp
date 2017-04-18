#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
int tab[100];
int global_current_max=INT_MAX;
int match (int samir,int dwik,int current_max,int pos){
if(pos==n)
    {
    global_current_max=min(global_current_max,current_max);
    return current_max;
    }
if(current_max>=global_current_max)
return global_current_max;

return min(match(samir+tab[pos],dwik,max(current_max,abs(samir+tab[pos]-dwik)),pos+1),match(samir,dwik+tab[pos],max(current_max,abs(samir-(dwik+tab[pos]))) ,pos+1));
}
int main()
{
    //freopen("in.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
    global_current_max=INT_MAX;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&tab[i]);
    int best=match(0,0,0,0);
    printf("%d\n",best);
    }
    return 0;
}
