//
//  Guest.cpp
//  CarRent
//
//  Created by Muhizi Aristide on 08/01/2021.
//

#include "header/guest.hpp"
#include <iostream>

std::string guest::toString()
{
    return customer::getFirstName() + " " + customer::getLastName();
}
guest::~guest(){}
