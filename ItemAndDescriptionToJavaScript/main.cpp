#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>

//Not going to worry about external libraries:
using namespace std;
/*
Program Name: ItemAndDescriptionToJavaScript
Purpose: To make an item checklist for dark souls. This just takes a list and converts it to javascript/json
Use: ItemAndDescriptionToJavaScript.exe inputfile.txt outputfile.js

*/

int main(int argc, char* argv[])
{
	//I got lazy during febuary and I should really pick up the pace.
	if (argc < 3 || argc > 3)
	{
		cout << "Error: bad argument list, need two. Usage: DropTableToJson.exe inputfile.txt outputfile.js" << endl;
		return EXIT_FAILURE;
	}

	vector<string> args;

	//Put arguments into a safe vector:
	for (int x = 1; x < argc; ++x)
	{
		args.push_back(argv[x]);
	}

	ifstream inFile(args.front());
	if (!inFile)
	{
		cout << "Error in opening file: " << args.front() << endl;
		return EXIT_FAILURE;
	}


	ofstream outFile;
	outFile.open(args.back());
	if (!outFile)
	{
		inFile.close();
		cout << "Error in creating file: " << args.back() << endl;
		return EXIT_FAILURE;
	}

	//Ok, so a preparation list:

	//Hold item name:
	string item("");

	//Used to store the how to description.
	string description("");

	string line("");

	bool addComa = false;
	bool haveItem = false;
	
						//Starter stuff:
	outFile << "items = [";
	while (getline(inFile, line))
	{
		if (haveItem && line != "" && addComa == true)
			outFile << "," << endl;
		if (line == "")
		{
			continue;
		}

		if (!haveItem)
		{
			haveItem = true;
			item = line;
			continue;
		}

		if (haveItem && line != "")
		{
			haveItem = false;
			description = line;

			outFile << "{\"item\" : \"" + item + "\", \"description\" : \"" + description + "\"}";

			addComa = true;
		}
	}

	//Finishing touches:
	outFile << endl << "];";
	inFile.close();
	outFile.close();
	return EXIT_SUCCESS;
}//End of main.