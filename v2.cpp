#include <iostream>
#include <vector>
#include <map>


using namespace std;




class dane
{
    public:
        int liczbaOsob;
        int liczbaOsobSegregacja=0;
        int turyGracza;
        vector<int>wynikiOsob;
        vector<int>wynikiGracza;
        vector<int>wynikiOsobSegregacja;
        vector<int>miejsceGraczaTab;

};



void wprowadzDane(dane &tab)
{

    cin>>tab.liczbaOsob;
    int pomocnicza;
    for(int i=0;i<tab.liczbaOsob;i++)
    {
        cin>>pomocnicza;
    tab.wynikiOsob.push_back(pomocnicza);
    }

    cin>>tab.turyGracza;
    for(int i=0;i<tab.turyGracza;i++)
    {
        cin>>pomocnicza;
        tab.wynikiGracza.push_back(pomocnicza);
    }
}


void usunDuplikaty(dane &tab)
{
   map<int,int>mapa;
   int liczba;
   int powt;

   for(int i=0;i<tab.liczbaOsob;i++)
   {
       liczba = tab.wynikiOsob[i];
       powt = ++mapa[liczba];

       if(powt==1)
       {
           tab.liczbaOsobSegregacja+=1;
           tab.wynikiOsobSegregacja.push_back(tab.wynikiOsob[i]);
       }
   }
}



void miejsceGracza(dane &tab)
{
    int miejsce = 0;
    for(int i=0;i<tab.turyGracza;i++)
    {
    miejsce = 1;
    for(int j=0;j<tab.liczbaOsob;j++)
    {
        if(j!=0 && (tab.wynikiOsob[j-1]==tab.wynikiOsob[j]))
        {
            miejsce-=1;
           // cout<<i<<" asd\n";
        }



        if(j==0 && (tab.wynikiOsob[j]<=tab.wynikiGracza[i]))
        {
            break;
        }
        else if(tab.wynikiOsob[j]<=tab.wynikiGracza[i])
        {
            miejsce=miejsce;
            break;
        }
        else
        {
            miejsce+=1;


        }

    }
    tab.miejsceGraczaTab.push_back(miejsce);
    }


}







int main()
{
    dane tab;
    int wynik;

    wprowadzDane(tab);

    //cout<<endl<<endl<<"Osoby: "<<tab.liczbaOsob<<endl<<"Wyniki: \n";
/*
    for(int i=0;i<tab.liczbaOsob;i++)
    {
        cout<<tab.wynikiOsob[i]<<endl;
    }
*/
   // usunDuplikaty(tab);
/*

    cout<<endl<<endl<<"Osoby: "<<tab.liczbaOsobSegregacja<<endl<<"Wyniki: \n";

    for(int i=0;i<tab.liczbaOsobSegregacja;i++)
    {
        cout<<tab.wynikiOsobSegregacja[i]<<endl;
    }

*/
miejsceGracza(tab);
    for(int i=0;i<tab.turyGracza;i++)
    {
        cout<<tab.miejsceGraczaTab[i]<<endl;
    }





    return 0;
}
