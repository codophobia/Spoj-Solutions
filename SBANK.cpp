#include <bits/stdc++.h>
using namespace std;
int main()
{


    int t;
    int n;
    int i;

    scanf("%d",&t);

    while(t--) {
        scanf("%d\n",&n);
        char s[40];
        map<string,int> m;
        map<string,int>::iterator it;
        for(i = 0; i < n; i++) {
            gets(s);
            m[(string)s]++;
        }

        for(it = m.begin(); it != m.end(); it++) {
            printf("%s %d\n",it->first.c_str(),it->second);
        }
        printf("\n");
    }

    return 0;
}
