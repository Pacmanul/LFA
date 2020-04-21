#include <iostream>
#include <fstream>
using namespace std;
int c1[100],c2[100],sf[100],si[100],lc[1000];
int nrs,nrf,nri;
void citire()
{   int i;
    ifstream f("AFD.in");
    f>>nrs;
    for(i=0;i<nrs;i++)
    {
        f>>c1[i]>>c2[i];

    }
    f>>nrf;
    for(i=0;i<nrf;i++)
    {
        int s;
        f>>s;
        sf[s]=1;
        lc[s]=1;
    }
    f>>nri;
    for(i=0;i<nri;i++)
    {
        int s;
        f>>s;
        si[s]=1;



    }

}
int t[1000],modr[1000];
int maxim()
{
    int maximi=-1;
    for(int i=0;i<nrs;i++)
        if(maximi<lc[i] && modr[i]==0)
            maximi=lc[i];
    return maximi;


}
void reset()
{
    for(int i=0;i<nrs;i++)
        modr[i]=0;

}
int nrm[100];
int v[100];
int countlc()
{
    int k=0,i;
    for(i=0;i<nrs;i++){
        nrm[lc[i]]=1;

    }
    for(i=0;i<100;i++)
    {
        if(nrm[i]==1)
            k++;

    }
    return k;

}
void transformare(){

int i,j;
//for(i=0;i<nrs;i++)
//{ if(t[i]==0)
//   {
//    cout<<i<<' ';
//    for(j=i+1;j<nrs;j++)
//    {
//        if((c1[i]==c1[j] && c2[i]==c2[j] && t[j]==0) || (c1[i]==c2[j] && c2[i]==c2[j] && t[j]==0)
//        {
//
//            cout<<j<<' ';
//            t[j]=1;
//
//
//        }
//    }
//    t[i]=1;
//    if(t[i]==1)
//    cout<<'\n';
//   }
//
//}
int k=2;
for(i=0;i<nrs;i++)
{
    for(j=0;j<nrs;j++)
    {
       if(c1[i]==c1[j] && c2[i]==c2[j] && sf[i]==sf[j])
       {
           lc[i]=k;
           lc[j]=k;

       }

    }
    k++;





}
for(i=0;i<nrs;i++)
{   k=0;
    for(j=0;j<nrs;j++)
        if(lc[i]==lc[j])
            k++;
    if(k>1)
        v[i]=1;

}
for(i=0;i<nrs;i++)
{
    if(v[i]==0)
        for(j=0;j<nrs; j++)
        {
            if(v[j]==0)
            {
                if(lc[c1[i]]==lc[c1[j]] || lc[c2[i]]==lc[c2[j]])
                {
                    v[j]=1;
                    lc[j]=lc[i];
                    si[j]=si[i];
                    sf[j]=sf[i];



                }
            }
        }
        v[i]=1;

}
int nrk=countlc();
int kor=1;
reset();
for(i=0;i<nrs;i++)
{
if(modr[i]==0)
   {cout<<"Date stare " << kor++<< " :\n";
//   nrstare[i]=kor-1;

   if(si[i]==1)
    cout<<"Stare initiala\n";
   else
    if(sf[i]==1)
        cout<<"Stare finala\n";
    else
        cout<<"Stare normala\n";

    cout<<i<<' ';

   for(j=0;j<nrs;j++)
   {
       if(lc[i]==lc[j] && i!=j)
       {
           cout<<j<<' ';
           modr[j]=1;


       }

   }
   cout<<endl;}
   modr[i]=1;




}





}
int main()
{


    citire();
    transformare();

}
