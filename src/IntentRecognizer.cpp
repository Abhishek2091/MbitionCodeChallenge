/**
 * @file IntentRecognizer.cpp
 *
 * @brief Reads user input and prints user intent
 *
 * @author Abhishek Kekre
 *
 * @version  1.0
 */

#include "IntentRecognizer.h"

#include <fstream>
#include <iostream>

using namespace std;


IntentRecognizer::IntentRecognizer()
{
	fillKeywordColl(IntentType::WEATHER);
	fillKeywordColl(IntentType::CITIES);
	fillKeywordColl(IntentType::FACTS);
}

/**
 *
 * Reads input from command line
 *
 * @param  string& : Input string
 */
void IntentRecognizer::processInput(string& input)
{
	convertToLowerCase(input);
	// Check if input is asking for a weather
	for(const auto& keyword : m_weather_keywords)
	{
		if(input.find(keyword) != string::npos)
		{
			input_output_map.insert(make_pair(input,"Get Weather"));
			break;
		}
	}
	
	// Check if input is asking for a weather in a city
	for(const auto& keyword : m_cities)
	{
		if(input.find(keyword) != string::npos)
		{
			auto itr = input_output_map.find(input);
			if(itr != input_output_map.end())
			{
				itr->second = "Get Weather City";
			}
			break;
		}
	}
	
	// Check if input is asking for a fact
	for(const auto& keyword : m_facts)
	{
		if(input.find(keyword) != string::npos)
		{
			input_output_map.insert(make_pair(input,"Get Fact"));
			break;
		}
	}
	
	// If none of the keywords match, we will just add input and print output as "Could not identify intent"
	if(input_output_map.find(input) == input_output_map.end())
	{
		input_output_map.insert(make_pair(input,"Could not identify intent"));
	}
}

/**
 *
 * Reads input fetched from text file
 *
 * @param  vector<string>& : Collection of input strings
 */
void IntentRecognizer::processInput(vector<string>& input)
{
	for(auto& input_str : input)
	{
		convertToLowerCase(input_str);
		// Check if input is asking for a weather
		for(const auto& keyword : m_weather_keywords)
		{
			if(input_str.find(keyword) != string::npos)
			{
				input_output_map.insert(make_pair(input_str,"Get Weather"));
				break;
			}
		}
		
		// Check if input is asking for a weather in a city
		for(const auto& keyword : m_cities)
		{
			if(input_str.find(keyword) != string::npos)
			{
				auto itr = input_output_map.find(input_str);
				if(itr != input_output_map.end())
				{
					itr->second = "Get Weather City";
				}
				break;
			}
		}
		
		// Check if input is asking for a fact
		for(const auto& keyword : m_facts)
		{
			if(input_str.find(keyword) != string::npos)
			{
				input_output_map.insert(make_pair(input_str,"Get Fact"));
				break;
			}
		}
		
		// If none of the keywords match, we will just add input and print output as "Could not identify intent"
		if(input_output_map.find(input_str) == input_output_map.end())
		{
			input_output_map.insert(make_pair(input_str,"Could not identify intent"));
		}
	}
	
}

/**
 *
 * Prints the output to command line
 *
 */
void IntentRecognizer::printOutput()
{
	cout << "\n------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "-------------------------------------------------------OUTPUT FROM INTENT RECOGNIZER------------------------------------------------------------\n";
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "\n";
	for (const auto& in_out_pair : input_output_map) 
	{
		cout << in_out_pair.first << " => " << in_out_pair.second << endl;
	}
}

/**
 *
 * Helper method that initializes class memebers
 *
 * @param  IntentType& : Type of intent
 */
void IntentRecognizer::fillKeywordColl(const IntentType& intType)
{
	string fileName;
	vector<string>* collPtr;
	switch(intType)
	{
		case IntentType::WEATHER:
			fileName = WEATHER_KEYWORDS_FILE;
			collPtr = &m_weather_keywords;
		    break;
		case IntentType::CITIES:
			fileName = CITIES_NAME_FILE;
			collPtr = &m_cities;
		    break;
		case IntentType::FACTS:
			fileName = FACT_RELATED_WORDS_FILE;
			collPtr = &m_facts;
		    break;
	}

	vector<string> keywords;
	ifstream fin(fileName);
	if(fin.is_open())
	{
		vector<string> input;
		string line;
		while (getline(fin,line)) 
		{
			if(!line.empty())
			{
				convertToLowerCase(line);
				collPtr->push_back(line);
			}
		}
		fin.close();
	}
}

/**
 *
 * Helper method for unit tests
 *
 * @param  input& : Input string
 */
string IntentRecognizer::returnIntent(const string& input)
{
	auto in_out_pair = input_output_map.find(input);
	
	return in_out_pair->second;
}