    #include <bits/stdc++.h>

    using namespace std;
    typedef long long ll;
    typedef pair<int,int> ii;
    typedef pair<double,ii> iii;
    typedef vector<ii> vii;
    int n,m,k;
    ll f;
    double dis[10010][200];
    double prices[10010];
    double global_max=500000;
    double res=500000.0;
    vector<vii> AdjList;
    vii stations;
    int calc_dist(int x,int y,int x1,int y1){
        return(abs(x-x1)+abs(y-y1));
    }

    void dijkstra(){
    if(f>=(m+n-2) ){res=0.0; return;}

    priority_queue<iii,vector<iii>,greater<iii> > pq;
      for (int j = 0; j < (int)AdjList[0].size(); j++) {
                ii v = AdjList[0][j];
                if (calc_dist(1,1,stations[v.first].first,stations[v.first].second) <=f) {
                {
                pq.push(iii(0, ii(f-v.second,v.first)));
               dis[v.first][f-v.second]=0;
                }

            }
            }
        //stations[10001]=ii(n,m);
     while(!pq.empty()){

            iii u = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
            double prix = u.first;
            int  current_f = u.second.first,pos=u.second.second;
            int tmp_f=current_f;
            double tmp_price=prix;
            if(pos==10001)
            {
            //cout<<" im there "<<endl;
            res=min(res,prix);
            continue;
            }
            if(prix>dis[pos][current_f])
             {
              //  cout<<" continue "<<endl;
              continue;  // this is a very important check
             }
               //I can buy another gallon and stay where I am
        if(current_f<f && prix+prices[pos]<dis[pos][current_f+1])
            {
                //cout<<" new prices "<<prices[pos]+prix<<endl;
                dis[pos][current_f+1]=prix+prices[pos];
                pq.push(iii(prix+prices[pos],ii(current_f+1,pos)));
            }


            for (int j = 0; j < (int)AdjList[pos].size(); j++) {
                ii v = AdjList[pos][j];
                 //cout<<" adjc "<<v.first<<" with dis "<<calc_dist(stations[pos].first,stations[pos].second,stations[v.first].first,stations[v.first].second)<<" and f= "<<current_f<<endl;
                if (calc_dist(stations[pos].first,stations[pos].second,stations[v.first].first,stations[v.first].second) <=current_f) {
                    if((dis[v.first][current_f-v.second])>prix)
                    {
                     //   cout<<" new dis to  "<<v.first<<"  from "<<pos<<" equal to "<<prix<<endl;
                        dis[v.first][current_f-v.second]=prix;
                        pq.push(iii(prix,ii(current_f-v.second,v.first)));

                    }

              }
            }
     }
    }




    int main()
    {
       freopen("efficient.in","r",stdin);
        int t;
        cin>>t;
        while(t--){
         res=500000.0;
                double a=500000.0;
                fill_n(&dis[0][0],10010*200,a);
                memset(prices,0,sizeof prices);
                stations.clear();
                AdjList.clear();
                AdjList.resize(10010);
                stations.resize(10010);

               // stat.clear();
                cin>>n>>m>>f>>k;
                stations[10001]=ii(n,m);
                for(int i=1;i<=k;i++){
                    int x,y;
                    double p;
                    cin>>x>>y>>p;
                    prices[i]=p;
                    stations[i]=ii(x,y);
                    if(calc_dist(1,1,x,y)<=f)
                        AdjList[0].push_back(ii(i,calc_dist(1,1,x,y)));
                    if(calc_dist(n,m,x,y)<=f)
                        AdjList[i].push_back(ii(10001,calc_dist(n,m,x,y)));
                    for(int l=i-1;l>=1;l--){
                       if(calc_dist(stations[l].first,stations[l].second,stations[i].first,stations[i].second)<=f)
                        {
                            AdjList[l].push_back(ii(i,calc_dist(stations[l].first,stations[l].second,stations[i].first,stations[i].second)));
                            AdjList[i].push_back(ii(l,calc_dist(stations[l].first,stations[l].second,stations[i].first,stations[i].second)));
                        }
                    }

                }


        dijkstra();
        printf("%.3f\n",res);
        }
        return 0;
    }
