#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<int> vi;


vector <vii> Adjlist;
vector<string> buvrette;
int getindex(string s){
int i=0;
//cout<<buvrette.size();
while(i<buvrette.size()){
  //  cout<<s.compare(buvrette[i])<<endl;
    if(s.compare(buvrette[i])==0){
        return i;
    }
    i++;
}
}

int main()
{
    int cmp=1;
   // freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int t;

while( cin>>t){


        Adjlist.clear();
        buvrette.clear();

        Adjlist.resize(t);
        buvrette.resize(t);
        vector<int> incom(t);
    for(int i=0;i<t;i++){
            string s;
            cin>>s;
            buvrette[i]=s;
    }
       //cout<<getindex("vodka");
       int n;
       cin>>n;
       for(int j=0;j<n;j++){
        string s1,s2;
        cin>>s1>>s2;
        //cout<<s1<<" "<<s2<<endl;
        Adjlist[getindex(s1)].push_back(make_pair(getindex(s2),1));
        incom[getindex(s2)]++;
       }
       vector<int>ans;

        while(ans.size()<t){
        int i=0;
        bool found=false;
        while((i<t)&&(!found)){
            if(incom[i]==0){
                    found=true;
                ans.push_back(i);
                for(int j=0;j<(int)Adjlist[i].size();j++){

                     incom[Adjlist[i][j].first]--;

                }
                incom[i]=-1;
            }

            i++;
        }
        }
        cout<<"Case #"<<cmp<<": Dilbert should drink beverages in this order:";
        cmp++;
         for(int j=0;j<ans.size();j++){
                     cout<<" "<<buvrette[ans[j]];

                }
                cout<<"."<<endl<<endl;


}

        return 0;
}
