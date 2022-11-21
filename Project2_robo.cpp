#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    //Open input and output files & test for success
    ifstream robo;
    robo.open ("small-robo-input.txt");
    if (robo.is_open())
        cout << "success" << endl;
    else
        cout << "failure";
    ofstream output;
    output.open ("output.txt");
    if (output.is_open())
        cout << "success" << endl;
    else
        cout << "failure";

    //get to operation lines (Remove display name line and increase loop by one before finishing)
    string current;
    int i = 0;
    for (int i = 0; i < 2; i++){
        getline(robo, current);
    }  
    getline(robo, current);             /*gets line 3 (name of robot)*/
    cout << "Robot Type: " << current << endl;        //displays name of robot

    //Get the number of operations
    int numOperations;
    robo >> numOperations;

    //Get the operations and put them into a vector
    vector<int> operations;
    int sprockets, numStages = 0;
    getline(robo, current);
    while (robo >> sprockets){      //gets sprocket value at the beginning of each loop
        robo >> numStages;          //gets the number of previous stages used
        cout << "Sprockets: " << sprockets << ". Stages: " << numStages << "." << endl; //test info, REMOVE
        if (numStages != 0)         //iterate through the previous stages and add their sprocket count
            for (i = 0; i < numStages; i++){
                sprockets+= operations.at(operations.size()-1-i);
            }
        operations.push_back(sprockets);    //add sprocket value to the vector
        getline(robo,current);              //getline to move to next line
    }

    //TEST LOOP, REMOVE
    for (i = 0; i < operations.size(); i++)
        cout << i << " " << operations.at(i) << endl;

    output << operations.back();
    return 0;
}