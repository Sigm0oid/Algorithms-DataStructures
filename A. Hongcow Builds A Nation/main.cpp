#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
vector<vii> Adjlist;
 vi p, raank, setSize;
 set<int> gouv;
int mat[1010][1010];

int numSets,k,res=0;
int N,m;
int findSet(int i) {
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
     }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
    int x = findSet(i), y = findSet(j);

    if (raank[x] > raank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (raank[x] == raank[y]) raank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }

 bool i_can_add(int i,int j){
 //cout<<" trying to match "<<i<<" "<<j<<endl;
    int gouv1=-1;
    int gouv2=-1;
    if(mat[i][j]==1)
    return false;
    for(auto a:gouv)
    {
        if(isSameSet(a,i))
        gouv1=a;
        if(isSameSet(a,j))
        gouv2=a;
        if(gouv1!=-1&&gouv2!=-1)
        break;
    }
    return (gouv1==-1||gouv2==-1||gouv1==gouv2);

 }

int main()
{
    freopen("in.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin>>N>>m>>k;
    memset(mat,0,sizeof mat);
    setSize.assign(N, 1); numSets = N; raank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
     for(int i=0;i<k;i++){
        int x;
        cin>>x;
        x--;
        gouv.insert(x);
    }

    while(m--){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    mat[a][b]=1;
    mat[b][a]=1;
    unionSet(a,b);
    }


    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(gouv.find(i)==gouv.end()||gouv.find(j)==gouv.end())
            if(i_can_add(i,j))
            {

                res++;
                unionSet(i,j);
                mat[i][j]=mat[j][i]=1;
            }

        }
    }
    cout<<res<<endl;
    return 0;
}

