//
//  customerFactory.cpp
//  CarRent
//
//  Created by Muhizi Aristide on 08/01/2021.
//

#include "header/customerFactory.hpp"
#include "header/guest.hpp"
#include "header/member.hpp"

customer *customerFactory::getCustomer(int &objId)
{
    switch (objId) {
        case 1:
            return new member;
            break;
        case 2:
            return new guest;
        default:
            return NULL;
            break;
    }
}
