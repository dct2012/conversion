#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void help();
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

int hexadecimal_char_to_int(char hex)
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
    int number = atoi(decimal); //TODO; create own atoi, also check if decimal
    char *b;
    char *h;
    print_everything(number, b = itoa(number, 2), h = itoa(number, 16));
    free(b);
    free(h);
}

bool is_hexadecimal(char *h)
{
    for(int i = 0; h[i]; i++)
    {
        // the chars 0-9 = int values 48-57
        // the chars A-F = int values 65-70
        // the chars a-f = int values 97-102
        if(h[i] < 48 || h[i] > 102 || (h[i] > 57 && h[i] < 65) || (h[i] > 70 && h[i] < 97))
            return false;
    }

    return true;
}

int hexadecimal_to_int(char *h)
{
    int val = 0;

    int size;
    for(size = 0; h[size + 1]; size++);

    for(int i = 0; h[i]; i++)
    {
        val += hexadecimal_char_to_int(h[i]) * pow(16, size);

        size--;
    }

    return val;
}

//TODO: if hexadecimal is lowercase print it uppercase
//      print hexadecimals at lengths of 2, 4, ...
void hexadecimal(char *hex)
{
    if(is_hexadecimal(hex))
    {
        char *b;
        int i = hexadecimal_to_int(hex);
        print_everything(i, b = itoa(i, 2), hex);
        free(b);
    }
    else
        puts("Error! insert a valid hexadecimal.\n");
}

bool is_binary(char* b)
{
    for(int i = 0; b[i]; i++)
        if(b[i] != '0' && b[i] != '1')
            return false;

    return true;
}

int binary_to_int(char *b)
{
    int val = 0;
    
    int size;
    for(size = 0; b[size + 1]; size++);

    for(int i = 0; b[i]; i++)
    {
        if(b[i] == '1')
            val += pow(2, size);

        size--;
    }

    return val;
}

//TODO: print binary at lengths of 8, 16, ...
void binary(char *bin)
{    
    if(is_binary(bin))
    {
        char *h;
        int i = binary_to_int(bin);
        print_everything(i, bin, h = itoa(i, 16));
        free(h);
    }
    else
        puts("Error! insert a valid binary.\n");
}

void easy_mode(char *c)
{
    int d = atoi(c);    //TODO: implement own atoi, check if decimal
    char *b;

    printf("Decimal:       %d\n", d);
    printf("Binary:        %s\n", b = itoa(d, 2)); //I dont think there's a shorter way for binary
    printf("Hexadecimal:   %X\n", d);

    free(b);
}
