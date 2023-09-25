
#include <stdio.h>
#include <stdlib.h>

struct slink
{
    int val;
    struct slink *add;
};

struct slink *h = NULL;

//1
void insert_at_front(int x);
//2
void insert_at_end(int x);
//3
void insert_at(int n, int x);
//4
void find(int x);
//5
void display();
//6
void delete(int x);
//7
void length();

void main()
{

    // struct slink *h;
    // h = NULL;

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

    printf("\n\n\t\t########## This is implementation of Singly Linked list.##########\n\nChoose from the Below :\n\n \n\t\t0. Exit\n\t\t1. Insert at Front \n\t\t2. Insert At End. \n\t\t3. Insert at p \n\t\t4. Find n \n\t\t5. Display List \n\t\t6. Delete n \n\t\t7. Length of List\n\t\t\t Choice : ");
    int choice;
    scanf("%d",&choice);

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
        insert_at(p,x);
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
        delete(x);
        printf("\n");
        main();
        break;


    case 7:
        printf("\n");
        length();
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

void insert_at_end(int x)
{
    struct slink *k;
    k = (struct slink *)malloc(sizeof(struct slink));
    k->val = x;
    k->add = NULL;

    if (h == NULL)
    {
        h = k;
    }
    else
    {
        struct slink *m;
        m = h;
        while (m->add != NULL)
        {
            m = m->add;
        }
        m->add = k;
    }
}

void display()
{
    struct slink *m;
    m = h;
    while (m != NULL)
    {
        printf("-> %d ", m->val);
        m = m->add;
    }
    printf("\n");
}

void insert_at_front(int x)
{
    struct slink *k;
    k = (struct slink *)malloc(sizeof(struct slink));
    k->val = x;
    k->add = h;
    h = k;
}

void delete(int x)
{
    struct slink *m;
    m = h;

    if (h->val == x)
    {
        h = h->add;
        return;
    }
    else
    {
        while (m->add != NULL)
        {
            if (m->add->val == x)
            {
                m->add = m->add->add;
                return;
            }
            m = m->add;
        }
    }

    printf("\nNot found\n");
}

void find(int x)
{
    struct slink *m;
    int b = 0;
    int n = 0;
    m = h;

    while (m->add != NULL)
    {
        n++;
        if (m->val == x)
        {
            b = 1;
            break;
        }
        m = m->add;
    }

    if (b)
    {
        printf("Number is found at : %dth place\n", n);
    }
    else
    {
        printf("Number is Not found. \n");
    }
}

void insert_at(int p, int x)
{
    struct slink *m;
    m = h;

    int b = 1;
    int n = 1;

    while (n != p)
    {
        n++;
        if (m->add == NULL)
        {
            b = 0;
            break;
        }
        m = m->add;
    }

    if (b)
    {
        struct slink *k;
        k = (struct slink *)malloc(sizeof(struct slink));
        k->val = x;
        k->add = m->add;
        m->add = k;
        printf("%d Added at  rank of %d.\n", x, p);
    }
    else
    {
        printf("Underflow rank of %d.\n", p);
    }
}


void length(){
    int l=0;
    struct slink *m;

    m = h;

    while(m!=NULL){
        l++;
        m = m->add;
    }

    printf("Number of nodes in This List is : %d",l);
}