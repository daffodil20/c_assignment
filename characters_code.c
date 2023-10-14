#include<stdio.h>
int main(){
    char character;
    character = getchar();
    while ('a' <= character && character <= 'v'){
        character = character + 4;
        putchar(character);
        break;
    }
    while ('A' <= character && character <= 'V'){
        character = character + 4;
        putchar(character);
        break;
    }
    while ('w' <= character && character <= 'z'){
        character = character - 22;
        putchar(character);
        break;
    }
    while ('W' <= character && character <= 'Z'){
        character = character - 22;
        putchar(character);
        break;
    }
    return 0;
}
