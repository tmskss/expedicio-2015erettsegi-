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

        cout<<tomb[a].nap<<" "<<tomb[a].amator<<endl<<tomb[a].szoveg<<endl<<endl;
        a++;
    }
    beker.close();
    return 0;
}
