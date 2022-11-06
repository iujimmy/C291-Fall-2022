#include <stdio.h>
#include <stdlib.h>

static double money = 0;

typedef struct item {
  char* name;
  char* label;
  double price;
  int quantity;
} item;

double insertMoney()
{
  double newMoney = 0.00;
  scanf("%lf", &newMoney);
  money += newMoney;
  return money;
}

void checkBalance()
{
  printf("Current Balance: %.2f\n", money);
}

double checkPrice(item * items, int index)
{
  return (*(items + (index))).price;
}

void purchase(item * items, int index)
{
  money -= checkPrice(items, index);
  printf("You purchased a %s for $%.2f\n",
  (*(items + (index))).name, checkPrice(items, index));
}

void checkQuantity(item * items, int index)
{
  printf("There is %d left! \n",(*(items + (index))).quantity);
}

void takeDown(item * items, int index)
{
  (*(items + (index))).name = "";
  (*(items + (index))).label = "";
  (*(items + (index))).quantity = 0;
  printf("%s is taken down! \n",(*(items + (index))).name);
}

double returnChange()
{
  double change = money;
  money = 0;
  printf("Change: $%.2f\n", change);
  return change;
}

void restok(item * items, int index, int quantity)
{
  (*(items + (index))).quantity = quantity;
  printf("Restoked %d %s\n", (*(items + (index))).quantity, (*(items + (index))).name);
}

void printOwnerMenu(item * items)
{
    int index = 0;
    int option = 0;
    while (option != 6)
    {
         while (option < 1 || option > 9) {
         printf("Enter a option: " );
         scanf("%d", &option);

      switch (option) {
        case 1:
        break;
        case 2:
        printf("Index: ");
        scanf("%d", &index);
      //  restok(items, index, quantity);
        case 3:
        printf("Index: ");
        scanf("%d", &index);
        checkQuantity(items, index);
        case 4:
        printf("Index: ");
        scanf("%d", &index);
        takeDown(items, index);
        case 6:
        option = 6;
        break;
      }
    }
  }
}

void printHome(item * items)
{
  printf("----------------------------------\n" );
  for(int i = 0; i < 3; i++)
  {
    printf("|%s \t|%s \t|%s \t|", (*(items + (i*3))).name ? (*(items + (i*3))).name : "Empty",
                                  (*(items + (i*3 + 1))).name ? (*(items + (i*1 + 1))).name : "Empty",
                                  ((*(items + (i*3 + 2))).name ? (*(items + (i*2 + 1))).name : "Empty"));
    printf("\n");
    printf("|%s \t|%s \t|%s \t|", (*(items + (i*3))).label ? (*(items + (i*3))).label : "",
                                  (*(items + (i*3 + 1))).label ? (*(items + (i*1 + 1))).label : "",
                                  ((*(items + (i*3 + 2))).label ? (*(items + (i*2 + 1))).label : ""));
   printf("\n");
   printf("-------------------------------------------\n" );

  }

  printf("1. Insert Money\n");
  printf("2. Check Balance\n");
  printf("3. Check Price\n");
  printf("4. Purchase\n");
  printf("5. Return Change\n");
  printf("6. Owner Menu\n");
  printf("7. Exit\n");
  return;
}

void main()
{
    item * items = malloc(sizeof(item)*9);

    item newItem = {"Coke", "A1",2.99,5};
    item newItem2 = {"Slips", "A3",1.99,1};
    item newItem3 = {"Crops", "B3",1.99,3};

    *(items + 0) = newItem;
    *(items + 1) = newItem2;
    *(items + 2) = newItem3;

    //printing soda
    printf("-------------------------------\n" );
    for(int i = 0; i < 3; i++)
    {
      printf("|%s \t|%s \t|%s \t|", (*(items + (i*3))).name ? (*(items + (i*3))).name : "Empty",
                                    (*(items + ((i*3) + 1))).name ? (*(items + ((i*1) + 1))).name : "Empty",
                                    ((*(items + ((i*3) + 2))).name ? (*(items + ((i*2) + 1))).name : "Empty"));
      printf("\n");
      printf("|%s \t|%s \t|%s \t|", (*(items + (i*3))).label ? (*(items + (i*3))).label : "",
                                    (*(items + ((i*3) + 1))).label ? (*(items + ((i*1) + 1))).label : "",
                                    ((*(items + ((i*3) + 2))).label ? (*(items + ((i*2) + 1))).label : ""));
     printf("\n");
     printf("-------------------------------\n" );
    }

    printf("1. Insert Money\n");
    printf("2. Check Balance\n");
    printf("3. Check Price\n");
    printf("4. Purchase\n");
    printf("5. Return Change\n");
    printf("6. Owner Menu\n");
    printf("7. Exit\n");

    int option = 0;
    while (option != 7)
    {
      option = 0;
      while (option < 1 || option > 9) {
        printf("Enter a option: " );
        scanf("%d", &option);
      }

      int index = 0;
      switch (option) {
        case 1:
        printf("Amont: ");
        money = insertMoney();
        break;

        case 2:
        checkBalance();
        break;

        case 3:
        printf("Index: ");
        scanf("%d", &index);
        double price = checkPrice(items, index);
        printf("Price is %.2f\n", price);
        break;

        case 4:
        printf("Index: ");
        scanf("%d", &index);
        purchase(items, index);
        break;

        case 5:
        returnChange();
        break;

        case 6:
        printOwnerMenu(items);
        break;

        defualt:
        printHome(items);
      }
    }
    return;
}
