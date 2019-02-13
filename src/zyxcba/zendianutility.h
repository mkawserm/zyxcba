/* Copyright (c) 2019, Md Kawser Munshi
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *   Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 *   Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following disclaimer
 *   in the documentation and/or other materials provided with the
 *   distribution.
 *
 *   Neither the names of the copyright owners nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ZENDIANUTILITY_H
#define ZENDIANUTILITY_H

#include <cassert>
#include <cstring>
#include <iostream>

namespace zyxcba {

///////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief The ZEndianUtility class
///
/// ZEndianUtility is useful to determine endianess about the cpu on runtime and some
/// necessary methods for byte ordering and manipulation.
///////////////////////////////////////////////////////////////////////////////////////////////////
class ZEndianUtility
{
public:
    explicit ZEndianUtility();
    virtual ~ZEndianUtility();

    bool isBigEndian() const;
    bool isLittleEndian() const;

    bool isBigEndianFromFlag() const;
    bool isLittleEndianFromFlag() const;

    int getCharSize() const;
    int getShortSize() const;
    int getIntSize() const;
    int getLongLongSize() const;

    std::string toBESS(const unsigned char &num) const;
    std::string toBESS(const unsigned short &num) const;
    std::string toBESS(const unsigned int &num) const;
    std::string toBESS(const unsigned long long &num) const;

    std::string toLESS(const unsigned char &num) const;
    std::string toLESS(const unsigned short &num) const;
    std::string toLESS(const unsigned int &num) const;
    std::string toLESS(const unsigned long long &num) const;

    unsigned char toUInt8FromBESS(const std::string &numstr) const;
    unsigned short toUInt16FromBESS(const std::string &numstr) const;
    unsigned int toUInt32FromBESS(const std::string &numstr) const;
    unsigned long long toUInt64FromBESS(const std::string &numstr) const;

    std::string toBigEndianStdStringFromUInt8(const unsigned char &num) const;
    std::string toBigEndianStdStringFromUInt16(const unsigned short &num) const;
    std::string toBigEndianStdStringFromUInt32(const unsigned int &num) const;
    std::string toBigEndianStdStringFromUInt64(const unsigned long long &num) const;

    std::string toLittleEndianStdStringFromUInt8(const unsigned char &num) const;
    std::string toLittleEndianStdStringFromUInt16(const unsigned short &num) const;
    std::string toLittleEndianStdStringFromUInt32(const unsigned int &num) const;
    std::string toLittleEndianStdStringFromUInt64(const unsigned long long &num) const;

    char toInt8FromBigEndianStdString(const std::string &numstr) const;
    short toInt16FromBigEndianStdString(const std::string &numstr) const;
    int toInt32FromBigEndianStdString(const std::string &numstr) const;
    long long toInt64FromBigEndianStdString(const std::string &numstr) const;

    unsigned char toUInt8FromBigEndianStdString(const std::string &numstr) const;
    unsigned short toUInt16FromBigEndianStdString(const std::string &numstr) const;
    unsigned int toUInt32FromBigEndianStdString(const std::string &numstr) const;
    unsigned long long toUInt64FromBigEndianStdString(const std::string &numstr) const;

    unsigned char toUInt8FromBigEndianCharString(const char *numstr) const;
    unsigned short toUInt16FromBigEndianCharString(const char *numstr) const;
    unsigned int toUInt32FromBigEndianCharString(const char *numstr) const;
    unsigned long long toUInt64FromBigEndianCharString(const char *numstr) const;


    char toInt8FromLittleEndianStdString(const std::string &numstr) const;
    short toInt16FromLittleEndianStdString(const std::string &numstr) const;
    int toInt32FromLittleEndianStdString(const std::string &numstr) const;
    long long toInt64FromLittleEndianStdString(const std::string &numstr) const;

    unsigned long long toUInt64FromLittleEndianStdString(const std::string &numstr) const;
    unsigned int toUInt32FromLittleEndianStdString(const std::string &numstr) const;
    unsigned short toUInt16FromLittleEndianStdString(const std::string &numstr) const;
    unsigned char toUInt8FromLittleEndianStdString(const std::string &numstr) const;


    unsigned char byteSwapInt8(const char &num) const;
    unsigned short byteSwapInt16(const short &num) const;
    unsigned int byteSwapInt32(const int &num) const;
    unsigned long long byteSwapInt64(const long long &num) const;

    unsigned char byteSwapUInt8(const unsigned char &num) const;
    unsigned short byteSwapUInt16(const unsigned short &num) const;
    unsigned int byteSwapUInt32(const unsigned int &num) const;
    unsigned long long byteSwapUInt64(const unsigned long long &num) const;

private:
    bool m_isLittleEndian;
};

}

#endif
