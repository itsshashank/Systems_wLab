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
//dirty code
char *itoa(long i, char *s, int dummy_radix)
{
    sprintf(s, "%ld", i);
    return s;
}
int main()
{
    FILE *fin, *fsymt, *fop, *fout, *fopgm;
    int addr, len, startaddr, end;
    char filename[max];
    printf("Enter the intermediate file(output of pass 1) :");
    scanf("%s", filename);
    fin = fopen(filename, "rb");
    printf("Enter the output file :");
    scanf("%s", filename);
    fout = fopen(filename, "wb");
    fop = fopen("opcode.dat", "rb");
    fsymt = fopen("symt.dat", "rb");
    char outcode[max], a[max];
    fscanf(fin, "%s %s %s", in.label, in.opcode, in.operand);
    if (strcmp(in.opcode, "START") == 0)
    {
        fprintf(fout, "%s\t%s\t%s\n", in.label, in.opcode, in.operand);
        startaddr = atoi(in.operand);
    }
    while (fscanf(fin, "%s %s %s %s", outcode, in.label, in.opcode, in.operand) != EOF)
    {
        end = atoi(outcode);
        fprintf(fout, "%s\t%s\t%s\t%s\t", outcode, in.label, in.opcode, in.operand);
        if (strcmp(in.opcode, "RESW") == 0 || strcmp(in.opcode, "RESB") == 0)
        {
            fprintf(fout, "*\n");
            continue;
        }
        else if (strcmp(in.opcode, "WORD") == 0)
        {
            len = strlen(in.operand);
            itoa(atoi(in.operand), a, 10);
            fprintf(fout, "00000%s\n", a);
            continue;
        }
        else if (strcmp(in.opcode, "BYTE") == 0)
        {
            len = strlen(in.operand);
            int actual_len = len - 3;
            for (int i = 2; i < (actual_len + 2); i++)
            {
                itoa(in.operand[i], a, 16);
            }
            strcpy(outcode, a);
        }
        else
        {
            //search for the opcode
            rewind(fop);
            while (fscanf(fop, "%s %s", o.code, o.size) != EOF)
            {
                if (strcmp(o.code, in.opcode) == 0)
                {
                    strcpy(outcode, o.size);
                    break;
                }
            }
            char temp[max];
            //search symbol
            rewind(fsymt);
            while (fscanf(fsymt, "%s %s", s.symbol, temp) != EOF)
            {
                if (strcmp(s.symbol, in.operand) == 0)
                    break;
            }
            strcat(outcode, temp);
        }
        fprintf(fout, "%s\n", outcode);
    }
    end -= startaddr ;
    end++;
    fclose(fout);
    printf("Pass 2 Completed Sucessfully check finalout File\n");
    //fclose(fopgm);
    fclose(fin);
    fclose(fsymt);
    fclose(fop);
    fout = fopen("finalout.x","r");
    fopgm = fopen("objprogram.dat","w");
    fscanf(fout,"%s%s%s",in.label,in.opcode,in.operand);
    if(strcmp(in.opcode,"START")==0)
    {
        itoa(end,outcode,16);
        fprintf(fopgm,"H^%s^%s^%s\n",in.label,in.operand,outcode);
    }
    char imp[max];
            fprintf(fopgm,"T^%s^%s",in.operand,outcode);
    while(fscanf(fout,"%s%s%s%s%s",outcode,in.label,in.opcode,in.operand,imp)!=EOF)
    {
        if(strcmp(in.opcode,"WORD")==0 || strcmp(in.opcode,"BYTE")==0)
        {
            fprintf(fopgm,"\nT^%s^02^%s",outcode,imp);
        }
        else if(strcmp(imp,"*")!=0)
            fprintf(fopgm,"^%s",imp);
    }
    itoa(startaddr,outcode,16);
    fprintf(fopgm,"\nE^00%s\n",outcode);
    fclose(fout);
    fclose(fopgm);
    return 0;
}