#include <stdio.h>

int main (int argc, char **argv) {

    int c, last = 0; 
    size_t ln = 1;      
    FILE *fp = argc > 1 ? fopen (argv[1], "r") : stdin;

    if (!fp) {  
        perror ("file open failed");
        return 1;
    }
    printf ("%03zu ", ln++);            
    while ((c = getc(fp)) != EOF) {     
        if (last)                       
            putchar (last);             
        if (last == '\n')               
            printf ("%03zu ", ln++);    
        last = c;                       
    }
    putchar (last);                    
    if (last != '\n')                   
        putchar('\n');                 
    if (fp != stdin)                    
        fclose (fp);

    return 0;
}