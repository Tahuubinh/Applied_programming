#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
typedef struct pair<double,double> dd;


double euclid(dd a, dd b)
{
    return sqrt((a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y));
}

dd point[5*10001];

bool cprX(dd a,dd b)
{
    if(a.X<b.X) return true;
    if(a.X==b.X)
    {
        if(a.Y<=b.Y) return true;
    }
    return false;
}
double minD = 1e15;

set<dd> s;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>point[i].X>>point[i].Y;
    sort(point+1,point+n+1,cprX);

    int j=1;
    for(int i=1;i<=n;i++)
    {
        while(point[i].X-point[j].X>minD)
        {

            ///xoa J khoi tap phai
            s.erase(dd(point[j].Y,j));
            j++;
        }

        set<dd>::iterator it = s.upper_bound(dd(point[i].Y+minD,0));
        set<dd>::iterator _it = s.lower_bound(dd(point[i].Y-minD,0));
        /// j thuoc _it -> it fabs(j.Y - i.Y) <= minD
        while(_it!=it)
        {
            int j = _it->Y;
            minD=min(minD,euclid(point[i],point[j]));
            _it++;
        }

        s.insert(dd(point[i].Y,i));
    }
    printf("%0.6lf",minD);
    return 0;
}
