#include<bits/stdc++.h>
using namespace std;

int r,c;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

void print(char ch[][50])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<ch[i][j];
        }
        cout<<endl;
    }
}

void FloodFill(char mat[][50],int i, int j, char ch, char color)
{
    //Base
    if(i<0||j<0 || i>=r||j>=c)
        return;

    //boundary
    if(mat[i][j]!=ch)
        return;

    //recursion
    mat[i][j] = color;
    for(int k=0;k<4;k++)
    {
        FloodFill(mat,i+dx[k],j+dy[k],ch,color);
    }
    return;
}


int main(int argc, char const *argv[]) {
    cin>>r>>c;
    char input[15][50];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>input[i][j];
        }
    }

    print(input);

    FloodFill(input,3,5,'.','r');

    print(input);

    return 0;
}
/*
7 7
aaaaaaa
a.....a
a.....a
a.....a
a.....a
a.....a
aaaaaaa
*/
