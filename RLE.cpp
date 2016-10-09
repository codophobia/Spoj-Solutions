#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[100005];
    int i;
    int j;
    int count;
    char prev;
    char current;

    while(scanf("%s",s) != EOF) {
            map<char,int> m;
            prev = s[0];
            count = 1;
        for(i = 1; i <= strlen(s);i++) {

            if(s[i] == prev) {
                count++;
            }
            else if(s[i] != prev) {
                if(count > 3) {
                    printf("%d!%c",count,prev);
                }
                else {
                    for(j = 0; j < count; j++) {
                        printf("%c",prev);
                    }
                }
                prev = s[i];
                count = 1;
            }




        }
        printf("\n");
    }
}

