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
    float _price;
    std::string _timePaid;
public:
    payment(float price =  0.0): _price(price), _timePaid(__TIME__){}
    void calcPrice(std::vector<car> &);
    
    /* getters and setters **/
    float getPrice() const;
    void setPrice(float);
    
    std::string toString();
};
#endif /* payment_hpp */
