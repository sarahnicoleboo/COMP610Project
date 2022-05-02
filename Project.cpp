#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// helper function to verift user input
bool inList(string input, string names[]) {
	bool b = false;
	for(int i = 0; i < names->size(); i++){
		if(input == names[i]){
			b = true;
		}
	}
	return b;
}

// function to populate array with words from file and search for the specified word
bool findWordUsingArray(string fileName, string inputWord) {
	// first read the values into a vectore
	vector<string> vectorOfWords;
	ifstream in(fileName);
	string str;
	while(getline(in, str)) {
		if (str.size() > 0) {
			vectorOfWords.push_back(str);
		}
	}
	in.close();
	
	// then search for the specified word
	if (find(vectorOfWords.begin(), vectorOfWords.end(), inputWord) != vectorOfWords.end()) {
		return true;
	} else {
		return false;
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
		 << "Array\nOtherOne\n";
		 
	// getting and verifying user input
	string dataStructureNames[2] = {"Array", "OtherOne"};
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
	
	if (inputDS == dataStructureNames[0]) {
		bool searchArrayResult;
		searchArrayResult = findWordUsingArray(inputFile, inputWord);
		if (searchArrayResult == true) {
			cout << "Word found";
		} else {
			cout << "Word not found";
		}
	}
    return 0;
}