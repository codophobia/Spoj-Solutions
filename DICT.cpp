#include <bits/stdc++.h>
using namespace std;
int c = 0;
struct trie
{
    char b[50];
    int words;
    struct trie *edges[30];
};
struct trie *root;
struct trie *initialise(struct trie *node)
{
    int i;
    node = (struct trie *)malloc(sizeof(struct trie));
    node->b[0] = '\0';
    node->words = 0;
    for(i = 0; i < 30; i++) {
        node->edges[i] = NULL;
    }

    return node;
}
void addword(char s[],struct trie *temp)
{
    int i;
    int k;


    for(i = 0; i < strlen(s);i++) {
        k = s[i] - 'a';
        if(temp->edges[k] == NULL) {
            temp->edges[k] = initialise(temp->edges[k]);
        }
        temp = temp->edges[k];
    }
    temp->words = 1;
    strcpy(temp->b,s);
}
struct trie *findword(char s[],struct trie *temp)
{
    int i;
    int k;

    for(i = 0; i < strlen(s); i++) {
        k = s[i] - 'a';
        if(temp->edges[k] == NULL) {
            return NULL;
        }
        temp = temp->edges[k];
    }

    return temp;
}

int dfs(struct trie *temp,char s[])
{


        int i;





        //cout << "hi " << temp->b << endl;
        if(temp->words == 1 && strcmp(temp->b,s) != 0) {
            printf("%s\n",temp->b);
            c++;
        }


        for(i = 0; i < 26; i++) {
            if(temp->edges[i] != NULL) {
                dfs(temp->edges[i],s);
            }
        }


    return c;

}
int main()
{
   int i;
    char s[50];
    char a[50];
   int n;
   int k;
   root = initialise(root);
   struct trie *temp;
   temp = initialise(temp);

   scanf("%d",&n);
   for(i = 0; i < n; i++) {
        scanf("%s",s);
        addword(s,root);
   }
   int j;

   scanf("%d",&k);
   for(i = 1; i <= k; i++) {
        scanf("%s",a);
        printf("Case #%d:\n",i);
        temp = findword(a,root);
        if(temp == NULL) {
            printf("No match.\n");
        }
        else {
            //cout << "bfs " << temp->b << endl;
           int c =  dfs(temp,a);
           if(c == 0) {
               printf("No match.\n");
           }

        }

   }

   return 0;





}
