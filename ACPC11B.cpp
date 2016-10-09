#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int m1[1005];
    int m2[1005];
    int n1;
    int n2;
    int i;
    int j;
    long long int min;


    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n1);
        min = 100000000;
        for(i = 0; i < n1; i++) {
            scanf("%d",&m1[i]);
        }
        scanf("%d",&n2);
        for(i = 0; i < n2; i++) {
            scanf("%d",&m2[i]);
        }

        for(i = 0; i < n1; i++) {
            for(j = 0; j < n2; j++) {
                if(abs(m1[i] - m2[j]) < min) {
                    min = abs(m1[i] - m2[j]);
                    if(min == 0) {
                        break;
                    }

                }
            }
            if(min == 0) {
                break;
            }
        }

        printf("%lld\n",min);
    }

    return 0;
}
