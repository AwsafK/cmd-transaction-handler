#ifndef TRANSACTIONS_CLASS_CLASS_H
#define TRANSACTIONS_CLASS_CLASS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

class TransactionsClass {

private:
  string   standIdentifcationStr;
  string   transactionIdStr;
  unsigned transactionArgumentUns;

public:
  const string& getIdentifcationStr() const 
  { return this->standIdentifcationStr; };
  void          setIdentifcationStr(string standIdentifcationStr)
  { this->standIdentifcationStr = standIdentifcationStr; }

  const string& getTransactionIdStr() const 
  { return this->transactionIdStr;};
  void          setTransactionIdStr(string transactionIdStr)
  { this->transactionIdStr = transactionIdStr; }

  unsigned getTransactionArgumentUns() const 
  {return this->transactionArgumentUns; };
  void     setTransactionArgumentUns(unsigned transactionArgumentUns)
  { this->transactionArgumentUns = transactionArgumentUns; }

  void printMessage()
  { 
      cout << setw(20) << left << "Transaction Stand Id" << ": " << this->getIdentifcationStr() << endl;
      cout << setw(20) << left << "Transaction Id" << ": " << this->getTransactionIdStr() << endl;
      cout << setw(20) << left << "Transaction Argument" << ": " << this->getTransactionArgumentUns() << endl << endl;
  };

};

#endif


