#include<stdio.h>

int array[100],a,n;

void insertbeg();
void insertend();
void insertany();
void deletebeg();
void deleteend();
void deleteany();
void show();

int main()
{ 
    int op;
    printf("Enter the length of the array:- \n");
    scanf("%d",&n);
    
    printf("Enter element for array:- \n");

    for(int i=0; i<n; i++)
    {
        scanf("%d",&array[i]);
    }

    printf("Choose The Option \n");
    printf("1. Insert the element at the end\n");
    printf("2. Insert the element at the begining\n");
    printf("3. Insert the element at the any position\n");
    printf("4. Delete the element at the end\n");
    printf("5. Delete the element at the begining\n");
    printf("6. Delete the element at the any position\n");
    printf("7. Print Array\n");
   
   scanf("%d",&op);

    switch(op)
    {
        case 1:
               {
                 insertend();
                 break;
               }
        case 2:
               {
                 insertbeg();
                 break;
               }
        case 3:
               {
                 insertany();
                 break;
               }
        case 4:
               {
                 deleteend();
                 break;
               }
        case 5:
               {
                 deletebeg();
                 break;
               }
        case 6:
               {
                 deleteany();
                 break;
               }
        case 7:
               {
                 show();
                 break;
               }
    }
    
    return 0;
}

void insertend()
{
    printf("Enter element which you want to add in array:- ");
    scanf("%d",&a);

    array[n]=a;

    for(int i=0; i<=n; i++)
    {
        printf("%d ",array[i]);
    }
}

void insertbeg()
{
    int pos=0;
    printf("Enter element which you want to add in array:- ");
    scanf("%d",&a);

    n++;
    for(int i=n; i>=pos; i--)
    {
         array[i]=array[i-1];
    }
    
    array[0]=a;

    for(int i=0; i<n; i++)
    {
        printf("%d ",array[i]);
    }    
}

void insertany()
{
    int pos;
    printf("Enter element which you want to add in array:- ");
    scanf("%d",&a);
    printf("Enter position where you want to add in array:- ");
    scanf("%d",&pos);

    n++;
    for(int i=n; i>=pos; i--)
    {
         array[i]=array[i-1];
    }
    
    array[pos-1]=a;

    for(int i=0; i<n; i++)
    {
        printf("%d ",array[i]);
    }
}

void deleteend()
{
    for(int i=0; i<n-1; i++)
    {
        printf("%d ",array[i]);
    }
}

void deletebeg()
{
    for(int i=1; i<n; i++)
    {
        printf("%d ",array[i]);
    }
}

void deleteany()
{
    int pos;
    printf("Enter position which you want to delete element:- ");
    scanf("%d",&pos);
    pos--;
    for(int i=0; i<n;i++)
    {
        if(i==pos)
        {
            continue;
        }
        else{
        printf("%d",array[i]);
        }
    }
    
}
void show()
{
    for(int i=0; i=n; i++)
    {
        printf("%d ",array[i]);
    }
}