#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int> a;
    set<int>::iterator it;

    int n;
    int m;
    int id;
    int d;
    int i;
    int count;
    count = 0;

    scanf("%d",&n);

    for(i = 0; i < n; i++) {
        scanf("%d",&id);
        a.insert(id);
        scanf("%d",&m);
        while(m--) {
            scanf("%d",&id);
            a.insert(id);

        }

    }


    printf("%d\n",a.size() - n);

    return 0;

}
