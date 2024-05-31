#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <assert.h>
#include <math.h>


int igual(int tamanho, char c[])
{
    for(int i = 1; i<tamanho; i++)
    if(c[i]!=c[0]) return 0;
    return 1;
}

int infinito(int texp, int tman, char exp[], char man[])
{
    if(igual(texp,exp) && igual(tman,man) && exp[0]== '1' && man[0] == '0') return 1;
    else return 0;
}

int zero(int texp, int tman, char exp[], char man[])
{
    if(igual(texp,exp) && igual(tman,man) && exp[0]== '0' && man[0]== '0') return 1;
    else return 0;
}

int bitAux(int tamanho, char e[]) 
{
    int r = 0;
    int exp = 1;

    for (int i = tamanho - 1; i >= 0; i--) 
    {
        if (e[i] == '1') 
        {
            r += exp;
        } 
        else 
        {
        r = r + 0;
        }
        exp *= 2;
    }

    return r;
}

double desn(char sinalc, char man[], int M, int E)
{
    int bias = pow(2,E-1) - 1;
    double v = 0;
    double bin = 0.5;
    double total;
    double sinal;

     for (int i = 0; i <= M - 1; i++) 
     {
        if (man[i] != '0') 
        {
            v += bin;
        } 
        else 
        {
        v = v + 0;
        }
        bin /= 2.0;
    }

    if(sinalc == '0')
    {
        sinal = 1;
    }
    else 
    {
        sinal = (-1);
    }

    total = sinal * v * (pow(2,1-bias));

    return total; 
}

double norm (char sinalc, char man[], int M, char exp[], int E)
{
    int bias = pow(2,E-1) - 1;
    double v = 0;
    double bin = 0.5;
    double total;
    double sinal;

    int expo = bitAux(E,exp) - bias;

    for (int i = 0; i <= M - 1; i++) 
    {
        if (man[i] != '0') 
        {
            v += bin;
        } 
        else 
        {
        v = v + 0;
        }
        bin /= 2.0;
    }

    if(sinalc == '0')
    {
        sinal = 1;
    }
    else 
    {
        sinal = (-1);
    }

    total = sinal * (1+v) * pow(2,expo);

    return total;
}

int main() 
{
    char buf[BUFSIZ];
    char sinal;
    char expoente[BUFSIZ] = {0};
    char mantissa[BUFSIZ] = {0};
    char formato[BUFSIZ];

    int binarios;

    if (scanf("%d", &binarios) == 1) 
    {    
        while (fgets(buf, BUFSIZ, stdin) != NULL) 
        {
            assert(buf[strlen(buf) - 1] == '\n');
            buf[strlen(buf) - 1] = 0;

            if(strlen(buf) < 3) continue;

            int E, M;
            char bits[BUFSIZ] = {0};

            sscanf(buf, "%d %d %s", &E, &M, bits);

            sprintf(formato, "%%c%%%ds%%%ds", E, M);

            sscanf(bits, formato, &sinal, expoente, mantissa);

            if (infinito(E, M, expoente, mantissa)) 
            {
                if (sinal == '0') 
                {
                    printf("+Infinity\n");
                } 
                else 
                {
                    printf("-Infinity\n");
                }
            } 
            else if ((igual(E, expoente) && expoente[0] == '1') ) 
            {
                printf("NaN\n");
            } 
            else if (zero(E, M, expoente, mantissa)) 
            {
                if (sinal == '0') 
                {
                    printf("0\n");
                } 
                else 
                {
                    printf("-0\n");
                }
            } 
            else if (igual(E, expoente) && expoente[0] == '0') 
            {
                double desnormalizado = desn(sinal, mantissa, M, E);
                printf("%lg\n", desnormalizado);
            } 
            else 
            {
                double normalizado = norm(sinal, mantissa, M, expoente, E);
                printf("%lg\n", normalizado);
            }
            binarios--;
        }

    }
    return 0;
}