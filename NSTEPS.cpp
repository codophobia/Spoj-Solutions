#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int t;
    int x,y;

    scanf("%d",&t);

    while(t--) {
        scanf("%d%d",&x,&y);

        if(x % 2 == 0 && y % 2 == 0) {
            if(y == x - 2) {
                printf("%d\n",x + y);
            }
            else if(x == y) {
                printf("%d\n",x + y);
            }
            else {
                printf("No Number\n");
            }
        }

         else if(x % 2 == 1 && y % 2 == 1) {
            if(y == x - 2) {
                printf("%d\n",x + y - 1);
            }
            else if(x == y) {
                printf("%d\n",x + y -1);
            }
            else {
                     printf("No Number\n");

            }
        }
        else {
                printf("No Number\n");

        }


    }
}
