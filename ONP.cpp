#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<char> s;
    char a[500];
    int t;
    int i;

    scanf("%d",&t);

    while(t--) {
        scanf("%s",a);

        for(i = 0; i < strlen(a); i++) {

            if(a[i] == '+' || a[i] == '*' || a[i] == '-' || a[i] == '^' || a[i] == '/') {
                s.push(a[i]);
            }
            else if(isalpha(a[i])) {
                printf("%c",a[i]);
            }

           else if(a[i] == ')' && !s.empty()) {

                printf("%c",s.top());
                s.pop();
            }


        }

        printf("\n");
    }

    return 0;
}
