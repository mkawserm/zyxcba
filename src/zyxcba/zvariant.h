#ifndef ZVARIANT_H
#define ZVARIANT_H

#include <map>
#include <vector>
#include <cstring>
#include <cstdint>
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

    explicit ZVariant(const ZVariantList &param);
    explicit ZVariant(const ZVariantMap &param);
    explicit ZVariant(const ZIntegerVariantMap &param);

    explicit ZVariant(const ZVariant &other);

    virtual ~ZVariant();

    ZVariantType variantType() const;
    std::string variantTypeString() const;

    bool isNone() const;

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


    bool operator <(const ZVariant& rhs) const
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


private:
    ZVariantType m_variantType;

    union{
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

        std::string m_string;

        ZVariantList m_list;
        ZVariantMap m_map;
        ZIntegerVariantMap m_integerVariantMap;
    };

};

}

#endif // ZVARIANT_H
