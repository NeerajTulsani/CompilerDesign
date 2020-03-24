#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

int  main()
{
    int table[5][4] = { {0,-1,-1,-1},
                        {-1,1,-1,2},
                        {3,-1,-1,-1},
                        {-1,2,4,2},
                        {5,-1,-1,-1}  };

    char tab[6][4] = { "TF\0","+TF\0","\0","VU\0","*VU\0","I\0" };

    char symbol,left[20],right[20],tok[4],csf[30] = "E",input[50],in[50];
    int flag = 1,len1,ssm=0,row,col,loc = 0;
    char brk(char* , int &);
    void leftright(char *,char left[20],char right[20],int ssm );

    //clrscr();
    cout<<"enter ur expression :";
    cin.getline(input,50);
    len1 = strlen(input);
    if (input[len1-1] != ';')
    {
        cout<<"please terminate the expression with a ';' ";
        exit(0);
    }
    strcpy(input,strupr(input));
    int j = 0;
    for(int i = 0;i< len1 - 2; i++)
    {
        if (input[i] != ' ')
            in[j++] = input[i];
    }
    in[j] = '\0';
    cout<<csf<<endl;
    symbol = brk(input,loc);
    while (flag)
    {

        if (csf[ssm] == 'E')      row = 0;
        elseif (csf[ssm] == 'F') row = 1;
        elseif (csf[ssm] == 'T') row = 2;
        elseif (csf[ssm] == 'U') row = 3;
        elseif (csf[ssm] == 'V') row = 4;
        else row = -1;

        if (symbol=='I')        col = 0;
        elseif (symbol== '+')  col = 1;
        elseif (symbol== '*')  col = 2;
        elseif (symbol == ';') col = 3;
        else col = -1;

        if (row == -1 || col == -1 || table[row][col] == -1)
        {
            cout<<endl<<input<<endl;
            for(i=0;i<2*ssm;i++)
              cout<<" ";
            cout<<"^"<<endl;
            cout<<"error in the expression "<<endl;
                   cout<<"symbol "<<symbol<<" is not valid in expression ";
            exit(0);
        }

        strcpy(tok, tab[table[row][col]]);

        leftright(csf,left,right,ssm);
        strcat(left,tok);
        strcat(left,right);
        strcpy(csf,left);

        if  (symbol == tok[0])
        {
            ssm++;
            symbol = brk(input,loc);
        }
        cout<<csf<<endl;

        if (!strcmp(in,csf))
              flag = 0;
    }
    cout<<"The Expression is valid";
    return 0;
}

char brk(char *input, int &loc)
{
    char symbol;
    if (input[loc] == ' ')
        loc++;
    symbol = input[loc++];
    return symbol;
}

void leftright(char *csf,char left[20],char right[20],int ssm)
{
     int i,len,j=0;
     strcpy(left,"\0");
     strcpy(right,"\0");
     len = strlen(csf);
     for(i = 0 ; i < ssm ; i++)
     {
        left[i] = csf[i];
     }
     left[i]='\0';
     for(i = ssm + 1 ;i<=len;i++)
     {
        right[j++] = csf[i];
     }
     right[j] = '\0';
}
