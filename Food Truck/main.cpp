#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef pair<ll,string> is;
typedef pair<double,double> dd;
typedef pair<ii,ii> iii;
typedef pair<is,dd> idd;
typedef pair<iii,idd> iiii;
vector<iiii> Edgelist;


map<string,int> dict;
static double d2r(double d) {
  return (d / 180.0) * ((double) M_PI);
}
int main()
{
    freopen("out.out","w",stdout);
    freopen("in.in","r",stdin);
    string s;
    getline(cin,s);
    stringstream ss;
    ss.str(s);
    string token;
    vector<string> v;
    while(getline(ss,token,',')){
    v.push_back(token);

    }

    double lat=atof(v[0].c_str());
    double lont=atof(v[1].c_str());
    double r;cin>>r;
    getline(cin,s);
    getline(cin,s);
    string date,others;
    while(cin>>date&&date.length()>0){
    cin>>others;
    //cyt date
    stringstream ss;
    ss.str(date);
    string token;
    vector<string> v;
    while(getline(ss,token,'/')){
    v.push_back(token);

    }
    int day=atoi(v[1].c_str());
    int mounth=atoi(v[0].c_str());
    int anne=atoi(v[2].c_str());
    string hrs ="";
    hrs+=others[0];
    hrs+=others[1];

    string mints="";
    mints+=others[3];
    mints+=others[4];
    int hour=atoi(hrs.c_str());
    int minuts=atoi(mints.c_str());
    ss.clear();
    ss.str(others);
    v.clear();
    while(getline(ss,token,',')){
    v.push_back(token);

    }
    double lat1=atof(v[1].c_str());
    double lont1=atof(v[2].c_str());
    string num=v[3];
    Edgelist.push_back(make_pair(iii(ii(anne,mounth),ii(day,hour)),idd(is(minuts,num),dd(lat1,lont1))));
    //cout<<v[1].c_str()<<" "<<lat1<<endl;
    }
    vector<string> res;

    sort(Edgelist.begin(),Edgelist.end());

    for(int i=Edgelist.size()-1;i>=0;i--){
    double lat1=Edgelist[i].second.second.first;
    double lont1=Edgelist[i].second.second.second;
    string num=Edgelist[i].second.first.second;
    //double d=2*6378.137*asin(sqrt(pow(d2r(sin((lat-lat1)/2)),2)+d2r(cos(lat))*d2r(cos(lat1))*pow(d2r(sin((lont-lont1)/2)),2)));
    //cout<<d<<endl;
    double d=2*6378.137*asin(sqrt(pow(sin(d2r((lat-lat1)/2)),2)+cos(d2r(lat))*cos(d2r(lat1))*pow(sin(d2r((lont-lont1)/2)),2)));


    if(dict.count(num)==0){
    if(d<=r){
    dict[num]=1;
    }
    else{
     dict[num]=-1;
    }
     }


    }  for(map<string,int>::iterator i=dict.begin();i!=dict.end();i++){
    if(i->second==1)
    res.push_back(i->first);

    }


    sort(res.begin(),res.end());
    for(ll i=0;i<res.size();i++){
    cout<<res[i];
    if(i!=res.size()-1)cout<<',';
    }
    cout<<endl;


    return 0;
}
