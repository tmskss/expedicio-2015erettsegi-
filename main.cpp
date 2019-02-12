#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class adatok{
public:
    int nap;
    int amator;
    string szoveg;
};
int main()
{
    ifstream beker;
    beker.open("veetel.txt");

    string bekert, sor;

    adatok tomb[200];
    int a=0;

    while(!beker.eof()){
        beker>>tomb[a].nap;
        beker>>tomb[a].amator;

        getline (beker,sor);
        getline(beker,bekert);
        tomb[a].szoveg=bekert;

        a++;
    }
    beker.close();
    a=a-1;

//2.feladat...........................................................................

    cout<<"2.feladat"<<endl;

    int amator;
    int maximum=0;

    for(int i=0;i<a;i++){
        if(tomb[i].nap==1){
            amator=tomb[i].amator;
        }
    }
    cout<<"Az elso uzenet rogzitoje: "<<amator<<"."<<endl;

    amator=0;

    for(int i=0;i<a;i++){
        if(tomb[i].nap>=maximum){
            amator=tomb[i].amator;
        }
    }
    cout<<"Az utolso uzenet rogzitoje: "<<amator<<"."<<endl;
    return 0;
}
