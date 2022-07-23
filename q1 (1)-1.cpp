// For an input string of words, find the most frequently occuring word. In case of ties, report any one of them. 
// Your algorithm should be O(n) time where n is the number of words in the string
// by Luis Umana
#include <iostream>
#include <vector>
#include <sstream>
#include<algorithm>
#include<unordered_map>

using namespace std;


string findWord(vector<string>& tokens);
 
int main() {
	string line = "Far out in the uncharted backwaters of the unfashionable end of the western spiral arm of the Galaxy lies a small unregarded yellow sun. Orbiting this at a distance of roughly ninety two million miles is an utterly insignificant little blue green planet whose ape descended life forms are so amazingly primitive that they still think digital watches are a pretty neat idea.";
	
	// Convert string to a vector of words
	char delimiter = ' ';
	string token;
	istringstream tokenStream(line);
	vector<string> tokens;
	while (getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}	
	cout << "The most frequently occuring word is: " << findWord(tokens) << endl;
	
}

string findWord(vector<string>& tokens) {
// Your code here

   unordered_map<string,int>Most;

   int MostWords=0;

   string MostWordsTokens="";

   for(int T=0;T<tokens.size();T++)

   {
    Most[tokens[T]]++;
    if(MostWords<Most[tokens[T]])
      {
      MostWords=Most[tokens[T]];
      
      MostWordsTokens=tokens[T];
       
      }
   }
   return MostWordsTokens;
}




