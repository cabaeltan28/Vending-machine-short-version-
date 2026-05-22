#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define file_tan "tan_store.txt"
#define file_patricia "patricia_store.txt"
#define file_nizzah "nizzah_store.txt"
#define file_cabarloc "cabarloc_store.txt"
#define file_inventory "file_inventory.txt"
#define file_money "file_money.txt"
typedef struct{
    char name[50];
    int price;
    int stock;
}Product;
void check_files();
int main(){
    Product *product[4];
    int sizes[4];


    return 0;
}
void check_files() {
    FILE *fp;

    fp = fopen(file_tan, "r");

    if (fp == NULL) {
        fp = fopen(file_products, "w");

        fprintf(fp, "Coke 35 10\n");
        fprintf(fp, "Water 20 15\n");
        fprintf(fp, "Royal 25 10\n");
        fprintf(fp, "Pepsi 30 15\n");
        fprintf(fp, "Sprite 30 15\n");

        fclose(fp);
    } else {
        fclose(fp);
    }
    fp = fopen(file_patricia, "r");

    if (fp == NULL) {
        fp = fopen(file_patricia, "w");

        fprintf(fp, "Oishi 10 10\n");
        fprintf(fp, "Clover 10 15\n");
        fprintf(fp, "Piatos 20 10\n");
        fprintf(fp, "Cracklings 10 15\n");
        fprintf(fp, "Marty's 10 15\n");

        fclose(fp);
    } else {
        fclose(fp);
    }
fp = fopen(file_nizzah, "r");

    if (fp == NULL) {
        fp = fopen(file_nizzah, "w");

        fprintf(fp, "Fita 10 10\n");
        fprintf(fp, "Lava 10 15\n");
        fprintf(fp, "Bravo 10 10\n");
        fprintf(fp, "Bingo 10 15\n");
        fprintf(fp, "Cloud9 10 15\n");

        fclose(fp);
    } else {
        fclose(fp);
    }
    fp = fopen(file_cabarloc, "r");

    if (fp == NULL) {
        fp = fopen(file_cabarloc, "w");

        fprintf(fp, "Mentos 2 50\n");
        fprintf(fp, "Maxx 2 50\n");
        fprintf(fp, "Nips 2 10\n");
        fprintf(fp, "V-fresh 2 50\n");
        fprintf(fp, "Jugde 2 50\n");

        fclose(fp);
    } else {
        fclose(fp);
    }

    fp = fopen(file_inventory, "r");

    if (fp == NULL) {
        fp = fopen(file_inventory, "w");
        fclose(fp);
    } else {
        fclose(fp);
    }

    fp = fopen(file_money, "r");

    if (fp == NULL) {
        fp = fopen(file_money, "w");
        fprintf(fp, "500");
        fclose(fp);
    } else {
        fclose(fp);
    }
}