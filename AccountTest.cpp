#include <iostream>
#include <string>
#include "LoanAccount.h"

using namespace std;

int main (){
	double amt, limit;
	string fName, lName, name;
	int accNum;
	
	cout << "Enter account name: ";
	cin >> fName >> lName;
	name = fName + " " + lName;
	//Gets user's fullname
	
	cout << "Enter account number: ";
	cin >> accNum;
	//Gets user's account number
	
	LoanAccount account (name, accNum);
	//Contructs user's account
	
	cout << "Set the account's balance: $";
	cin >> amt;
	account.setBalance(amt);
	//Sets user's initial balance of account
	
	cout << "Set the overdraft limit: $";
	cin >> limit;
	account.setOverdraftLimit(limit);
	//Sets the overdraft limit of the account
	
	cout << "Enter amount to withdraw: $";
	cin >> amt;
	account.withdraw(amt);
	//Withdraws money from the account
	
	account.calculateProjectedInterest();
	cout << endl;
	account.display();
	//Calculates the interest and display the account details.
	
	return 0;
}
