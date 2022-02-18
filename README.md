# MbitionCodeChallenge

**Introduction**
<br>
This project implements a embedded intent recognizer which takes input from user and prints the user intent.

E.g.:

What is the weather like today ? => Get Weather

What is the weather like in Paris ? => Get Weather City

Tell me some interesting facts. => Get Facts
<br>
<br>
<br>
**Structure**
<br>
This project has 3 main directories :

1.**src** : Contains the headers and source code.
<br>
<br>
2.**config** : Contains 3 files :
<br>
<br>
**weather_keyword.txt** : This file contains all the words related to weather and can be extended by adding new words.

**cities.txt** : This file contains names of major cities in the world.

**facts_related_words** : This file contains words that can be used to get information or facts.
<br>
<br>
**3.tst** : This folder contains the unit tests


Main repo has file **input.txt** which can be passed to this program if you want to get intent for multiple strings at once.

To pass this file as input, you need to select input_type=text_file when running the exe.
<br>
<br>
<br>
**How to build the code ?**

1.First clone the googletest repo from git clone https://github.com/google/googletest/

Next create a lib folder under root directory and copy the googletest folder in lib folder.

2.In root directory of the repo, create a build directory using command "mkdir build".

3.Go to build directory using command "cd build"

4.Run the cmake command **cmake -G "MinGW Makefiles" ..**

4.Run make by command "make all".
<br>
<br>
<br>
**How to run the exe and unit test ?**

1.Go to build folder.

2.The exe name is "**IntentRecognizer.exe**".Run it as follows :

If you want to enter input through command line :
<br>
**./IntentRecognizer.exe -input_mode=cmd_line**

If you want to enter input through text file which will have strings for which you want to get intent :
<br>
**./IntentRecognizer.exe -input_mode=text_file**

Next you need to enter path to text file which will have input strings.
Enter path in format : E.g **C:/input.txt**

3.To run the tests, run the exe "**IntentRecognizer_tst.exe**".
