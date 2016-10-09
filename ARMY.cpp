#include <bits/stdc++.h>
using namespace std;
int g[1000005];
int m[1000005];
int main()
{
    int ng;
    int nm;
    int i;
    int t;
    int j;

    scanf("%d",&t);

    while(t--) {
            printf("\n");
        scanf("%d%d",&ng,&nm);

        for(i = 0; i < ng; i++) {
            scanf("%d",&g[i]);
        }

        for(i = 0; i < nm; i++) {
            scanf("%d",&m[i]);
        }
        i = 0;
        j = 0;

        while(i != ng && j != nm) {
                if(g[i] < m[j]) {
                    i++;
                }

                else if(m[j] < g[i]) {
                    j++;
                }

                else if(m[j] == g[i]) {
                    j++;
                }

        }

        if(i == ng) {
            printf("MechaGodzilla\n");
        }
        else if(j == nm) {
            printf("Godzilla\n");
        }
    }

    return 0;




}
