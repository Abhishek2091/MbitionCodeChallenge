
#include "IntentRecognizer.h"

#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;


IntentRecognizer::IntentRecognizer()
{
	fillKeywordColl(IntentType::WEATHER);
	fillKeywordColl(IntentType::CITIES);
	fillKeywordColl(IntentType::FACTS);
}

void IntentRecognizer::processInput(const string& input)
{
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

void IntentRecognizer::processInput(const vector<string>& input)
{
	for(const auto& input_str : input)
	{
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
				transform(line.begin(),line.end(),line.begin(),[](unsigned char ch){return tolower(ch);});
				collPtr->push_back(line);
			}
		}
		fin.close();
	}
}