#include <bits/stdc++.h>
using namespace std;
#define max 1000008
int p[max];
int in[max];
vector<int> v[15];
void sieve()
{
    memset(p,0,sizeof(p));
    memset(in,0,sizeof(in));
    int i;
    int j;
    in[1] = 1;


    for(i = 2; i <= sqrt(max);i++) {
            if(in[i] == 0) {
        for(j = i ; j < max; j = j + i) {
            p[j] = p[j] + 1;
            in[j] = 1;
        }
            }
    }

    for(i = 2; i < max; i++) {
        j = p[i];
        v[j].push_back(i);
    }


}
int main()
{
    sieve();
    int a;
    int b;
    int t;
    int n;

    vector<int>::iterator low,up;

    scanf("%d",&t);

    while(t--) {
        scanf("%d%d%d",&a,&b,&n);

        if(n == 0 ) {
            if(a > 0) {
                printf("0\n");
            }
            else {
                printf("1\n");
            }
            continue;
        }
        else {
            low = lower_bound(v[n].begin(),v[n].end(),a);
            up = upper_bound(v[n].begin(),v[n].end(),b);
            printf("%d\n",(up-v[n].begin())-(low-v[n].begin()));
        }

        }

        return 0;
    }

