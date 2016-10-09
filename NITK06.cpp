#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int n;
    int i;
    long long int s;
    long long int b;
    int flag;

    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        scanf("%lld",&s);
        flag = 0;

        for(i = 1; i < n; i++) {
            scanf("%lld",&b);

            s = b - s;
        }


            if(s == 0) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }


    }
}
