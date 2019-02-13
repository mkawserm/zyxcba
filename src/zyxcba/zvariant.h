#ifndef ZVARIANT_H
#define ZVARIANT_H

#include <map>
#include <vector>
#include <cstring>
#include <cstdint>
#include <ostream>
#include <iostream>

#include "ztype.h"

namespace zyxcba {

class ZVariant;
typedef std::vector<ZVariant> ZVariantList;
typedef std::map<ZVariant,ZVariant> ZVariantMap;
typedef std::map<std::uint64_t,ZVariant> ZIntegerVariantMap;


///////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief The ZVariantType enum
///
///////////////////////////////////////////////////////////////////////////////////////////////////
enum class ZVariantType
{
    None,
    Bool,

    Int8,
    Int16,
    Int32,
    Int64,

    UInt8,
    UInt16,
    UInt32,
    UInt64,

    Float32,
    Float64,

    String,

    List,
    Map,
    IntegerVariantMap
};



///////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief The ZVariant class
///
/// The ZVariant class acts like a union for the most common c++ data types.
///////////////////////////////////////////////////////////////////////////////////////////////////
class ZVariant
{

public:
    explicit ZVariant();

    explicit ZVariant(const bool &param);
    explicit ZVariant(const std::int8_t &param);
    explicit ZVariant(const std::int16_t &param);
    explicit ZVariant(const std::int32_t &param);
    explicit ZVariant(const std::int64_t &param);

    explicit ZVariant(const std::uint8_t &param);
    explicit ZVariant(const std::uint16_t &param);
    explicit ZVariant(const std::uint32_t &param);
    explicit ZVariant(const std::uint64_t &param);

    explicit ZVariant(const zfloat32 &param);
    explicit ZVariant(const zfloat64 &param);

    explicit ZVariant(const std::string &param);
    explicit ZVariant(const std::string &&param);

    explicit ZVariant(const ZVariantList &param);
    explicit ZVariant(const ZVariantMap &param);
    explicit ZVariant(const ZIntegerVariantMap &param);

    explicit ZVariant(const ZVariant &other);

    explicit ZVariant(ZVariant &&rhs);
    explicit ZVariant(const ZVariant &&other);

    virtual ~ZVariant();

    ZVariantType variantType() const;
    std::string variantTypeString() const;

    bool isValid() const;
    bool isNone() const;
    bool isBool() const;

    bool isInt8() const;
    bool isInt16() const;
    bool isInt32() const;
    bool isInt64() const;

    bool isUInt8() const;
    bool isUInt16() const;
    bool isUInt32() const;
    bool isUInt64() const;

    bool isFloat32() const;
    bool isFloat64() const;

    bool isNumber() const;

    bool isString() const;

    bool isMap() const;
    bool isList() const;
    bool isIntegerVariantMap() const;

    std::uint64_t mapLength() const;
    std::uint64_t listLength() const;
    std::uint64_t stringLength() const;
    std::uint64_t integerVariantMapLength() const;

    bool getBool() const;
    std::int8_t getInt8() const;
    std::int16_t getInt16() const;
    std::int32_t getInt32() const;
    std::int64_t getInt64() const;

    std::uint8_t getUInt8() const;
    std::uint16_t getUInt16() const;
    std::uint32_t getUInt32() const;
    std::uint64_t getUInt64() const;

    zfloat32 getFloat32() const;
    zfloat64 getFloat64() const;

    std::uint64_t getNumber() const;
    std::uint64_t getLength() const;


    const std::string &getString() const;
    const ZVariantList &getList() const;
    const ZVariantMap &getMap() const;
    const ZIntegerVariantMap &getIntegerVariantMap() const;

    void makeInvalid();
    void setBool(const bool &param);
    void setInt8(const std::int8_t &param);
    void setInt16(const std::int16_t &param);
    void setInt32(const std::int32_t &param);
    void setInt64(const std::int64_t &param);

    void setUInt8(const std::uint8_t &param);
    void setUInt16(const std::uint16_t &param);
    void setUInt32(const std::uint32_t &param);
    void setUInt64(const std::uint64_t &param);

    void setFloat32(const zfloat32 &param);
    void setFloat64(const zfloat64 &param);

    void setString(const std::string &param);
    void setList(const ZVariantList &param);
    void setMap(const ZVariantMap &param);
    void setIntegerVariantMap(const ZIntegerVariantMap &param);

    void setValue(const bool &param);
    void setValue(const std::int8_t &param);
    void setValue(const std::int16_t &param);
    void setValue(const std::int32_t &param);
    void setValue(const std::int64_t &param);

    void setValue(const std::uint8_t &param);
    void setValue(const std::uint16_t &param);
    void setValue(const std::uint32_t &param);
    void setValue(const std::uint64_t &param);

    void setValue(const zfloat32 &param);
    void setValue(const zfloat64 &param);

    void setValue(const std::string &param);

    void setValue(const ZVariantList &param);
    void setValue(const ZVariantMap &param);
    void setValue(const ZIntegerVariantMap &param);

    void reserveList(const std::uint64_t &length);

    bool addToList(const bool &value);
    bool addToList(const std::int8_t &value);
    bool addToList(const std::int16_t &value);
    bool addToList(const std::int32_t &value);
    bool addToList(const std::int64_t &value);

    bool addToList(const std::uint8_t &value);
    bool addToList(const std::uint16_t &value);
    bool addToList(const std::uint32_t &value);
    bool addToList(const std::uint64_t &value);

    bool addToList(const zfloat32 &value);
    bool addToList(const zfloat64 &value);
    bool addToList(const std::string &value);

    bool addToList(const ZVariant &value);

    bool addToMap(const std::uint64_t &key, const bool &value);
    bool addToMap(const std::uint64_t &key, const std::int8_t &value);
    bool addToMap(const std::uint64_t &key, const std::int16_t &value);
    bool addToMap(const std::uint64_t &key, const std::int32_t &value);
    bool addToMap(const std::uint64_t &key, const std::int64_t &value);
    bool addToMap(const std::uint64_t &key, const std::uint8_t &value);
    bool addToMap(const std::uint64_t &key, const std::uint16_t &value);
    bool addToMap(const std::uint64_t &key, const std::uint32_t &value);
    bool addToMap(const std::uint64_t &key, const std::uint64_t &value);
    bool addToMap(const std::uint64_t &key, const zfloat32 &value);
    bool addToMap(const std::uint64_t &key, const zfloat64 &value);
    bool addToMap(const std::uint64_t &key, const std::string &value);
    bool addToMap(const std::uint64_t &key, const ZVariant &value);

    bool addToMap(const ZVariant &key, const ZVariant &value);


    bool operator<(const ZVariant& rhs) const;

    ZVariant &operator=(const ZVariant &rhs);
    ZVariant &operator=(ZVariant &&rhs);
    ZVariant &operator=(const ZVariant &&rhs);

    friend std::ostream &operator<<(std::ostream &os, const ZVariant &other)
    {

        switch (other.variantType())
        {
        case ZVariantType::Bool:
            if(other.getBool())
            {
                os << "ZVariant("<<other.variantTypeString()<<": True"<<")";
            }
            else
            {
                os << "ZVariant("<<other.variantTypeString()<<": False"<<")";
            }
            break;
        case ZVariantType::Int32:
            os << "ZVariant("<<other.variantTypeString()<<": "<<other.getInt32()<<")";
            break;

        case ZVariantType::Map:
            os << "ZVariant("<<other.variantTypeString()<<": "<<other.getLength()<<")";
            break;
        case ZVariantType::IntegerVariantMap:
            os << "ZVariant("<<other.variantTypeString()<<": "<<other.getLength()<<")";
            break;
        case ZVariantType::List:
            os << "ZVariant("<<other.variantTypeString()<<": "<<other.getLength()<<")";
            break;
        case ZVariantType::String:
            os << "ZVariant("<<other.variantTypeString()<<": "<<other.getString()<<")";
            break;

        default:
            os << "ZVariant("<<other.variantTypeString()<<")";
            break;
        }

        return os;
    }

private:
    ZVariantType m_variantType;

    union{
        bool m_bool;
        std::int8_t m_int8;
        std::int16_t m_int16;
        std::int32_t m_int32;
        std::int64_t m_int64;

        std::uint8_t m_uint8;
        std::uint16_t m_uint16;
        std::uint32_t m_uint32;
        std::uint64_t m_uint64;

        zfloat32 m_float32;
        zfloat64 m_float64;
    };

    std::string m_string;
    ZVariantList m_list;
    ZVariantMap m_map;
    ZIntegerVariantMap m_integerVariantMap;

};


}

#endif // ZVARIANT_H
