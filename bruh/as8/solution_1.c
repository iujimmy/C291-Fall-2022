#include <stdio.h>
#include <stdlib.h>

typedef struct Address{
  char* street;
  char* city;
  char* state;
  char* zip;
} Address;

Address createAddress(char* street, char* city, char* state, char* zip)
{
  Address *addy = malloc(sizeof(Address));
  addy->street = street;
  addy->city = city;
  addy->state = state;
  addy->zip = zip;
  return *addy;
}

typedef struct Product{
  char* name;
  double price;
} Product;

Product createProducts(char* name, double price)
{
  Product *prod = malloc(sizeof(Product));
  prod->name = name;
  prod->price = price;
  return *prod;
}

typedef struct Item{
   Product prod;
   int quantity;
} Item;

Item createLineItem(Product prod, int quantity)
{
  Item *item = malloc(sizeof(Item));
  item->prod = prod;
  item->quantity = quantity;
  return *item;
}

typedef struct Items{
  Item* items;
}Items;

typedef struct Invoice{
  Items* items;
  Address address;
} Invoice;

Invoice createInvoice(Items *items, Address address)
{
  Invoice* inv = malloc(sizeof(Invoice));
  inv->items = items;
  inv->address = address;
  return *inv;
}

void printInvoice(Invoice invoice)
{
    printf("I N V O I C E\n" );
    printf("Jim's Goods and Stuff\n" );
    printf("%s\n",invoice.address.street);
    printf("%s,", invoice.address.city);
    printf("%s %s\n", invoice.address.state, invoice.address.zip );

    printf("Description \t\t Price \t Qty \t Total\n");
    double total = 0;
    for(int i = 0; i < 2; i++)
    {
      printf("%s \t\t %f \t %d \t %f", invoice.items->items[i].prod.name,
                                       invoice.items->items[i].prod.price,
                                       invoice.items->items[i].quantity,
                                       invoice.items->items[i].quantity
                                       * invoice.items->items[i].prod.price);
     printf("\n" );
     total += invoice.items->items[i].quantity
     * invoice.items->items[i].prod.price;
    }
     printf("Amount Due: $%f\n", total);
}

void main()
{
    char * street = "5909 Crow St";
    char * city = "San Diego";
    char * state = " CA";
    char * zip = "52091";
    Address addy = createAddress(street,city,state,zip);

//product 1
    char * name = "Metal Ring";
    double price = 7.99;
    Product prod = createProducts(name, price);

    Item item1 = createLineItem(prod, 28);

//product 2
    char * name2 = "Bath Robe";
    double price2 = 12.99;
    Product prod2 = createProducts(name2, price2);

    Item item2 = createLineItem(prod2, 9);
//

    //Items* items = malloc(sizeof(Items));
    Item * item = malloc(sizeof(Item)*10);
    Items items = {item};

    printf("(test)\n" );

    (items.items[0]) = item1;
    (items.items[1]) = item2;

    Invoice inv = createInvoice(&items, addy);
    printInvoice(inv);
}
