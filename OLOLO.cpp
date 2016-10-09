#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int i;
    int a;
    int res;

    scanf("%d",&n);
    scanf("%d",&res);

    for(i = 1; i < n; i++) {
        scanf("%d",&a);
        res = res ^ a;
    }

    printf("%d\n",res);

    return 0;
}

