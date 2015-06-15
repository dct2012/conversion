#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void help();
char hexTable(int);
void decimalToBinary(int);
void decimalToHex(int);
void decimal(char*);
void hexadecimal(char*);
void binary(char*);

int main(int argc, char *argv[])
{
        if(argc == 1 || strcmp(argv[1], "--help") == 0)
        {
                help();
        }
        else if(argc < 3)
        {
                puts("error! try --help\n");
        }
        else if(strcmp(argv[1], "-d") == 0)
        {
                decimal(argv[2]);
        }
        else if(strcmp(argv[1], "-b") == 0)
        {
                binary(argv[2]);
        }
        else if(strcmp(argv[1], "-h") == 0)
        {
                hexadecimal(argv[2]);
        }
        else
        {
                puts("error! try --help\n");
        }

        return 0;
}

void help()
{
        puts("--help         display help page");
        puts("-h (hex)       to converge hex to binary and decimal");
        puts("-b (binary)    to converge binary to hex and decimal");
        puts("-d (decimal)   to converge decimal to binary and hex");
}

char hexTable(int temp)
{
        char hex;

        switch(temp)
        {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                        hex = temp + '0';
                        break;
                case 10:
                        hex = 'A';
                        break;
                case 11:
                        hex = 'B';
                        break;
                case 12:
                        hex = 'C';
                        break;
                case 13:
                        hex = 'D';
                        break;
                case 14:
                        hex = 'E';
                        break;
                case 15:
                        hex = 'F';
                        break;
                default:
                        hex = '0';
                        break;
        }

        return hex;
}

int hexToNum(char hex)
{
        int number;

        switch(hex)
        {
                case '0':
                        number = 0;
                        break;
                case '1':
                        number = 1;
                        break;
                case '2':
                        number = 2;
                        break;
                case '3':
                        number = 3;
                        break;
                case '4':
                        number = 4;
                        break;
                case '5':
                        number = 5;
                        break;
                case '6':
                        number = 6;
                        break;
                case '7':
                        number = 7;
                        break;
                case '8':
                        number = 8;
                        break;
                case '9':
                        number = 9;
                        break;
                case 'a':
                case 'A':
                        number = 10;
                        break;
                case 'b':
                case 'B':
                        number = 11;
                        break;
                case 'c':
                case 'C':
                        number = 12;
                        break;
                case 'd':
                case 'D':
                        number = 13;
                        break;
                case 'e':
                case 'E':
                        number = 14;
                        break;
                case 'f':
                case 'F':
                        number = 15;
                        break;
                default:
                        number = -1;
                        break;
        }

        return number;
}

void decimalToBinary(int number)
{
        int size;

        if(number > 65535)
        {
                size = 24;
        }
        else if(number > 255)
        {
                size = 16;
        }
        else
        {
                size = 8;
        }
        
        char binary[size];

        int temp;
        for(int i = (size - 1); i > -1; i--)
        {
                temp = number % 2;
                if(temp != 0)
                {
                        binary[i] = '1';
                }
                else
                {
                        binary[i] = '0';
                }

                number = number - temp;
                number = number / 2;
        }

        printf("Binary:        ");
        for(int i = 0; i < size; i++)
        {
                printf("%c", binary[i]);
        }

        printf("\n");
}

void decimalToHex(int number)
{
        int size;

        if(number > 65535)
        {
                size = 6;
        }
        else if(number > 255)
        {
                size = 4;
        }
        else
        {
                size = 2;
        }
        
        char hex[size];

        int temp;
        for(int i = (size - 1); i > -1; i--)
        {
                temp = number % 16;
                
                hex[i] = hexTable(temp);

                number = number - temp;
                number = number / 16;
        }

        printf("Hexadecimal:   ");
        for(int i = 0; i < size; i++)
        {
                printf("%c", hex[i]);
        }
        printf("\n");
}

void decimal(char *decimal)
{
        int number = atoi(decimal);
        printf("Decimal:       %d\n", number);
        decimalToBinary(number);
        decimalToHex(number);
}

void hexadecimal(char *hex)
{
        int size = 0;
        bool flag = true;
        
        for(int i = 0; hex[i]; i++)
        {
                size = i;
        }
       
        int temp = 0;
        int number = 0;
        for(int i = 0; hex[i]; i++)
        {
                temp = hexToNum(hex[i]);

                if(temp == -1)
                {
                        flag = false;
                }

                number = number + (temp * pow(16, size));

                size--;
        }
        
        if(flag)
        {
                printf("Decimal:       %d\n", number);
                decimalToBinary(number);
                printf("Hexadecimal:   %s\n", hex);
        }
        else
        {
                puts("Error! insert a valid hexadecimal.\n"); 
        }
}

void binary(char *bin)
{
        int size = 0;
        bool flag = true;
        
        for(int i = 0; bin[i]; i++)
        {
                size = i;
        }
       
        int number = 0;
        for(int i = 0; bin[i]; i++)
        {
                if(bin[i] != '0' && bin[i] != '1')
                {
                        flag = false;
                }
                
                if(bin[i] == '1')
                {
                        number = number + pow(2, size);
                }

                size--;
        }
        
        if(flag)
        {
                printf("Decimal:       %d\n", number);
                printf("Binary:        %s\n", bin);
                decimalToHex(number);
        }
        else
        {
                puts("Error! insert a valid binary.\n"); 
        }
}
