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
void scan_files();
int mymoney();
void view_tan(Product *products[], int sizes[], int *timailhan);
void view_patricia(Product *products[], int sizes[]);
void view_nizzah(Product *products[], int sizes[]);
void view_cabarloc(Product *products[], int sizes[]);
void view_products(Product *products[],int sizes[]);

int main(){
    Product *products[4];
    int sizes[4];
    int money;
    int choice;
    for(int i=0;i<4; i++){
        products[i]=malloc(sizeof(Product)*100);
    }
    money=mymoney();
    check_files();
    scan_files(products, sizes);
    do{
        
        printf("====================================\n");
        printf("====This is PBCT Vending Machine====\n");
        printf(" Barato na may tsansa pang manalo ka\n");
        printf("          ===============\n\n\n");
        printf("1. Buy Product\n2. View Product\n3. View personal inventory\n");
        printf("4. Play Mystery box game\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 2: view_products(products, sizes);
        }
    }while(choice!=0);
    
    return 0;
}
void check_files() {
    FILE *fp;

    fp = fopen(file_tan, "r");

    if (fp == NULL) {
        fp = fopen(file_tan, "w");

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
void scan_files(Product *products[], int sizes[]){
    FILE *fp;
    char *myfiles[]={
        file_tan,file_patricia,file_nizzah,file_cabarloc
    };
    for(int i=0; i<4;i++){
    int j=0;
    fp=fopen(myfiles[i],"r");
    if(fp==NULL)continue;
    while(fscanf(fp, "%s %d %d", products[i][j].name, &products[i][j].price,&products[i][j].stock)==3){
        j++;
    }
    fclose(fp);
    sizes[i]=j;
}   
}
int mymoney(){
    FILE *fp;
    int money;
    fp=fopen(file_money,"r");
    fscanf(fp,"%d", &money);
    fclose(fp);
    return money;
}
void view_tan(Product *products[], int sizes[], int *timailhan){
    int choice;
    do{
    printf("====================================\n");
    printf("---------- Tan's store -------------\n");
    printf(" lami lami lami lami lami lami kaayo\n\n\n");
    for(int i=0; i<sizes[0]; i++){
        printf("%d. %s %d %d\n", i+1,products[0][i].name, products[0][i].price,products[0][i].stock);
    }
    printf("1. Go back to previous menu\n");
    printf("2. Go back to main menu\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    if(choice==2){
        *timailhan=1;
    }
    }while(choice!=1 || choice!=2);
}
void view_products(Product *products[], int sizes[]){
    int choice, timailhan=0;
    do{
    printf("====================================\n");
    printf("--- You are now viewing products ---\n");
    printf("    ----------------------------\n\n\n");
    printf("1. Tan's store\n");
    printf("2. Patricia's store\n");
    printf("3. Nizzah's store\n");
    printf("4. Cabarloc's store\n");
    printf("5. Go back to main menu\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1: view_tan(products, sizes, &timailhan);break;
    }
    if(timailhan==1)break;
    }while(choice!=5||timailhan==1);
}