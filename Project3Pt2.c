//Project done by Javier Carranza and Herbert Alvarenga
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET  "\x1b[0m"

char* int2DArrayToString(int m, int n, int input[][n])
{
    int i, j;
    char static str[128];
    str[128]=memset(str,0,sizeof(str));
    char buffer[32];
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
      {

          itoa (input[i][j],buffer,10);
          strcat(str, buffer);
          strcat(str,"");
      }
    return str;
}
int *orderedArray(int m, int n,int input[][n],int size)
{
    int i,j,k=0;
    int arr[m*n];
    static int *p;
    int min=0;
    int replace=0;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
                arr[k]=input[i][j];
                k+=1;
        }
        for(i=0;i<size-1;i++)
        {
            min=i;
            for(j=i+1;j<size;j++)
            {
                if (arr[j] < arr[min])
                    min=j;
                swap(&arr[min],&arr[i]);
            }
        }
        p=arr;
    return p;
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int sumArray(int input[], int size)
{
    int sum = 0;


    for(int i=0; i<size; i++)
    {
        sum += input[i];
    }
    return sum;
}
int averageArray(int input[], int size)
{
    int sum = 0;
    int i=0;
    int test=0;
    for(i=0; i<size; i++)
    {
        sum += input[i];
    }
    test=sum/size;
    return test;
}
int sum2DArray(int m, int n, int input[][n])
{
    int sum = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            sum += input[i][j];
    }
    return sum;
}

void testFunction1()
{
    int test=0;
    int i=0;
    int m=3;
    int n=4;
    const int size=m*n;
    int input1[3][4] = {{15,2,3,20},{5,4,3,2},{6,7,8,9}};
    int *p=malloc(sizeof(int)*size);
    char *str;
    int sum=0,sum2=0;
    int avg=0;
    int array[size];
    char strTest[]={"15232054326789"};
    int arrTest[]={2,2,3,3,4,5,6,7,8,9,15,20};

    sum=sumArray(input1,size);
    avg=averageArray(input1,size);
    sum2=sum2DArray(m,n,input1);
    str=int2DArrayToString(m,n,input1);
    p=orderedArray(m,n,input1,size);

    printf("Ordered Array Test: ");
    for(i=0;i<size;i++)//ordered array test
    {
    if(*(p+i)!=arrTest[i])
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
        i=size-1;
        test=-1;
    }
    }
    if(test!=-1)
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }

    printf("Array to String Test: ");
    if(strcmp(str,strTest)==0)//string test
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }
    else
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
    }

    printf("Sum Array Test: ");
    if(sum==84)//sum test
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }
    else
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
    }

    printf("Average of an Array Test: ");
    if(avg==7)//avg test
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }
    else
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
    }

    printf("Sum 2D Array Test: ");
    if(sum2==84)//sum test 2d
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }
    else
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
    }
}
void testFunction2()
{
    int test=0;
    int i=0;
    int m=3;
    int n=4;
    const int size=m*n;
    int input2[3][4] = {{999,95,313,219},{875,650,370,280},{777,836,145,436}};
    int *p;
    char *str;
    int sum=0,sum2=0;
    int avg=0;
    int array[size];
    char strTest[]={"99995313219875650370280777836145436"};
    int arrTest[]={95,145,219,280,313,370,436,650,777,836,875,999};

    str=int2DArrayToString(m,n,input2);
    p=orderedArray(m,n,input2,size);
    sum=sumArray(input2,size);
    avg=averageArray(input2,size);
    sum2=sum2DArray(m,n,input2);

    printf("Ordered Array Test: ");
    for(i=0;i<size;i++)//ordered array test
    {
    if(*(p+i)!=arrTest[i])
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
        i=size-1;
        test=-1;
    }
    }
    if(test!=-1)
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }

    printf("Array to String Test: ");
    if(strcmp(str,strTest)==0)//string test
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }
    else
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
    }

    printf("Sum Array Test: ");
    if(sum==5995)//sum test
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }
    else
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
    }

    printf("Average of an Array Test: ");
    if(avg==499)//avg test
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }
    else
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
    }

    printf("Sum 2D Array Test: ");
    if(sum2==5995)//sum test 2d
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }
    else
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
    }
}
void testFunction3()
{
    int test=0;
    int i=0;
    int m=3;
    int n=1;
    const int size=m*n;
    int input3[3][1] = {{80},{55},{65}};
    int *p;
    char *str;
    int sum=0,sum2=0;
    int avg=0;
    int array[size];
    char strTest[]={"805565"};
    int arrTest[]={55,65,80};

    str=int2DArrayToString(m,n,input3);
    p=orderedArray(m,n,input3,size);
    sum=sumArray(input3,size);
    avg=averageArray(input3,size);
    sum2=sum2DArray(m,n,input3);

    printf("Ordered Array Test: ");
    for(i=0;i<size;i++)//ordered array test
    {
    if(*(p+i)!=arrTest[i])
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
        i=size-1;
        test=-1;
    }
    }
    if(test!=-1)
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }

    printf("Array to String Test: ");
    if(strcmp(str,strTest)==0)//string test
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }
    else
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
    }

    printf("Sum Array Test: ");
    if(sum==200)//sum test
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }
    else
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
    }

    printf("Average of an Array Test: ");
    if(avg==66)//avg test
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }
    else
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
    }

    printf("Sum 2D Array Test: ");
    if(sum2==200)//sum test 2d
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }
    else
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
    }
}
void testFunction4()
{
    int test=0;
    int i=0;
    int m=2;
    int n=4;
    const int size=m*n;
    int input4[2][4] = {{70,20,11,15},{8,9,90,22}};
    int *p;
    char *str;
    int sum=0,sum2=0;
    int avg=0;
    int array[size];
    char strTest[]={"70201115899022"};
    int arrTest[]={8,9,11,15,20,22,70,90};

    str=int2DArrayToString(m,n,input4);
    p=orderedArray(m,n,input4,size);
    sum=sumArray(input4,size);
    avg=averageArray(input4,size);
    sum2=sum2DArray(m,n,input4);

    printf("Ordered Array Test: ");
    for(i=0;i<size;i++)//ordered array test
    {
    if(*(p+i)!=arrTest[i])
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
        i=size-1;
        test=-1;
    }
    }
    if(test!=-1)
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }

    printf("Array to String Test: ");
    if(strcmp(str,strTest)==0)//string test
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }
    else
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
    }

    printf("Sum Array Test: ");
    if(sum==245)//sum test
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }
    else
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
    }

    printf("Average of an Array Test: ");
    if(avg==30)//avg test
    {
        printf(ANSI_COLOR_GREEN   "This text is GREEN!"   ANSI_COLOR_RESET "\n");
    }
    else
    {
    printf(ANSI_COLOR_RED"FAILED"ANSI_COLOR_RESET "\n");
    }

    printf("Sum 2D Array Test: ");
    if(sum2==245)//sum test 2d
    {
    printf(ANSI_COLOR_GREEN"PASSED"ANSI_COLOR_RESET"\n");
    }
    else
    {
        printf(ANSI_COLOR_RED"This text is RED!\n");
    }
}
int main(int argc, char const *argv[])
{
    printf("First array:\n");
    testFunction1();
    printf("\n");
    printf("Second array:\n");
    testFunction2();
    printf("\n");
    printf("Third array:\n");
    testFunction3();
    printf("\n");
    printf("Fourth array:\n");
    testFunction4();
    return 0;
}
