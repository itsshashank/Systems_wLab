#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 10

struct symtable
{
    char symbol[max];
    int addr;
}s;

int main()
{
    char opcode[10], mnemonic[10], operand[10], label[10], code[10];
    int locctr, start, length;
    FILE *fp1, *fp2, *fp3, *fp4;
    fp1 = fopen("assemblerCode.asm","r");
    fp2 = fopen("s.dat","w");
    fp3 = fopen("out1.dat","w");
    fp4 = fopen("opcode.dat","r");
    fscanf(fp1,"%s %s %s", label, opcode, operand);
    if (strcmp(opcode,"START") == 0)
    {
        start = atoi(operand);
        locctr = start;
        fprintf(fp3,"%s\t %s\t %s\n", label, opcode, operand);
        fscanf(fp1,"%s %s %s", label, opcode, operand);
    }
    else
        locctr = 0;
    while (strcmp(opcode,"END") != 0)
    {
        fprintf(fp3,"%d\t", locctr);
        rewind(fp2);
        int found =0;
        while(fread(&s,sizeof(struct symtable),1,fp2))
        {
            if(strcmp(label,s.symbol)==0)
                found++;
        }
        if(found > 0)
        {
            printf("\n ERROR in code\n");
            return 1;
        }
        s.addr = locctr;
        if (strcmp(label,"**") != 0)
            fwrite(&s,sizeof(struct symtable),1,fp2);
        rewind(fp4);
        fscanf(fp4,"%s", mnemonic);
        while (strcmp(mnemonic,"END") != 0)
        {
            if (strcmp(opcode, mnemonic) == 0)
            {
                locctr += 3;
                break;
            }
            fscanf(fp4,"%s", mnemonic);
        }
        if (strcmp(opcode,"WORD") == 0)
            locctr += 3;
        else if (strcmp(opcode,"RESW") == 0)
            locctr += (3 * (atoi(operand)));
        else if (strcmp(opcode,"RESB") == 0)
            locctr += (atoi(operand));
        else if (strcmp(opcode,"BYTE") == 0)
            ++locctr;
        fprintf(fp3,"%s\t %s\t %s\n", label, opcode, operand);
        fscanf(fp1,"%s %s %s", label, opcode, operand);
    }
    fprintf(fp3,"%d\t %s\t %s\t %s\n", locctr, label, opcode, operand);
    length = locctr - start;
    printf("\nPass 1 completed\nThe length of the program is %d\n", length);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
}