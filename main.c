#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
void scan_files(Product *products[], int sizes[]);
int mymoney();
void view_ourstores(int i, Product *products[], int sizes[], int *timailhan);
void view_products(Product *products[],int sizes[]);
void calculation(int i, int j, int quantity, Product *products[], int *money, int sizes[]);
void buy_tan(int i, Product *products[], int sizes[], int *timailhan, int *money);
void buy_products(Product *products[], int sizes[], int *money);
void update_money(int money);
void viewInventory(int money);
void add_money(int *money);
void game(int *money);

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

    do{//main menu nato guys

        printf("\n\n====================================\n");
        printf("====This is TPNC Vending Machine====\n");
        printf(" Barato na may tsansa pang manalo ka\n");
        printf("          --------------\n\n");

        printf("Your pocket money: PHP%d.00\n\n", money);

        printf("1. Buy Product\n");
        printf("2. View Product\n");
        printf("3. View personal inventory\n");
        printf("4. Add money\n");
        printf("5. Play Mysterious box game\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");

        char input[100];
        char extra;

        fgets(input, sizeof(input), stdin);//stores nato ang answers sa string nga input

        if(sscanf(input, "%d %c", &choice, &extra) != 1){//restrict the spaces and extra characters
            printf("Invalid input!\n");
            continue;
        }

        switch(choice){

            case 1:
                buy_products(products,sizes, &money);
                break;

            case 2:
                view_products(products, sizes);
                break;

            case 3:
                viewInventory(money);
                break;

            case 4:
                add_money(&money);
                break;

            case 5:
                game(&money);
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid Entry!\n");
                break;
        }

    }while(choice!=6);

    for(int i = 0; i < 4; i++){
        free(products[i]);
    }

    return 0;
}

void check_files(){//initializing nato sa files nato

    FILE *fp;

    fp = fopen(file_tan, "r");

    if(fp == NULL){

        fp = fopen(file_tan, "w");//tan files

        fprintf(fp, "Coke 35 10\n");
        fprintf(fp, "Water 20 15\n");
        fprintf(fp, "Royal 25 10\n");
        fprintf(fp, "Pepsi 30 15\n");
        fprintf(fp, "Sprite 30 15\n");

        fclose(fp);

    }else{
        fclose(fp);
    }

    fp = fopen(file_patricia, "r");//patricias files

    if(fp == NULL){

        fp = fopen(file_patricia, "w");

        fprintf(fp, "Oishi 10 10\n");
        fprintf(fp, "Clover 10 15\n");
        fprintf(fp, "Piatos 20 10\n");
        fprintf(fp, "Cracklings 10 15\n");
        fprintf(fp, "Marty's 10 15\n");

        fclose(fp);

    }else{
        fclose(fp);
    }

    fp = fopen(file_nizzah, "r");//nizzahs files

    if(fp == NULL){

        fp = fopen(file_nizzah, "w");

        fprintf(fp, "Fita 10 10\n");
        fprintf(fp, "Lava 10 15\n");
        fprintf(fp, "Bravo 10 10\n");
        fprintf(fp, "Bingo 10 15\n");
        fprintf(fp, "Cloud9 10 15\n");

        fclose(fp);

    }else{
        fclose(fp);
    }

    fp = fopen(file_cabarloc, "r");//cabarlocs files

    if(fp == NULL){

        fp = fopen(file_cabarloc, "w");

        fprintf(fp, "Mentos 2 50\n");
        fprintf(fp, "Maxx 2 50\n");
        fprintf(fp, "Nips 2 10\n");
        fprintf(fp, "V-fresh 2 50\n");
        fprintf(fp, "Judge 2 50\n");

        fclose(fp);

    }else{
        fclose(fp);
    }

    fp = fopen(file_inventory, "r");

    if(fp == NULL){

        fp = fopen(file_inventory, "w");//inventorys files

        fclose(fp);

    }else{
        fclose(fp);
    }

    fp = fopen(file_money, "r");

    if(fp == NULL){

        fp = fopen(file_money, "w");//moneys files

        fprintf(fp, "500");

        fclose(fp);

    }else{
        fclose(fp);
    }
}

void scan_files(Product *products[], int sizes[]){//read all files

    FILE *fp;

    char *myfiles[]={
        file_tan,
        file_patricia,
        file_nizzah,
        file_cabarloc
    };

    for(int i=0; i<4;i++){

        int j=0;

        fp=fopen(myfiles[i],"r");

        if(fp==NULL) continue;

        while(fscanf(fp, "%s %d %d",
            products[i][j].name,
            &products[i][j].price,
            &products[i][j].stock)==3){

            j++;
        }

        fclose(fp);

        sizes[i]=j;
    }
}

int mymoney(){//our money

    FILE *fp;

    int money;

    fp=fopen(file_money,"r");

    fscanf(fp,"%d", &money);

    fclose(fp);

    return money;
}

void view_ourstores(int i, Product *products[], int sizes[], int *timailhan){//view stores solution

    int choice;

    char *files[]={
        "Tan's",
        "Pat's",
        "Niz's",
        "Cab's"
    };

    do{

        printf("\n\n====================================\n");

        printf("---------- %s store -------------\n",files[i-1]);

        for(int k=0; k<sizes[i-1]; k++){

            printf("%d. %3s - PHP %d - %d pcs\n",
                k+1,
                products[i-1][k].name,
                products[i-1][k].price,
                products[i-1][k].stock);
        }

        printf("\n1. Go back to previous menu\n");
        printf("2. Go back to main menu\n");

        printf("\nEnter your choice: ");

        char input[100];
        char extra;

        fgets(input, sizeof(input), stdin);

        if(sscanf(input, "%d %c", &choice, &extra) != 1){
            printf("Invalid input!\n");
            continue;
        }

        if(choice==2){

            *timailhan=1;

        }else if(choice==1){

            break;

        }else{

            printf("Invalid choice!\n");
        }

    }while(choice!=1 && choice!=2);
}

void view_products(Product *products[], int sizes[]){//view product menu

    int choice, timailhan=0;

    do{

        printf("\n\n====================================\n");

        printf("--- You are now viewing products ---\n\n");

        printf("1. Tan's store        (DRINKS)\n");
        printf("2. Patricia's store   (JUNKFOODS)\n");
        printf("3. Nizzah's store     (BISCUITS)\n");
        printf("4. Cabarloc's store   (CANDIES)\n");
        printf("5. Go back to main menu\n");

        printf("\nEnter your choice(1-5): ");

        char input[100];
        char extra;

        fgets(input, sizeof(input), stdin);

        if(sscanf(input, "%d %c", &choice, &extra) != 1){
            printf("Invalid input!\n");
            continue;
        }

        if(choice>=1&&choice<=4){

            view_ourstores(choice, products, sizes, &timailhan);

        }else if(choice==5){

            break;

        }else{

            printf("Invalid Entry!\n");
        }

        if(timailhan==1) break;

    }while(choice!=5);
}

void calculation(int i, int j, int quantity, Product *products[], int *money,int sizes[]){//calculation sa buy and sell

    int m=*money;

    if(products[i-1][j-1].stock==0){

        printf("%s out of stock!\n", products[i-1][j-1].name);

        return;
    }

    if(quantity>products[i-1][j-1].stock){

        printf("Not enough stock there are only %d %s left!\n", products[i-1][j-1].stock, products[i-1][j-1].name);

        return;
    }

    int total_price=products[i-1][j-1].price*quantity;

    if(*money<total_price){

        printf("Not enough money!You only have PHP %d.00 left!\n", *money);

        return;
    }

    products[i-1][j-1].stock-=quantity;

    *money-=total_price;

        printf("\nYou bought %d %s item\n",quantity,
            products[i-1][j-1].name
            );

    printf("Remaining money: PHP%d\n", *money);

    update_money(*money);

    FILE *fp;

    fp = fopen(file_inventory, "a");

    fprintf(fp, "%s - PHP %d (Quantity: %d)\n",
            products[i-1][j-1].name,
            products[i-1][j-1].price,
            quantity);

    fclose(fp);

    char *files[]={
        file_tan,
        file_patricia,
        file_nizzah,
        file_cabarloc
    };

    fp=fopen(files[i-1], "w");

    for(int k=0; k<sizes[i-1]; k++){

        fprintf(fp,"%s %d %d\n",
            products[i-1][k].name,
            products[i-1][k].price,
            products[i-1][k].stock);
    }

    fclose(fp);
}

void buy_tan(int i, Product *products[], int sizes[], int *timailhan, int *money){//buy and sells

    int choice=0;

    int k=i-1;
    char *storename[]={
        "Tan", "Pat", "Niz", "Cab"
    };

    do{

        int j, quantity;

        printf("\n\n====================================\n");
        printf("===========   %s's store   ========\n\n", storename[k]);

        for(int x=0; x<sizes[k]; x++){

            printf("%d. %3s - PHP %d - %d pcs\n",
                x+1,
                products[k][x].name,
                products[k][x].price,
                products[k][x].stock);
        }

        printf("\nEnter what do you want to buy(1-5): ");

        char input[100];
        char extra;

        fgets(input, sizeof(input), stdin);

        if(sscanf(input, "%d %c", &j, &extra) != 1){
            printf("Invalid input!\n");
            continue;
        }

        if(j>=1&&j<=sizes[k]){

            printf("How many %s do you want to buy: ", products[i-1][j-1].name);

            fgets(input, sizeof(input), stdin);

            if(sscanf(input, "%d %c", &quantity, &extra) != 1){//restrict spaces and extra characters
                printf("Invalid quantity!\n");
                continue;
            }

            calculation(i,j, quantity, products, money, sizes);

            printf("\n1. Buy again\n");
            printf("2. Go back to previous menu\n");
            printf("3. Main menu\n");
            printf("Enter your choice: ");
            fgets(input, sizeof(input), stdin);

            if(sscanf(input, "%d %c", &choice, &extra) != 1){
                printf("Invalid input!\n");
                continue;
            }

            if(choice==3){
                *timailhan=1;
                break;
            }

        }else{

            printf("Invalid product!\n");
        }

    }while(choice!=2);
}

void buy_products(Product *products[], int sizes[], int *money){//buy stores menu

    int i, timailhan=0;

    do{

        printf("\n\n====================================\n");

        printf("--- You are now buying products ---\n\n");

        printf("1. Tan's store       (DRINKS)\n");
        printf("2. Patricia's store  (JUNKFOODS)\n");
        printf("3. Nizzah's store    (BISCUITS)\n");
        printf("4. Cabarloc's store  (CANDIES)\n");
        printf("5. Go back to main menu\n");

        printf("\nEnter your choice: ");

        char input[100];
        char extra;

        fgets(input, sizeof(input), stdin);

        if(sscanf(input, "%d %c", &i, &extra) != 1){
            printf("Invalid input!\n");
            continue;
        }

        if(i>=1 && i<=4){

            buy_tan(i,products,sizes,&timailhan, money);

        }else if(i==5){

            break;

        }else{

            printf("Invalid Entry!\n");
        }

        if(timailhan==1) break;

    }while(i!=5);
}

void update_money(int money){

    FILE *fp;

    fp=fopen(file_money,"w");

    fprintf(fp,"%d", money);

    fclose(fp);
}

void viewInventory(int money){//view inventory menu

    FILE *fp;

    char line[100];

    printf("\n\n===== INVENTORY =====\n");

    fp = fopen(file_inventory, "r");

    while(fgets(line, sizeof(line), fp) != NULL){

        printf("%s", line);
    }

    fclose(fp);

    printf("\nRemaining Money: PHP %d\n", money);

    printf("\nPress 1 to go back: ");

    int choice;

    char input[100];
    char extra;

    fgets(input, sizeof(input), stdin);

    sscanf(input, "%d %c", &choice, &extra);
}

void add_money(int *money){

    int add;

    printf("\n\n===== ADD MONEY =====\n");

    printf("Current money: PHP %d\n", *money);

    printf("How much do you want to add: ");

    char input[100];
    char extra;

    fgets(input, sizeof(input), stdin);

    if(sscanf(input, "%d %c", &add, &extra) != 1){
        printf("Invalid input!\n");
        return;
    }

    *money += add;

    update_money(*money);

    printf("Money added successfully!\n");
    printf("\nYour money now is %d.00\n",*money );
    int l;
    do{
        printf("Tap 1 to exit!");
        scanf("%d", &l);
        if(l==1){
            break;
        }else{
            printf("Invalid input! : \n");
        }
    }while(l!=1);
}

void game(int *money){

    int choice;

    do{

        printf("\n\n====================================\n");

        printf(" =========  Mystery box  ==========\n\n");

        if(*money < 10){

            printf("Not enough money to play because you only have PHP%d.00 and it needs atleast PHP 10.00!\n", *money);

            break;
        }
        printf("Mechanics:\n\n");
        printf("You need to pay PHP 10.00 to play\n");
        printf("By only PHP 10.00 you have the chance to select a box in 5 boxes\n");
        printf("In the 5 boxes there is one box contain PHP 100 and the rest is empty\n");
        printf("We used randomizer for the jackpot box\n\n");
        
        printf("1. Play\n");
        printf("2. Exit\n");

        printf("Enter your choice: ");

        char input[100];
        char extra;

        fgets(input, sizeof(input), stdin);

        if(sscanf(input, "%d %c", &choice, &extra) != 1){
            printf("Invalid input!\n");
            continue;
        }

        if(choice==1){

            int guess;

            printf("Enter the box number you want to choose (1-5): ");

            fgets(input, sizeof(input), stdin);

            if(sscanf(input, "%d %c", &guess, &extra) != 1){
                printf("Invalid input!\n");
                continue;
            }

            if(guess <1 || guess >5){

                printf("Invalid number!\n");

                continue;
            }

            srand(time(NULL));

            int random = rand()%5+1;

            *money -= 10;

            printf("Jackpot box: %d\n", random);

            if(guess == random){

                *money += 100;

                printf("You won PHP100.00!\n");
                FILE *fp;
                
                fp=fopen(file_inventory,"a");
                
                fprintf(fp,"You won PHP 100.00\n");
                fclose(fp);

            }else{

                printf("You lost PHP 10!\n");
                 FILE *fp;
                 
                fp=fopen(file_inventory,"a");
                
                fprintf(fp,"You lost PHP %d.00\n", *money);
                fclose(fp);
            }

            update_money(*money);

            printf("Current money: PHP %d.00\n", *money);
        }

    }while(choice!=2);
}