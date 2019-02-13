#include "zvariant.h"

namespace zyxcba {

ZVariant::ZVariant():
    m_variantType(ZVariantType::None)
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
    switch (m_variantType) {
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

ZVariant::~ZVariant()
{

}

ZVariantType ZVariant::variantType() const
{
    return this->m_variantType;
}

std::string ZVariant::variantTypeString() const
{
    switch (m_variantType) {

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

bool ZVariant::isNone() const
{
    return this->m_variantType == ZVariantType::None;
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

std::int8_t ZVariant::getInt8() const
{
    return this->m_int8;
}

std::int16_t ZVariant::getInt16() const
{
    return this->m_int16;
}

std::int32_t ZVariant::getInt32() const
{
    return this->m_int32;
}

std::int64_t ZVariant::getInt64() const
{
    return this->m_int64;
}

std::uint8_t ZVariant::getUInt8() const
{
    return this->m_uint8;
}

std::uint16_t ZVariant::getUInt16() const
{
    return this->m_uint16;
}

std::uint32_t ZVariant::getUInt32() const
{
    return this->m_uint32;
}

std::uint64_t ZVariant::getUInt64() const
{
    return this->m_uint64;
}

zfloat32 ZVariant::getFloat32() const
{
    return this->m_float32;
}

zfloat64 ZVariant::getFloat64() const
{
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

}
