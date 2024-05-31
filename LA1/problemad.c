#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

double frqRel[26] = {43.31 , 10.56 , 23.13 , 17.25 , 56.88 , 9.24 , 12.59 , 15.31 , 38.45 , 1.00 , 5.61 , 27.98 , 15.36 ,  33.92 ,  36.51 , 16.14 , 1.00, 38.64 , 29.23 , 35.43 , 18.51 , 5.13 , 6.57 , 1.48 , 9.06 , 1.39};


int nivelLetra (char letra)
{
    if(isupper(letra)) 
    {
        return letra - 'A';
    } 
    else 
    {
        return letra - 'a';
    }
}

double frasePaFreq(char frase[],double freq[])
{
    int size = 0;
    int letras[26] = {0};
    double freqT = 0;

    for( int i = 0 ; frase[i] != '\0'; i++)
    {
        if(isalpha(frase[i]))
        {
        letras[nivelLetra(frase[i])] ++;
        size ++; 
        }
    }
    for (int i = 0; i < 26; i++)
    {
        freqT += pow((freq[i] - letras[i]),2) / freq[i];

    }
    return freqT;
}
void decifra(char *frase, int posicao)
{
    char mainusco;
    for(int i = 0; i < (int)strlen(frase)-1; i++)
    {
        if(isalpha(frase[i]))
        {
            if(isupper(frase[i]))
            {
                mainusco = 'A';
            }
            else
            {
                mainusco = 'a';
            }

            int novoNivel = (nivelLetra(frase[i]) + 26 - posicao) % 26;
                  
            frase[i] = mainusco + novoNivel;
        }
    }
}


int main()
{
    char frase[10000] = {0};
    double ft = 99999;
    int posicao = 0;
    int maiorFreq = 0;    

 while (fgets(frase, 1000, stdin) != NULL)
 {
    for(posicao = 0; posicao < 26; posicao++)
    {
        if(frasePaFreq(frase,frqRel) < ft)
        {
            ft = frasePaFreq(frase,frqRel);
            maiorFreq = posicao;
        }
        decifra(frase,-1);
    }
    

    decifra(frase,(-1) * maiorFreq);

    printf("%d ", maiorFreq);

    printf("%s" ,frase);
    break;
    }
    return 0;
}
