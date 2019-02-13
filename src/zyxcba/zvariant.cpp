#include "zvariant.h"

namespace zyxcba {

ZVariant::ZVariant():
    m_variantType(ZVariantType::None)
{

}

ZVariant::ZVariant(const bool &param):
    m_variantType(ZVariantType::Bool),
    m_bool(param)
{

}

ZVariant::ZVariant(const std::int8_t &param):
    m_variantType(ZVariantType::Int8),
    m_int8(param)
{

}

ZVariant::ZVariant(const std::int16_t &param):
    m_variantType(ZVariantType::Int16),
    m_int16(param)
{

}

ZVariant::ZVariant(const std::int32_t &param):
    m_variantType(ZVariantType::Int32),
    m_int32(param)
{

}

ZVariant::ZVariant(const std::int64_t &param):
    m_variantType(ZVariantType::Int64),
    m_int64(param)
{

}

ZVariant::ZVariant(const std::uint8_t &param):
    m_variantType(ZVariantType::UInt8),
    m_uint8(param)
{

}

ZVariant::ZVariant(const std::uint16_t &param):
    m_variantType(ZVariantType::UInt16),
    m_uint16(param)
{

}

ZVariant::ZVariant(const std::uint32_t &param):
    m_variantType(ZVariantType::UInt32),
    m_uint32(param)
{

}

ZVariant::ZVariant(const std::uint64_t &param):
    m_variantType(ZVariantType::UInt64),
    m_uint64(param)
{

}

ZVariant::ZVariant(const zfloat32 &param):
    m_variantType(ZVariantType::Float32),
    m_float32(param)
{

}

ZVariant::ZVariant(const zfloat64 &param):
    m_variantType(ZVariantType::Float64),
    m_float64(param)
{

}

ZVariant::ZVariant(const std::string &param):
    m_variantType(ZVariantType::String),
    m_string(param)
{

}

ZVariant::ZVariant(const std::string &&param):
    m_variantType(ZVariantType::String),
    m_string(std::move(param))
{
    std::cout<<"Moving string..."<<std::endl;
}

ZVariant::ZVariant(const ZVariantList &param):
    m_variantType(ZVariantType::List)
{
    std::copy(param.begin(), param.end(), back_inserter(this->m_list));
}

ZVariant::ZVariant(const ZVariantMap &param):
    m_variantType(ZVariantType::Map)
{
    this->m_map.insert(param.begin(),param.end());
}

ZVariant::ZVariant(const ZIntegerVariantMap &param):
    m_variantType(ZVariantType::IntegerVariantMap)
{
    this->m_integerVariantMap.insert(param.begin(),param.end());
}

ZVariant::ZVariant(const ZVariant &other):
    m_variantType(other.m_variantType)
{
#ifdef ZYXCBA_DEBUG
    std::cout<<"Constructor Copying... "<<this->variantTypeString()<<std::endl;
#endif

    switch (m_variantType) {
    case ZVariantType::Bool:
        this->m_bool = other.m_bool;
        break;
    case ZVariantType::Int8:
        this->m_int8 = other.m_int8;
        break;

    case ZVariantType::Int16:
        this->m_int16 = other.m_int16;
        break;

    case ZVariantType::Int32:
        this->m_int32 = other.m_int32;
        break;

    case ZVariantType::Int64:
        this->m_int64 = other.m_int64;
        break;

    case ZVariantType::UInt8:
        this->m_uint8 = other.m_uint8;
        break;

    case ZVariantType::UInt16:
        this->m_uint16 = other.m_uint16;
        break;

    case ZVariantType::UInt32:
        this->m_uint32 = other.m_uint32;
        break;

    case ZVariantType::UInt64:
        this->m_uint64 = other.m_uint64;
        break;

    case ZVariantType::Float32:
        this->m_float32 = other.m_float32;
        break;

    case ZVariantType::Float64:
        this->m_float64 = other.m_float64;
        break;

    case ZVariantType::String:
        this->m_string = other.m_string;
        break;

    case ZVariantType::List:
        this->m_list.clear();
        std::copy(other.m_list.begin(), other.m_list.end(), back_inserter(this->m_list));
        break;
    case ZVariantType::Map:
        this->m_map.clear();
        this->m_map.insert(other.m_map.begin(),other.m_map.end());
        break;
    case ZVariantType::IntegerVariantMap:
        this->m_integerVariantMap.clear();
        this->m_integerVariantMap.insert(other.m_integerVariantMap.begin(),other.m_integerVariantMap.end());
        break;
    default:
        m_variantType = ZVariantType::None;
        break;
    }

}

ZVariant::ZVariant(const ZVariant &&other):
    m_variantType(other.m_variantType)
{
#ifdef ZYXCBA_DEBUG
    std::cout<<"Constructor Moving const ZVariant..."<<std::endl;
#endif

    if(this != &other)
    {
        switch (m_variantType) {
        case ZVariantType::Bool:
            this->m_bool = std::move(other.m_bool);
            break;
        case ZVariantType::Int8:
            this->m_int8 = std::move(other.m_int8);
            break;

        case ZVariantType::Int16:
            this->m_int16 = std::move(other.m_int16);
            break;

        case ZVariantType::Int32:
            this->m_int32 = std::move(other.m_int32);
            break;

        case ZVariantType::Int64:
            this->m_int64 = std::move(other.m_int64);
            break;

        case ZVariantType::UInt8:
            this->m_uint8 = std::move(other.m_uint8);
            break;

        case ZVariantType::UInt16:
            this->m_uint16 = std::move(other.m_uint16);
            break;

        case ZVariantType::UInt32:
            this->m_uint32 = std::move(other.m_uint32);
            break;

        case ZVariantType::UInt64:
            this->m_uint64 = std::move(other.m_uint64);
            break;

        case ZVariantType::Float32:
            this->m_float32 = std::move(other.m_float32);
            break;

        case ZVariantType::Float64:
            this->m_float64 = std::move(other.m_float64);
            break;

        case ZVariantType::String:
            this->m_string = std::move(other.m_string);
            break;

        case ZVariantType::List:
            //this->m_list.clear();
            //this->m_list.reserve(other.m_list.size());
            this->m_list = std::move(other.m_list);
            //std::copy(other.m_list.begin(), other.m_list.end(), back_inserter(this->m_list));
            break;
        case ZVariantType::Map:
            //this->m_map.clear();
            this->m_map = std::move(other.m_map);
            //this->m_map.insert(other.m_map.begin(),other.m_map.end());
            break;
        case ZVariantType::IntegerVariantMap:
            //this->m_integerVariantMap.clear();
            this->m_integerVariantMap = std::move(other.m_integerVariantMap);
            //this->m_integerVariantMap.insert(other.m_integerVariantMap.begin(),other.m_integerVariantMap.end());
            break;
        default:
            m_variantType = ZVariantType::None;
            break;
        }
    }

    //other.makeInvalid();
}

ZVariant::ZVariant(ZVariant &&rhs)
{
#ifdef ZYXCBA_DEBUG
    std::cout<<"Constructor Moving ZVariant ..."<<std::endl;
#endif

    if(this != &rhs)
    {
        this->makeInvalid();
        this->m_variantType = rhs.m_variantType;

        switch (rhs.m_variantType) {
        case ZVariantType::Bool:
            this->m_bool = std::move(rhs.m_bool);
            break;
        case ZVariantType::Int8:
            this->m_int8 = std::move(rhs.m_int8);
            break;

        case ZVariantType::Int16:
            this->m_int16 = std::move(rhs.m_int16);
            break;

        case ZVariantType::Int32:
            this->m_int32 = std::move(rhs.m_int32);
            break;

        case ZVariantType::Int64:
            this->m_int64 = std::move(rhs.m_int64);
            break;

        case ZVariantType::UInt8:
            this->m_uint8 = std::move(rhs.m_uint8);
            break;

        case ZVariantType::UInt16:
            this->m_uint16 = std::move(rhs.m_uint16);
            break;

        case ZVariantType::UInt32:
            this->m_uint32 = std::move(rhs.m_uint32);
            break;

        case ZVariantType::UInt64:
            this->m_uint64 = std::move(rhs.m_uint64);
            break;

        case ZVariantType::Float32:
            this->m_float32 = std::move(rhs.m_float32);
            break;

        case ZVariantType::Float64:
            this->m_float64 = std::move(rhs.m_float64);
            break;

        case ZVariantType::String:
            this->m_string = std::move(rhs.m_string);
            break;

        case ZVariantType::List:
            //this->m_list.clear();
            //this->m_list.reserve(other.m_list.size());
            this->m_list = std::move(rhs.m_list);
            break;
        case ZVariantType::Map:
            //this->m_map.clear();
            this->m_map = std::move(rhs.m_map);
            break;
        case ZVariantType::IntegerVariantMap:
            //this->m_integerVariantMap.clear();
            this->m_integerVariantMap = std::move(rhs.m_integerVariantMap);
            break;
        default:
            m_variantType = ZVariantType::None;
            break;
        }

        rhs.makeInvalid();
    }
}


ZVariant::~ZVariant()
{

#ifdef ZYXCBA_DEBUG
    std::cout<<"ZVariant::~ZVariant()"<<std::endl;
#endif

    if(this->m_variantType == ZVariantType::Map)
    {
        this->m_map.clear();
    }
    else if(this->m_variantType == ZVariantType::List){
        this->m_list.clear();
    }
    else if(this->m_variantType == ZVariantType::IntegerVariantMap)
    {
        this->m_integerVariantMap.clear();
    }
    else if(this->m_variantType == ZVariantType::String)
    {
        this->m_string.clear();
    }
}

ZVariantType ZVariant::variantType() const
{
    return this->m_variantType;
}

std::string ZVariant::variantTypeString() const
{
    switch (m_variantType) {
    case ZVariantType::Bool:
        return std::string("Bool");

    case ZVariantType::Int8:
        return std::string("Int8");
    case ZVariantType::Int16:
        return std::string("Int16");
    case ZVariantType::Int32:
        return std::string("Int32");
    case ZVariantType::Int64:
        return std::string("Int64");


    case ZVariantType::UInt8:
        return std::string("UInt8");

    case ZVariantType::UInt16:
        return std::string("UInt16");

    case ZVariantType::UInt32:
        return std::string("UInt32");

    case ZVariantType::UInt64:
        return std::string("UInt64");

    case ZVariantType::Float32:
        return std::string("Float32");

    case ZVariantType::Float64:
        return std::string("Float64");

    case ZVariantType::String:
        return std::string("String");

    case ZVariantType::List:
        return std::string("List");
    case ZVariantType::Map:
        return std::string("Map");
    case ZVariantType::IntegerVariantMap:
        return std::string("IntegerVariantMap");

    default:
        return std::string("None");
    }
}

bool ZVariant::isValid() const
{
    return !this->isNone();
}

bool ZVariant::isNone() const
{
    return this->m_variantType == ZVariantType::None;
}

bool ZVariant::isBool() const
{
    return this->m_variantType == ZVariantType::Bool;
}

bool ZVariant::isInt8() const
{
    return this->m_variantType == ZVariantType::Int8;
}

bool ZVariant::isInt16() const
{
    return this->m_variantType == ZVariantType::Int16;
}

bool ZVariant::isInt32() const
{
    return this->m_variantType == ZVariantType::Int32;
}

bool ZVariant::isInt64() const
{
    return this->m_variantType == ZVariantType::Int64;
}

bool ZVariant::isUInt8() const
{
    return this->m_variantType == ZVariantType::UInt8;
}

bool ZVariant::isUInt16() const
{
    return this->m_variantType == ZVariantType::UInt16;
}

bool ZVariant::isUInt32() const
{
    return this->m_variantType == ZVariantType::UInt32;
}

bool ZVariant::isUInt64() const
{
    return this->m_variantType == ZVariantType::UInt64;
}

bool ZVariant::isFloat32() const
{
    return this->m_variantType == ZVariantType::Float32;
}

bool ZVariant::isFloat64() const
{
    return this->m_variantType == ZVariantType::Float64;
}

bool ZVariant::isNumber() const
{
    return this->isInt8()
            ||this->isInt16()
            ||this->isInt32()
            ||this->isInt64()
            ||this->isUInt8()
            ||this->isUInt16()
            ||this->isUInt32()
            ||this->isUInt64()
            ||this->isFloat32()
            ||this->isFloat64();
}

bool ZVariant::isString() const
{
    return this->m_variantType == ZVariantType::String;
}

bool ZVariant::isList() const
{
    return this->m_variantType == ZVariantType::List;
}

bool ZVariant::isIntegerVariantMap() const
{
    return this->m_variantType == ZVariantType::IntegerVariantMap;
}

bool ZVariant::isMap() const
{
    return this->m_variantType == ZVariantType::Map;
}

std::uint64_t ZVariant::mapLength() const
{
    if(this->isMap()) return this->m_map.size();
    return 0;
}

std::uint64_t ZVariant::listLength() const
{
    if(this->isList()) return this->m_list.size();
    return 0;
}

std::uint64_t ZVariant::stringLength() const
{
    if(this->isString()) return this->m_string.size();
    return 0;
}

std::uint64_t ZVariant::integerVariantMapLength() const
{
    if(this->isIntegerVariantMap()) return this->m_integerVariantMap.size();
    return 0;
}

bool ZVariant::getBool() const
{
    if(!this->isBool()) return false;
    return this->m_bool;
}

std::int8_t ZVariant::getInt8() const
{
    if(!this->isInt8()) return 0;
    return this->m_int8;
}

std::int16_t ZVariant::getInt16() const
{
    if(!this->isInt16()) return 0;
    return this->m_int16;
}

std::int32_t ZVariant::getInt32() const
{
    if(!this->isInt32()) return 0;
    return this->m_int32;
}

std::int64_t ZVariant::getInt64() const
{
    if(!this->isInt64()) return 0;
    return this->m_int64;
}

std::uint8_t ZVariant::getUInt8() const
{
    if(!this->isUInt8()) return 0;
    return this->m_uint8;
}

std::uint16_t ZVariant::getUInt16() const
{
    if(!this->isUInt16()) return 0;
    return this->m_uint16;
}

std::uint32_t ZVariant::getUInt32() const
{
    if(!this->isUInt32()) return 0;
    return this->m_uint32;
}

std::uint64_t ZVariant::getUInt64() const
{
    if(!this->isUInt64()) return 0;
    return this->m_uint64;
}

zfloat32 ZVariant::getFloat32() const
{
    if(!this->isFloat32()) return 0;
    return this->m_float32;
}

zfloat64 ZVariant::getFloat64() const
{
    if(!this->isFloat64()) return 0;
    return this->m_float64;
}

std::uint64_t ZVariant::getNumber() const
{
    switch (m_variantType) {
    case ZVariantType::Int8:
        return static_cast<std::uint64_t>(this->m_int8);
    case ZVariantType::Int16:
        return static_cast<std::uint64_t>(this->m_int16);
    case ZVariantType::Int32:
        return static_cast<std::uint64_t>(this->m_int32);
    case ZVariantType::Int64:
        return static_cast<std::uint64_t>(this->m_int64);

    case ZVariantType::UInt8:
        return static_cast<std::uint64_t>(this->m_uint8);
    case ZVariantType::UInt16:
        return static_cast<std::uint64_t>(this->m_uint16);
    case ZVariantType::UInt32:
        return static_cast<std::uint64_t>(this->m_uint32);
    case ZVariantType::UInt64:
        return static_cast<std::uint64_t>(this->m_uint64);

    case ZVariantType::Float32:
        return static_cast<std::uint64_t>(this->m_float32);
    case ZVariantType::Float64:
        return static_cast<std::uint64_t>(this->m_float64);
    default:
        return 0;
    }
}

std::uint64_t ZVariant::getLength() const
{
    switch (m_variantType)
    {
    case ZVariantType::String:
        return this->m_string.length();
    case ZVariantType::List:
        return this->m_list.size();
    case ZVariantType::Map:
        return this->m_map.size();
    case ZVariantType::IntegerVariantMap:
        return this->m_integerVariantMap.size();
    default:
        return 0;
    }
}

const std::string &ZVariant::getString() const
{
    return this->m_string;
}

const ZVariantList &ZVariant::getList() const
{
    return this->m_list;
}

const ZVariantMap &ZVariant::getMap() const
{
    return this->m_map;
}

const ZIntegerVariantMap &ZVariant::getIntegerVariantMap() const
{
    return this->m_integerVariantMap;
}

void ZVariant::makeInvalid()
{
    if(this->m_variantType == ZVariantType::String)
    {
        this->m_string.clear();
    }
    else if(this->m_variantType == ZVariantType::List)
    {
        this->m_list.clear();
    }
    else if(this->m_variantType == ZVariantType::Map)
    {
        this->m_map.clear();
    }
    else if(this->m_variantType == ZVariantType::IntegerVariantMap)
    {
        this->m_integerVariantMap.clear();
    }

    this->m_variantType = ZVariantType::None;
}

void ZVariant::setBool(const bool &param)
{
    this->m_variantType = ZVariantType::Bool;
    this->m_bool = param;
}

void ZVariant::setInt8(const std::int8_t &param)
{
    this->m_variantType = ZVariantType::Int8;
    this->m_int8 = param;
}

void ZVariant::setInt16(const std::int16_t &param)
{
    this->m_variantType = ZVariantType::Int16;
    this->m_int16 = param;
}

void ZVariant::setInt32(const std::int32_t &param)
{
    this->m_variantType = ZVariantType::Int32;
    this->m_int32 = param;
}

void ZVariant::setInt64(const std::int64_t &param)
{
    this->m_variantType = ZVariantType::Int64;
    this->m_int64 = param;
}

void ZVariant::setUInt8(const std::uint8_t &param)
{
    this->m_variantType = ZVariantType::UInt8;
    this->m_uint8 = param;
}

void ZVariant::setUInt16(const std::uint16_t &param)
{
    this->m_variantType = ZVariantType::UInt16;
    this->m_uint16 = param;
}

void ZVariant::setUInt32(const std::uint32_t &param)
{
    this->m_variantType = ZVariantType::UInt32;
    this->m_uint32 = param;
}

void ZVariant::setUInt64(const std::uint64_t &param)
{
    this->m_variantType = ZVariantType::UInt64;
    this->m_uint64 = param;
}

void ZVariant::setFloat32(const zfloat32 &param)
{
    this->m_variantType = ZVariantType::Float32;
    this->m_float32 = param;
}

void ZVariant::setFloat64(const zfloat64 &param)
{
    this->m_variantType = ZVariantType::Float64;
    this->m_float64 = param;
}

void ZVariant::setString(const std::string &param)
{
    this->m_variantType = ZVariantType::String;
    this->m_string = param;
}

void ZVariant::setList(const ZVariantList &param)
{
    this->m_variantType = ZVariantType::List;
    this->m_list.clear();
    std::copy(param.begin(), param.end(), back_inserter(this->m_list));
}

void ZVariant::setMap(const ZVariantMap &param)
{
    this->m_variantType = ZVariantType::Map;
    this->m_map.clear();
    this->m_map.insert(param.begin(),param.end());
}

void ZVariant::setIntegerVariantMap(const ZIntegerVariantMap &param)
{
    this->m_variantType = ZVariantType::IntegerVariantMap;
    this->m_integerVariantMap.clear();
    this->m_integerVariantMap.insert(param.begin(),param.end());
}

void ZVariant::setValue(const bool &param)
{
    this->setBool(param);
}

void ZVariant::setValue(const std::int8_t &param)
{
    this->setInt8(param);
}

void ZVariant::setValue(const std::int16_t &param)
{
    this->setInt16(param);
}

void ZVariant::setValue(const std::int32_t &param)
{
    this->setInt32(param);
}

void ZVariant::setValue(const std::int64_t &param)
{
    this->setInt64(param);
}

void ZVariant::setValue(const std::uint8_t &param)
{
    this->setUInt8(param);
}

void ZVariant::setValue(const std::uint16_t &param)
{
    this->setUInt16(param);
}

void ZVariant::setValue(const std::uint32_t &param)
{
    this->setUInt32(param);
}

void ZVariant::setValue(const std::uint64_t &param)
{
    this->setUInt64(param);
}

void ZVariant::setValue(const zfloat32 &param)
{
    this->setFloat32(param);
}

void ZVariant::setValue(const zfloat64 &param)
{
    this->setFloat64(param);
}

void ZVariant::setValue(const std::string &param)
{
    this->setString(param);
}

void ZVariant::setValue(const ZVariantList &param)
{
    this->setList(param);
}

void ZVariant::setValue(const ZVariantMap &param)
{
    this->setMap(param);
}

void ZVariant::setValue(const ZIntegerVariantMap &param)
{
    return this->setIntegerVariantMap(param);
}

void ZVariant::reserveList(const std::uint64_t &length)
{
    this->m_list.reserve(length);
}

bool ZVariant::addToList(const ZVariant &value)
{
    if(this->m_variantType == ZVariantType::None)
    {
        this->m_variantType = ZVariantType::List;
    }

    if(this->m_variantType == ZVariantType::List)
    {
        this->m_list.push_back(value);
        return true;
    }
    else
    {
        return false;
    }
}

bool ZVariant::addToList(const bool &value)
{
    if(this->m_variantType == ZVariantType::None)
    {
        this->m_variantType = ZVariantType::List;
    }

    if(this->m_variantType == ZVariantType::List)
    {
        this->m_list.emplace_back(value);
        return true;
    }
    else
    {
        return false;
    }
}

bool ZVariant::addToList(const std::int8_t &value)
{
    if(this->m_variantType == ZVariantType::None)
    {
        this->m_variantType = ZVariantType::List;
    }

    if(this->m_variantType == ZVariantType::List)
    {
        this->m_list.emplace_back(value);
        return true;
    }
    else
    {
        return false;
    }
}

bool ZVariant::addToList(const std::int16_t &value)
{
    if(this->m_variantType == ZVariantType::None)
    {
        this->m_variantType = ZVariantType::List;
    }

    if(this->m_variantType == ZVariantType::List)
    {
        this->m_list.emplace_back(value);
        return true;
    }
    else
    {
        return false;
    }
}

bool ZVariant::addToList(const std::int32_t &value)
{
    if(this->m_variantType == ZVariantType::None)
    {
        this->m_variantType = ZVariantType::List;
    }

    if(this->m_variantType == ZVariantType::List)
    {
        this->m_list.emplace_back(value);
        return true;
    }
    else
    {
        return false;
    }
}

bool ZVariant::addToList(const std::int64_t &value)
{
    if(this->m_variantType == ZVariantType::None)
    {
        this->m_variantType = ZVariantType::List;
    }

    if(this->m_variantType == ZVariantType::List)
    {
        this->m_list.emplace_back(value);
        return true;
    }
    else
    {
        return false;
    }
}

bool ZVariant::addToList(const std::uint8_t &value)
{
    if(this->m_variantType == ZVariantType::None)
    {
        this->m_variantType = ZVariantType::List;
    }

    if(this->m_variantType == ZVariantType::List)
    {
        this->m_list.emplace_back(value);
        return true;
    }
    else
    {
        return false;
    }
}

bool ZVariant::addToList(const std::uint16_t &value)
{
    if(this->m_variantType == ZVariantType::None)
    {
        this->m_variantType = ZVariantType::List;
    }

    if(this->m_variantType == ZVariantType::List)
    {
        this->m_list.emplace_back(value);
        return true;
    }
    else
    {
        return false;
    }
}

bool ZVariant::addToList(const std::uint32_t &value)
{
    if(this->m_variantType == ZVariantType::None)
    {
        this->m_variantType = ZVariantType::List;
    }

    if(this->m_variantType == ZVariantType::List)
    {
        this->m_list.emplace_back(value);
        return true;
    }
    else
    {
        return false;
    }
}

bool ZVariant::addToList(const std::uint64_t &value)
{
    if(this->m_variantType == ZVariantType::None)
    {
        this->m_variantType = ZVariantType::List;
    }

    if(this->m_variantType == ZVariantType::List)
    {
        this->m_list.emplace_back(value);
        return true;
    }
    else
    {
        return false;
    }
}

bool ZVariant::addToList(const zfloat32 &value)
{
    if(this->m_variantType == ZVariantType::None)
    {
        this->m_variantType = ZVariantType::List;
    }

    if(this->m_variantType == ZVariantType::List)
    {
        this->m_list.emplace_back(value);
        return true;
    }
    else
    {
        return false;
    }
}

bool ZVariant::addToList(const zfloat64 &value)
{
    if(this->m_variantType == ZVariantType::None)
    {
        this->m_variantType = ZVariantType::List;
    }

    if(this->m_variantType == ZVariantType::List)
    {
        this->m_list.emplace_back(value);
        return true;
    }
    else
    {
        return false;
    }
}

bool ZVariant::addToList(const std::string &value)
{
    if(this->m_variantType == ZVariantType::None)
    {
        this->m_variantType = ZVariantType::List;
    }

    if(this->m_variantType == ZVariantType::List)
    {
        this->m_list.emplace_back(value);
        return true;
    }
    else
    {
        return false;
    }
}

bool ZVariant::addToMap(const std::uint64_t &key, const ZVariant &value)
{
    if(this->m_variantType == ZVariantType::None)
    {
        this->m_variantType = ZVariantType::IntegerVariantMap;
    }

    if(this->m_variantType == ZVariantType::IntegerVariantMap)
    {
        this->m_integerVariantMap.insert(std::pair<std::uint64_t,ZVariant>(key,value));
        return true;
    }
    else
    {
        return false;
    }
}

bool ZVariant::addToMap(const ZVariant &key, const ZVariant &value)
{
    if(this->m_variantType == ZVariantType::None)
    {
        this->m_variantType = ZVariantType::Map;
    }

    if(this->m_variantType == ZVariantType::Map)
    {
        this->m_map.insert(std::pair<ZVariant,ZVariant>(key,value));
        return true;
    }
    else
    {
        return false;
    }
}

bool ZVariant::operator<(const ZVariant &rhs) const
{
    if(this->isNumber())
    {
        return this->getNumber()<rhs.getNumber();
    }
    else
    {
        return this->getLength()<rhs.getLength();
    }
}

ZVariant &ZVariant::operator=(ZVariant &&rhs)
{
    std::cout<<"Assignment Moving ZVariant = ..."<<std::endl;
    if(this != &rhs)
    {
        this->makeInvalid();
        this->m_variantType = rhs.m_variantType;

        switch (rhs.m_variantType) {
        case ZVariantType::Bool:
            this->m_bool = std::move(rhs.m_bool);
            break;
        case ZVariantType::Int8:
            this->m_int8 = std::move(rhs.m_int8);
            break;

        case ZVariantType::Int16:
            this->m_int16 = std::move(rhs.m_int16);
            break;

        case ZVariantType::Int32:
            this->m_int32 = std::move(rhs.m_int32);
            break;

        case ZVariantType::Int64:
            this->m_int64 = std::move(rhs.m_int64);
            break;

        case ZVariantType::UInt8:
            this->m_uint8 = std::move(rhs.m_uint8);
            break;

        case ZVariantType::UInt16:
            this->m_uint16 = std::move(rhs.m_uint16);
            break;

        case ZVariantType::UInt32:
            this->m_uint32 = std::move(rhs.m_uint32);
            break;

        case ZVariantType::UInt64:
            this->m_uint64 = std::move(rhs.m_uint64);
            break;

        case ZVariantType::Float32:
            this->m_float32 = std::move(rhs.m_float32);
            break;

        case ZVariantType::Float64:
            this->m_float64 = std::move(rhs.m_float64);
            break;

        case ZVariantType::String:
            this->m_string = std::move(rhs.m_string);
            break;

        case ZVariantType::List:
            //this->m_list.clear();
            //this->m_list.reserve(other.m_list.size());
            this->m_list = std::move(rhs.m_list);
            break;
        case ZVariantType::Map:
            //this->m_map.clear();
            this->m_map = std::move(rhs.m_map);
            break;
        case ZVariantType::IntegerVariantMap:
            //this->m_integerVariantMap.clear();
            this->m_integerVariantMap = std::move(rhs.m_integerVariantMap);
            break;
        default:
            m_variantType = ZVariantType::None;
            break;
        }

        rhs.makeInvalid();
    }
    return *this;
}

ZVariant &ZVariant::operator=(const ZVariant &rhs)
{
    std::cout<<"Copying = ..."<<std::endl;
    this->m_variantType = rhs.m_variantType;
    switch (m_variantType) {
    case ZVariantType::Bool:
        this->m_bool = rhs.m_bool;
        break;
    case ZVariantType::Int8:
        this->m_int8 = rhs.m_int8;
        break;

    case ZVariantType::Int16:
        this->m_int16 = rhs.m_int16;
        break;

    case ZVariantType::Int32:
        this->m_int32 = rhs.m_int32;
        break;

    case ZVariantType::Int64:
        this->m_int64 = rhs.m_int64;
        break;

    case ZVariantType::UInt8:
        this->m_uint8 = rhs.m_uint8;
        break;

    case ZVariantType::UInt16:
        this->m_uint16 = rhs.m_uint16;
        break;

    case ZVariantType::UInt32:
        this->m_uint32 = rhs.m_uint32;
        break;

    case ZVariantType::UInt64:
        this->m_uint64 = rhs.m_uint64;
        break;

    case ZVariantType::Float32:
        this->m_float32 = rhs.m_float32;
        break;

    case ZVariantType::Float64:
        this->m_float64 = rhs.m_float64;
        break;

    case ZVariantType::String:
        this->m_string = rhs.m_string;
        break;

    case ZVariantType::List:
        this->m_list.clear();
        std::copy(rhs.m_list.begin(), rhs.m_list.end(), back_inserter(this->m_list));
        break;
    case ZVariantType::Map:
        this->m_map.clear();
        this->m_map.insert(rhs.m_map.begin(),rhs.m_map.end());
        break;
    case ZVariantType::IntegerVariantMap:
        this->m_integerVariantMap.clear();
        this->m_integerVariantMap.insert(rhs.m_integerVariantMap.begin(),rhs.m_integerVariantMap.end());
        break;
    default:
        break;
    }

    return *this;
}

ZVariant &ZVariant::operator=(const ZVariant &&rhs)
{
#ifdef ZYXCBA_DEBUG
    std::cout<<"Assignment Moving const ZVariant = ..."<<std::endl;
#endif

    if(this != &rhs)
    {
        m_variantType = rhs.m_variantType;
        switch (m_variantType) {
        case ZVariantType::Bool:
            this->m_bool = std::move(rhs.m_bool);
            break;
        case ZVariantType::Int8:
            this->m_int8 = std::move(rhs.m_int8);
            break;

        case ZVariantType::Int16:
            this->m_int16 = std::move(rhs.m_int16);
            break;

        case ZVariantType::Int32:
            this->m_int32 = std::move(rhs.m_int32);
            break;

        case ZVariantType::Int64:
            this->m_int64 = std::move(rhs.m_int64);
            break;

        case ZVariantType::UInt8:
            this->m_uint8 = std::move(rhs.m_uint8);
            break;

        case ZVariantType::UInt16:
            this->m_uint16 = std::move(rhs.m_uint16);
            break;

        case ZVariantType::UInt32:
            this->m_uint32 = std::move(rhs.m_uint32);
            break;

        case ZVariantType::UInt64:
            this->m_uint64 = std::move(rhs.m_uint64);
            break;

        case ZVariantType::Float32:
            this->m_float32 = std::move(rhs.m_float32);
            break;

        case ZVariantType::Float64:
            this->m_float64 = std::move(rhs.m_float64);
            break;

        case ZVariantType::String:
            this->m_string = std::move(rhs.m_string);
            break;

        case ZVariantType::List:
            //this->m_list.clear();
            //this->m_list.reserve(other.m_list.size());
            this->m_list = std::move(rhs.m_list);
            //std::copy(other.m_list.begin(), other.m_list.end(), back_inserter(this->m_list));
            break;
        case ZVariantType::Map:
            //this->m_map.clear();
            this->m_map = std::move(rhs.m_map);
            //this->m_map.insert(other.m_map.begin(),other.m_map.end());
            break;
        case ZVariantType::IntegerVariantMap:
            //this->m_integerVariantMap.clear();
            this->m_integerVariantMap = std::move(rhs.m_integerVariantMap);
            //this->m_integerVariantMap.insert(other.m_integerVariantMap.begin(),other.m_integerVariantMap.end());
            break;
        default:
            m_variantType = ZVariantType::None;
            break;
        }

    }

    return *this;
}

}
