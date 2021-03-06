#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace std::chrono;

// helper function to verify user input
bool inList(string input, string names[]) {
	bool b = false;
	for(int i = 0; i < names->size(); i++){
		if(input == names[i]){
			b = true;
		}
	}
	return b;
}

// function to populate array(vector) with words from file and search for the specified word
void findWordUsingArray(string fileName, string inputWord) {
	auto start = high_resolution_clock::now();	// start timer for loading the data structure
	// read the values into a vector
	vector<string> vectorOfWords;
	ifstream in(fileName);
	string str;
	while(getline(in, str)) {
		if (str.size() > 0) {
			vectorOfWords.push_back(str);
		}
	}
	in.close();
	auto stop = high_resolution_clock::now();	// end timer for loading the data structure
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Loading the array took: " << duration.count() << " microseconds" << endl;
	
	// then search for the specified word
	auto start1 = high_resolution_clock::now();	// start timer for searching for the word
	if (find(vectorOfWords.begin(), vectorOfWords.end(), inputWord) != vectorOfWords.end()) {
		auto stop1 = high_resolution_clock::now();	// end timer for searching for the word
		auto duration1 = duration_cast<microseconds>(stop1 - start1);
		cout << "Word found! Searching for the word took: " << duration1.count() << " microseconds" << endl;
	} else {
		auto stop1 = high_resolution_clock::now(); // end the timer just to stop memory leaks
		cout << "Word not found";
	}
}

// function to populate hashtable(unordered map) from file and search for the specified word
void findWordUsingHashTable(string fileName, string inputWord) {
	auto start = high_resolution_clock::now();	// start timer for loading the data structure
	// read the values into an unorderedmap
	unordered_map<string, string> umap;
	ifstream in(fileName);
	string str;
	while(getline(in, str)) {
		if (str.size() > 0) {
			umap[str] = str;
		}
	}
	in.close();
	auto stop = high_resolution_clock::now();	// end timer for loading the data structure
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Loading the hashtable took: " << duration.count() << " microseconds" << endl;
	
	//then search for the specified word
	auto start1 = high_resolution_clock::now();	// start timer for searching for the word
	if (umap.find(inputWord) == umap.end()) {		
		auto stop1 = high_resolution_clock::now(); // end the timer just to stop memory leaks
		cout << "Word not found";
	} else {
		auto stop1 = high_resolution_clock::now();	// end timer for searching for the word
		auto duration1 = duration_cast<microseconds>(stop1 - start1);
		cout << "Word found! Searching for the word took: " << duration1.count() << " microseconds" << endl;
	}
}

int main()
{
	// giving the user an option of which file to pick
	string names[6] = {"1000.txt", "10000.txt", "100000.txt", "1000000.txt", "10000000.txt", "100000000.txt"};
    cout<<"Please enter the name of the file to search. \nYour options are: \n";
	for(string name : names) {
		cout << name << "\n";
	}
	
	// getting and verifying the user input
	string inputFile;
	getline(cin, inputFile);
	bool shouldRun = true;
	while (shouldRun) {
		bool result = inList(inputFile, names);
		if(result == false) {
			cout << "Not a valid file name. Try again:\n";
			getline(cin, inputFile);
		} else {
			shouldRun = false;
		}
	}
	
	// asking the user to enter the word they are searching
	cout << "Please enter the word you want to search for\n";
	string inputWord;
	getline(cin, inputWord);
	
	// giving the user an option of which data structure to user
	cout << "Please enter the name of the data structure to use. \nYour options are:\n"
		 << "Array\nHashTable\n";
		 
	// getting and verifying user input
	string dataStructureNames[2] = {"Array", "HashTable"};
	string inputDS;
	getline(cin, inputDS);
	bool shouldRun2 = true;
	while (shouldRun2) {
		bool result = inList(inputDS, dataStructureNames);
		if(result == false) {
			cout << "Not a valid data structure name. Try again:\n";
			getline(cin, inputDS);
		} else {
			shouldRun2 = false;
		}
	}
	
	// if the user selected array
	if (inputDS == dataStructureNames[0]) {
		findWordUsingArray(inputFile, inputWord);
	}
	
	// if the user selected hashtable
	if (inputDS == dataStructureNames[1]) {
		findWordUsingHashTable(inputFile, inputWord);
	}
	
    return 0;
}