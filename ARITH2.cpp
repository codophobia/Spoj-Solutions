#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a;
    long long int b;
    char ch;
    long long int t;

    scanf("%lld",&t);

    while(t--) {
        printf("\n");
        scanf("%lld",&a);

        while(1) {
            scanf(" %c",&ch);

            if(ch == '=') {
                break;
            }

            scanf("%lld",&b);

            if(ch == '+') {
                a = a + b;
            }
            else if(ch == '-') {
                a = a - b;
            }
            else if(ch == '*') {
                a = a * b;
            }
            else if(ch == '/') {
                a = a / b;
            }
        }

        printf("%lld\n",a);
    }
    
    return 0;
}
