#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    //Open input file as omni & test for success
    ifstream robo;
    robo.open ("small-robo-input.txt");
    if (robo.is_open())
        cout << "success" << endl;
    else
        cout << "failure";
    ;
    string current;
    int i = 0;
    for (int i = 0; i < 2; i++){
        getline(robo, current);
    }  
    getline(robo, current);             /*gets line 3 (name of robot)*/
    cout << "Robot Type: " << current << endl;        //displays name of robot

    
    return 0;

}