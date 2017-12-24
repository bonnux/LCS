#include <iostream>
using namespace std;
int b[100][100];
int c[100][100];
void lcs(char *x,char *y,int m,int n)
{
    int i,j;
    for(i=0; i<=m; i++)
        c[i][0]=0;
    for(j=1; j<=n; j++)
        c[0][j]=0;

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;                //“1”代表斜向上箭头
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]=2;                //“2”代表上箭头
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]=3;                //“3”代表向左的箭头
            }
        }
}

void print(char *x,int i,int j)
{
    if(i==0||j==0)
        return;
    if(b[i][j]==1)
    {
        print(x,i-1,j-1);
        cout<<x[i-1]<<" ";
    }
    else if(b[i][j]==2)
        print(x,i-1,j);
    else
        print(x,i,j-1);
}

int main()
{
    char x[]="sadasfwqederwsdf";
    char y[]="asaasdsffghjhgj";
    int m=strlen(x);
    int n=strlen(y);
    lcs(x,y,m,n);
    print(x,m,n);
}