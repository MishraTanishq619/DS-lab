
#include<stdio.h>
#include<stdlib.h>


struct slink{
    int val;
    struct slink *add;
};

struct slink *h = NULL;


void insert_at_end(int x);
void insert_at_front(int x);
void display();
void delete(int x);

void main(){

    // struct slink *h;
    // h = NULL;

    insert_at_end(12);
    insert_at_end(32);
    insert_at_front(43);
    insert_at_end(53);
    insert_at_end(23);

    display();

    delete (3);
    display();

}




void insert_at_end(int x){
    struct slink *k;
    k = (struct slink *)malloc(sizeof(struct slink));
    k->val = x;
    k->add = NULL;


    if(h==NULL){
        h = k;
    }
    else{
        struct slink *m;
        m = h;
        while (m->add != NULL)
        {
            m = m->add;
        }
        m->add = k;
    }
}

void display(){
    struct slink *m;
    m = h;
    while (m!=NULL)
    {
        printf("-> %d ", m->val);
        m = m->add;
    }
    printf("\n");
}


void insert_at_front(int x){
    struct slink *k;
    k = (struct slink *)malloc(sizeof(struct slink));
    k->val = x;
    k->add = h;
    h = k;
}

void delete(int x){
    struct slink *m;
    m = h;

    if (h->val==x)
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