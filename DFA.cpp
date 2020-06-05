/* NAME-KASHYAP SINGH
   SECTION-A
   CLASS ROLL NUMBER-31
   UNIVERSITY ROLL NUMBER-2013357*/
//MINIMIZATION OF DFA PROGRAM USING C++
#include<bits/stdc++.h>
using namespace std;
#define MARKED 1
#define UNMARKED -1
int total_state,total_symbol,final_state,fin,a;
int transition[10][10],m[10][10],newstate[10][10],arr[10],new_transition[10][10];
/*
    transition[10][10]-Stores initial transition table.
    m[10][10]-Used for table filling method i.e for mark and unmark.
    newstate[10][10]-Stores equivalent sets.
    arr[10]-Used to store states.
    new_transition[10][10]-Contains new transition table.
*/
void store_dfa(void)
{
    int i,j;
    cout<<"Enter total no. of states neglecting unreachable states:";
    cin>>total_state;
    cout<<"Enter total no. of allowed symbols :";
    cin>>total_symbol;
    cout<<"Enter the final state "<<endl;
    cin>>final_state;
    cout<<"Enter the transitions :- "<<endl;
    for(i=0;i<total_state;i++)//It will store initial transition table.
    {
        for(j=0;j<total_symbol;j++)
        {
            cout<<endl<<i<< " ---> "<<char(j+97)<<" :";
            cin>>transition[i][j];
        }
    }
}
void show_dfa(void)
{
    int i,j;
    cout<<endl<<endl<<endl;
    cout<<endl<<"   TRANSITION TABLE OF ENTERED DFA IS AS FOLLOWS ";
    cout<<endl<<"===================================================="<<endl;
    for(i=0;i<total_symbol;i++)
    cout<<"\t"<<char(i+97);
    cout<<endl;
    for(i=0;i<(total_symbol+1);i++)
    cout<<"-\t";
    cout<<"\n";
    for(i=0;i<total_state;i++)//Prints initial DFA
    {
        cout<<"\n"<<i<<"\t";
        for(j=0;j<total_symbol;j++)
        {
            cout<<transition[i][j]<<"\t";
        }
    }
    cout<<endl<<endl<<"Total no. is states :"<<total_state;
    cout<<endl<<"Final state is :"<<final_state;
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
void newstate_table()//Use to make equivalent sets.
{
    int i,j,k=0,b=0;
    for(i=0;i<total_state;i++)
    {
        for(j=0;j<total_state;j++)
        {
            newstate[i][j]=total_state;//Assigning the value of total_state in the 2D array.
        }
    }
    for(i=0;i<total_state;i++)
    {
        arr[i]=total_state;//Another 1D array which stores the value of total_state.
    }
    for(i=0;i<total_state;i++)//This loop will give us Equivalent sets.
    {
        if(check(i)!=0)//Use to check whether the number of states is over or not.
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
int find_s(int x)//Use to know the position of x in newstate 2D array.
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
void trans_table()
{
    int i,x,s1,k;
    for(i=0;i<=a;i++)//Here the value of a is equal to the no. of new states after using equivalent rule.
    {                //This loop will give us minimized transition table.
        x=newstate[i][0];
        for(k=0;k<total_symbol;k++)
        {
            s1=transition[x][k];
            fin=find_s(s1);
            new_transition[i][k]=fin;
        }
    }
    final_state = find_s(final_state);
}
void show_minimized_dfa()//Prints the minimized table.
{
    int i,j;
    cout<<"\n\n\n";
    cout<<"\n   MINIMIZED DFA TABLE";
    cout<<"\n===========================\n\t";
    for(i=0;i<total_symbol;i++)
    cout<<char(i+97)<<"\t";
    cout<<"\n";
    for(i=0;i<(total_symbol+1);i++)
    cout<<"-\t";
    cout<<"\n";
    for(i=0;i<a;i++)
    {
        cout<<"\n"<<i<<"\t";
        for(j=0;j<total_symbol;j++)
        {
            cout<<new_transition[i][j]<<"\t";
        }
    }
    cout<<endl<<endl<<"Total no. of new state is :"<<a;
    cout<<endl<<"Final State is :"<<final_state;
}
int main()
{
    store_dfa();
    show_dfa();
    mark_dfa();
    newstate_table();
    trans_table();
    show_minimized_dfa();
}
