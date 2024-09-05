#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to sort the characters of a string
string sortString(const string &str) {
  string sorted_str = str;
  sort(sorted_str.begin(), sorted_str.end());
  return sorted_str;
}

// Function to check if two words are anagrams
bool areAnagrams(const string &word1, const string &word2) {
  return sortString(word1) == sortString(word2);
}

// Function to check if two words are subanagrams
bool areSubAnagrams(const string &word1, const string &word2) {
  bool isit = 0;

  
  for(int letter = 0; letter < word1.length(); letter+=1){
    if(sortString(word1.substr(0,letter)) == sortString(word2)){
      bool isit = 1;
    }
  return isit;
  }
}

// Function to find and return all anagrams in the file
vector<string> findAnagrams(const string &word, const string &filename, const int type) {
  ifstream file(filename);
  vector<string> anagrams;
  vector<string> subanagrams;
  string line;

  if (!file.is_open()) {
    cerr << "Error: Could not open the file " << filename << endl;
    return anagrams;
  }

  if(type==0){
  while (getline(file, line)) {
    if (areAnagrams(word, line)) {
      anagrams.push_back(line);
    }
  }
  }
  if(type==1){
  while (getline(file, line)) {
    if (areSubAnagrams(word, line)) {
      subanagrams.push_back(line);
    }
  }
  }

  file.close();
  if(type==0){
  return anagrams;
  }
  if(type==1){
    return subanagrams;
  }
}

int main() {
  string word, filename;

  // Get the word from the user
  cout << "Enter a word: ";
  cin >> word;

  // Get the filename from the user
  cout << "Enter the filename containing the list of words: ";
  cin >> filename;

  // Find anagrams in the file
  vector<string> anagrams = findAnagrams(word, filename, 0);
  vector<string> subanagrams = findAnagrams(word, filename, 1);

  // Output the results
  if (anagrams.empty()) {
    cout << "No anagrams found for the word '" << word << "' in the file."
         << endl;
  } 
  if (!anagrams.empty()) {
    cout << "Anagrams found for the word '" << word << "':" << endl;

    int an_number = 1;
    for (const string &anagram : anagrams) {
      cout << an_number << "." << anagram << endl;
      an_number += 1;
    }
    an_number = 1;
  }
  if (subanagrams.empty()) {
  cout << "No subanagrams found for the word '" << word << "' in the file."
        << endl;
  }
  if (!subanagrams.empty()) {
    cout << "Subanagrams found for the word '" << word << "':" << endl;

    int suban_number = 1;
    for (const string &subanagram : subanagrams) {
      cout << suban_number << "." << subanagram << endl;
      suban_number += 1;
    }
  }
    
  


  return 0;
}
