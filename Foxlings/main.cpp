#include <bits/stdc++.h>

using namespace std;
typedef unordered_map<int,int> vi;
vi parent,rang;

int findset(int i){
return (parent[i] == i) ? i : (parent[i] = findset(parent[i]));
}

bool sameset(int i,int j){
return(findset(i)==findset(j));
}

void unionset(int i,int j){
int x=findset(i);
int y=findset(j);

//if(rang[x]>rang[y])
//parent[y]=x;
//else
//{
parent[y]=x;
//if (rang[x]==rang[y])
//rang[y]++;
//}




}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
//    parent.assign(n,0);
//    rang.assign(n,0);
//    for(int  i=0;i<n;i++)
//    {
//    parent[i]=i;
//    }
    int a,b;
    for(int i=0;i<m;i++){
    scanf("%d %d",&a,&b);
    a--;b--;
    if(parent.find(a)==parent.end())
    parent[a]=a;
    if(parent.find(b)==parent.end())
    parent[b]=b;

    if(!sameset(a,b)){
    n--;
    unionset(a,b);
    }
    if(n==1)
    break;

    }
    printf("%d\n",n);

    return 0;
}
