#include "gtest/gtest.h"
#include "IntentRecognizer.h"

TEST(IntentRecognizerTest, CheckWeatherIntent) 
{
	IntentRecognizer intRecog;
	string s1 = "Is it sunny today ?";
	string s2 = "Will it snow on 13th ?";
	string s3 = "Will there be thunderstorm next week ?";
	string s4 = "How was your day ?";
	
	intRecog.processInput(s1);
	intRecog.processInput(s2);
	intRecog.processInput(s3);
	intRecog.processInput(s4);
	
	EXPECT_STREQ("Get Weather",intRecog.returnIntent(s1).c_str());
	EXPECT_STREQ("Get Weather",intRecog.returnIntent(s2).c_str());
	EXPECT_STREQ("Get Weather",intRecog.returnIntent(s3).c_str());
	EXPECT_STREQ("Could not identify intent",intRecog.returnIntent(s4).c_str());
}

TEST(IntentRecognizerTest, CheckWeatherCityIntent) 
{
	IntentRecognizer intRecog;
	string s1 = "Is it sunny today in London ?";
	string s2 = "Is it snowing in Berlin ?";
	string s3 = "How is the weather in Munich ?";
	string s4 = "How was your day ?";
	
	intRecog.processInput(s1);
	intRecog.processInput(s2);
	intRecog.processInput(s3);
	intRecog.processInput(s4);
	
	EXPECT_STREQ("Get Weather City",intRecog.returnIntent(s1).c_str());
	EXPECT_STREQ("Get Weather City",intRecog.returnIntent(s2).c_str());
	EXPECT_STREQ("Get Weather City",intRecog.returnIntent(s3).c_str());
	EXPECT_STREQ("Could not identify intent",intRecog.returnIntent(s4).c_str());
}

TEST(IntentRecognizerTest, CheckFacrIntent) 
{
	IntentRecognizer intRecog;
	string s1 = "Tell me something interesting.";
	string s2 = "Do you know some historical facts ?";
	string s3 = "Tell me something amazing";
	string s4 = "How was your day ?";
	
	intRecog.processInput(s1);
	intRecog.processInput(s2);
	intRecog.processInput(s3);
	intRecog.processInput(s4);
	
	EXPECT_STREQ("Get Fact",intRecog.returnIntent(s1).c_str());
	EXPECT_STREQ("Get Fact",intRecog.returnIntent(s2).c_str());
	EXPECT_STREQ("Get Fact",intRecog.returnIntent(s3).c_str());
	EXPECT_STREQ("Could not identify intent",intRecog.returnIntent(s4).c_str());
}