#include <stdio.h>

void replicaten (int n, char c)
{
    for (int i = 0; i<n; i++)
    putchar (c);
}

void quadrado(int n){
 for (int i = 0; i<n ; i++)
    {for (int j=0 ;j<n ; j++)
    printf("#");
    printf("\n");
    }
}

void xadrez(int n)
{
    for (int i = 0; i<n ; i++)
    {
        for (int j=0; j<n; j++)
        {
            if ((i+j)%2==0) printf ("#");
            else printf ("_");
        }
        printf ("\n");
    }

}

void triangulo (int n)
{
    for (int i = 1; i<n;i++)
    {
        for (int j = 0; j<i;j++)
        putchar('#');
        putchar('\n');
    }
    for (int k = n; k>0;k--)
    {
        for (int l = 0; l<k;l++)
        putchar ('#');
        putchar('\n');

    }    
}

void trianguloeq (int n)
{
    for (int i = 1; i<n; i++)
    {
        for(int j = n; j>i; j--)
        putchar (' ');
        for (int k = 0; k<((2*i)-1);k++)
        putchar ('#');
        putchar ('\n');
    }
}

void circulo (int n)
{
    for(int y = n; y >= -n; y--)
    {
        for(int x = -n; x <= n; x++)
        if (x*x + y*y <= n*n) putchar ('#');
        else putchar (' ');
        putchar ('\n'); 
    }
}

int main()
{
    quadrado(5);
    printf ("\n");
    xadrez(5);
    putchar ('\n');
    triangulo(5);
    putchar ('\n');
    trianguloeq(5);
    putchar ('\n');
    circulo(5);
    return 0;
}
