#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    ifstream omni;
    omni.open ("omni.txt");
    if (omni.is_open())
        cout << "success" << endl;
    else
        cout << "failure";
    string current;
    int i = 0;
    for (int i = 0; i < 2; i++){
        getline(omni, current);
        cout << current << endl;
    }
    getline(omni, current);
    cout << "Robot Type: " << current << endl;


    queue<pair<int, int>> operations_list;
    int numParts, numOperations = 0;
    omni >> numParts;
    omni >> numOperations;
    cout << numParts << " parts, " << numOperations << " operations." << endl;
    getline(omni, current);

    int addedPart, createdPart;
    pair<int, int> operation;
    for (i = 0; i < numOperations; i++){
        omni >> operation.first;
        omni >> operation.second;
        getline(omni, current);
        operations_list.push(operation);
    }

    vector<int> partValues;
    int cost;
    for (i = 0; i < numParts; i++){
        omni >> cost;
        partValues.insert(cost);
    }
    cout << "size" << partValues.size();
    for (i = 0; i < partValues.size(); i++){
        cout << partValues.at(i);
    }

    

}
