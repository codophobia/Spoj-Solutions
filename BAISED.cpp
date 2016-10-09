#include <iostream>
#include <stdio.h>
//#include <string.h>
#include <limits.h>
#include <math.h>
#include <cstdlib>
#include <algorithm>
//psyduck
#define ll long long
#define S(x) scanf("%d",&x)
#define Sf(x) scanf("%f",&x)
#define Slf(x) scanf("%lf",&x)
#define Sl(x) scanf("%lld",&x)
#define P(x)  printf("%d\n", x)
#define Pf(x)  printf("%f\n", x)
#define Plf(x)  printf("%lf\n", x)
#define Pl(x)  printf("%lld\n", x)
using namespace std;
struct point{
        string name;
        ll int pos;
};
point a[100005];
ll int cmp(point p, point q){
        return p.pos < q.pos;
}
int main()
{
    ll int t,i,n,ans;
    Sl(t);
    while(t--){
        ans = 0;
        Sl(n);
        for(i = 0; i < n; i++){
            cin >> a[i].name;
            Sl(a[i].pos);
        }
        sort(a,a+n,cmp);
        ll int z = 1;
        for (i = 0; i < n; i++){
            ans = ans + abs(z-a[i].pos);
            z++;
        }
        Pl(ans);
    }
}
