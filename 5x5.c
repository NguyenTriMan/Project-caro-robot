#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

time_t t;
int n,m;
int whofirst,move,cpumove;
int win = 1;
char board[25] = {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',};

 
void display()
{
    for (int i = 0; i< 25;i++)
    {
        printf(" | %c",board[i]);
        if (i == 4 || i == 9 || i==14 || i == 19 || i ==24 )
            {printf("\n");}
    }
    printf("\n");
}
int main()
{

    printf("1 user first,2 cpu first: "); // x is first 
    scanf("%d",&whofirst);
    if (whofirst == 1)
    {
        printf("your choice: ");
        scanf("%d",&move);
        board[move] = 'x';
        display();
    }
    while(1)
    {
        printf("loading..... ");
        // random 0 to 24
        srand((unsigned) time(&t));
        do
        {
            cpumove = rand() % 25;
        }
        while (board[cpumove] != '-');
        printf("cpu move: %d \n",cpumove);
        board[cpumove] = 'o';
        display();
        printf("your choice: ");
        scanf("%d",&move);
        while(board[move] != '-')
        {
           printf("you choice again: ");
           scanf("%d",&move); 
        }
        board[move] = 'x';
        display();
    }

}

