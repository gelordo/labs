#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void easy1(char s[],int n){
    int i;
    int k;
    for(i=0; i<(n/2);i++)
    {
        if (s[i]==s[n-1]){k=1;}
        else {k=0;}
        n--;
    }
    if (k){printf("\nIt's a palindrome");} else
    {printf("\nIt isn't a palindrome");}
}
void easy2(char s[],int n){
    int i; char up_s[100];
    int k;
    strcpy(up_s,s);
    for (i=0; i<n; i++){
        if (up_s[i]!=' '){
            k= (int) up_s[i];
            k=k-32;
            up_s[i]= (char)k;}

    }printf("The word with uppercases: ");
    puts(up_s);}
void easy3(char s[],int n){
    int k; int i; k=0;
    for (i=0;i<n;i++){
        if ((s[i]=='a') || (s[i]=='e') ||
            (s[i]=='i') || (s[i]=='o') ||
            (s[i]=='u')||(s[i]=='A') || (s[i]=='E') ||
            (s[i]=='I') || (s[i]=='O') ||
            (s[i]=='U')){
            k++;}

    }
    printf("The number of vowels: %d",k);}
void medium1(char s[]){
    int i; int k; k=0;
    int n=strlen(s)-1;
    for(i=0; i<n; i++){
        if ((s[i]==',')||(s[i]=='.')||(s[i]=='?')||(s[i]=='!')||
            (s[i]=='-')||(s[i]==':')||(s[i]==';')||(s[i]=='[')||
            (s[i]==']')||(s[i]=='{')||(s[i]=='}')||(s[i]=='(')||
            (s[i]==')')||(s[i]=='\'')||(s[i]=='\"')){
            if ((s[i]=='.')&&(s[i+1]=='.')&&(s[i+2]=='.')){k++; i=i+3;}else{ k++;}
        }
    }
    printf("The number of the punctuation marks: %d\n",k);
}

int compare(const void *a, const void *b) {
    return strlen(*(const char **)b) - strlen(*(const char **)a);
}

void basetask(char *s, int size) {
    printf("Unsorted string: ");
    fgets(s, size, stdin);

    // Tokenize the string into words
    char *words[100]; // Assuming a maximum of 100 words

    char *word = strtok(s, " \n"); // Tokenize using space and newline
    int wordCount = 0;
    while (word != NULL) {
        words[wordCount] = (char *)malloc(strlen(word) + 1); // +1 for null terminator
        strcpy(words[wordCount], word);
        word = strtok(NULL, " \n");
        wordCount++;
    }

    // Sort the words in descending order by their lengths
    qsort(words, wordCount, sizeof(char *), compare);

    // Concatenate the sorted words into a single string
    char sortedString[1000]; // Assuming a maximum combined length of 1000
    strcpy(sortedString, "");
    for (int i = 0; i < wordCount; i++) {
        strcat(sortedString, words[i]);
        if (i < wordCount - 1) {
            strcat(sortedString, " "); // Add a space between words
        }
        free(words[i]); // Free memory allocated for each word
    }

    // Print the sorted words in a row
    printf("Sorted string: %s\n", sortedString);
}


int main()
{
    char s[1000];
    char med1[1000];
    char basestring[1000];
    printf("Write a sentence for basetask, ");
    basetask(basestring, sizeof(basestring));
    printf("write a word for easy tasks, or sentence: ");
    fgets(s,sizeof(s),stdin);
    int n=strlen(s)-1;
    easy1(s,n);
    printf("\n");
    easy2(s,n);
    printf("\n");
    easy3(s,n);
    printf("\n");
    printf("Write a sentence to count the number of punctuation marks in it: ");
    fgets(med1,sizeof(med1),stdin);
    medium1(med1);
	getchar();
    return 0;
}
