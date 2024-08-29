#pragma once
#include<iostream>
#include<vector>


using namespace std;

struct CleansedWord
{
    string originalWord;
    string cleansedWord;
   
    int frequency;



};



class WordCollection
{
public:
    WordCollection(string path);
    int getWordCount();
    int getDistinctWordCount();
    bool wordSearch(string cheese);
    
    vector <CleansedWord> getMostUsedWords(int numTopWords);
    vector <CleansedWord> getCompare(int numTopWords, int minWordLength);
    vector <CleansedWord> getWordsUsed(int usedNumTimes);
    string cleanseWord(string cleansedWord);

    void printAllWords();
    void PrintVector(vector<CleansedWord> anything);

private:
    vector <CleansedWord> allWords;
   
  
};

