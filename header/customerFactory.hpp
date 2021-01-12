//
//  customerFactory.hpp
//  CarRent
//
//  Created by Muhizi Aristide on 08/01/2021.
//

#ifndef customerFactory_hpp
#define customerFactory_hpp

#include <stdio.h>
#include "customer.hpp"

class customerFactory
{
private:
    customer *_cstm;
public:
    customer *getCustomer(int &);
};
#endif /* customerFactory_hpp */
