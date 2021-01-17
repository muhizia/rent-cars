//
//  Customer.cpp
//  CarRent
//
//  Created by Muhizi Aristide on 08/01/2021.
//

#include <iostream>
#include "header/customer.hpp"

customer::~customer(){}
std::vector<car> *customer::getRentedCars()
{
    return &crs;
}
void customer::getRentedCars(std::vector<car> &cars, int customer_id){}
void customer::rentCar(car c){
    crs.push_back(c);
}
void customer::calcAmount(std::vector<car> &car)
{
    bill.calcPrice(car);
}
/* getters **/
std::string customer::getFirstName() const
{
    return firstName;
}
std::string customer::getLastName() const
{
    return lastName;
}
std::string customer::getDof() const
{
    return  dof;
}

/* setters **/
void customer::setFirstName(std::string f)
{
    firstName = f;
}
void customer::setLastName(std::string l)
{
    lastName = l;
}
void customer::setDof(std::string d)
{
    dof = d;
}
