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
} o;
int main()
{
    int locctr, start, len;
    FILE *fin, *fsymt, *fop, *fout;
    char filename[max];
    printf("Enter the asm file name :");
    scanf("%s", filename);
    fin = fopen(filename, "rb");
    printf("Enter the output file :");
    scanf("%s", filename);
    fout = fopen(filename, "wb");
    fop = fopen("opcode.dat", "rb");
    //FirstLine
    fsymt = fopen("symt.dat", "wb");
    fclose(fsymt); // to clear
    fscanf(fin, "%s %s %s", in.label, in.opcode, in.operand);
    if (strcmp(in.opcode, "START") == 0)
    {
        start = atoi(in.operand);
        locctr = start;
        fprintf(fout, "%s\t%s\t%s\n", in.label, in.opcode, in.operand);
        /*fprintf(fsymt, "%s\t%s\n", in.opcode, in.operand);
        fclose(fsymt);*/
    }
    else
        locctr = 0;
    while (fscanf(fin, "%s %s %s", in.label, in.opcode, in.operand) != EOF)
    {
        fsymt = fopen("symt.dat", "rb");
        printf("the code is %s %s %s\n", in.label, in.opcode, in.operand);
        if (strcmp(in.opcode, "END") == 0){
            fclose(fsymt);
            break;
        }
        fprintf(fout, "%d\t", locctr);
        //printf("\nfile location of write is %d", ftell(fsymt));
        while (fscanf(fsymt, "%s", s.symbol) != EOF)
        {
            printf("comparing the symbol to symbol tabel %s with %s\n", in.label, s.symbol);
            if (strcmp(s.symbol, in.label) == 0)
            {
                printf("\n ERROR in code :(\n");
                return 1;
            }
        }
        fclose(fsymt);

        if (strcmp(in.label, "**") != 0)
        {
            fsymt = fopen("symt.dat", "ab");
            strcpy(s.symbol, in.label);
            s.addr = locctr;
            printf("writing the symbol to symbol tabel %s\n", in.label);
            fprintf(fsymt, "%s\t%d\n", s.symbol, s.addr);
            //towrite completely
            fclose(fsymt);
        }

        rewind(fop);
        fscanf(fop, "%s", o.code);
        while (strcmp(o.code, "END") != 0)
        {
            if (strcmp(in.opcode, o.code) == 0)
            {
                locctr += 3;
                break;
            }
            fscanf(fop, "%s", o.code);
        }
        if (strcmp(in.opcode, "WORD") == 0)
            locctr += 3;
        else if (strcmp(in.opcode, "RESW") == 0)
            locctr += (3 * (atoi(in.operand)));
        else if (strcmp(in.opcode, "RESB") == 0)
            locctr += (atoi(in.operand));
        else if (strcmp(in.opcode, "BYTE") == 0)
            ++locctr;//strlen
        fprintf(fout, "%s\t %s\t %s\n", in.label, in.opcode, in.operand);
    }
    fclose(fin);
    fclose(fop);
    len = locctr - start;
    printf("\nPASS one completed\nThe len of the program is %d\n", len);
    fclose(fout);
    return 0;
}