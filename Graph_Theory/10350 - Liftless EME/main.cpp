    #include <bits/stdc++.h>

    using namespace std;
    typedef long long ll;
    typedef pair<int,int> ii;
    typedef vector<ii> vii;
    typedef vector <int> vi;
    vector<vii> Adjlist;
    vi dis,vis;
    int n,m;
    void dijkstra(int src){
    vis[src]=1;
    dis[src]=0;

    priority_queue <ii,vector<ii>,greater<ii> > pq;
    pq.push(ii(0,src));
    while(!pq.empty()){

        ii v=pq.top();
        pq.pop();
        int x=v.second;
        int d=v.first;
        if(d>dis[x])
            continue;
        for(int i=0;i<Adjlist[x].size();i++){

        ii v=Adjlist[x][i];
        if(dis[v.first]>dis[x]+v.second){

        dis[v.first]=dis[x]+v.second;
        //cout<<"Updated "<<dis[v.first]<<endl;
        pq.push(ii(dis[v.first],v.first));
        }
        }
    }

    }

    int main()

    {
        //freopen("in.in","r",stdin);
        string name;
        while(cin>>name&&name.length()>0){

        cin>>n>>m;
        int nbholes=((n-1)*m);
        Adjlist.clear();
        Adjlist.resize((n*m)+2);
        dis.clear();
        dis.assign((n*m)+2,10000000);
        vis.clear();
        vis.resize((n*m)+2);

        for(int i=0;i<m;i++){
        Adjlist[0].push_back(ii(0+i+1,0));
        Adjlist[m*(n-1)+i+1].push_back(ii(n*m+1,0));

        }

        for(int i=0;i<((n-1));i++){
        for(int j=0;j<m;j++){
        for(int k=0;k<m;k++){
        int a;
        cin>>a;
        Adjlist[i*m+j+1].push_back(ii(i*m+m+k+1,a+2));
        //  cout<<" edge from "<<i+i+j<<" to "<<((i+i+m+k))<<" cost "<<a<<endl;
        }
        }

        }
        dijkstra(0);
        int res=dis[n*m+1];

    //    for(int i=0;i<n*m+2;i++){
    //    cout<<dis[i]<<" ";}
    //    cout<<endl;
        cout<<name<<endl;
        cout<<res<<endl;


        }
        return 0;
    }

