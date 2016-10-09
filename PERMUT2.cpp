#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int main()
{
    int n;
    int i;
    int flag;


    while(1) {
        scanf("%d",&n);

        if(n == 0) {
            break;
        }


        memset(b,0,sizeof(b));
        flag = 0;
        for(i = 1; i <= n; i++) {
            scanf("%d",&a[i]);
            b[a[i]] = i;
        }

        for(i = 1; i <= n; i++) {
            if(a[i] != b[i]) {
                flag = 1;
                break;
            }
        }

        if(flag == 1){
            printf("not ambiguous\n");
        }
        else {
            printf("ambiguous\n");
        }


    }

    return 0;

}
