#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct point { int x, y; // whenever possible, work with point_i
point() { x = y = 0; } // default constructor
point(int _x, int _y) : x(_x), y(_y) {} }; // user-defined

double dist(point p1, point p2) { // Euclidean distance
// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
return hypot(p1.x - p2.x, p1.y - p2.y); } // return double


struct vec { double x, y; // name: ‘vec’ is different from STL vector
vec(double _x, double _y) : x(_x), y(_y) {} };
vec toVec(point a, point b) { // convert 2 points to vector a->b
return vec(b.x - a.x, b.y - a.y); }

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }


double angle(point a, point o, point b) { // returns angle aob in rad
vec oa = toVec(o, a), ob = toVec(o, b);
return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

static double r2d(double d) {
  return (d*180/(double) M_PI);
}

int main()
{
    freopen("progress_pie.txt","r",stdin);
    freopen("progress_pie_out.txt","w",stdout);
    int t;
    cin>>t;
    point center(50,50);
    for(int i=0;i<t;i++){
        cout<<"Case #"<<i+1<<": ";
        int p,x,y;
        cin>>p>>x>>y;
        point p1;
        p1.x=x;
        p1.y=y;
        double ang=angle(p1,center,point(50,100));
        double progress_angle=(p*360/100.00);
        ang=r2d(ang);
        if(x<50)
            ang=(180+180-ang);
        if(dist(p1,center)<=50&&ang<=(p*360/100.00)||(p>0&&(x==50&&y==50)))
            cout<<"black"<<endl;
        else
            cout<<"white"<<endl;

    }

    return 0;
}
