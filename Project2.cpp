#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    //Open input file as omni & test for success
    ifstream omni;
    omni.open ("small-omni-input.txt");
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
    for (int i = 0; i < 2; i++){
        getline(omni, current);
        //cout << current << endl;      /*displays content*/
    }
    getline(omni, current);             /*gets line 3 (name of robot)*/
    //cout << "Robot Type: " << current << endl;        //displays name of robot


    //create queue for the list of operations, and read the number of operations and parts into variables
    queue<pair<int, int>> operations_list;
    int numParts, numOperations = 0;
    omni >> numParts;
    omni >> numOperations;
    getline(omni, current);
    //cout << numParts << " parts, " << numOperations << " operations." << endl; /*display part and operation num*/


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


    //display part values for testing
    /*cout << "size " << partValues.size() << endl;
    for (i = 0; i < partValues.size(); i++){
        cout << partValues.at(i) << endl;
    }*/


    //Perform operations
    //cout << "num operations: " << operations_list.size() << endl;
    for (i = 0; i < numOperations; i++){
        operation = operations_list.front();                                    //get operation
        operations_list.pop();
        partValues.at(operation.second) += partValues.at(operation.first);      //Add the value of the first part to the value of the second
    }

    cout << "result " << partValues.back() << endl;
    output << partValues.back();            //Put results into file
    return 0;
}