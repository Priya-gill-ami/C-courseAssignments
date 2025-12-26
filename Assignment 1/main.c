#include <stdio.h>

int main(void)
{
    printf("Hello World!\n'C Programming'");
    // return 0;
}

/*
1. \n :- print the "C Programming" in the next line of Hello World line
2. commenting the include <stdio.h> gives the erro of implicit declaration of function 'printf' [-Wimplicit-function-declaration]
     printf("Hello World!\n'C Programming'");
 
3. The program is not compiled when commented the #include but compiled when commented the return 0 statement 
*/