#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vii student;
int n;
double res,tmpres;
vector<int> matching;
double dp[1000][1000];
double dist (int i,int j)
{
return (double)2*sqrt(pow(student[i].first-student[j].first,2)+pow(student[i].second-student[j].second,2));
}

double calcule(){
double tmp=0;
for(int i=0;i<2*n;i++){
tmp+=(double)sqrt(pow(student[i].first-student[matching[i]].first,2)+pow(student[i].second-student[matching[i]].second,2));
}
return tmp;
}
void match(){

int j=-1;
for( j=0;j<2*n;j++){
if(matching[j]==-1)
break;
}

if(j==2*n)
res=min(res,tmpres);



for(int i=j+1;i<2*n;i++){
    if(matching[i]==-1)
    {
    matching[j]=i;
    matching[i]=j;
    tmpres+=dist(i,j);
    if(tmpres<=res){
    match();
    }
    matching[j]=-1;
    matching[i]=-1;
    tmpres-=dist(i,j);
    }
  }

}

int main()
{
    freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int cmp=0;
    while(cin>>n&&n>0){

    cmp++;
    res=INT_MAX;
    tmpres=0;
    memset(dp,-1,sizeof dp);
    student.clear();
    student.resize(n*2);
    matching.clear();
    matching.assign(n*2,-1);

    string name;
    for(int i=0;i<2*n;i++)
    cin>>name>>student[i].first>>student[i].second;

    match();

    cout<<"Case "<<cmp<<": ";
    printf("%.2f\n",res/2);
    }
    return 0;
}

