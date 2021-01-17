//
//  payment.cpp
//  CarRent
//
//  Created by Muhizi Aristide on 16/01/2021.
//

#include "header/payment.hpp"

void payment::calcPrice(std::vector<car> &cars)
{
    float price = 0;
    for(auto car : cars)
    {
        price += car.getPrice();
    }
    _price = price;
}

float payment::getPrice() const
{
    return _price;
}

void payment::setPrice(float price)
{
    _price = price;
}
