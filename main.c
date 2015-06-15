#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void help();
int hexToNum(char);
char* itoa(int, int);
void print_everything(int, char*, char*);
void decimal(char*);
void hexadecimal(char*);
void binary(char*);
void easy_mode(char*);

int main(int argc, char *argv[])
{
    if(argc == 1 || argc < 3 || strcmp(argv[1], "--help") == 0)
        help();
    
    else if(strcmp(argv[1], "-d") == 0)
        decimal(argv[2]);
    
    else if(strcmp(argv[1], "-b") == 0)
        binary(argv[2]);
    
    else if(strcmp(argv[1], "-h") == 0)
        hexadecimal(argv[2]);
    
    else if(strcmp(argv[1], "-e") == 0)
        easy_mode(argv[2]);
    
    else
        puts("error! try --help\n");

    return 0;
}

void help()
{
    puts("--help         display help page");
    puts("-h (hex)       to converge hex to binary and decimal");
    puts("-b (binary)    to converge binary to hex and decimal");
    puts("-d (decimal)   to converge decimal to binary and hex");
    puts("-e (decimal)   convert using printf, etc");
}

int hexToNum(char hex)
{
    for (int i = 0; i < 16; i++)
    {
        //TODO: try to consolidate these 2 conditions
        if("0123456789ABCDEF"[i] == hex || "0123456789abcdef"[i] == hex)
            return i;
    }
}

char* itoa(int val, int base)
{
    int size = 0;
    int temp = val;
    for(; temp; size++, temp /= base);

    char *buf = malloc(size);                               //TODO: this is actually 4 bytes not 4 chars
   
    for(int i = --size; val; i--, val /= base)
        buf[i] = "0123456789ABCDEF"[val % base];

    return buf;
}

void print_everything(int d, char *b, char *h)
{
    printf("Decimal:       %d\n", d);
    printf("Binary:        %s\n", b);
    printf("Hexadecimal:   %s\n", h);
}

void decimal(char *decimal)
{
    int number = atoi(decimal);
    char *b;
    char *h;
    print_everything(number, b = itoa(number, 2), h = itoa(number, 16));
    free(b);
    free(h);
}

//TODO: if hexadecimal is lowercase print it uppercase
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
        char *b;
        print_everything(number, b = itoa(number, 2), hex);
        free(b);
    }
    else
        puts("Error! insert a valid hexadecimal.\n");
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
        char *h;
        print_everything(number, bin, h = itoa(number, 16));
        free(h);
    }
    else
        puts("Error! insert a valid binary.\n");
}

void easy_mode(char *c)
{
    int d = atoi(c);                                        //TODO: implement own atoi
    char *b;

    printf("Decimal:       %d\n", d);
    printf("Binary:        %s\n", b = itoa(d, 2));          //TODO: I dont think there's a shorter way for binary
    printf("Hexadecimal:   %X\n", d);

    free(b);
}
