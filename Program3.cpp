// Program3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const string rule_msg_1 = "The selected password must be at least eight characters long.";
const string rule_msg_2 = "The selected password must have at least one uppercase letter.";
const string rule_msg_3 = "The selected password must have at least one lowercase letter.";
const string rule_msg_4 = "The selected password must have at least one digit.";
const string rule_msg_5 = "The selected password must have at least one of special characters: [@,!,#,^,&,*,$]";
const string rule_msg_6 = "The selected password has been leaked.";
const string rule_msg_7 = "The selected password cannot contain a dictionary word.";

char specialChar[7] = {'@','!','#','^','&','*','$'};
string passWord;	

void CheckRules(string passWord) {
	if (passWord.length() < 8) cout << rule_msg_1;
	if (passWord != passWord.isupper(i)) cout << rule_msg_2;
	if (passWord != passWord.islower(i)) return rule_msg_3;
	if (passWord != passWord
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
	CheckRules();

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
