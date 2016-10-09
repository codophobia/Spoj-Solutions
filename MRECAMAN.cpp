#include <bits/stdc++.h>
using namespace std;
long long int a[500005];
map<long long,int> m;

void sequence()
{
    int i;
    long long int val;
    a[0] = 0;
    m[0] = 1;

    for(i = 1; i < 500005; i++) {

        val = a[i-1] - i;
        if(val > 0 && m[val] == 0) {
            a[i] = val;
            m[val] = 1;
        }
        else {
            a[i] = a[i-1] + i;
            val = a[i];
            m[val] = 1;
        }
    }
}

int main()
{
    int n;
    sequence();

    while(1) {
        scanf("%d",&n);
        if(n == -1) {
            break;
        }
        printf("%lld\n",a[n]);
    }
}
