#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lp, *rp;
};
struct node *h = NULL;

void insert_at_right();

void insert_at_left();

void show();

int main()
{

    int choice;
    printf("\t................Doubly Linked List................\n\n\t\tChoose from the following :\n\n\t0. exit.\n\t1. insert at right.\n\t2. insert at left.\n\t3. show.\n\n\t\tYour Choice :");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
        exit(0);
        main();
        break;

    case 1:
        insert_at_right();
        main();
        break;

    case 2:
        insert_at_left();
        main();
        break;

    case 3:
        show();
        main();
        break;

    default:
        printf("...........Wrongly Typed...........");
        main();
        break;
    }

    printf("\n");
    return 0;
}

void insert_at_right()
{
    int n;
    printf("\n\t\tType the number to be inserted at right :");
    scanf("%d", &n);

    if (h == NULL)
    {
        h = (struct node *)malloc(sizeof(struct node));
        h->data = n;
        h->lp = NULL;
        h->rp = NULL;
    }
    else
    {
        struct node *m = h;
        struct node *k = (struct node *)malloc(sizeof(struct node));
        k->data = n;
        k->rp = NULL;

        while (m->rp != NULL)
        {
            m = m->rp;
        }
        m->rp = k;
        k->lp = m;
    }
}

void insert_at_left()
{
    int n;
    printf("\n\t\tType the number to be inserted at left :");
    scanf("%d", &n);

    if (h == NULL)
    {
        h = (struct node *)malloc(sizeof(struct node));
        h->data = n;
        h->lp = NULL;
        h->rp = NULL;
    }
    else
    {
        struct node *m = h;

        struct node *k = (struct node *)malloc(sizeof(struct node));
        k->data = n;
        k->lp = NULL;

        while (m->lp != NULL)
        {
            m = m->lp;
        }
        m->lp = k;
        k->rp = m;
    }
}

void show()
{
    printf("\n");

    if (h == NULL)
    {
        printf("Empty list.");
        printf("\n\n");
        return;
    }

    struct node *m = h;
    while (m->lp != NULL)
    {
        m = m->lp;
    }

    while (m->rp != NULL)
    {
        printf("-> %d", m->data);
        m = m->rp;
    }
    printf("-> %d", m->data);

    printf("\n\n");
}