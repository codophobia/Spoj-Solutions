#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int n;
    double a;
    double ans;

    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        ans = n / (double)(n+1);
        printf("%.8lf\n",ans);
    }
}
