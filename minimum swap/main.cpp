// C++ program to find  minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;


int minSwaps(vector<int> v, int n)
{
   int ans=0;
   vector<pair<int,int> > pos;
   for(int i=0;i<n;i++){
    pos.push_back(ii(i,v[i]));
   }
    sort(v.begin(),v.end());


   vector<int> vis;
   vis.assign(n,0);

   for(int i=0;i<n;i++){

    if(vis[i]!=0||pos[i].second==i)
    continue;

    int j=i;
    int cycle=0;
    while(vis[j]==0&&pos[j].second!=j){
        vis[j]=1;
        cycle++;
        j=pos[j].second;
    }
    ans+=(cycle-1);
   }
   return ans;


}

int main()
{
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x-1);
    }
    cout << minSwaps(v, n);
    return 0;
}

