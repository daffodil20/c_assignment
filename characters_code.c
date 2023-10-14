#include<stdio.h>
int main(){
    char character;
    character = getchar();
    while ('a' <= character && character <= 'v'){
        character = character + 4;
        printf("%c",character);
    }
    while ('A' <= character && character <= 'V'){
        character = character + 4;
        printf("%c",character);
    }
    while ('w' <= character <= 'z'){
        character = character - 22;
        printf("%c",character);
    }
    while ('W' <= character <= 'Z'){
        character = character - 22;
        printf("%c",character);
    }
    return 0;
}
