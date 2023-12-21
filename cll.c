#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *link;
};

struct node *h = NULL;

// 1
void insert_at_front(int x);
// 2
void insert_at_end(int x);
// 3
void insert_at(int n, int x);
// 4
void find(int x);
// 5
void display();
// 6
void delete(int x);
// 7
void length();
// 8
void Hval();

void main()
{

    //
    // insert_at_end(12);
    // insert_at_end(32);
    // insert_at_front(43);
    // insert_at_end(53);
    // insert_at_end(23);

    // display();

    // delete (3);
    // insert_at(2, 50);
    // display();
    // find(43);
    //

    printf("\n\n\t\t########## This is implementation of Singly Linked list.##########\n\nChoose from the Below :\n\n \n\t\t0. Exit\n\t\t1. Insert at Front \n\t\t2. Insert At End. \n\t\t3. Insert at p \n\t\t4. Find n \n\t\t5. Display List \n\t\t6. Delete n \n\t\t7. Length of List \n\t\t8. Head Value \n\t\t\t Choice :  ");
    int choice;
    scanf("%d", &choice);

    // printf("\n%d", choice);
    int p;
    int x;
    switch (choice)
    {
    case 1:
        printf("\n\n\t\tType Number to be inserted : ");
        scanf("%d", &x);
        insert_at_front(x);
        main();
        break;

    case 2:
        printf("\n\n\t\tType Number to be inserted : ");
        scanf("%d", &x);
        insert_at_end(x);
        main();
        break;

    case 3:
        printf("\n\n\t\tType Where to be inserted : ");
        scanf("%d", &p);
        printf("\n\n\t\tType Number to be inserted : ");
        scanf("%d", &x);
        insert_at(p, x);
        main();
        break;

    case 4:
        printf("\n\n\t\tType Number to be Searched : ");
        scanf("%d", &x);
        find(x);
        main();
        break;

    case 5:
        printf("\n");
        display();
        printf("\n");
        main();
        break;

    case 6:
        printf("\n\n\t\tType Number to be Deleted : ");
        scanf("%d", &x);
        delete (x);
        printf("\n");
        main();
        break;

    case 7:
        printf("\n");
        length();
        printf("\n");
        main();
        break;

    case 8:
        printf("\n");
        Hval();
        printf("\n");
        main();
        break;

    case 0:
        printf("\n\n\t\tExiting..........");
        printf("\n");
        exit(0);
        break;

    default:
        printf("Wrongly typed........\n\n");
        break;
    }
}

// 1
void insert_at_front(int x)
{
    struct node *k;
    k = (struct node *)malloc(sizeof(struct node));
    k->val = x;
    if (h == NULL)
    {
        h = k;
        h->link = h;
        return;
    }
    k->link = h;
    h = k;

    struct node *itr;
    itr = (struct node *)malloc(sizeof(struct node));
    itr = h->link->link;
    while (itr->link != h->link)
    {
        itr = itr->link;
    }
    itr->link = h;
};
// 2
void insert_at_end(int x)
{
    if (h == NULL)
    {
        insert_at_front(x);
        return;
    }

    struct node *k;
    k = (struct node *)malloc(sizeof(struct node));
    k->val = x;
    k->link = h;

    struct node *itr;
    itr = (struct node *)malloc(sizeof(struct node));
    itr = h;
    while (itr->link != h)
    {
        itr = itr->link;
    }
    itr->link = k;
};
// 3
void insert_at(int n, int x)
{
    if (n == 0)
    {
        insert_at_front(x);
        return;
    }

    struct node *k;
    k = (struct node *)malloc(sizeof(struct node));
    k->val = x;

    struct node *itr;
    itr = (struct node *)malloc(sizeof(struct node));
    int i = 1;
    itr = h;

    while (i < n)
    {
        i++;
        itr = itr->link;
    }
    k->link = itr->link;
    itr->link = k;
};

// 4
void find(int x)
{
    struct node *itr;
    itr = (struct node *)malloc(sizeof(struct node));
    int i = 0;
    itr = h;

    while (itr->link != h)
    {
        if (itr->val == x)
        {
            printf("Found at :%d.", i);
            return;
        }
        i++;
        itr = itr->link;
    }
    printf("Not Found.");
};
// 5
void display()
{
    if (h == NULL)
    {
        printf("Empty List.");
        return;
    }

    struct node *itr;
    itr = (struct node *)malloc(sizeof(struct node));

    printf("-> %d ", h->val);
    itr = h->link;

    while (itr != h)
    {
        printf("-> %d ", itr->val);
        itr = itr->link;
    }

    // printf("-> -%d- ", itr->val);
    // itr = itr->link;
};
// 6
void delete(int x)
{
    struct node *itr;
    itr = (struct node *)malloc(sizeof(struct node));
    itr = h;

    if (h->val == x)
    {
        if (h->link == h)
        {
            h = NULL;
            return;
        }

        printf(" found at 1 ");
        while (itr->link != h)
        {
            itr = itr->link;
        }
        itr->link = itr->link->link;
        h = h->link;
    }
    else
    {
        while (itr->link->val != x)
        {
            itr = itr->link;
            if (itr == h)
            {
                printf("Not found %d.", x);
                return;
            }
        }
        itr->link = itr->link->link;
        printf(" found ");
    }
};
// 7
void length()
{
    struct node *itr;
    itr = (struct node *)malloc(sizeof(struct node));
    itr = h;
    int i = 1;

    while (itr->link != h)
    {
        i++;
        itr = itr->link;
    }
    printf("Length is : %d", i);
};

// 8
void Hval()
{
    if (h == NULL)
    {

        printf("Head is Null.");
    }
    else
    {
        printf("Head val is : %d.", h->val);
    }
}