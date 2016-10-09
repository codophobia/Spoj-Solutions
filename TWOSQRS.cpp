#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long int n;
    long long int i;
    long long int s;
    double a;
    long long as;
    double b;
    long long bs;
    int flag;

    scanf("%d",&t);

    while(t--) {
        scanf("%lld",&n);
        a = sqrt((double)n);
        as = a;
        flag = 0;

        for(i = 0; i <= as; i++) {

            s = n - i * i;
            b = sqrt((double)s);
            bs = b;

            if(bs * bs == s) {
                flag = 1;
                break;
            }
        }

        if(flag == 1) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }





    }
}
