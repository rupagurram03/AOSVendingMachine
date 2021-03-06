#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

#include<iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceServiceHandler();
  ~BeveragePreferenceServiceHandler() override=default;

  void GetBeverage(std::string& _return,const BeverageType::type b) override;
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

}

// Remote Procedure "PlaceOrder"

void BeveragePreferenceServiceHandler::GetBeverage(std::string& _return,BeverageType::type b) {
     // Your implementation goes here
     printf("GetBeverage\n");

     std::string hotBeverage[3] = {"cappuccino" ,"latte", "espresso"};
     std::string coldBeverage[3] = {"lemonade" , "ice tea", "soda"};
     
     srand(time(0));

     std::cout << "beverage type" <<b<< std::endl;
    // randomly select a beverage
    if (b == BeverageType::type::HOT)
	    _return = hotBeverage[rand() % 3];
    else
	    _return = coldBeverage[rand() % 3];
	  
    // _return = "from beverage service";

}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H

