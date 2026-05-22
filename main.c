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
void view_ourstores(int i, Product *products[], int sizes[], int *timailhan);
void view_products(Product *products[],int sizes[]);
void calculation(int i, int j, int quantity, Product *products[], int *money, int sizes[]);
void buy_tan(int i, Product *products[], int sizes[], int *timailhan, int *money);
void buy_products(Product *products[], int sizes[], int *money);
void update_money(int money);
void viewInventory(int money);
void add_money(int *money);
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
        printf("          ===============\n\n");
        printf("1. Buy Product\n2. View Product\n3. View personal inventory\n");
        printf("4. Add money\n5. Play Mysterious box game\n");
        printf("\nYou inserted : PHP%d", money);
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: buy_products(products,sizes, &money);break;
            case 2: view_products(products, sizes);break;
            case 3: viewInventory(money);
            case 4: add_money(&money);
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

void view_ourstores(int i, Product *products[], int sizes[], int *timailhan){
    int choice;
    char *files[]={
        "Tan's","Patricia's","Nizzah's","Cabarloc's"
    };
    do{
    printf("====================================\n");
    printf("---------- %s store -------------\n",files[i-1]);
    printf(" lami lami lami lami lami lami kaayo\n\n\n");
    for(int k=0; k<sizes[i-1]; k++){
        printf("%d. %s %d %d\n", k+1,products[i-1][k].name, products[i-1][k].price,products[i-1][k].stock);
    }
    printf("\n\n1. Go back to previous menu\n");
    printf("2. Go back to main menu\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    if(choice==2){
        *timailhan=1;
    }else if(choice==1){
        break;
    }else{
        printf("Invalid choice!\n");
    }
    }while(choice!=1 && choice!=2);
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
    if(choice>=1&&choice<=4){
        view_ourstores(choice, products, sizes, &timailhan);
    }else if(choice==5){
        break;
    }else{
        printf("Invalid Entry!\n");
    }
    if(timailhan==1)break;
    }while(choice!=5);
}
void calculation(int i, int j, int quantity, Product *products[], int *money,int sizes[]){
    int m=*money;
    if(products[i-1][j-1].stock==0){
        printf("%s out of stock!\n", products[i-1][j-1].name);
        return ;
    }
    if(quantity>products[i-1][j-1].stock){
           printf("You can not buy %d %ss because there are only %d %ss left!\n",quantity,products[i-1][j-1].name, products[i-1][j-1].stock, products[i-1][j-1].name);  
        return;
    }
    int total_price=products[i-1][j-1].price*quantity;
    products[i-1][j-1].stock-=quantity;
    if(*money<total_price){
        if(quantity==1){
        printf("Not enough money! You only have PHP%d left and %d %s cost %d\n", *money, quantity,products[i-1][j-1].name, total_price);
        }else if(quantity>1){
            printf("Not enough money! You only have PHP%d left and %d %ss cost %d\n", *money, quantity,products[i-1][j-1].name, total_price);
        }
        return;
    }
    printf("-------RECIEPT-------\n");
    if(quantity==1){
    printf("\nYou bought %d %s\n\n",quantity, products[i-1][j-1].name);
    }else if(quantity>1){
        printf("\nYou bought %d %ss\n\n",quantity, products[i-1][j-1].name);
    }
    for(int k=0; k<quantity;k++){
        printf("%s   PHP %d.00\n",products[i-1][j-1].name, products[i-1][j-1].price);
    }
    printf("---------------------\n");
    printf("Your cash: PHP %d.00", m);
    printf("\nTotal = %d.00\n", total_price);
    *money-=total_price;
    printf("Remaining money= PHP%d.00\n", *money);
    update_money(*money);
    FILE *fp;
     fp = fopen(file_inventory, "a");
    getchar();
    fprintf(fp, "%s - PHP %d (Quantity: %d) Total: %d\n",
            products[i-1][j-1].name,
            products[i-1][j-1].price,
            quantity, total_price);

    fclose(fp);
    char *files[]={
        file_tan, file_patricia, file_nizzah, file_cabarloc
    };
    fp=fopen(files[i-1], "w");
    for(int k=0; k<sizes[i-1]; k++){
        fprintf(fp,"%s %d %d\n",products[i-1][k].name, products[i-1][k].price,products[i-1][k].stock);
    }
    fclose(fp);

}
void buy_tan(int i, Product *products[], int sizes[], int *timailhan, int *money){
    int choice;
    int k=i-1;
    char *files[]={
        "Tan's","Patricia's","Nizzah's","Cabarloc's"
    };
    do{
    int j, quantity;
     printf("====================================\n");
    printf("---------- %s store -------------\n", files[k]);
    printf(" lami lami lami lami lami lami kaayo\n\n");
    for(int i=0; i<sizes[k]; i++){
        printf("%d. %s %d %d\n", i+1,products[k][i].name, products[k][i].price,products[k][i].stock);
    }
    printf("\nEnter what do you want to buy: ");
    scanf("%d", &j);
    if(j>=1&&j<=sizes[k]){
    printf("How many %s do you want to buy: ", products[i-1][j-1].name);
    scanf("%d", &quantity);
    calculation(i,j, quantity, products, money, sizes);
    printf("\n1. Buy again\n");
    printf("2. Go back to previous menu\n");
    printf("3. Go back to main menu\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    if(choice==3){
        *timailhan=1;break;
    }else if(choice==2){
        break;
    }else if(choice==1){
    }else{
        printf("Invalid choice!\n");
    }
    }else{
        printf("Invalid Entry!\n");
    }
    }while(choice!=2);
}

void buy_products(Product *products[], int sizes[], int *money){
    int i, timailhan=0, choice;
    do{
    printf("====================================\n");
    printf("--- You are now buying products ---\n");
    printf("    ----------------------------\n\n");
    printf("1. Tan's store\n");
    printf("2. Patricia's store\n");
    printf("3. Nizzah's store\n");
    printf("4. Cabarloc's store\n");
    printf("5. Go back to main menu\n");
    printf("\nEnter your choice: ");
    scanf("%d", &i);
    if(i>=1 && i<=4){
    buy_tan(i,products,sizes,&timailhan, money);
    }else if(i==5){
        break;
    }else{
        printf("Invalid Entry!\n");
    }
    if(timailhan==1)break;
    }while(i!=5);
}
void update_money(int money){
    FILE *fp;
    fp=fopen(file_money,"w");
    fprintf(fp,"%d", money);
    fclose(fp);
}
void viewInventory(int money) {
    while(1) {
    printf("\n======================================\n");
    printf("  You are now viewing your inventory.\n");
    FILE *fp;
    char line[100];

    fp = fopen(file_inventory, "r");

    printf("\n  ===== STUDENT INVENTORY =====\n\n");

    while(fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);

    printf("\nRemaining Money: PHP %d", money);
    
    int choice;
    
   
    printf("\n==============================\n");
    printf("Tap 1 to go back to main menu:");
    scanf("%d", &choice);
    if(choice == 1) {
        break;
    }
    
    }
}
void add_money(int *money){
    
    int add, choice;
    printf("\n=============================================\n");
    printf("You are now adding money to your bank account.\n");
    printf("\n            ===== SMALL BANK =====\n\n");
    printf("Your remaining money = PHP %d\n", *money);
    printf("How much do you want to add: ");
    scanf("%d", &add);
    *money=*money+add;
    printf("Your money become : PHP %d\n", *money);
    update_money(*money);
    do{
    printf("\nTap 1 to go back to main menu: ");
    scanf("%d", &choice);
    if(choice==1){
        break;
    }else{
        printf("Invalid Entry!");
    }
    }while(choice!=1);
}
