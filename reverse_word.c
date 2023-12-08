//Write a program to reverse the individual word of a given sentence.

#include <stdio.h>
#include <string.h>

void reverseWord(char *begin, char *end) {
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

void reverseSentence(char *sentence) {
    char *wordBegin = sentence;
    char *temp = sentence;
    
    while (*temp) {
        temp++;
        if (*temp == '\0') {
            reverseWord(wordBegin, temp - 1);
        } else if (*temp == ' ') {
            reverseWord(wordBegin, temp - 1);
            wordBegin = temp + 1;
        }
    }
    
    reverseWord(sentence, temp - 1);
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    // Remove trailing newline if present
    size_t len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }
    
    reverseSentence(sentence);
    printf("Reversed sentence: %s\n", sentence);
    
    return 0;
}
