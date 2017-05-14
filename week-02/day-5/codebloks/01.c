#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word1 [255];
    char word2 [255];
    char temp;
    printf("What is the first word?\n");
    scanf("%s", &word1);
    printf("What is the next word?\n");
    scanf("%s", &word2);
    if(strlen(word1) != strlen(word2)){
         printf("Not anagram.\n");
    }
    else{
        for (int i=0; i<strlen(word1)-1; i++){
            for (int j = i+1; j < strlen(word1); j++) {
                if (word1[i] > word1[j]) {
                    temp  = word1[i];
                    word1[i] = word1[j];
                    word1[j] = temp;
                }
                if (word2[i] > word2[j]) {
                    temp  = word2[i];
                    word2[i] = word2[j];
                    word2[j] = temp;
                }
            }
        }
        for(int i = 0; i<strlen(word1); i++) {
            if(word1[i] != word2[i]) {
                printf("Strings are not anagrams! %s, %s \n", word1, word2);
            }
            else{
                printf("Strings are anagrams! \n");
            }
        }
    }

    return 0;
}



