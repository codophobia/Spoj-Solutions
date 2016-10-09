#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[1005];

    int n;
    int i;
    int j;
    int k;
    int flag;
    int need;

    while(1) {
        scanf("%d",&n);
        stack<int> s;

        if(n == 0) {
            break;
        }

        flag = 0;
        need = 1;

        for(i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }

        for(i = 0; i < n; i++) {

            while(!s.empty()  && s.top() == need) {
                need++;
                s.pop();
            }

            if(a[i] == need) {
                need++;
            }
            else if(!s.empty() && s.top() < a[i]) {

                flag = 1;
                break;
            }
            else {
                s.push(a[i]);
            }






        }

        if(flag == 1) {
            printf("no\n");
        }
        else {
            printf("yes\n");
        }












    }

    return 0;
}
