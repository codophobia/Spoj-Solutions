#include <bits/stdc++.h>
using namespace std;
int main()
{
    double r1,r2,r3,k1,k2,k3,k4,r4;
    int t;

    scanf("%d",&t);

    while(t--) {
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        k1 = 1/r1;
        k2 = 1/r2;
        k3 = 1/ r3;
        k4 = k1 + k2 + k3 + 2 * sqrt(k1*k2+k1*k3+k2*k3);
        r4 = 1/k4;
        printf("%.6lf\n",r4);

    }
}
