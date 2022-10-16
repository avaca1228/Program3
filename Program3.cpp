// Program3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cctype>
#include <fstream>

using namespace std;

const string rule_msg_1 = "The selected password must be at least eight characters long.";
const string rule_msg_2 = "The selected password must have at least one uppercase letter.";
const string rule_msg_3 = "The selected password must have at least one lowercase letter.";
const string rule_msg_4 = "The selected password must have at least one digit.";
const string rule_msg_5 = "The selected password must have at least one of special characters: [@,!,#,^,&,*,$]"; // Use find_first_of()
const string rule_msg_6 = "The selected password has been leaked.";
const string rule_msg_7 = "The selected password cannot contain a dictionary word.";

char specialChar[7] = {'@','!','#','^','&','*','$'};
char digits[9] = {'1','2','3','4','5','6','7','8','9'};
int UpperCount = 0;
int LowerCount = 0;
int specCount = 0;
int digCount = 0;
bool PassReject = false;	
	
void passwordFiles(string passwordFile, vector <string> &searchPw) {
	string newLine;
	ifstream passwordStream;
	passwordStream.open(passwordFile, ios::in);

	while (passwordStream >> newLine) {
		searchPw.push_back(newLine);
	}
	passwordStream.close();
}

string lowerPass(string passWord) {

	string tempPassword = "";
	for (int i = 0; i < passWord.size(); i++) {
		tempPassword.push_back(tolower(passWord[i]));
	}
	return tempPassword;
}

string RemoveSpec(string passWord) {
	string ReplChar = "";
	for (int n = 0; n < passWord.size(); n++) {
		if (isalnum(passWord[n])) {
			ReplChar.push_back(passWord[n]);
		}
	}
	return ReplChar;
}

string CompareWords(string passWord) {
	passWord = lowerPass(passWord);
	passWord = RemoveSpec(passWord);
	string compareResult;
	for (int b = 0; b < passWord.size(); b++) {
		if (isalpha(passWord[b])) {
			compareResult.push_back(passWord[b]);
		}
	}
	return compareResult;
}

int binarySearch(vector<string> &vectorSearch, string searchPass) {
	int low = 0;
	int mid = 0;
	int high = vectorSearch.size() - 1;
	searchPass = lowerPass(searchPass);
	searchPass = RemoveSpec(searchPass);
	while (low <= high) {
		int mid = (high + low) / 2;
		if (RemoveSpec(vectorSearch.at(mid)) == searchPass) {
			return mid;
		}
		if (RemoveSpec(vectorSearch.at(mid)) < searchPass) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

int LeakCheck(vector<string>& vectorSearch, string searchPass) {
	int low = 0;
	int mid = 0;
	int high = vectorSearch.size() - 1;
	while (low <= high) {
		int mid = (high + low) / 2;
		if (vectorSearch.at(mid) == searchPass) {
			return mid;
		}
		if (vectorSearch.at(mid) < searchPass) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

	int run(string leaked_password_file, string english_word_file) {
		int PassReject = false;
		int ruleSix = 0;
		int ruleSeven = 0;

		vector<string> leakedPassword;
		vector<string> englishWords;

		string passWord;
		cout << "Enter password: ";
		getline(cin, passWord);

		if (passWord.size() < 8) {
			cout << rule_msg_1 << endl;
			PassReject = true;
		}
		for (int i = 0; i < passWord.size(); i++) {
			if (isupper(passWord[i]))
				UpperCount++; }
			if (UpperCount == 0) {
			cout << rule_msg_2 << endl;
			PassReject = true;
		}

		for (int i = 0; i < passWord.size(); i++) {
			if (islower(passWord[i])) LowerCount++; }
			if (LowerCount == 0) {
				cout << rule_msg_3;
				PassReject = true;
			}
		
		for (int i = 0; i < passWord.size(); i++) {
			for (int j = 0; j < 9; j++) {
				if (passWord[i] == digits[j]) {
					digCount++;
				}
			}
		}
		if (digCount == 0) {
			cout << rule_msg_4 << endl;
			PassReject = true;
		}
		for (int i = 0; i < passWord.size(); i++) {
			for (int j = 0; j < 7; j++) {
				if (passWord[i] == specialChar[j]) 	specCount++; 
			}
			if (specCount < 0) {
				cout << rule_msg_5 << endl;
				PassReject = true;
				break;
			}
		}

		if (PassReject == true) cout << "Password rejected!";

		if (PassReject == false) {
			passwordFiles(leaked_password_file, leakedPassword);
			if (LeakCheck(leakedPassword, passWord) < 0) {
			}
			else { ruleSix++; }

			if (ruleSix <= 0) {
				cout << rule_msg_6 << endl;
				cout << "Password rejected!";
			}
		}

		if (ruleSix == 1) {
			passWord = CompareWords(passWord);
			passwordFiles(english_word_file, englishWords);
			for (int x = 0; x < englishWords.size(); x++) {
				if (englishWords[x] == passWord) {
					ruleSeven++;
				}
			}
		}
		if (ruleSeven > 0) {
			cout << rule_msg_7 << endl;
			cout << "Password rejected!";
		}
		if (PassReject == false && ruleSix == 1 && ruleSeven == 0) {
			cout << "Password accepted!" << endl;
		}
		return 0;
	}

	int main() {
		/** Change the address of the files appropriatly based on your local machine.
		 * This main function will be replaced during testing. Do not add any line of code to the main function
		 **/
		string leaked_password_file = "alleged-gmail-passwords.txt"; //change this based on the location of the file on your machine
		string english_word_file = "words_5.txt"; //change this based on the location of the file on your machine
		run(leaked_password_file, english_word_file);
		return 0;
	}