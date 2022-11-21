#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    //Open input file (omni) and output file (output) & test for success
    ifstream omni;
    omni.open ("input.txt");
    if (omni.is_open())
        cout << "success" << endl;
    else
        cout << "failure";
    ofstream output;
    output.open ("output.txt");
    if (output.is_open())
        cout << "success" << endl;
    else
        cout << "failure";
    
    //get to line 4 (where it tells us part num and operation num)
    string current;
    int i = 0;
    for (int i = 0; i <= 2; i++){
        getline(omni, current);
    }

    //create queue for the list of operations, and read the number of operations and parts into variables
    queue<pair<int, int>> operations_list;
    int numParts, numOperations = 0;
    omni >> numParts;
    omni >> numOperations;
    getline(omni, current);

    //store the operations in the queue "operation"   
    int addedPart, createdPart;
    pair<int, int> operation;
    for (i = 0; i < numOperations; i++){
        omni >> operation.first;
        omni >> operation.second;
        getline(omni, current);
        operations_list.push(operation);
    }

    //store the part values in vector "partValues"
    vector<int> partValues;
    int cost;
    for (i = 0; i < numParts; i++){
        omni >> cost;
        partValues.push_back(cost);
    }

    //Perform operations
    for (i = 0; i < numOperations; i++){
        operation = operations_list.front();                                    //get operation
        operations_list.pop();
        partValues.at(operation.second) += partValues.at(operation.first);      //Add the value of the first part to the value of the second
    }

    output << partValues.back();
    return 0;
}