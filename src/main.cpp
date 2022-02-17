// To Do : Write header to descibe this

#include "IntentRecognizer.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <memory>
#include <string.h>

using namespace std;

void printUsage()
{
	cout << "Usage: " << endl 
			<< "\t1. ./IntentRecognizer -rel" << endl
    		<< "\t    Shows the version information " << endl
    		<< "\t2. ./IntentRecognizer --help or IntentRecognizer -h" << endl
    		<< "\t    Prints this help message" << endl
    		<< "\t3. ./IntentRecognizer -input_type=cmd_line or IntentRecognizer -input_type=text_file or IntentRecognizer -input_type=database" << endl;
}

void printReleaseVersion()
{
	cout << "Version: 1.0.0" << endl;
}

void readInputFromCmdLine(shared_ptr<IntentRecognizer>& intentRecog)
{
	// Currenttly this functions reads from single user
	// We can extend this for multiple users by using threads
	
	
	string input;
	char ch;
	do
	{
		cout << "\nEnter input string for which you want to get intent : " << endl;
		cout << "E.g.How is the weather today ?" << endl <<endl;
		getline(cin, input);
		if(!input.empty())
		{
			intentRecog->processInput(input);
		}
		else
		{
			cerr << "Input empty.Please enter valid input string." << endl;
		}
	
		cout << "\nDo you wish to continue(y/n) ?" << endl;
		cin >> ch;
		cin.ignore(256, '\n');
		
	}while(tolower(ch)=='y');
}

bool readInputFromFile(const string& fileName,shared_ptr<IntentRecognizer>& intentRecog)
{
	ifstream fin(fileName);
	if(fin.is_open())
	{
		vector<string> input;
		string line;
		while (getline(fin,line)) 
		{
			if(!line.empty())
			{
				input.push_back(line);
			}
		}
		intentRecog->processInput(input);
		fin.close();
	} 	
	else
	{
		cerr << "Could not open file : " << fileName << endl;
		cout << "File path : " << fileName << " invalid.Please enter correct path" << endl;
		return false;
	}
	
	return true;
}

bool parseInput(const string& input_type_param,shared_ptr<IntentRecognizer>& intentRecog)
{
	if( int pos = input_type_param.find("="); pos != string::npos )
	{
		string input_type = input_type_param.substr(pos+1);
		transform(input_type.begin(),input_type.end(),input_type.begin(),[](unsigned char ch){return tolower(ch);});
		if(input_type == "cmd_line")
		{
			cout << "You have choosen to enter input from command line." << endl << endl;
			readInputFromCmdLine(intentRecog);
		}
		else if(input_type == "text_file")
		{
			cout << "You have choosen to enter input from text file" << endl;
			cout << "Enter path to text file : E.g. C:/Users/Input.txt" << endl;
			string fileName;
			getline(cin,fileName);
			return readInputFromFile(fileName,intentRecog);
			
		}
		else if(input_type == "database")
		{
			// Shall be supported in future
			cout << "You have choosen to enter input from database" << endl;
			cout << "This input type shall be supported in future releases" << endl;
			return true;
		}
		else
		{
			
			cerr << " Invalid input type : " << input_type << endl;
			cout << " Please specify input type as cmd_line or text_file or database" << endl ;
			return false;
		}
	}
	else
	{
		cerr << "Invalid format !! Please see usage below." << endl;
		cout << "./IntentRecognizer -input_type=cmd_line or IntentRecognizer -input_type=text_file or IntentRecognizer -input_type=database" << endl << endl;
		return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	if( argc < 2)
	{
		printUsage();
		return 1;
	}

	cout << "***********************************************************************************************************************************************" << endl;
	cout << "***********************************************************************************************************************************************" << endl;
	cout << "************************************************************** WELCOME TO INTENT RECOGNIZER ***************************************************" << endl;
	cout << "***********************************************************************************************************************************************" << endl;
	cout << "***********************************************************************************************************************************************" << endl;
	cout << endl << endl;

	shared_ptr<IntentRecognizer> intentRecog = make_shared<IntentRecognizer>();;
	
	if( argc == 2 && (strcmp(argv[1],"-rel") == 0))
	{
		printReleaseVersion();
		return 0;
	}
	if( argc == 2 && (strcmp(argv[1],"--help") == 0 || strcmp(argv[1],"-h") == 0))
	{
		printUsage();
		return 0;
	}
	if( argc == 2 && (strstr(argv[1],"-input_type") != nullptr))
	{
		if(!parseInput(strstr(argv[1],"-input_type"),intentRecog)) //ToDo : Use C++17 feature of declaring variable inside if and pass that variable here
		{
			return 1;
		}
	}
	else
	{
		printUsage();
	}
	
	intentRecog->printOutput();
	return 0;
}