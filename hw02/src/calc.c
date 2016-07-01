/**
 * @file    calc.c
 * @author  Filip Valchar <valchar@mail.muni.cz>
 * @since   2015-03-01
 */

#include <stdio.h>

int additional(int x, int y)
{
    return x + y;
}

int subtraction(int x, int y)
{
    return x - y;
}

float division(float x, float y)
{
    return x / y;
}

int divisionRemain(int x, int y)
{
    return x / y;
}

int modulo(int x, int y)
{
    return x % y;
}

int multiply(int x, int y)
{
    return x * y;
}

long int power(int x, int y)
{
    long int result = 1;

    if(y >= 0) {
        while(y) {
            result = result * x;
            y--;
        }
        return result;
    }
    else {
        return -1;
    }
}

long long int factorial(int x)
{
    long long result = 1;

    if(x >= 0) {
        while(x) {
            result = result * x;
            x--;
        }
        return result;
    }
    else {
        return -1;
    }
}

int sum(int x)
{
    int sequence;
    int value = 0;

    if(x == 0) {
        return x;
    }
    else {
        for(int i = 0; i < x; i++) {
            scanf("%d",&sequence);
            value = value + sequence;
        }
        return value;
    }
}

float average(int x)
{
    int sequence;
    int value = 0;

    if(x == 0) {
        return x;
    }
    else {
        for(int i = 0; i < x; i++) {
            scanf("%d",&sequence);
            value = value + sequence;
        }
    return (float)value / x;
    }
}

long long int combinations(int x, int y)
{
    if(x < 0 || y < 0) {
        return -1;
    }
    else {
        if(x >= y && y>= 0) {
            return ((factorial(x))/((factorial(x-y))*(factorial(y))));
        }
        else {
            return -1;
        }
    }
}

int main(void)
{
    int x, y;
    char sign;
    float numerator, denominator;

    do {
        printf("> ");

        scanf("%c",&sign);

        switch(sign) {
            case '+':
                scanf("%d%d",&x,&y);
                printf("# %d\n",additional(x,y));
                break;

            case '-':
                scanf("%d%d",&x,&y);
                printf("# %d\n",subtraction(x,y));
                break;

            case '/':
                scanf("%f%f",&numerator,&denominator);
                printf("# %.2f\n",division(numerator,denominator));
                break;

            case 'd':
                scanf("%d%d",&x,&y);
                printf("# %d\n",divisionRemain(x,y));
                break;

            case 'm':
                scanf("%d%d",&x,&y);
                printf("# %d\n",modulo(x,y));
                break;

            case '*':
                scanf("%d%d",&x,&y);
                printf("# %d\n",multiply(x,y));
                break;

            case '^':
                scanf("%d%d",&x,&y);
                printf("# %ld\n",power(x,y));
                break;

            case '!':
                scanf("%d",&x);
                printf("# %lld\n",factorial(x));
                break;

            case 's':
                scanf("%d",&x);
                printf("# %d\n",sum(x));
                break;

            case 'a':
                scanf("%d",&x);
                printf("# %.2f\n",average(x));
                break;

            case 'c':
                scanf("%d%d",&x,&y);
                printf("# %lld\n",combinations(x,y));
                break;
            }
        getchar();
    }
    while(sign != 'q');

    return 0;
}
