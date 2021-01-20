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
    _amount = price;
}
void payment::printBill(std::vector<car> &cars)
{
    payment::calcPrice(cars);
    std::cout<<"The bill for the paid car\n";
    std::cout<< getTimePaid() << std::endl;
    std::cout<<std::endl << "Plate Number \t\t\tPrice" <<std::endl;
    for(auto car : cars)
    {
        std::cout<< car.getCarPlateNo() <<"\t\t\t" <<car.getPrice()<<std::endl;
    }
    std::cout<< "The total " << "\t\t\t" << getAmount() <<std::endl;
}
float payment::getAmount() const
{
    return _amount;
}
std::string payment::getTimePaid()
{
    return _timePaid;
}
void payment::setAmount(float price)
{
    _amount = price;
}
