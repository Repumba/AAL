#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream csvFile;
    csvFile.open("results.csv", ios::app);
    if(!csvFile){
        cout << "not ok" << endl;
        return 0;
    }
    csvFile << "ok" << endl;
    csvFile.close();
    return 0;
}