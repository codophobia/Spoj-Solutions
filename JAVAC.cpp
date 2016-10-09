#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    char a[105];
    int flag1;
    int flag2;
    int flag3;


    while(scanf("%s",a) != EOF) {

        flag1 = 1;
        flag2 = 1;
        flag3 = 0;


        int len = strlen(a);

        if(!islower(a[0])) {
            flag1 = 0;
            flag2 = 0;
        }

        for(i = 1; i < strlen(a);i++) {

            if(!isalpha(a[i])) {
                flag1 = 0;
            }

            if(a[i] == '_') {
                if(!islower(a[i+1])) {
                    flag2 = 0;
                }
            }
            else if(!islower(a[i])) {
                flag2 = 0;
            }


        }

        if(flag1 == 0 && flag2 == 0) {
            printf("Error!\n");
            continue;
        }



            for(i = 0; i < strlen(a);i++) {
                if(a[i] == '_') {

                    i = i + 1;
                    printf("%c",toupper(a[i]));
                    continue;

                }



                if(isupper(a[i])) {
                    printf("_");
                    printf("%c",tolower(a[i]));
                }

                if(islower(a[i])) {
                    printf("%c",a[i]);
                }
            }


        printf("\n");
    }
}
