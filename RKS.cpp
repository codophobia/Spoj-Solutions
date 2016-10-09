#include <bits/stdc++.h>
using namespace std;
map<int,int> f;
map<int,int> priority;
int a[1005];
int compare(int x,int y)
{
    if(f[x] == f[y]) {
        return(priority[x] < priority[y]);
    }

    return(f[x] > f[y]);
}

int main()
{
    int n;
    int c;
    int i;

    scanf("%d%d",&n,&c);

    for(i = 0; i < n; i++) {
        scanf("%d",&a[i]);
        f[a[i]]++;

    }

    for(i = n - 1; i >= 0; i--) {
        priority[a[i]] = i;
    }

    sort(a,a+n,compare);

    for(i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }

    printf("\n");

    return 0;


}
