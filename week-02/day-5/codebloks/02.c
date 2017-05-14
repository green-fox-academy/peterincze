#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word [255];
    char wordBack[255]="";
    printf("what is the word?\n");
    scanf("%s", &word);
    int j=0;
    for (int i=strlen(word)-1; i>=0; i--){
        wordBack[j]=word[i];
        j++;
    }
    printf("%s%s\n", word, wordBack);
    return 0;
}
