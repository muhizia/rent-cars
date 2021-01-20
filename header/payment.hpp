//
//  payment.hpp
//  CarRent
//
//  Created by Muhizi Aristide on 16/01/2021.
//

#ifndef payment_hpp
#define payment_hpp

#include <iostream>
#include <string>
#include <vector>
#include "car.hpp"

class payment
{
private:
    float _amount;
    std::string _timePaid;
public:
    payment(float amount =  0.0): _amount(amount), _timePaid(__TIME__){}
    void calcPrice(std::vector<car> &);
    void printBill(std::vector<car> &);
    /* getters and setters **/
    float getAmount() const;
    void setAmount(float);
    std::string getTimePaid();
    std::string toString();
};
#endif /* payment_hpp */
