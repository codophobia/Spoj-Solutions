#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long int n;
    int p;

    scanf("%d",&t);

    while(t--) {
        scanf("%lld%d",&n,&p);

        if(p == 0) {
            printf("Airborne wins.\n");
        }
        else if(p == 1) {
            printf("Pagfloyd wins.\n");
        }
    }

    return 0;
}
