#include <stdio.h>
#define SIZE 50
#include <string.h>

int maior(int val) 
{
        scanf("%d \n", &val);
        int max = val;
            while (val != 0) 
            {
                if (val>max) max = val;
                scanf("%d \n", &val);
            }
    printf("%d \n", max);
    return max;
}

int media(int val)
{
        int i=0; int r=0;
        scanf("%d", &val);
            while (val!=0)
            {
                i++;
                r+=val;
                scanf("%d", &val);
            }
        return r/i;
}   

int segundoMaior (int val)
{
    int maior,smaior;
    maior = smaior = 0;
    scanf("%d", &val);
    while (val != 0) 
        {
        if (val > maior) {
            smaior = maior;
            maior = val;
        } 
        else if (val > smaior && val != maior) 
        {
            smaior = val;
        }
        scanf("%d", &val);
    }
    return smaior;
}

int bitsUm (unsigned int n)
{
    int uns = 0;
    for(int i = n; i > 0; i/=2)
    {
        if(i%2==1) uns++;
    }
    return uns;
}

int trailingZ (unsigned int n)
{
    int zeros = 0;
    for(int i = n; i>0; i/=2)
    {
        if(i % 2 == 0) zeros++;
    }
    return zeros;
}

int qDig (unsigned int n)
{
    int i=n;
    int contador=0;
    while(i>0)
    {
    i/=10;
    contador++;
    }
    return contador;
}

char *strcatquim (char *s1, char *s2)
{
    int i, j;
    for(i=0 ; s1[i]!= '\0';i++)
    ;
    for(j=0; s2[j]!='\0';j++,i++)
    {
    s1[i] = s2[j];
    }
    s1[i]= '\0';
    return s1;
}

char *strcpyquim (char *dest, char source[])
{
    int i;
    for(i=0;source[i]!='\0';i++)
    {
        dest[i]=source[i];
    }
    dest[i]='\0';
    return dest;
}

int strcmpquim (char s1[], char s2[])
{
    int r;
    if(strlen(s1) > strlen(s2)) r=strlen(s2);
    else r=strlen(s1);
    for(int i=0;i<r;i++)
    {
        if((s1[i]-s2[i])>0) return 1;
        if((s1[i]-s2[i])<0) return -1;
    }
    return 0;
}

char *mystrstr(char s1[], char s2[]) {
    char *res = NULL;
    int i,p;
    if (s2[0] == '\0') return s1;
    for(i = 0; s1[i] != '\0' && res == NULL; i++) {
        for(p = 0; s2[p] != '\0' && s2[p] == s1[i+p];p++);
        if (s2[p] == '\0')
            res = s1 + i;
    }
    return res;
}

void swap (char s[], int n, int b)
{
    char i = s[n];
    s[n]=s[b];
    s[b]=i;
}

void strrev (char s[])
{
    int i, r=strlen(s);
    for(i=0;i<r/2;i++)
    {
        swap(s,i,r-i-1);   
    }
}

int isVogal(char n)
{
    if (n == 'A' ||  n == 'E' || n == 'I' ||  n == 'O' || n == 'U' ||  n == 'a' || n == 'e' ||  n == 'i' || n == 'o' ||  n == 'u')
    return 1;
    else return 0;
}

void strnoV (char s[])
{
    int i, j;
    for(i=0;s[i]!='\0';i++)
    {
        if(isVogal(s[i]))
        {
            for(j=i; s[j]!='\0';j++)
            {
                s[j]=s[j+1];
            }
            s[j]='\0';
            i--;
        }
    }
}

void truncW (char t[], int n)
{
    int i, ad, pos;
    for(i=0, ad=0,pos=0; t[i]!='\0'; i++)
        {
            if(t[i]==' ')
            {
                ad = 0;
                t[pos++]= t[i];
            }
            else if(ad<n)
            {
                t[pos++]=t[i];
                ad++;
            }
        }
    t[pos] = '\0';
}

char charMaisFreq (char s[])
{
    char maisFreq = '0';
    int i,j,f,freq=0;
    for(i=0;s[i]!='\0';i++)
    {
        f=0;
        for(j=0;s[j]!='\0';j++)
        {
            if (s[i]==s[j])f++;
        }
        if(freq<f)
        {
            maisFreq = s[i];
            freq = f;
        }
    }
    return maisFreq;
}

int iguaisCons(char s[]) {
    int i, count = 1, maxCount = 1;
    for (i = 1; s[i] != '\0'; i++) 
    {
        if (s[i] == s[i - 1]) 
        {
            count++;
            if (count > maxCount) 
            {
                maxCount = count;
            }
        } 
        else 
        {
            count = 1;
        }
    }
    return maxCount;
}

int diferentesCons (char s[])
{
    int i, count=1, maxCount = 1;
    for (i=1; s[i] != '\0';i++)
    {
        if(s[i] != s[i-1])
        {
            count++;
            if (count>maxCount)
            {
                maxCount = count;
            }
        }
        else
        {
            count=1;
        }
    }
    return maxCount;
}

int main()
{
    /*printf("Digite números (0 para acabar) \n");
    int vmax;
    scanf("%d \n", &vmax);
    int rmax = maior(vmax);
    printf("O Max é %d \n", rmax);
    printf("Digite números (0 para acabar) \n");
    int valor;
    int result;
    scanf("%d \n", &valor);
    result = media(valor);
    printf("A média é %d \n" , result);
    printf("Digite números (0 para acabar) \n");   
    int v2m;
    scanf("%d \n", &v2m);
    int rmax2 = segundoMaior(v2m);
    printf("O 2º Max é %d \n", rmax2);
    printf("Diz aí um numaro para ver quantos uns tem em binario \n");
    int bin1;
    scanf ("%d \n", &bin1);
    int resp;
    resp = bitsUm(bin1);
    printf ("Têm %d uns \n", resp);
    int r6 = qDig(440);
    printf("Resposta: %d \n", r6); 
    char s1[SIZE] = "quim";
    char *s2 = "cao";
    strcatquim(s1,s2);
    printf ("%s \n",s1);
    const char *src = "josecarlos";
    char dest[SIZE] = "";

    // Certifique-se de que dest tem espaço suficiente para armazenar a string
    if (sizeof(dest) >= sizeof(src)) {
        strcpyquim(dest, src);
        printf("%s\n", dest);
    } else {
        printf("Dest não tem espaço suficiente para armazenar a string.\n");
    } */
    char s11[]="aaeecccppoishjkryseusadashkdhhdjsdhsj";
    int r15=diferentesCons("abcdefghijklmnopqrstuvwyz");
    printf("Fica: %d\n", r15);
    return 0;
}

