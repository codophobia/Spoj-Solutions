#include <bits/stdc++.h>
using namespace std;
struct points
{
    int x;
    int y;
};

points a[1000];
int main()
{
    int n;
    int i;
    int j;
    int g;
    int u;
    int d;

    while(1) {
    scanf("%d",&n);
    map<pair<int,int>,int> m;
    if(n == 0) {
        break;
    }

    for(i = 0; i < n; i++) {
        scanf("%d%d",&a[i].x,&a[i].y);
    }

    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            u = a[i].y - a[j].y;
            d = a[i].x - a[j].x;

            g = __gcd(d,u);

            u = u / g;
            d = d / g;

            if(d < 0) {
                d = d * -1;
                u = u * -1;
            }

            m[make_pair(u,d)]++;





        }
    }

    cout<<m.size()<<endl;
    }
}
