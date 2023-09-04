#include<stdio.h>
#include<stdlib.h>

struct stack{
    int arr[6];
    int p;
} ;

struct stack stk ={ .p = -1 };
// push, pop, val, show, exit

void push();
void pop();
void val();
void show();
void find();

int main()

{
    // struct stack stk;
    int choice;

    printf("\n\nChoose from the below :\n\t\t1.Push\n\t\t2.Pop\n\t\t3.Value\n\t\t4.Show\n\t\t5.Find N\t\t6.Exit\n\t:");
    scanf("%d",&choice);
    printf("\n\n");

    switch (choice)
    {
    case 1:
        push();
        main();
        break;
    
    case 2:
        pop();
        main();
    
    case 3:
        val();
        main();
    
    case 4:
        show();
        main();
    
    
    case 5:
        find();
        main();
    
    case 6:
        exit(0);
        return 0;

    default:
        printf("\nInvalid Input.\n");
    }
}



void push(){
    int n;
    printf("Type a number to be pushed :");
    scanf("%d", &n);

    if (stk.p==5)
    {
        printf("Stack Overflow.");
    }
    else
    {
        stk.arr[++stk.p] = n;
    }
}

void pop(){
    if (stk.p==-1)
    {
        printf("Stack Underflow.");
    }
    else
    {
        stk.p--;
    }
}


void val(){
    printf("Current value is : %d", stk.arr[stk.p]);
}


void show(){
    for (int i = stk.p; i >= 0;i--){
        printf("\n%d", stk.arr[i]);
    }
}




void find(){
    int x;
    int b=0;

    printf("Type Number to find : ");
    scanf("%d",&x);


    for (int i = 0; i <=stk.p; i++)
    {
        if(stk.arr[i]==x) {
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