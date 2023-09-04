// queue


#include <stdio.h>
#include<stdlib.h>


struct queue{
    int arr[5];
    int h;
    int t;
};

struct queue q={
    .h=-1,
    .t=-1
};

void enqueue();
void dequeue();
void show();
void find();


void main(){

    int choice;
    printf("\n\nChoose from the following : \n\t\t1.Enqueue\n\t\t2.Dequeue\n\t\t3.Show\n\t\t4.Find N\t\t5.Exit\n\t:");
    scanf("%d",&choice);

    // printf("%d %d\n",q.h,q.t);
    // for (int i = q.h; i <=q.t; i++)
    // {
    //     printf(" %d",q.arr[i]);
    // }
    



    switch (choice)
    {
    case 1:
        enqueue();
        main();
        break;
        
    case 2:
        dequeue();
        main();
        break;
        
    case 3:
        show();
        main();
        break;
        
    case 4:
        find();
        main();
        break;

    case 5:
        exit(0);
        break;
    
    default:
        printf("Wrongly Typed.\n\n");
        break;
    }

}




void enqueue(){
    int n;
    if (q.t>4)
    {
        printf("full");
    }
    else
    {    
        if (q.h==-1 && q.t==-1)
        {
            q.h++;
        }
        printf("\nType the number to be entered : ");
        scanf("%d",&n);
        q.t=q.t + 1;
        q.arr[q.t] = n ;
    }
}


void dequeue(){
    if(q.h>q.t || q.h==-1){
        printf("Empyt Queue.");
    }
    q.h++;
}


void show(){
    printf("  <- ");
    for(int i=q.h;i<=q.t;i++){
        printf("%d  ",q.arr[i]);
    }   
    printf("  <- ");
}



void find(){
    int x;
    int b=0;

    printf("Type Number to find : ");
    scanf("%d",&x);


    for (int i = q.h; i <=q.t; i++)
    {
        if(q.arr[i]==x) {
            b=1;
            break;
        }
    }

    if (b==0)
    {
        printf("Didn't Found.");
    }
    else
    {
        printf("Found it.");
    }
    
    
}