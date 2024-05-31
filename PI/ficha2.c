#include <stdio.h>

int verificasesim (int s[], int n)
{
    int i;
    for(i=1; i < n ; i++)
    {
        if(s[0]!= s[i]+2 && s[0] != s[i] + 4 && s[0] != s[i]-2 && s[0]!= s[i]-4) return 0;
    }
    return 1;
}

int main()
{
    int seq1[]={1,3,5};
    int seq2[]={5,3,1};
    int seq3[]={5,2,1};

    if (verificasesim(seq1,3)) printf("lindo...\n");
    else printf("mau!\n");  
    if (verificasesim(seq2,3)) printf("lindo...\n");
    else printf("mau!\n"); 
    if (verificasesim(seq3,3)) printf("lindo...\n");
    else printf("mau!\n"); 
    return 0;
}