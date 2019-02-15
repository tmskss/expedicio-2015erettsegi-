#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class beadatok{
public:
    int nap;
    int radioamator;
    string szoveg;

};
class szoveg{
public:
    int nap;
    string szoveg;
};
int main()
{
    ifstream beker;
    beker.open("veetel.txt");

    string bekert;
    string sor;

    beadatok tomb[200];

    for(int i=0;i<200;i++){
        tomb[i].nap=0;
        tomb[i].radioamator=0;
        tomb[i].szoveg="";
    }

    int a=0;
    int maximum=0;

    while(!beker.eof()){
        beker>>tomb[a].nap>>tomb[a].radioamator;

        getline(beker,sor);
        getline(beker,bekert);

        tomb[a].szoveg=bekert;
        a++;
    }
    beker.close();
    a--;

//2.feladat..........................................................................................................................
    cout<<"2.feladat."<<endl;

    int amator;

    for(int i=0;i<a;i++){
        if(tomb[i].nap<=0){
            amator=tomb[i].radioamator;
        }
    }
    cout<<"Elso: "<<amator<<endl;

    for(int i=0;i<a;i++){
        if(tomb[i].nap>=maximum){
            amator=tomb[i].radioamator;
            maximum=tomb[i].nap;
        }
    }
    cout<<"Utolso: "<<amator<<endl;

//4.feladat...............................................................................................................................
    cout<<"4.feladat"<<endl;

    int napok[12];

    for(int i=0;i<11;i++){
        napok[i]=0;
    }

    for(int i=0;i<11;i++){
        for(int j=0;j<a;j++){
            if(tomb[j].nap==i+1){
                napok[i]++;
            }
        }
    }
    for(int i=0;i<11;i++){
        if(i<9){
            cout<<"0"<<i+1<<" ";
            for(int j=0;j<napok[i];j++){
                cout<<"+";
            }
            cout<<endl;
        }else{
            cout<<i+1<<" ";
            for(int j=0;j<napok[i];j++){
                cout<<"+";
            }
            cout<<endl;
        }
    }

//5.feladat.......................................................................................
    cout<<"5.feladat"<<endl;


    szoveg eredeti[12];
    string szoveg="";
    string eredetiszoveg="";


    for(int i=0;i<11;i++){
            eredetiszoveg=eredeti[i].szoveg;
            eredeti[i].nap=i+1;

            for(int k=0;k<89;k++){
            eredetiszoveg=eredetiszoveg+'#';
        }

        for(int j=0;j<a;j++){
            if(tomb[j].nap==i+1){
                szoveg=tomb[j].szoveg;
                for(int k=0;k<89;k++){
                    if(szoveg.at(k)!='#' && eredetiszoveg.at(k)=='#'){
                        eredetiszoveg.at(k)=szoveg.at(k);
                    }
                }
            }

        }
        eredeti[i].szoveg=eredetiszoveg;
    }
    for(int i=0;i<11;i++){
        cout<<eredeti[i].nap<<".nap: "<<eredeti[i].szoveg<<endl;
    }
    return 0;
}
