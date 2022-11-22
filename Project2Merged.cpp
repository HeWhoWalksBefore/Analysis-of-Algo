#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int omnidroid(ifstream& omni, string current);
int robotomata(ifstream& robo, string current);
int main()
{
    //Open input file (omni) and output file (output) & test for success
    ifstream robot;
    robot.open ("example-input.txt");
    if (robot.is_open())
        cout << "success" << endl;
    else
        cout << "failure";
    ofstream output;
    output.open ("output.txt");
    if (output.is_open())
        cout << "success" << endl;
    else
        cout << "failure";

    //Go to omnidroid or robotomata depending on input. If output file shows -1, the getline 
    int result = -1;                                                    //name doesn't match
    string current;
    while (!robot.eof()){
        getline(robot, current);
        if (current == "omnidroid"){
            result = omnidroid(robot, current);
            output << result << endl;
        }
        else if (current == "robotomaton"){
            result = robotomata(robot, current);
            output << result << endl;
        }
    }
    return 0;
}

int omnidroid(ifstream& omni, string current){
    //create queue for the list of operations, and read the number of operations and parts into variables
    queue<pair<int, int>> operations_list;
    int numParts, numOperations = 0;
    omni >> numParts;
    omni >> numOperations;
    getline(omni, current);

    //store the operations in the queue "operation"   
    int addedPart, createdPart;
    pair<int, int> operation;
    for (int i = 0; i < numOperations; i++){
        omni >> operation.first;
        omni >> operation.second;
        getline(omni, current);
        operations_list.push(operation);
    }

    //store the part values in vector "partValues"
    vector<int> partValues;
    int cost;
    for (int i = 0; i < numParts; i++){
        omni >> cost;
        partValues.push_back(cost);
    }

    //Perform operations
    for (int i = 0; i < numOperations; i++){
        operation = operations_list.front();                                    //get operation
        operations_list.pop();
        partValues.at(operation.second) += partValues.at(operation.first);      //Add the value of the first part to the value of the second
    }

    return partValues.back();
}

int robotomata(ifstream& robo, string current){
    //Get the number of operations
    int numOperations;
    robo >> numOperations;

    //Get the operations and put them into a vector
    vector<int> operations;
    int sprockets, numStages = 0;
    getline(robo, current);
    while (robo >> sprockets){      //gets sprocket value at the beginning of each loop
        robo >> numStages;          //gets the number of previous stages used
        if (numStages != 0)         //iterate through the previous stages and add their sprocket count
            for (int i = 0; i < numStages; i++){
                sprockets+= operations.at(operations.size()-1-i);
            }
        operations.push_back(sprockets);    //add sprocket value to the vector
        getline(robo,current);              //getline to move to next line
    }

    //output results
    return operations.back();
}