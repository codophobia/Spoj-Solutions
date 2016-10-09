#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[505];
    char k[10];

    int key;
    int t;
    int i;
    char c;
    int j;
    int d;
    int flag;
    int len;

    scanf("%d",&t);

    while(t--) {
        scanf("%s",k);
        scanf("%s",s);
        stack<int> s1,s2;
        j = 0;
        len = strlen(k);

        key = atoi(k);
        while(key != 0 || len > 0)  {
            d = key % 10;
            s1.push(d);
            key = key / 10;
            len--;
        }

        i = 0;

        while(i != strlen(s)) {

            while(!s1.empty() && i != strlen(s)) {
            key = s1.top();
            d = ((s[i]- 97))- key;
            if(d < 0) {
                d = d + 26;
            }

            s[i] = 97 + d;
            s2.push(key);
            s1.pop();
            i++;
            }

            while(!s2.empty() && i != strlen(s)){
            key = s2.top();
            d = ((s[i]- 97) - key);
            if(d < 0) {
                d = d + 26;
            }
            s[i] = 97 + d;
            s1.push(key);
            s2.pop();
            i++;
            }
        }









        printf("%s\n",s);
    }
}
