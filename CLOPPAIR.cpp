#include <bits/stdc++.h>
using namespace std;
#define type pair<double,pair<int,int> >
int u;
int v;
double bestmin = 1000000000;
struct points
{
    int x;
    int y;
    int pos;
};
int xcompare(points a, points b)
{
    return(a.x < b.x);
}
int ycompare(points a, points b)
{
    return (a.y < b.y);
}
double dis(points a,points b)
{
    double d;
    d = sqrt(((a.x - b .x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
    return d;
}
double brute(points a[],int s,int e)
{
    int i;
    int j;
    int n;
    int c;
    int d;
    int l;
    int r;
    double min;
    min = 999999999;
    n = e - s + 1;

    for(i = s; i <= e ; i++) {
        for(j = i + 1; j <= e; j++) {
            if(dis(a[i],a[j]) < min) {
                min = dis(a[i],a[j]);
                if(min < bestmin) {
                    bestmin = min;
                    u = a[i].pos;
                    v = a[j].pos;
                }
            }
        }
    }

    return min;
}
double findclose(points a[],int k, double d)
{
    sort(a,a+k,ycompare);

    int i;
    int j;
    double min;
    min = d;


    for(i = 0; i < k; i++) {
        for(j = i + 1; j < k && (a[j].y - a[i].y) < min; j++) {
            if(dis(a[i],a[j]) < min) {
                min = dis(a[i],a[j]);
                if(min < bestmin) {
                    bestmin = min;
                    u = a[i].pos;
                    v = a[j].pos;
                }

            }
        }
    }

    return min;
}
double closepoints(points a[],int s, int e,int size)
{
    int n = e - s + 1;


    int mid = (s + e) / 2;
    if(n <= 3) {
       return  brute(a,s,e);
    }

    double l = closepoints(a,s,mid,size);
    double r = closepoints(a,mid + 1,e,size);
    //cout<<l<<' '<<r<<endl;

    double m = min(l,r);

    points b[n];
    int k;
    int i;
    int mid1;
    mid1 = a[mid].x;
    //cout<<mid1<<endl;
    k = 0;

    for(i = s; i <= e; i++) {
        if(abs(mid1 - a[i].x) < m) {
            b[k] = a[i];
            k++;

            //cout<<i<<endl;
        }
    }


    return min(m,findclose(b,k,m));

}
int main()
{
    int n;
    points a[50006];
    int i;
    type t;

    cin>>n;
    for(i = 0; i < n; i++) {
        cin>>a[i].x>>a[i].y;
        a[i].pos = i;
    }

    sort(a,a+n,xcompare);


    closepoints(a,0,n-1,n);
    if(u > v) {
        swap(u,v);
    }
    printf("%d %d %.6lf\n",u,v,bestmin);
}

