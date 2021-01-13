//
//  Guest.hpp
//  CarRent
//
//  Created by Muhizi Aristide on 08/01/2021.
//

#ifndef Guest_hpp
#define Guest_hpp


#include <string>
#include "customer.hpp"

class guest: public customer
{
public:
    guest() : customer(){};
    ~guest();
//    void viewCar();
//    void searchCar();
//    void rentCar();
    std::string toString();
};
#endif /* Guest_hpp */
