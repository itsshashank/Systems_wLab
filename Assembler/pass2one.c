#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 10
struct incode
{
    char label[max], opcode[max], operand[max];
} in;
struct symT
{
    char symbol[max];
    int addr;
} s;
struct opcode
{
    char code[max];
    char size[max];
}
int main()
{
    int locctr, start, len;
    FILE *fin, *fsymt, *fop, *fout;
    char filename[max];
    printf("Enter the asm file name :");
    scanf("%s", filename);
    fin = fopen(filename, "rb");
    //symbol table
    fsymt = fopen("symt.dat", "wb");
    printf("Enter the output file :");
    scanf("%s", filename);
    fout = fopen(filename, "wb");
    fop = fopen("opcode.dat", "rb");
    //FirstLine
    fread(&in,sizeof(struct incode),1,fin);
    if (strcmp(in.opcode,"START") == 0)
    {
        start = atoi(in.operand);
        locctr = start;
        fwrite(&in,sizeof(struct incode),1,fout);
    }
    else
        locctr = 0;
    while(fread(&in,sizeof(struct incode),1,fin))
    {
        if(strcmp(in.opcode,"END")==0)
            break;
        fprintf(fout,"%d\t",locctr);
        rewind(fsymt);
        while(fread(&s,sizeof(struct symT),1,fsymt))
        {
            if(strcmp(in.label,s.symbol)==0)
            {
                printf("\nERROR in code");
                return 1;
            }
        }
        s.symbol = in.label;
        s.addr = locctr;
        fwrite(&s,sizeof(struct symT),1,fsymt);
        rewind(fop);

    }
    fclose(fin);
    fclose(fsymt);
    fclose(fop);
    len = locctr - start;
    printf("\nPASS one completed\nThe len of the program is %d\n", len);
    fclose(fout);
    return 0;
}