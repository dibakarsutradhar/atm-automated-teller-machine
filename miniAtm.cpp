// Dibakar Sutra Dhar
// Please update idpassword.txt for your own User ID and Password
// Please update bankdetails.txt for your own balance.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <cctype>
#include <ctime>

using namespace std;

int main() {
	string userid, password, a, b;
	int pass1, pass2, pass3;
	ifstream fin;
	ofstream fout;

	cout << "Enter your user id : ";
	cin >> userid;

	cout << "Enter password : ";
	cin >> password;

	fin.open("idpassword.txt");			// validating user input from txt file
	fin >> a >> b;
	fin.close();

	time_t now = time(0);				// collecting local time from machine
	char * dt = ctime(&now);

	if (userid != a || password != b) {
		cout << "Transaction rejected" << endl;
	}
	else {
		cout << "\n\t\t**Welcome!**\n" << endl;

		double balance, withdraw, deposit;
		int option;
		bool finished = false;			// if users selects exit, finished = true, otherwise finished = false

		cout << "\n\t\t**DIBAKAR BANK**\n";
		cout << "\t**Automated Teller Machine**\n";

		while (!finished) {				// looping until user selects quit
			cout << "Choose your option: \n";		// menu option
			cout << "\n";
			cout << "[1] Inquire Balance\n";
			cout << "[2] Withdraw\n";
			cout << "[3] Deposit\n";
			cout << "[4] Account Statement\n";
			cout << "[5] Password Update\n";
			cout << "[6] Exit\n";
			cout << "\n";
			cout << "Enter Option: ";
			cin >> option;

			switch (option)				// switch case for option
			{
			case 1:
				cout << "\n[[[BALANCE INQUIRY]]]\n";
				cout.setf(ios::fixed);
				cout.setf(ios::showpoint);
				cout.precision(2);
				fin.open("bankdetails.txt");		// collecting data from bankdetails.txt file
				fin >> balance;
				cout << "\nYour current balance is RM " << balance << endl;
				fin.close();						// closing txt file
				break;

			case 2:
				cout << "\n[[[WITHDRAW]]]\n";
				fout.open("bankdetails.txt", ios::out);
				cout << "Enter Amount: RM ";
				cin >> withdraw;
				fout << withdraw;
				fout.close();

				balance = balance - withdraw;
				fout.open("bankdetails.txt");		// writing data in .txt file
				fout << balance;
				fout.close();

				cout.setf(ios::fixed);
				cout.setf(ios::showpoint);
				cout.precision(2);

				cout << "Your withdrew RM " << withdraw << endl;
				cout << "Your remaining balance is RM " << balance << endl;
				continue;

			case 3:
				cout << "\n[[[DEPOSIT]]]\n";
				fout.open("bankdetails.txt", ios::out);
				cout << "Enter Amount: RM ";
				cin >> deposit;
				fout << deposit;
				fout.close();

				balance = balance + deposit;
				fout.open("bankdetails.txt");
				fout << balance;
				fout.close();

				cout.setf(ios::fixed);
				cout.setf(ios::showpoint);
				cout.precision(2);

				cout << "You deposited RM " << deposit << endl;
				cout << "Your new balance is RM " << balance << endl;
				continue;

			case 4:
				cout << "\n[[[BANK STATEMENT]]]\n";
				cout << "AFRA BANK\n";
				cout << "\nAccount Name: " << userid << endl;
				cout << "Account Number: 123-456-789\n" << endl;

				cout.setf(ios::fixed);
				cout.setf(ios::showpoint);
				cout.precision(2);

				cout << dt << "Your current balance is: " << balance << "\n" << endl;
				cout << dt << "Your last withdrawal balance is: " << withdraw << "\n" << endl;
				cout << dt << "Your last deposit balance is: " << deposit << endl;

				continue;

			case 5:
				cout << "\n[[[PASSWORD UPDATE]]]\n";
				{
					cout << "Enter your old password: ";
					cin >> pass1;
					if (pass1 == 123456) {
						cout << "Enter your 6 digit new passowrd: ";
						cin >> pass2;
						cout << "Confirm new password: ";
						cin >> pass3;
						if (pass2 == pass3) {
							cout << "\nPassword has been changed successfully\n" << endl;
						}
						else {
							cout << "\nPassword did not match\n" << endl;
							main();
						}
					}
					else {
						cout << "\nIncorrect password\n" << endl;
						main();
					}
				}
				break;

			case 6:
				cout << "\nThanks " << userid << " for bankning with us!\n" << endl;
				getch();
				return 0;

			default:
				cout << "\nThis is an invalid option\n" << endl;
				break;
			}
		}
	}
	system("pause");
	return 0;
}