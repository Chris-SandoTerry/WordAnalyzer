#include "WorldCollection.h"

#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

WordCollection::WordCollection(string path)
{
    ifstream infile;

    infile.open(path);

    if (infile.good())
    {
        string bingo;
        string clean;

        while (infile.good())
        {
            infile >> bingo;
            clean = cleanseWord(bingo);
            if(clean == "")
            {
                continue;
            }
            if (!wordSearch(clean))
            {
                allWords.push_back({ bingo,clean,1 });
            }
        }

      
    }
    else
    {
        cout << "Cannot open the file: " << path << endl;
    }


}

int WordCollection::getWordCount()
{
    int Bum = 0;
    for(int i = 0; i < allWords.size(); i++)
    {
        Bum = Bum + allWords[i].frequency;
    }
	return Bum;
}

int WordCollection::getDistinctWordCount()
{
    return allWords.size();
}

bool WordCollection::wordSearch(string cheese)
{
   bool retVal = false;
   //binary

    for(int i = 0; i < allWords.size(); i++)
    {
     if(cheese == allWords[i].cleansedWord)
     {
         retVal = true;
         allWords[i].frequency++;
     }
    
    }
    return retVal;
}

vector<CleansedWord> WordCollection::getMostUsedWords(int numTopWords)
{
    vector<CleansedWord> MostUsed;

    for(int i = 0; i < numTopWords;i++)
    {
      for(int i = 0; i < allWords.size() - 1;i++)
      {
        if(allWords[i].frequency > allWords[i + 1].frequency)
        {
            CleansedWord Currency;
            Currency = allWords[i];
            allWords[i] = allWords[i + 1];
            allWords[i + 1] = Currency;
        }

      }
    
    }

    for( int i = allWords.size()- 1 ; i > allWords.size() - numTopWords - 1; i--)
    {
        MostUsed.push_back(allWords[i]);
    
    }

	return MostUsed;
}

vector<CleansedWord> WordCollection::getCompare(int numTopWords, int minWordLength)
{
    vector<CleansedWord> autoBots;

    for (int i = 0; i < numTopWords; i++)
    {
        for (int i = 0; i < allWords.size() - 1; i++)
        {
           if(allWords[i].cleansedWord.length() > 9)
           {
               if(allWords[i + 1].cleansedWord.length() > 9)
               {
               
                   if (allWords[i].frequency > allWords[i + 1].frequency)
                   {
                       CleansedWord Currency;
                       Currency = allWords[i];
                       allWords[i] = allWords[i + 1];
                       allWords[i + 1] = Currency;
                   }
               
               }
               else 
               {
                   CleansedWord Currency;
                   Currency = allWords[i];
                   allWords[i] = allWords[i + 1];
                   allWords[i + 1] = Currency;
                
               }





               
           }

        }

    }

    int ant = allWords.size() - 1;

    while (autoBots.size() < numTopWords)
    {
        if (allWords[ant].cleansedWord.length() >= minWordLength)
        { 
            autoBots.push_back(allWords[ant]);
           

        }
        
        
        ant--;
    }
	return autoBots;
}

vector<CleansedWord> WordCollection::getWordsUsed(int usedNumTimes)
{
    vector<CleansedWord>Bumblebee;

    for(int i = 0; i < allWords.size(); i++)
    {

     if(allWords[i].frequency == usedNumTimes)
     {
         Bumblebee.push_back(allWords[i]);
     }
      
    }

    return Bumblebee;
}

string WordCollection::cleanseWord(string cleansedWord)
{



    for (int i = 0; i < cleansedWord.size(); i++)
    {
        if (ispunct(cleansedWord[i]))
        {
            cleansedWord.erase(i, 1);
            i--;
        }
    }

    for (int i = 0; i < cleansedWord.length(); i++)
    {
        cleansedWord[i] = tolower(cleansedWord[i]);
    }

    return cleansedWord;
    
}

void WordCollection::printAllWords()
{
 
    cout << "Word Count:" << getWordCount() << endl;
    cout << "=======================================" << endl;
    cout << "Distinct Word Count:"<< getDistinctWordCount() << endl;
    cout << "=======================================" << endl;
    cout << "Most 10 Words Used Words: " << endl;
    PrintVector(getMostUsedWords(10));
    cout <<"=======================================" <<endl;
    cout << "Get Words Used exactly 10 times: " << endl;
    PrintVector(getWordsUsed(10));
    cout << "=======================================" << endl;
    cout << "31 Most Used words that are 10 letters long: " << endl;
    PrintVector(getCompare(31, 10));
    
 
}

void WordCollection::PrintVector(vector<CleansedWord> anything)
{
    for (int i = 0; i < anything.size(); i++)
    {
        cout << anything[i].cleansedWord << ": " << anything[i].frequency << endl;

    }
}
