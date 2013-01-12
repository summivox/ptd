#include <stdio.h>
#include <stdlib.h>

typedef unsigned char u8;

static void swap_u8(u8* a, u8* b){
    u8 c=*a; *a=*b; *b=c;
}

static void transform(u8* buf, size_t len){
    u8* end=buf+len;
    for(u8* p=buf;p<end;){
        *p++^=(u8)0x03;
        *p++^=(u8)0x18;
    }

    u8* end2=end-16;
    for(u8* p=buf;p<=end2;p+=16){
        swap_u8(p+ 0, p+ 8);
        swap_u8(p+ 1, p+ 9);
        swap_u8(p+ 5, p+13);
        swap_u8(p+ 6, p+14);
    }
}

#define BUF_SIZE 32768
u8 buf[BUF_SIZE];

int main(int argc, char** argv){
    if(argc!=3){
        puts("Usage: ptd <input> <output>\n");
        return 1;
    }
    FILE* fin=fopen(argv[1], "rb");
    if(!fin){
        printf("Error: cannot open input file %s \n", argv[1]);
        return 2;
    }
    FILE* fout=fopen(argv[2], "wb");
    if(!fout){
        printf("Error: cannot open output file %s \n", argv[2]);
        return 2;
    }

    size_t len;
    do{
        len=fread(buf, 1, BUF_SIZE, fin);
        transform(buf, len);
        fwrite(buf, 1, len, fout);
    }while(len==BUF_SIZE);
    return 0;
}
