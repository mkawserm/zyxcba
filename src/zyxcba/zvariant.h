#ifndef ZVARIANT_H
#define ZVARIANT_H

#include <map>
#include <cstring>
#include <iostream>

#include "ztype.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief The ZVariant class
///
/// The ZVariant class acts like a union for the most common c++ data types.
///////////////////////////////////////////////////////////////////////////////////////////////////
class ZVariant
{
public:
    explicit ZVariant();
    virtual ~ZVariant();
};


#endif // ZVARIANT_H
