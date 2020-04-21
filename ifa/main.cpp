#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int v[100][100][100];
int i,j;
int n;
char cuv[100];
int nrf,vf[100];
int nri;
int vi[100];
int lc=2;
int r=0;
int adancime=0;
int rasp(int cont,int cr)
{
    if(cuv[cr]==NULL)
    {
        i=0;
        while(i<nrf)
            {if(vf[i]==cont)
                r=1;
             i+=1;
            }
    }
    else
        for(int j=1;j<=adancime;j++)
        for(int m=1; m<=n; m++)
            if(v[cont][m][j]==cuv[cr]-'0' && cuv[cr]!=NULL)
            {
                cout<<cont<<' '<<m;

                rasp(m,cr+1);

            }


}
int main()
{

    ifstream f("afn.iin");

    f>>n;
    f>>nri;
    i=0;
    while(i<nri)
        f>>vi[i++];
    i=0;
    f>>nrf;

    while(i<nrf)
        f>>vf[i++];
        f>>adancime;
for(int m=1;m<=adancime;m++)
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            f>>v[i][j][m];
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            cout<<v[i][j][2]<<' ';
        cout<<endl;
    }


    cin>>cuv;
    rasp(1,0);
    cout<<endl;
    cout<<r;

return 0;

}



