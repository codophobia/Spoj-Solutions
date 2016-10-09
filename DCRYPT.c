#include <stdio.h>
#include <string.h>
char s[100005];
int main()
{

    int k;
    int t;
    int i;
    char c;
    int d;

    scanf("%d",&t);

    while(t--) {
        scanf("%d",&k);
        scanf("%s",s);



            if(k >= 0 && k <= 25) {
                for(i = 0; s[i] != '\0' ; i++) {
                if(s[i] >= 65 && s[i] <= 90) {
                    d = ((s[i]- 65) + k) % 26;
                    s[i] = 65 + d;
                }
                else if(s[i] >= 97 && s[i] <= 122) {
                    d = ((s[i]- 97) + k) % 26;
                    s[i] = 97 + d;
                }
                else {
                    s[i] = 32;
                }
            }
            }
            else if(k >= 26 && k <= 51) {
                for(i = 0; s[i] != '\0' ;i++) {
                if(s[i] >= 65 && s[i] <= 90) {
                     d = ((s[i]- 65) + k) % 26;
                     s[i] = d + 97;

                }
                 else if(s[i] >= 97 && s[i] <= 122) {
                    d = ((s[i]- 97) + k) % 26;
                    s[i] = d + 65;
                }
                else {
                    s[i] = 32;
                }
                }



        }

        printf("%s\n",s);


    }

    return 0;
}
