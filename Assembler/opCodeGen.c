#include <stdio.h>
#define max 10
struct opcode
{
    char mnemonic[max];
    char code[max/2];
} o;
void main()
{
    char fname[max];
    printf("enter the file name to store the opcode table:");
    scanf("%s",fname);
    FILE *f;
    f=fopen(fname,"wb");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %s",o.mnemonic,o.code);
        fprintf(f,"%s \t %s \n",o.mnemonic,o.code);
    }
    fclose(f);
}