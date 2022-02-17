// To Do : Write header to describe this file

#ifndef INTENTRECOGNIZER_H
#define INTENTRECOGNIZER_H

#define WEATHER_KEYWORDS_FILE "../config/weather_keywords.txt"
#define CITIES_NAME_FILE "../config/cities.txt"
#define FACT_RELATED_WORDS_FILE "../config/fact_related_words.txt"

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum class IntentType
{
	WEATHER,
	CITIES,
	FACTS,
};

class IntentRecognizer
{
	public:
	IntentRecognizer();
	IntentRecognizer(const IntentRecognizer&) = default;
	IntentRecognizer& operator=(const IntentRecognizer&) = default;
	
	void processInput(const string& input);
	void processInput(const vector<string>& input);
	void printOutput();
	
	private:
	void fillKeywordColl( const IntentType&);

	vector<string> m_weather_keywords;
	vector<string> m_cities;
	vector<string> m_facts;
	unordered_multimap<string,string> input_output_map;
	
};

#endif