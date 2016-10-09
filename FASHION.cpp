#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int m[1005];
    int f[1005];
    int i;
    int t;
    int sum;


    scanf("%d",&t);

    while(t--) {

    scanf("%d",&n);
    sum = 0;

    for(i = 0; i < n; i++) {
        scanf("%d",&m[i]);
    }
    for(i = 0; i < n; i++) {
        scanf("%d",&f[i]);
    }

    sort(m,m+n);
    sort(f,f+n);

    for(i = 0; i < n; i++) {
        sum = sum + (m[i] * f[i]);
    }

    printf("%d\n",sum);
    }
    return 0;
}
