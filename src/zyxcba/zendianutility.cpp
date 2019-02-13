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

#include "zendianutility.h"

namespace zyxcba {

ZEndianUtility::ZEndianUtility()
{
    this->m_isLittleEndian = this->isLittleEndian();
}

ZEndianUtility::~ZEndianUtility()
{

}

bool ZEndianUtility::isBigEndian() const
{
    return !this->isLittleEndian();
}

bool ZEndianUtility::isLittleEndian() const
{
    /* runtime endianess detection
     * Check this url to understand about the process
     * https://stackoverflow.com/questions/4239993/determining-endianness-at-compile-time/4240029
    */
    short int number = 0x1;
    char *numPtr = reinterpret_cast<char*>(&number);
    return (numPtr[0] == 1);
}

bool ZEndianUtility::isBigEndianFromFlag() const
{
    return !this->m_isLittleEndian;
}

bool ZEndianUtility::isLittleEndianFromFlag() const
{
    return this->m_isLittleEndian;
}

int ZEndianUtility::getCharSize() const
{
    return sizeof (char);
}

int ZEndianUtility::getShortSize() const
{
    return sizeof (short);
}

int ZEndianUtility::getIntSize() const
{
    return sizeof (int);
}

int ZEndianUtility::getLongLongSize() const
{
    return sizeof (long long);
}

std::string ZEndianUtility::toBESS(const unsigned char &num) const
{
    return this->toBigEndianStdStringFromUInt8(num);
}

std::string ZEndianUtility::toBESS(const unsigned short &num) const
{
    return this->toBigEndianStdStringFromUInt16(num);
}

std::string ZEndianUtility::toBESS(const unsigned int &num) const
{
    return this->toBigEndianStdStringFromUInt32(num);
}

std::string ZEndianUtility::toBESS(const unsigned long long &num) const
{
    return this->toBigEndianStdStringFromUInt64(num);
}

std::string ZEndianUtility::toLESS(const unsigned char &num) const
{
    return this->toLittleEndianStdStringFromUInt8(num);
}

std::string ZEndianUtility::toLESS(const unsigned short &num) const
{
    return this->toLittleEndianStdStringFromUInt16(num);
}

std::string ZEndianUtility::toLESS(const unsigned int &num) const
{
    return this->toLittleEndianStdStringFromUInt32(num);
}

std::string ZEndianUtility::toLESS(const unsigned long long &num) const
{
    return this->toLittleEndianStdStringFromUInt64(num);
}

unsigned char ZEndianUtility::toUInt8FromBESS(const std::string &numstr) const
{
    return this->toUInt8FromBigEndianStdString(numstr);
}

unsigned short ZEndianUtility::toUInt16FromBESS(const std::string &numstr) const
{
    return this->toUInt16FromBigEndianStdString(numstr);
}

unsigned int ZEndianUtility::toUInt32FromBESS(const std::string &numstr) const
{
    return this->toUInt32FromBigEndianStdString(numstr);
}

unsigned long long ZEndianUtility::toUInt64FromBESS(const std::string &numstr) const
{
    return this->toUInt64FromBigEndianStdString(numstr);
}

std::string ZEndianUtility::toBigEndianStdStringFromUInt8(const unsigned char &num) const
{
    std::string r;
    r.reserve(1);
    r.push_back(static_cast<char>( num));
    return r;
}

std::string ZEndianUtility::toBigEndianStdStringFromUInt16(const unsigned short &num) const
{
    unsigned short temp = this->m_isLittleEndian?this->byteSwapUInt16(num):num;
    std::string r;
    r.reserve(2);
    r.push_back(static_cast<char>(temp & 0xFF));
    r.push_back(static_cast<char>((temp>>8) & 0xFF));
    return r;
}

std::string ZEndianUtility::toBigEndianStdStringFromUInt32(const unsigned int &num) const
{
    unsigned int temp = this->m_isLittleEndian?this->byteSwapUInt32(num):num;
    std::string r;
    r.reserve(4);
    r.push_back(static_cast<char>(temp & 0xFF));
    r.push_back(static_cast<char>((temp>>8) & 0xFF));
    r.push_back(static_cast<char>((temp>>16) & 0xFF));
    r.push_back(static_cast<char>((temp>>24) & 0xFF));
    return r;
}

std::string ZEndianUtility::toBigEndianStdStringFromUInt64(const unsigned long long &num) const
{
    unsigned long long temp = this->m_isLittleEndian?this->byteSwapUInt64(num):num;
    std::string r;
    r.reserve(8);
    r.push_back(static_cast<char>(temp & 0xFF));
    r.push_back(static_cast<char>((temp>>8) & 0xFF));
    r.push_back(static_cast<char>((temp>>16) & 0xFF));
    r.push_back(static_cast<char>((temp>>24) & 0xFF));
    r.push_back(static_cast<char>((temp>>32) & 0xFF));
    r.push_back(static_cast<char>((temp>>40) & 0xFF));
    r.push_back(static_cast<char>((temp>>48) & 0xFF));
    r.push_back(static_cast<char>((temp>>56) & 0xFF));
    return r;
}

std::string ZEndianUtility::toLittleEndianStdStringFromUInt8(const unsigned char &num) const
{
    std::string r;
    r.reserve(1);
    r.push_back(static_cast<char>( num));
    return r;
}

std::string ZEndianUtility::toLittleEndianStdStringFromUInt16(const unsigned short &num) const
{
    unsigned short temp = this->m_isLittleEndian?this->byteSwapUInt16(num):num;
    std::string r;
    r.reserve(2);
    r.push_back(static_cast<char>((temp>>8) & 0xFF));
    r.push_back(static_cast<char>(temp & 0xFF));
    return r;
}

std::string ZEndianUtility::toLittleEndianStdStringFromUInt32(const unsigned int &num) const
{
    unsigned int temp = this->m_isLittleEndian?this->byteSwapUInt32(num):num;
    std::string r;
    r.reserve(4);
    r.push_back(static_cast<char>((temp>>24) & 0xFF));
    r.push_back(static_cast<char>((temp>>16) & 0xFF));
    r.push_back(static_cast<char>((temp>>8) & 0xFF));
    r.push_back(static_cast<char>(temp & 0xFF));
    return r;
}

std::string ZEndianUtility::toLittleEndianStdStringFromUInt64(const unsigned long long &num) const
{
    unsigned long long temp = this->m_isLittleEndian?this->byteSwapUInt64(num):num;
    std::string r;
    r.reserve(8);
    r.push_back(static_cast<char>((temp>>56) & 0xFF));
    r.push_back(static_cast<char>((temp>>48) & 0xFF));
    r.push_back(static_cast<char>((temp>>40) & 0xFF));
    r.push_back(static_cast<char>((temp>>32) & 0xFF));
    r.push_back(static_cast<char>((temp>>24) & 0xFF));
    r.push_back(static_cast<char>((temp>>16) & 0xFF));
    r.push_back(static_cast<char>((temp>>8) & 0xFF));
    r.push_back(static_cast<char>(temp & 0xFF));
    return r;
}

char ZEndianUtility::toInt8FromBigEndianStdString(const std::string &numstr) const
{
    assert(numstr.length()==1);
    return numstr.at(0);
}

unsigned char ZEndianUtility::toUInt8FromBigEndianStdString(const std::string &numstr) const
{
    assert(numstr.length()==1);
    return static_cast<unsigned char>(numstr.at(0));
}

short ZEndianUtility::toInt16FromBigEndianStdString(const std::string &numstr) const
{
    return static_cast<short>(this->toUInt16FromBigEndianStdString(numstr));
}

unsigned short ZEndianUtility::toUInt16FromBigEndianStdString(const std::string &numstr) const
{
    assert(numstr.length()==2);
    unsigned short r;
    std::memcpy(&r,numstr.data(),2);
    if(this->m_isLittleEndian) r = this->byteSwapUInt16(r);
    return r;
}

int ZEndianUtility::toInt32FromBigEndianStdString(const std::string &numstr) const
{
    return static_cast<int>(this->toUInt32FromBigEndianStdString(numstr));
}

unsigned int ZEndianUtility::toUInt32FromBigEndianStdString(const std::string &numstr) const
{
    assert(numstr.length()==4);
    unsigned int r;
    std::memcpy(&r,numstr.data(),4);
    if(this->m_isLittleEndian) r = this->byteSwapUInt32(r);
    return r;
}

long long ZEndianUtility::toInt64FromBigEndianStdString(const std::string &numstr) const
{
    return static_cast<long long>(this->toUInt64FromBigEndianStdString(numstr));
}

unsigned long long ZEndianUtility::toUInt64FromBigEndianStdString(const std::string &numstr) const
{
    assert(numstr.length()==8);
    unsigned long long r;
    std::memcpy(&r,numstr.data(),8);
    if(this->m_isLittleEndian) r = this->byteSwapUInt64(r);
    return r;
}

unsigned char ZEndianUtility::toUInt8FromBigEndianCharString(const char *numstr) const
{
    unsigned char r;
    std::memcpy(&r,numstr,1);
    return r;
}

unsigned short ZEndianUtility::toUInt16FromBigEndianCharString(const char *numstr) const
{
    unsigned short r;
    std::memcpy(&r,numstr,2);
    if(this->m_isLittleEndian) r = this->byteSwapUInt16(r);
    return r;
}

unsigned int ZEndianUtility::toUInt32FromBigEndianCharString(const char *numstr) const
{
    unsigned int r;
    std::memcpy(&r,numstr,4);
    if(this->m_isLittleEndian) r = this->byteSwapUInt32(r);
    return r;
}

unsigned long long ZEndianUtility::toUInt64FromBigEndianCharString(const char *numstr) const
{
    unsigned long long r;
    std::memcpy(&r,numstr,8);
    if(this->m_isLittleEndian) r = this->byteSwapUInt64(r);
    return r;
}

char ZEndianUtility::toInt8FromLittleEndianStdString(const std::string &numstr) const
{
    assert(numstr.length()==1);
    return numstr.at(0);
}

unsigned char ZEndianUtility::toUInt8FromLittleEndianStdString(const std::string &numstr) const
{
    assert(numstr.length()==1);
    return static_cast<unsigned char>(numstr.at(0));
}

short ZEndianUtility::toInt16FromLittleEndianStdString(const std::string &numstr) const
{
    return static_cast<short>(this->toUInt16FromLittleEndianStdString(numstr));
}

unsigned short ZEndianUtility::toUInt16FromLittleEndianStdString(const std::string &numstr) const
{
    assert(numstr.length()==2);
    unsigned short r;
    std::memcpy(&r,numstr.data(),2);
    if(!this->m_isLittleEndian) r = this->byteSwapUInt16(r);
    return r;
}

int ZEndianUtility::toInt32FromLittleEndianStdString(const std::string &numstr) const
{
    return static_cast<int>(this->toUInt32FromLittleEndianStdString(numstr));
}

unsigned int ZEndianUtility::toUInt32FromLittleEndianStdString(const std::string &numstr) const
{
    assert(numstr.length()==4);
    unsigned int r;
    std::memcpy(&r,numstr.data(),4);
    if(!this->m_isLittleEndian) r = this->byteSwapUInt32(r);
    return r;
}

long long ZEndianUtility::toInt64FromLittleEndianStdString(const std::string &numstr) const
{
    return static_cast<long long>(this->toUInt64FromLittleEndianStdString(numstr));
}

unsigned long long ZEndianUtility::toUInt64FromLittleEndianStdString(const std::string &numstr) const
{
    assert(numstr.length()==8);
    unsigned long long r;
    std::memcpy(&r,numstr.data(),8);
    if(!this->m_isLittleEndian) r = this->byteSwapUInt64(r);
    return r;
}

unsigned char ZEndianUtility::byteSwapInt8(const char &num) const
{
    return this->byteSwapUInt8(static_cast<unsigned char>(num));
}

unsigned short ZEndianUtility::byteSwapInt16(const short &num) const
{
    return this->byteSwapUInt16(static_cast<unsigned short>(num));
}

unsigned int ZEndianUtility::byteSwapInt32(const int &num) const
{
    return this->byteSwapUInt32(static_cast<unsigned int>(num));
}

unsigned long long ZEndianUtility::byteSwapInt64(const long long &num) const
{
    return this->byteSwapUInt64(static_cast<unsigned long long>(num));
}

unsigned char ZEndianUtility::byteSwapUInt8(const unsigned char &num) const
{
    return num;
}

unsigned short ZEndianUtility::byteSwapUInt16(const unsigned short &num) const
{
    return static_cast<unsigned short>( 0
                                        | ((num & 0x00ff) << 8)
                                        | ((num & 0xff00) >> 8) );
}

unsigned int ZEndianUtility::byteSwapUInt32(const unsigned int &num) const
{
    return 0
            | ((num & 0x000000ff) << 24)
            | ((num & 0x0000ff00) << 8)
            | ((num & 0x00ff0000) >> 8)
            | ((num & 0xff000000) >> 24);
}

unsigned long long ZEndianUtility::byteSwapUInt64(const unsigned long long &num) const
{
    return 0
            | ((num & 0x00000000000000ffULL) << 56)
            | ((num & 0x000000000000ff00ULL) << 40)
            | ((num & 0x0000000000ff0000ULL) << 24)
            | ((num & 0x00000000ff000000ULL) << 8)
            | ((num & 0x000000ff00000000ULL) >> 8)
            | ((num & 0x0000ff0000000000ULL) >> 24)
            | ((num & 0x00ff000000000000ULL) >> 40)
            | ((num & 0xff00000000000000ULL) >> 56);
}

}
