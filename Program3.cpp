// Program3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

const string rule_msg_1 = "The selected password must be at least eight characters long.";
const string rule_msg_2 = "The selected password must have at least one uppercase letter.";
const string rule_msg_3 = "The selected password must have at least one lowercase letter.";
const string rule_msg_4 = "The selected password must have at least one digit.";
const string rule_msg_5 = "The selected password must have at least one of special characters: [@,!,#,^,&,*,$]"; // Use find_first_of()
const string rule_msg_6 = "The selected password has been leaked.";
const string rule_msg_7 = "The selected password cannot contain a dictionary word.";

string passWord;
char specialChar[7] = {'@','!','#','^','&','*','$'};
char digits[9] = {'1','2','3','4','5','6','7','8','9'};
int UpperCount = 0;
int LowerCount = 0;
int specCount = 0;
int digCount = 0;

void binarySearch() {

}
void CheckRulesThru5(string passWord) {	
	if (passWord.length() < 8) {
		cout << rule_msg_1 << endl;
		cout << "Password rejected!";
	for (int i = 0; i < passWord.size(); i++) {
		if (isupper(passWord[i]))
			UpperCount++;
		if (UpperCount == 0) cout << rule_msg_2 << endl;
		cout << "Password rejected!";
	}
	for (int j = 0; j < passWord.size(); j++) {
		if (islower(passWord[j]))
			LowerCount++;
		if (LowerCount == 0) {
			cout << rule_msg_3;
			cout << "Password rejected!";
		}
	}
	for (int l = 0; l < passWord.size(); l++) {
		for (int m = 0; m < 9; m++) {
			if (passWord[l] == digits[m]) {
				digCount++;
			}
			if (digCount < 0) {
				cout << rule_msg_4 << endl;
				cout << "Password rejected!";
			}
		}
	}
	for (int h = 0; h <passWord.size(); h++) {
		for (int k = 0; k < 7; k++) {
			if (passWord[h] == specialChar[k])
				specCount++;
		}
		if (specCount < 1) {
			cout << rule_msg_5 << endl;
			cout << "Password rejected!";
		}
	}
}

void CheckRules5and6(string passWord) {

	}

int main() 
{
	/****************************
	 *
	 * HEADER
	 *
	 * *** **********************/

	cout << "Enter password: ";
	cin >> passWord;
	CheckRulesThru5(passWord);
	CheckRules5and6(passWord);

	/****
	 * Runs the main part of the program
	 ****/
	int run(string leaked_password_file, string english_word_file);

	int main() {
		/** Change the address of the files appropriatly based on your local machine. 
		 * This main function will be replaced during testing. Do not add any line of code to the main function
		 **/
		string leaked_password_file = "alleged-gmail-passwords.txt"; //change this based on the location of the file on your machine
		string english_word_file = "words_5.txt"; //change this based on the location of the file on your machine
		run(leaked_password_file, english_word_file);
		return 0;
	}
}
