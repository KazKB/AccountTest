#ifndef LOANACCOUNT_H
#define LOANACCOUNT_H
#include <iostream>
#include <string>

#include "BankAccount.h"

using namespace std;

class LoanAccount : public BankAccount {
	private:
		static double interestRate;
		double overdraftLimit;
		double projectedInterest;
		
	public:
		LoanAccount (string name, int accNum) : BankAccount (name, accNum){
			overdraftLimit = 0.0;
		}
		
		//Defines setBalance From BankAccount header file
		void setBalance (double amt){
			accountBalance = amt;
		}//Sets the balance
		
		//Override Methods
		void withdraw (double amt) {
			if (amt <= overdraftLimit)
				accountBalance -= amt;
			else 
				cout << "Over the overdraft limit!" << endl;
		}//Withdrawals
		
		void display (){
			BankAccount :: display();
			cout << "Projected Interest: " << projectedInterest << endl;
		}//Display Associated With LoanAccount
		
		void calculateProjectedInterest (){
			projectedInterest = (accountBalance >= 0) ? 0 : accountBalance * interestRate;
		}//Calculates the interest
		
		//Getter and Setters		
		static double getInterestRate () {
			return interestRate;
		}//Retrieves interestRate
		
		void setOverdraftLimit (double limit){
			overdraftLimit = limit;
		}//Sets overdraft limit
		
		double getOverdraftLimit (){
			return overdraftLimit;
		}//Retrieves the overdraft limit
};

double LoanAccount :: interestRate = 3.5;//Sets interestRate
#endif//LoanAccount.h
