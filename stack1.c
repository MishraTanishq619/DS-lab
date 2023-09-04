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


int main()
{
    // struct stack stk;
    int choice;

    printf("\n\nChoose from the below :\n\t\t1.Push\n\t\t2.Pop\n\t\t3.Value\n\t\t4.Show\t\t5.Exit\n\t:");
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

