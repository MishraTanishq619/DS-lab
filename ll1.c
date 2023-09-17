
#include <stdio.h>
#include <stdlib.h>

struct slink
{
    int val;
    struct slink *add;
};

struct slink *h = NULL;

void insert_at_end(int x);
void insert_at_front(int x);
void display();
void delete(int x);
void insert_at(int n, int x);
void find(int x);

void main()
{

    // struct slink *h;
    // h = NULL;

    insert_at_end(12);
    insert_at_end(32);
    insert_at_front(43);
    insert_at_end(53);
    insert_at_end(23);

    display();

    delete (3);
    insert_at(2, 50);
    display();
    find(43);
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
