#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char * decimalToOctal();
char * decimalToHex();
void decimalToBinary(); 

int promptUserInput()
{
    int result;
    printf("\n Hello, Enter a decimal number for conversion:");
    scanf("%d", &result);
    return result;
}

void printResults(int input)
{
    char *Octal;
    char *Hex;
    
    Octal = decimalToOctal(input);
    Hex = decimalToHex(input);

    printf("\nThe decimal %d in octal: %s \n", input,Octal);
    printf("The decimal %d in hex: %s \n", input,Hex);
    printf("The decimal %d in binary: ", input);
    decimalToBinary(input);
    printf("\n \n");

    free(Octal);
    free(Hex); 
}

char * decimalToOctal(int input)
{
    char *result;

    result = (char*)malloc(sizeof(char)*(int)(log10(input)/(log10(8)+1)));
    sprintf(result, "%o",input);
    return result;
}

char * decimalToHex(int input)
{
    char *result;

    result = (char*)malloc(sizeof(char)*(int)(log10(input)/(log10(16)+1)));
    sprintf(result, "%x",input);
    return result;
}

void decimalToBinary(int input)
{
    if (input == 1)
        printf("1");
    else
    {
        decimalToBinary(input / 2);
        printf("%d", input % 2);
    }
   
}


int main(int argc,char *argv[])
{
    int input;
    if (argc < 2)
    {
        input = promptUserInput();
    }
    else
    {
        input = (int)strtol(argv[1],NULL,10);
    }
    printResults(input);
    return 0;
}