/**
 * @file    ascii85.c
 * @author  Filip Valchář <valchar@mail.muni.cz>
 * @since   2016-08-03
 */

#include <stdio.h>
#include <string.h>

/**
 * Five ASCII characters to represent four bytes of binary data
 *
 * @param buffer        input buffer represent four bytes
 * @param bufferAscii   output buffer represent five bytes
 */

void asciiAlgorithm(char *buffer, char *bufferAscii)
{
    unsigned long int N = 0x00000000;

    for(int i = 0; i < 4; i++) {
        N = N<<8;
        N = buffer[i] | N;
    }

    for(int j = 4; j >= 0; j--) {
        bufferAscii[j] = N % 85;
        bufferAscii[j] += 33;
        N = N / 85;
    }

    for(int i = 0; i < 5; i++) {
        fprintf(stdout,"%c",bufferAscii[i]);
    }
}

int main(void)
{
    char buffer[4] = "";
    char bufferAscii[5] = "";
    char inputString[41] = "";
    int length = 0;
    int c = 0;

    for(int i = 0; i < 40; i++) {
        c = getchar();
        if(c == '\n' || c == EOF) {
            break;
        }
        else {
            inputString[length] = c;
            length++;
        }
    }

    if(!(length % 4 == 0)) {
        for(int i = length; i < 40; i++) {
            inputString[i] = '\0';
            length++;
            if(i % 4 == 0) {
                break;
            }
        }
    }

    for(int i = 0, j = 0; i < length; i++, j++) {
        buffer[j] = inputString[i];
        if(j == 3) {
            asciiAlgorithm(buffer,bufferAscii);
            j = -1;
        }
    }

    fprintf(stdout,"\n");

    return 0;
}
