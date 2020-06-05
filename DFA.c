//MINIMIZATION OF DFA PROGRAM USING C
#include<stdio.h>
#define MARKED 1
#define UNMARKED -1
void show_dfa();            //USED TO SHOW THE TRANSITION TABLE OF THE DFA
void store_dfa();           //USED TO STORE THE VALUES IN THE TRANSITION TABLE
void mark_dfa();            //USED FOR TABLE FILLING
void newtransition_table();
int check(int);
void show_minimized_dfa();
void trans_table();
int find(int);
int total_state,total_symbol,transition[10][10],final_state,m[10][10],newstate[10][10],arr[10],a,new_transition[10][10],fin;
int main()
{
    int i,j;
    store_dfa();                //CALLING store_dfa() FUNCTION
    show_dfa();                 //CALLING show_dfa() FUNCTION
    mark_dfa();                 //CALLING mark_dfa() FUNCTION
    newtransition_table();      //CALLING newtransition_table FUNCTION
    trans_table();
    show_minimized_dfa();
}
void store_dfa(void)
{
    int i,j;
    printf("Enter total no. of states neglecting unreachable states:");
    scanf("%d",&total_state);
    printf("Enter total no. of allowed symbols :");
    scanf("%d",&total_symbol);
    printf("Enter the final state \n");
    scanf("%d",&final_state);
    printf("Enter the transitions :- \n");
    for(i=0;i<total_state;i++)
    {
        for(j=0;j<total_symbol;j++)
        {
            printf("\n %d ---> %c :\t",i,(char)j+97);
            scanf("%d",&transition[i][j]);
        }
    }
}
void show_dfa(void)
{
    int i,j;
    printf("\n\n\n");
    printf("\n   TRANSITION TABLE OF ENTERED DFA IS AS FOLLOWS ");
    printf("\n====================================================\n\t");
    for(i=0;i<total_symbol;i++)
    printf("%c\t",(char)i+97);
    printf("\n");
    for(i=0;i<(total_symbol+1);i++)
    printf("-\t");
    printf("\n");
    for(i=0;i<total_state;i++)
    {
        printf("\n%d\t",i);
        for(j=0;j<total_symbol;j++)
        {
            printf("%d\t ",transition[i][j]);
        }
    }
}
void mark_dfa()
{
    int i,j,k,x,y;
    for(i=0;i<total_state;i++)
    {
        for(j=0;j<total_state;j++)
        {
                if(j>i)
                {
                    m[i][j]=MARKED;
                }
                else
                {
                if(((i==final_state&&j!=final_state)||(i!=final_state&&j==final_state))&&(i!=j))
                {
                    m[i][j]=MARKED;
                }
                else
                {
                    m[i][j]=UNMARKED;
                }
                }
        }
    }
    for(i=0;i<total_state;i++)
    {
        for(j=i+1;j<total_state;j++)
        {
            if(m[j][i]==UNMARKED)
            {
                for(k=0;k<total_symbol;k++)
                {
                    x=transition[i][k];
                    y=transition[j][k];
                    if(m[x][y]==MARKED||m[y][x]==MARKED)
                    {
                        m[j][i]=MARKED;
                        break;
                    }
                }
            }
        }
    }
}
void newtransition_table()
{
    int i,j,k=0,b=0;
    for(i=0;i<total_state;i++)
    {
        for(j=0;j<total_state;j++)
        {
            newstate[i][j]=total_state;
        }
    }
    for(i=0;i<total_state;i++)
    {
        arr[i]=total_state;
    }
    for(i=0;i<total_state;i++)
    {
        if(check(i)!=0)
        {
            b=0;
            newstate[a][b]=i;
            for(j=i+1;j<total_state;j++)
            {
                if(m[j][i]==UNMARKED)
                {
                    arr[k]=j;
                    k++;
                    newstate[a][b+1]=j;
                }
            }
            a++;
        }
    }
}
int check(int x)
{
    int c;
    for(c=0;c<total_state;c++)
    {
        if(x==arr[c])
        {
            return(0);
        }
    }
    return(1);

}
void trans_table()
{
    int i,x,s1,k;
    for(i=0;i<=a;i++)
    {
        x=newstate[i][0];
        for(k=0;k<total_symbol;k++)
        {
            s1=transition[x][k];
            fin=find(s1);
            new_transition[i][k]=fin;
        }
    }
    final_state = find(final_state);
}
int find(int x)
{
    int i,j;
    for(i=0;i<=a;i++)
    {
        for(j=0;j<total_state;j++)
        {
            if(x==newstate[i][j])
            return i;
        }
    }
}
void show_minimized_dfa()
{
    int i,j;
    printf("\n\n\n");
    printf("\n   MINIMIZED DFA TABLE");
    printf("\n===========================\n\t");
    for(i=0;i<total_symbol;i++)
    printf("%c\t",(char)i+97);
    printf("\n");
    for(i=0;i<(total_symbol+1);i++)
    printf("-\t");
    printf("\n");
    for(i=0;i<a;i++)
    {
        printf("\n%d\t",i);
        for(j=0;j<total_symbol;j++)
        {
            printf("%d\t",new_transition[i][j]);
        }
    }
}
