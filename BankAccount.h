//Defining Header File
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>

using namespace std;

class BankAccount {
	protected: 
		string accountName;
		int accountNumber;
		double accountBalance;
		virtual void setBalance (double amt) = 0;
		
	public:
		BankAccount (string name, int myAcc);
		void deposit (double myDep);
		void withdraw (double amt);
		virtual void display ();
		~BankAccount ();
		
};//BankAccount

//Defining Methods
BankAccount :: BankAccount (string name, int myAcc){
	accountName = name;
	accountNumber = myAcc;
	accountBalance = 0.0;
}//Constructor

void BankAccount :: deposit (double myDep){
	accountBalance += myDep;
}//Deposits

void BankAccount :: withdraw (double amt){
	if (amt <= accountBalance)
		accountBalance -= amt;
}//Withdrawals

void BankAccount :: display (){
	cout << accountName << ": Balance = $" << accountBalance << endl;
}//Display Account Info

BankAccount :: ~BankAccount (){
	cout << "I am outta here!!!" << endl;
}//Destructor
#endif //BankAccount.h
