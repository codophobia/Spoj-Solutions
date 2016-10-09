#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a,b,c;

    while(1) {
        scanf("%d%d%d",&a,&b,&c);
        if(a == 0 && b == 0 && c == 0) {
            break;
        }

        if((2 * b) == (a + c)) {
            printf("AP %d\n",c + (c - b));
        }
        else if((b * b) == (a * c)) {
            printf("GP %d\n",(c * (b / a)));
        }
    }
}
