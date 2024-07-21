#ifndef HOTDOG_STAND_CLASS_H
#define HOTDOG_STAND_CLASS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

class HotDogStandsClass {

private:
  string   identificationStr,
           addressStr;
  float    hotdogPriceFl;
  unsigned inventoryAmountUns,
           soldAmountUns;

public:


  HotDogStandsClass(const string& identificationStr, const string& addressStr, float hotdogPriceFl, unsigned inventoryAmountUns, unsigned soldAmountUns) 
      
  {
      setIdStr(identificationStr);
      setAddressStr(addressStr);
      setPriceFl(hotdogPriceFl);
      setInventoryAmountUns(inventoryAmountUns);
      setSoldAmountUns(soldAmountUns);

  }

  static unsigned globalSoldCountUns;

  const string& getIdStr() const
  {
      return this->identificationStr;
  };



  void    setIdStr(const string& identificationStr)
  {
      this->identificationStr = identificationStr;
  };


  const string& getAddressStr() const
  {   
      return this->addressStr;
  
  };
  
  void          setAddressStr(const string& addressStr)
  {
      this->addressStr = addressStr;
  };

  float getPriceFl() const
  {
      return this->hotdogPriceFl;
  };
  
  void  setPriceFl(float hotdogPriceFl)
  {
      this->hotdogPriceFl = hotdogPriceFl;
  };

  unsigned        getSoldAmountUns() const
  { return this->soldAmountUns;
  };

  void            setSoldAmountUns(unsigned soldAmountUns)
  {
      this->soldAmountUns = soldAmountUns;
  };

  unsigned        getInventoryAmountUns() const
  {
      return this->inventoryAmountUns;
  };

  void            setInventoryAmountUns(unsigned inventoryAmountUns)
  {
      this->inventoryAmountUns = inventoryAmountUns;
  };

  void stockInventoryAmountUns(unsigned stockCountUns)
  {

      if (stockCountUns < 0) // If the restock value is a negative number.
      {
          cout << "Error! Stock value provided is a negative number." << endl;
      }
      else
      {
          this->inventoryAmountUns += stockCountUns;
      }

  };

  void           hotDogsBuyUns(unsigned count)
  {
      if (this->inventoryAmountUns <= 0)  //If there are no hotdogs left in the stand
      {
          cout << "There are no hot dogs left in this stand. Please try again later." << endl;
      }
      else if (count > this->inventoryAmountUns)  //If the buy order is larger than amount left in stand
      {
          cout << "*We only have " << this->inventoryAmountUns << " hotdogs left.*" << endl;
      }
      else 
      {
          globalSoldCountUns += count;
          ofstream infoGlobalSoldFile("infoGlobalSold.txt");
          infoGlobalSoldFile << to_string(globalSoldCountUns);
          this->soldAmountUns += count;
          this->inventoryAmountUns -= count;
          cout << "Transaction Successful. " << endl;

      }

  }

  void printMessage()  
  {

      cout << setw(20) << left << "Stand Id" << ": " << this->getIdStr() << endl;
      cout << setw(20) << left << "Address " << ": " << this->getAddressStr() << endl;
      cout << setw(20) << left << "Price" << ": " << this->getPriceFl() << endl;
      cout << setw(20) << left << "Inventory" << ": " << this->getInventoryAmountUns() << endl;
      cout << setw(20) << left << "Store Sold" << ": " << this->getSoldAmountUns() << " at $" << this->getPriceFl() << " ea." << endl;
      

      cout << endl;

  };

};//HotDogStandsClass

#endif
