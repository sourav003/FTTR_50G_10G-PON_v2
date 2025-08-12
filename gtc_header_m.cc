//
// Generated file, do not edit! Created by opp_msgtool 6.0 from gtc_header.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "gtc_header_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(gtc_header)

gtc_header::gtc_header(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

gtc_header::gtc_header(const gtc_header& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

gtc_header::~gtc_header()
{
    delete [] this->Olt_onu_rtt;
    delete [] this->Onu_start_time_TC1;
    delete [] this->Onu_grant_TC1;
    delete [] this->Onu_start_time_TC2;
    delete [] this->Onu_grant_TC2;
    delete [] this->Onu_start_time_TC3;
    delete [] this->Onu_grant_TC3;
    delete [] this->Mfu_sfu_rtt;
    delete [] this->Sfu_start_time_TC1;
    delete [] this->Sfu_grant_TC1;
    delete [] this->Sfu_start_time_TC2;
    delete [] this->Sfu_grant_TC2;
    delete [] this->Sfu_start_time_TC3;
    delete [] this->Sfu_grant_TC3;
}

gtc_header& gtc_header::operator=(const gtc_header& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void gtc_header::copy(const gtc_header& other)
{
    this->Downlink = other.Downlink;
    this->Uplink = other.Uplink;
    this->Ext_pon = other.Ext_pon;
    this->Int_pon = other.Int_pon;
    delete [] this->Olt_onu_rtt;
    this->Olt_onu_rtt = (other.Olt_onu_rtt_arraysize==0) ? nullptr : new double[other.Olt_onu_rtt_arraysize];
    Olt_onu_rtt_arraysize = other.Olt_onu_rtt_arraysize;
    for (size_t i = 0; i < Olt_onu_rtt_arraysize; i++) {
        this->Olt_onu_rtt[i] = other.Olt_onu_rtt[i];
    }
    delete [] this->Onu_start_time_TC1;
    this->Onu_start_time_TC1 = (other.Onu_start_time_TC1_arraysize==0) ? nullptr : new double[other.Onu_start_time_TC1_arraysize];
    Onu_start_time_TC1_arraysize = other.Onu_start_time_TC1_arraysize;
    for (size_t i = 0; i < Onu_start_time_TC1_arraysize; i++) {
        this->Onu_start_time_TC1[i] = other.Onu_start_time_TC1[i];
    }
    delete [] this->Onu_grant_TC1;
    this->Onu_grant_TC1 = (other.Onu_grant_TC1_arraysize==0) ? nullptr : new double[other.Onu_grant_TC1_arraysize];
    Onu_grant_TC1_arraysize = other.Onu_grant_TC1_arraysize;
    for (size_t i = 0; i < Onu_grant_TC1_arraysize; i++) {
        this->Onu_grant_TC1[i] = other.Onu_grant_TC1[i];
    }
    delete [] this->Onu_start_time_TC2;
    this->Onu_start_time_TC2 = (other.Onu_start_time_TC2_arraysize==0) ? nullptr : new double[other.Onu_start_time_TC2_arraysize];
    Onu_start_time_TC2_arraysize = other.Onu_start_time_TC2_arraysize;
    for (size_t i = 0; i < Onu_start_time_TC2_arraysize; i++) {
        this->Onu_start_time_TC2[i] = other.Onu_start_time_TC2[i];
    }
    delete [] this->Onu_grant_TC2;
    this->Onu_grant_TC2 = (other.Onu_grant_TC2_arraysize==0) ? nullptr : new double[other.Onu_grant_TC2_arraysize];
    Onu_grant_TC2_arraysize = other.Onu_grant_TC2_arraysize;
    for (size_t i = 0; i < Onu_grant_TC2_arraysize; i++) {
        this->Onu_grant_TC2[i] = other.Onu_grant_TC2[i];
    }
    delete [] this->Onu_start_time_TC3;
    this->Onu_start_time_TC3 = (other.Onu_start_time_TC3_arraysize==0) ? nullptr : new double[other.Onu_start_time_TC3_arraysize];
    Onu_start_time_TC3_arraysize = other.Onu_start_time_TC3_arraysize;
    for (size_t i = 0; i < Onu_start_time_TC3_arraysize; i++) {
        this->Onu_start_time_TC3[i] = other.Onu_start_time_TC3[i];
    }
    delete [] this->Onu_grant_TC3;
    this->Onu_grant_TC3 = (other.Onu_grant_TC3_arraysize==0) ? nullptr : new double[other.Onu_grant_TC3_arraysize];
    Onu_grant_TC3_arraysize = other.Onu_grant_TC3_arraysize;
    for (size_t i = 0; i < Onu_grant_TC3_arraysize; i++) {
        this->Onu_grant_TC3[i] = other.Onu_grant_TC3[i];
    }
    delete [] this->Mfu_sfu_rtt;
    this->Mfu_sfu_rtt = (other.Mfu_sfu_rtt_arraysize==0) ? nullptr : new double[other.Mfu_sfu_rtt_arraysize];
    Mfu_sfu_rtt_arraysize = other.Mfu_sfu_rtt_arraysize;
    for (size_t i = 0; i < Mfu_sfu_rtt_arraysize; i++) {
        this->Mfu_sfu_rtt[i] = other.Mfu_sfu_rtt[i];
    }
    delete [] this->Sfu_start_time_TC1;
    this->Sfu_start_time_TC1 = (other.Sfu_start_time_TC1_arraysize==0) ? nullptr : new double[other.Sfu_start_time_TC1_arraysize];
    Sfu_start_time_TC1_arraysize = other.Sfu_start_time_TC1_arraysize;
    for (size_t i = 0; i < Sfu_start_time_TC1_arraysize; i++) {
        this->Sfu_start_time_TC1[i] = other.Sfu_start_time_TC1[i];
    }
    delete [] this->Sfu_grant_TC1;
    this->Sfu_grant_TC1 = (other.Sfu_grant_TC1_arraysize==0) ? nullptr : new double[other.Sfu_grant_TC1_arraysize];
    Sfu_grant_TC1_arraysize = other.Sfu_grant_TC1_arraysize;
    for (size_t i = 0; i < Sfu_grant_TC1_arraysize; i++) {
        this->Sfu_grant_TC1[i] = other.Sfu_grant_TC1[i];
    }
    delete [] this->Sfu_start_time_TC2;
    this->Sfu_start_time_TC2 = (other.Sfu_start_time_TC2_arraysize==0) ? nullptr : new double[other.Sfu_start_time_TC2_arraysize];
    Sfu_start_time_TC2_arraysize = other.Sfu_start_time_TC2_arraysize;
    for (size_t i = 0; i < Sfu_start_time_TC2_arraysize; i++) {
        this->Sfu_start_time_TC2[i] = other.Sfu_start_time_TC2[i];
    }
    delete [] this->Sfu_grant_TC2;
    this->Sfu_grant_TC2 = (other.Sfu_grant_TC2_arraysize==0) ? nullptr : new double[other.Sfu_grant_TC2_arraysize];
    Sfu_grant_TC2_arraysize = other.Sfu_grant_TC2_arraysize;
    for (size_t i = 0; i < Sfu_grant_TC2_arraysize; i++) {
        this->Sfu_grant_TC2[i] = other.Sfu_grant_TC2[i];
    }
    delete [] this->Sfu_start_time_TC3;
    this->Sfu_start_time_TC3 = (other.Sfu_start_time_TC3_arraysize==0) ? nullptr : new double[other.Sfu_start_time_TC3_arraysize];
    Sfu_start_time_TC3_arraysize = other.Sfu_start_time_TC3_arraysize;
    for (size_t i = 0; i < Sfu_start_time_TC3_arraysize; i++) {
        this->Sfu_start_time_TC3[i] = other.Sfu_start_time_TC3[i];
    }
    delete [] this->Sfu_grant_TC3;
    this->Sfu_grant_TC3 = (other.Sfu_grant_TC3_arraysize==0) ? nullptr : new double[other.Sfu_grant_TC3_arraysize];
    Sfu_grant_TC3_arraysize = other.Sfu_grant_TC3_arraysize;
    for (size_t i = 0; i < Sfu_grant_TC3_arraysize; i++) {
        this->Sfu_grant_TC3[i] = other.Sfu_grant_TC3[i];
    }
    this->OnuID = other.OnuID;
    this->SfuID = other.SfuID;
    this->MfuID = other.MfuID;
    this->BufferOccupancyTC1 = other.BufferOccupancyTC1;
    this->BufferOccupancyTC2 = other.BufferOccupancyTC2;
    this->BufferOccupancyTC3 = other.BufferOccupancyTC3;
    this->SeqID = other.SeqID;
}

void gtc_header::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->Downlink);
    doParsimPacking(b,this->Uplink);
    doParsimPacking(b,this->Ext_pon);
    doParsimPacking(b,this->Int_pon);
    b->pack(Olt_onu_rtt_arraysize);
    doParsimArrayPacking(b,this->Olt_onu_rtt,Olt_onu_rtt_arraysize);
    b->pack(Onu_start_time_TC1_arraysize);
    doParsimArrayPacking(b,this->Onu_start_time_TC1,Onu_start_time_TC1_arraysize);
    b->pack(Onu_grant_TC1_arraysize);
    doParsimArrayPacking(b,this->Onu_grant_TC1,Onu_grant_TC1_arraysize);
    b->pack(Onu_start_time_TC2_arraysize);
    doParsimArrayPacking(b,this->Onu_start_time_TC2,Onu_start_time_TC2_arraysize);
    b->pack(Onu_grant_TC2_arraysize);
    doParsimArrayPacking(b,this->Onu_grant_TC2,Onu_grant_TC2_arraysize);
    b->pack(Onu_start_time_TC3_arraysize);
    doParsimArrayPacking(b,this->Onu_start_time_TC3,Onu_start_time_TC3_arraysize);
    b->pack(Onu_grant_TC3_arraysize);
    doParsimArrayPacking(b,this->Onu_grant_TC3,Onu_grant_TC3_arraysize);
    b->pack(Mfu_sfu_rtt_arraysize);
    doParsimArrayPacking(b,this->Mfu_sfu_rtt,Mfu_sfu_rtt_arraysize);
    b->pack(Sfu_start_time_TC1_arraysize);
    doParsimArrayPacking(b,this->Sfu_start_time_TC1,Sfu_start_time_TC1_arraysize);
    b->pack(Sfu_grant_TC1_arraysize);
    doParsimArrayPacking(b,this->Sfu_grant_TC1,Sfu_grant_TC1_arraysize);
    b->pack(Sfu_start_time_TC2_arraysize);
    doParsimArrayPacking(b,this->Sfu_start_time_TC2,Sfu_start_time_TC2_arraysize);
    b->pack(Sfu_grant_TC2_arraysize);
    doParsimArrayPacking(b,this->Sfu_grant_TC2,Sfu_grant_TC2_arraysize);
    b->pack(Sfu_start_time_TC3_arraysize);
    doParsimArrayPacking(b,this->Sfu_start_time_TC3,Sfu_start_time_TC3_arraysize);
    b->pack(Sfu_grant_TC3_arraysize);
    doParsimArrayPacking(b,this->Sfu_grant_TC3,Sfu_grant_TC3_arraysize);
    doParsimPacking(b,this->OnuID);
    doParsimPacking(b,this->SfuID);
    doParsimPacking(b,this->MfuID);
    doParsimPacking(b,this->BufferOccupancyTC1);
    doParsimPacking(b,this->BufferOccupancyTC2);
    doParsimPacking(b,this->BufferOccupancyTC3);
    doParsimPacking(b,this->SeqID);
}

void gtc_header::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->Downlink);
    doParsimUnpacking(b,this->Uplink);
    doParsimUnpacking(b,this->Ext_pon);
    doParsimUnpacking(b,this->Int_pon);
    delete [] this->Olt_onu_rtt;
    b->unpack(Olt_onu_rtt_arraysize);
    if (Olt_onu_rtt_arraysize == 0) {
        this->Olt_onu_rtt = nullptr;
    } else {
        this->Olt_onu_rtt = new double[Olt_onu_rtt_arraysize];
        doParsimArrayUnpacking(b,this->Olt_onu_rtt,Olt_onu_rtt_arraysize);
    }
    delete [] this->Onu_start_time_TC1;
    b->unpack(Onu_start_time_TC1_arraysize);
    if (Onu_start_time_TC1_arraysize == 0) {
        this->Onu_start_time_TC1 = nullptr;
    } else {
        this->Onu_start_time_TC1 = new double[Onu_start_time_TC1_arraysize];
        doParsimArrayUnpacking(b,this->Onu_start_time_TC1,Onu_start_time_TC1_arraysize);
    }
    delete [] this->Onu_grant_TC1;
    b->unpack(Onu_grant_TC1_arraysize);
    if (Onu_grant_TC1_arraysize == 0) {
        this->Onu_grant_TC1 = nullptr;
    } else {
        this->Onu_grant_TC1 = new double[Onu_grant_TC1_arraysize];
        doParsimArrayUnpacking(b,this->Onu_grant_TC1,Onu_grant_TC1_arraysize);
    }
    delete [] this->Onu_start_time_TC2;
    b->unpack(Onu_start_time_TC2_arraysize);
    if (Onu_start_time_TC2_arraysize == 0) {
        this->Onu_start_time_TC2 = nullptr;
    } else {
        this->Onu_start_time_TC2 = new double[Onu_start_time_TC2_arraysize];
        doParsimArrayUnpacking(b,this->Onu_start_time_TC2,Onu_start_time_TC2_arraysize);
    }
    delete [] this->Onu_grant_TC2;
    b->unpack(Onu_grant_TC2_arraysize);
    if (Onu_grant_TC2_arraysize == 0) {
        this->Onu_grant_TC2 = nullptr;
    } else {
        this->Onu_grant_TC2 = new double[Onu_grant_TC2_arraysize];
        doParsimArrayUnpacking(b,this->Onu_grant_TC2,Onu_grant_TC2_arraysize);
    }
    delete [] this->Onu_start_time_TC3;
    b->unpack(Onu_start_time_TC3_arraysize);
    if (Onu_start_time_TC3_arraysize == 0) {
        this->Onu_start_time_TC3 = nullptr;
    } else {
        this->Onu_start_time_TC3 = new double[Onu_start_time_TC3_arraysize];
        doParsimArrayUnpacking(b,this->Onu_start_time_TC3,Onu_start_time_TC3_arraysize);
    }
    delete [] this->Onu_grant_TC3;
    b->unpack(Onu_grant_TC3_arraysize);
    if (Onu_grant_TC3_arraysize == 0) {
        this->Onu_grant_TC3 = nullptr;
    } else {
        this->Onu_grant_TC3 = new double[Onu_grant_TC3_arraysize];
        doParsimArrayUnpacking(b,this->Onu_grant_TC3,Onu_grant_TC3_arraysize);
    }
    delete [] this->Mfu_sfu_rtt;
    b->unpack(Mfu_sfu_rtt_arraysize);
    if (Mfu_sfu_rtt_arraysize == 0) {
        this->Mfu_sfu_rtt = nullptr;
    } else {
        this->Mfu_sfu_rtt = new double[Mfu_sfu_rtt_arraysize];
        doParsimArrayUnpacking(b,this->Mfu_sfu_rtt,Mfu_sfu_rtt_arraysize);
    }
    delete [] this->Sfu_start_time_TC1;
    b->unpack(Sfu_start_time_TC1_arraysize);
    if (Sfu_start_time_TC1_arraysize == 0) {
        this->Sfu_start_time_TC1 = nullptr;
    } else {
        this->Sfu_start_time_TC1 = new double[Sfu_start_time_TC1_arraysize];
        doParsimArrayUnpacking(b,this->Sfu_start_time_TC1,Sfu_start_time_TC1_arraysize);
    }
    delete [] this->Sfu_grant_TC1;
    b->unpack(Sfu_grant_TC1_arraysize);
    if (Sfu_grant_TC1_arraysize == 0) {
        this->Sfu_grant_TC1 = nullptr;
    } else {
        this->Sfu_grant_TC1 = new double[Sfu_grant_TC1_arraysize];
        doParsimArrayUnpacking(b,this->Sfu_grant_TC1,Sfu_grant_TC1_arraysize);
    }
    delete [] this->Sfu_start_time_TC2;
    b->unpack(Sfu_start_time_TC2_arraysize);
    if (Sfu_start_time_TC2_arraysize == 0) {
        this->Sfu_start_time_TC2 = nullptr;
    } else {
        this->Sfu_start_time_TC2 = new double[Sfu_start_time_TC2_arraysize];
        doParsimArrayUnpacking(b,this->Sfu_start_time_TC2,Sfu_start_time_TC2_arraysize);
    }
    delete [] this->Sfu_grant_TC2;
    b->unpack(Sfu_grant_TC2_arraysize);
    if (Sfu_grant_TC2_arraysize == 0) {
        this->Sfu_grant_TC2 = nullptr;
    } else {
        this->Sfu_grant_TC2 = new double[Sfu_grant_TC2_arraysize];
        doParsimArrayUnpacking(b,this->Sfu_grant_TC2,Sfu_grant_TC2_arraysize);
    }
    delete [] this->Sfu_start_time_TC3;
    b->unpack(Sfu_start_time_TC3_arraysize);
    if (Sfu_start_time_TC3_arraysize == 0) {
        this->Sfu_start_time_TC3 = nullptr;
    } else {
        this->Sfu_start_time_TC3 = new double[Sfu_start_time_TC3_arraysize];
        doParsimArrayUnpacking(b,this->Sfu_start_time_TC3,Sfu_start_time_TC3_arraysize);
    }
    delete [] this->Sfu_grant_TC3;
    b->unpack(Sfu_grant_TC3_arraysize);
    if (Sfu_grant_TC3_arraysize == 0) {
        this->Sfu_grant_TC3 = nullptr;
    } else {
        this->Sfu_grant_TC3 = new double[Sfu_grant_TC3_arraysize];
        doParsimArrayUnpacking(b,this->Sfu_grant_TC3,Sfu_grant_TC3_arraysize);
    }
    doParsimUnpacking(b,this->OnuID);
    doParsimUnpacking(b,this->SfuID);
    doParsimUnpacking(b,this->MfuID);
    doParsimUnpacking(b,this->BufferOccupancyTC1);
    doParsimUnpacking(b,this->BufferOccupancyTC2);
    doParsimUnpacking(b,this->BufferOccupancyTC3);
    doParsimUnpacking(b,this->SeqID);
}

bool gtc_header::getDownlink() const
{
    return this->Downlink;
}

void gtc_header::setDownlink(bool Downlink)
{
    this->Downlink = Downlink;
}

bool gtc_header::getUplink() const
{
    return this->Uplink;
}

void gtc_header::setUplink(bool Uplink)
{
    this->Uplink = Uplink;
}

bool gtc_header::getExt_pon() const
{
    return this->Ext_pon;
}

void gtc_header::setExt_pon(bool Ext_pon)
{
    this->Ext_pon = Ext_pon;
}

bool gtc_header::getInt_pon() const
{
    return this->Int_pon;
}

void gtc_header::setInt_pon(bool Int_pon)
{
    this->Int_pon = Int_pon;
}

size_t gtc_header::getOlt_onu_rttArraySize() const
{
    return Olt_onu_rtt_arraysize;
}

double gtc_header::getOlt_onu_rtt(size_t k) const
{
    if (k >= Olt_onu_rtt_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Olt_onu_rtt_arraysize, (unsigned long)k);
    return this->Olt_onu_rtt[k];
}

void gtc_header::setOlt_onu_rttArraySize(size_t newSize)
{
    double *Olt_onu_rtt2 = (newSize==0) ? nullptr : new double[newSize];
    size_t minSize = Olt_onu_rtt_arraysize < newSize ? Olt_onu_rtt_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        Olt_onu_rtt2[i] = this->Olt_onu_rtt[i];
    for (size_t i = minSize; i < newSize; i++)
        Olt_onu_rtt2[i] = 0;
    delete [] this->Olt_onu_rtt;
    this->Olt_onu_rtt = Olt_onu_rtt2;
    Olt_onu_rtt_arraysize = newSize;
}

void gtc_header::setOlt_onu_rtt(size_t k, double Olt_onu_rtt)
{
    if (k >= Olt_onu_rtt_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Olt_onu_rtt_arraysize, (unsigned long)k);
    this->Olt_onu_rtt[k] = Olt_onu_rtt;
}

void gtc_header::insertOlt_onu_rtt(size_t k, double Olt_onu_rtt)
{
    if (k > Olt_onu_rtt_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Olt_onu_rtt_arraysize, (unsigned long)k);
    size_t newSize = Olt_onu_rtt_arraysize + 1;
    double *Olt_onu_rtt2 = new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Olt_onu_rtt2[i] = this->Olt_onu_rtt[i];
    Olt_onu_rtt2[k] = Olt_onu_rtt;
    for (i = k + 1; i < newSize; i++)
        Olt_onu_rtt2[i] = this->Olt_onu_rtt[i-1];
    delete [] this->Olt_onu_rtt;
    this->Olt_onu_rtt = Olt_onu_rtt2;
    Olt_onu_rtt_arraysize = newSize;
}

void gtc_header::appendOlt_onu_rtt(double Olt_onu_rtt)
{
    insertOlt_onu_rtt(Olt_onu_rtt_arraysize, Olt_onu_rtt);
}

void gtc_header::eraseOlt_onu_rtt(size_t k)
{
    if (k >= Olt_onu_rtt_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Olt_onu_rtt_arraysize, (unsigned long)k);
    size_t newSize = Olt_onu_rtt_arraysize - 1;
    double *Olt_onu_rtt2 = (newSize == 0) ? nullptr : new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Olt_onu_rtt2[i] = this->Olt_onu_rtt[i];
    for (i = k; i < newSize; i++)
        Olt_onu_rtt2[i] = this->Olt_onu_rtt[i+1];
    delete [] this->Olt_onu_rtt;
    this->Olt_onu_rtt = Olt_onu_rtt2;
    Olt_onu_rtt_arraysize = newSize;
}

size_t gtc_header::getOnu_start_time_TC1ArraySize() const
{
    return Onu_start_time_TC1_arraysize;
}

double gtc_header::getOnu_start_time_TC1(size_t k) const
{
    if (k >= Onu_start_time_TC1_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_start_time_TC1_arraysize, (unsigned long)k);
    return this->Onu_start_time_TC1[k];
}

void gtc_header::setOnu_start_time_TC1ArraySize(size_t newSize)
{
    double *Onu_start_time_TC12 = (newSize==0) ? nullptr : new double[newSize];
    size_t minSize = Onu_start_time_TC1_arraysize < newSize ? Onu_start_time_TC1_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        Onu_start_time_TC12[i] = this->Onu_start_time_TC1[i];
    for (size_t i = minSize; i < newSize; i++)
        Onu_start_time_TC12[i] = 0;
    delete [] this->Onu_start_time_TC1;
    this->Onu_start_time_TC1 = Onu_start_time_TC12;
    Onu_start_time_TC1_arraysize = newSize;
}

void gtc_header::setOnu_start_time_TC1(size_t k, double Onu_start_time_TC1)
{
    if (k >= Onu_start_time_TC1_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_start_time_TC1_arraysize, (unsigned long)k);
    this->Onu_start_time_TC1[k] = Onu_start_time_TC1;
}

void gtc_header::insertOnu_start_time_TC1(size_t k, double Onu_start_time_TC1)
{
    if (k > Onu_start_time_TC1_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_start_time_TC1_arraysize, (unsigned long)k);
    size_t newSize = Onu_start_time_TC1_arraysize + 1;
    double *Onu_start_time_TC12 = new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Onu_start_time_TC12[i] = this->Onu_start_time_TC1[i];
    Onu_start_time_TC12[k] = Onu_start_time_TC1;
    for (i = k + 1; i < newSize; i++)
        Onu_start_time_TC12[i] = this->Onu_start_time_TC1[i-1];
    delete [] this->Onu_start_time_TC1;
    this->Onu_start_time_TC1 = Onu_start_time_TC12;
    Onu_start_time_TC1_arraysize = newSize;
}

void gtc_header::appendOnu_start_time_TC1(double Onu_start_time_TC1)
{
    insertOnu_start_time_TC1(Onu_start_time_TC1_arraysize, Onu_start_time_TC1);
}

void gtc_header::eraseOnu_start_time_TC1(size_t k)
{
    if (k >= Onu_start_time_TC1_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_start_time_TC1_arraysize, (unsigned long)k);
    size_t newSize = Onu_start_time_TC1_arraysize - 1;
    double *Onu_start_time_TC12 = (newSize == 0) ? nullptr : new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Onu_start_time_TC12[i] = this->Onu_start_time_TC1[i];
    for (i = k; i < newSize; i++)
        Onu_start_time_TC12[i] = this->Onu_start_time_TC1[i+1];
    delete [] this->Onu_start_time_TC1;
    this->Onu_start_time_TC1 = Onu_start_time_TC12;
    Onu_start_time_TC1_arraysize = newSize;
}

size_t gtc_header::getOnu_grant_TC1ArraySize() const
{
    return Onu_grant_TC1_arraysize;
}

double gtc_header::getOnu_grant_TC1(size_t k) const
{
    if (k >= Onu_grant_TC1_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_grant_TC1_arraysize, (unsigned long)k);
    return this->Onu_grant_TC1[k];
}

void gtc_header::setOnu_grant_TC1ArraySize(size_t newSize)
{
    double *Onu_grant_TC12 = (newSize==0) ? nullptr : new double[newSize];
    size_t minSize = Onu_grant_TC1_arraysize < newSize ? Onu_grant_TC1_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        Onu_grant_TC12[i] = this->Onu_grant_TC1[i];
    for (size_t i = minSize; i < newSize; i++)
        Onu_grant_TC12[i] = 0;
    delete [] this->Onu_grant_TC1;
    this->Onu_grant_TC1 = Onu_grant_TC12;
    Onu_grant_TC1_arraysize = newSize;
}

void gtc_header::setOnu_grant_TC1(size_t k, double Onu_grant_TC1)
{
    if (k >= Onu_grant_TC1_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_grant_TC1_arraysize, (unsigned long)k);
    this->Onu_grant_TC1[k] = Onu_grant_TC1;
}

void gtc_header::insertOnu_grant_TC1(size_t k, double Onu_grant_TC1)
{
    if (k > Onu_grant_TC1_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_grant_TC1_arraysize, (unsigned long)k);
    size_t newSize = Onu_grant_TC1_arraysize + 1;
    double *Onu_grant_TC12 = new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Onu_grant_TC12[i] = this->Onu_grant_TC1[i];
    Onu_grant_TC12[k] = Onu_grant_TC1;
    for (i = k + 1; i < newSize; i++)
        Onu_grant_TC12[i] = this->Onu_grant_TC1[i-1];
    delete [] this->Onu_grant_TC1;
    this->Onu_grant_TC1 = Onu_grant_TC12;
    Onu_grant_TC1_arraysize = newSize;
}

void gtc_header::appendOnu_grant_TC1(double Onu_grant_TC1)
{
    insertOnu_grant_TC1(Onu_grant_TC1_arraysize, Onu_grant_TC1);
}

void gtc_header::eraseOnu_grant_TC1(size_t k)
{
    if (k >= Onu_grant_TC1_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_grant_TC1_arraysize, (unsigned long)k);
    size_t newSize = Onu_grant_TC1_arraysize - 1;
    double *Onu_grant_TC12 = (newSize == 0) ? nullptr : new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Onu_grant_TC12[i] = this->Onu_grant_TC1[i];
    for (i = k; i < newSize; i++)
        Onu_grant_TC12[i] = this->Onu_grant_TC1[i+1];
    delete [] this->Onu_grant_TC1;
    this->Onu_grant_TC1 = Onu_grant_TC12;
    Onu_grant_TC1_arraysize = newSize;
}

size_t gtc_header::getOnu_start_time_TC2ArraySize() const
{
    return Onu_start_time_TC2_arraysize;
}

double gtc_header::getOnu_start_time_TC2(size_t k) const
{
    if (k >= Onu_start_time_TC2_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_start_time_TC2_arraysize, (unsigned long)k);
    return this->Onu_start_time_TC2[k];
}

void gtc_header::setOnu_start_time_TC2ArraySize(size_t newSize)
{
    double *Onu_start_time_TC22 = (newSize==0) ? nullptr : new double[newSize];
    size_t minSize = Onu_start_time_TC2_arraysize < newSize ? Onu_start_time_TC2_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        Onu_start_time_TC22[i] = this->Onu_start_time_TC2[i];
    for (size_t i = minSize; i < newSize; i++)
        Onu_start_time_TC22[i] = 0;
    delete [] this->Onu_start_time_TC2;
    this->Onu_start_time_TC2 = Onu_start_time_TC22;
    Onu_start_time_TC2_arraysize = newSize;
}

void gtc_header::setOnu_start_time_TC2(size_t k, double Onu_start_time_TC2)
{
    if (k >= Onu_start_time_TC2_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_start_time_TC2_arraysize, (unsigned long)k);
    this->Onu_start_time_TC2[k] = Onu_start_time_TC2;
}

void gtc_header::insertOnu_start_time_TC2(size_t k, double Onu_start_time_TC2)
{
    if (k > Onu_start_time_TC2_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_start_time_TC2_arraysize, (unsigned long)k);
    size_t newSize = Onu_start_time_TC2_arraysize + 1;
    double *Onu_start_time_TC22 = new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Onu_start_time_TC22[i] = this->Onu_start_time_TC2[i];
    Onu_start_time_TC22[k] = Onu_start_time_TC2;
    for (i = k + 1; i < newSize; i++)
        Onu_start_time_TC22[i] = this->Onu_start_time_TC2[i-1];
    delete [] this->Onu_start_time_TC2;
    this->Onu_start_time_TC2 = Onu_start_time_TC22;
    Onu_start_time_TC2_arraysize = newSize;
}

void gtc_header::appendOnu_start_time_TC2(double Onu_start_time_TC2)
{
    insertOnu_start_time_TC2(Onu_start_time_TC2_arraysize, Onu_start_time_TC2);
}

void gtc_header::eraseOnu_start_time_TC2(size_t k)
{
    if (k >= Onu_start_time_TC2_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_start_time_TC2_arraysize, (unsigned long)k);
    size_t newSize = Onu_start_time_TC2_arraysize - 1;
    double *Onu_start_time_TC22 = (newSize == 0) ? nullptr : new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Onu_start_time_TC22[i] = this->Onu_start_time_TC2[i];
    for (i = k; i < newSize; i++)
        Onu_start_time_TC22[i] = this->Onu_start_time_TC2[i+1];
    delete [] this->Onu_start_time_TC2;
    this->Onu_start_time_TC2 = Onu_start_time_TC22;
    Onu_start_time_TC2_arraysize = newSize;
}

size_t gtc_header::getOnu_grant_TC2ArraySize() const
{
    return Onu_grant_TC2_arraysize;
}

double gtc_header::getOnu_grant_TC2(size_t k) const
{
    if (k >= Onu_grant_TC2_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_grant_TC2_arraysize, (unsigned long)k);
    return this->Onu_grant_TC2[k];
}

void gtc_header::setOnu_grant_TC2ArraySize(size_t newSize)
{
    double *Onu_grant_TC22 = (newSize==0) ? nullptr : new double[newSize];
    size_t minSize = Onu_grant_TC2_arraysize < newSize ? Onu_grant_TC2_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        Onu_grant_TC22[i] = this->Onu_grant_TC2[i];
    for (size_t i = minSize; i < newSize; i++)
        Onu_grant_TC22[i] = 0;
    delete [] this->Onu_grant_TC2;
    this->Onu_grant_TC2 = Onu_grant_TC22;
    Onu_grant_TC2_arraysize = newSize;
}

void gtc_header::setOnu_grant_TC2(size_t k, double Onu_grant_TC2)
{
    if (k >= Onu_grant_TC2_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_grant_TC2_arraysize, (unsigned long)k);
    this->Onu_grant_TC2[k] = Onu_grant_TC2;
}

void gtc_header::insertOnu_grant_TC2(size_t k, double Onu_grant_TC2)
{
    if (k > Onu_grant_TC2_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_grant_TC2_arraysize, (unsigned long)k);
    size_t newSize = Onu_grant_TC2_arraysize + 1;
    double *Onu_grant_TC22 = new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Onu_grant_TC22[i] = this->Onu_grant_TC2[i];
    Onu_grant_TC22[k] = Onu_grant_TC2;
    for (i = k + 1; i < newSize; i++)
        Onu_grant_TC22[i] = this->Onu_grant_TC2[i-1];
    delete [] this->Onu_grant_TC2;
    this->Onu_grant_TC2 = Onu_grant_TC22;
    Onu_grant_TC2_arraysize = newSize;
}

void gtc_header::appendOnu_grant_TC2(double Onu_grant_TC2)
{
    insertOnu_grant_TC2(Onu_grant_TC2_arraysize, Onu_grant_TC2);
}

void gtc_header::eraseOnu_grant_TC2(size_t k)
{
    if (k >= Onu_grant_TC2_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_grant_TC2_arraysize, (unsigned long)k);
    size_t newSize = Onu_grant_TC2_arraysize - 1;
    double *Onu_grant_TC22 = (newSize == 0) ? nullptr : new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Onu_grant_TC22[i] = this->Onu_grant_TC2[i];
    for (i = k; i < newSize; i++)
        Onu_grant_TC22[i] = this->Onu_grant_TC2[i+1];
    delete [] this->Onu_grant_TC2;
    this->Onu_grant_TC2 = Onu_grant_TC22;
    Onu_grant_TC2_arraysize = newSize;
}

size_t gtc_header::getOnu_start_time_TC3ArraySize() const
{
    return Onu_start_time_TC3_arraysize;
}

double gtc_header::getOnu_start_time_TC3(size_t k) const
{
    if (k >= Onu_start_time_TC3_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_start_time_TC3_arraysize, (unsigned long)k);
    return this->Onu_start_time_TC3[k];
}

void gtc_header::setOnu_start_time_TC3ArraySize(size_t newSize)
{
    double *Onu_start_time_TC32 = (newSize==0) ? nullptr : new double[newSize];
    size_t minSize = Onu_start_time_TC3_arraysize < newSize ? Onu_start_time_TC3_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        Onu_start_time_TC32[i] = this->Onu_start_time_TC3[i];
    for (size_t i = minSize; i < newSize; i++)
        Onu_start_time_TC32[i] = 0;
    delete [] this->Onu_start_time_TC3;
    this->Onu_start_time_TC3 = Onu_start_time_TC32;
    Onu_start_time_TC3_arraysize = newSize;
}

void gtc_header::setOnu_start_time_TC3(size_t k, double Onu_start_time_TC3)
{
    if (k >= Onu_start_time_TC3_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_start_time_TC3_arraysize, (unsigned long)k);
    this->Onu_start_time_TC3[k] = Onu_start_time_TC3;
}

void gtc_header::insertOnu_start_time_TC3(size_t k, double Onu_start_time_TC3)
{
    if (k > Onu_start_time_TC3_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_start_time_TC3_arraysize, (unsigned long)k);
    size_t newSize = Onu_start_time_TC3_arraysize + 1;
    double *Onu_start_time_TC32 = new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Onu_start_time_TC32[i] = this->Onu_start_time_TC3[i];
    Onu_start_time_TC32[k] = Onu_start_time_TC3;
    for (i = k + 1; i < newSize; i++)
        Onu_start_time_TC32[i] = this->Onu_start_time_TC3[i-1];
    delete [] this->Onu_start_time_TC3;
    this->Onu_start_time_TC3 = Onu_start_time_TC32;
    Onu_start_time_TC3_arraysize = newSize;
}

void gtc_header::appendOnu_start_time_TC3(double Onu_start_time_TC3)
{
    insertOnu_start_time_TC3(Onu_start_time_TC3_arraysize, Onu_start_time_TC3);
}

void gtc_header::eraseOnu_start_time_TC3(size_t k)
{
    if (k >= Onu_start_time_TC3_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_start_time_TC3_arraysize, (unsigned long)k);
    size_t newSize = Onu_start_time_TC3_arraysize - 1;
    double *Onu_start_time_TC32 = (newSize == 0) ? nullptr : new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Onu_start_time_TC32[i] = this->Onu_start_time_TC3[i];
    for (i = k; i < newSize; i++)
        Onu_start_time_TC32[i] = this->Onu_start_time_TC3[i+1];
    delete [] this->Onu_start_time_TC3;
    this->Onu_start_time_TC3 = Onu_start_time_TC32;
    Onu_start_time_TC3_arraysize = newSize;
}

size_t gtc_header::getOnu_grant_TC3ArraySize() const
{
    return Onu_grant_TC3_arraysize;
}

double gtc_header::getOnu_grant_TC3(size_t k) const
{
    if (k >= Onu_grant_TC3_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_grant_TC3_arraysize, (unsigned long)k);
    return this->Onu_grant_TC3[k];
}

void gtc_header::setOnu_grant_TC3ArraySize(size_t newSize)
{
    double *Onu_grant_TC32 = (newSize==0) ? nullptr : new double[newSize];
    size_t minSize = Onu_grant_TC3_arraysize < newSize ? Onu_grant_TC3_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        Onu_grant_TC32[i] = this->Onu_grant_TC3[i];
    for (size_t i = minSize; i < newSize; i++)
        Onu_grant_TC32[i] = 0;
    delete [] this->Onu_grant_TC3;
    this->Onu_grant_TC3 = Onu_grant_TC32;
    Onu_grant_TC3_arraysize = newSize;
}

void gtc_header::setOnu_grant_TC3(size_t k, double Onu_grant_TC3)
{
    if (k >= Onu_grant_TC3_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_grant_TC3_arraysize, (unsigned long)k);
    this->Onu_grant_TC3[k] = Onu_grant_TC3;
}

void gtc_header::insertOnu_grant_TC3(size_t k, double Onu_grant_TC3)
{
    if (k > Onu_grant_TC3_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_grant_TC3_arraysize, (unsigned long)k);
    size_t newSize = Onu_grant_TC3_arraysize + 1;
    double *Onu_grant_TC32 = new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Onu_grant_TC32[i] = this->Onu_grant_TC3[i];
    Onu_grant_TC32[k] = Onu_grant_TC3;
    for (i = k + 1; i < newSize; i++)
        Onu_grant_TC32[i] = this->Onu_grant_TC3[i-1];
    delete [] this->Onu_grant_TC3;
    this->Onu_grant_TC3 = Onu_grant_TC32;
    Onu_grant_TC3_arraysize = newSize;
}

void gtc_header::appendOnu_grant_TC3(double Onu_grant_TC3)
{
    insertOnu_grant_TC3(Onu_grant_TC3_arraysize, Onu_grant_TC3);
}

void gtc_header::eraseOnu_grant_TC3(size_t k)
{
    if (k >= Onu_grant_TC3_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Onu_grant_TC3_arraysize, (unsigned long)k);
    size_t newSize = Onu_grant_TC3_arraysize - 1;
    double *Onu_grant_TC32 = (newSize == 0) ? nullptr : new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Onu_grant_TC32[i] = this->Onu_grant_TC3[i];
    for (i = k; i < newSize; i++)
        Onu_grant_TC32[i] = this->Onu_grant_TC3[i+1];
    delete [] this->Onu_grant_TC3;
    this->Onu_grant_TC3 = Onu_grant_TC32;
    Onu_grant_TC3_arraysize = newSize;
}

size_t gtc_header::getMfu_sfu_rttArraySize() const
{
    return Mfu_sfu_rtt_arraysize;
}

double gtc_header::getMfu_sfu_rtt(size_t k) const
{
    if (k >= Mfu_sfu_rtt_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Mfu_sfu_rtt_arraysize, (unsigned long)k);
    return this->Mfu_sfu_rtt[k];
}

void gtc_header::setMfu_sfu_rttArraySize(size_t newSize)
{
    double *Mfu_sfu_rtt2 = (newSize==0) ? nullptr : new double[newSize];
    size_t minSize = Mfu_sfu_rtt_arraysize < newSize ? Mfu_sfu_rtt_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        Mfu_sfu_rtt2[i] = this->Mfu_sfu_rtt[i];
    for (size_t i = minSize; i < newSize; i++)
        Mfu_sfu_rtt2[i] = 0;
    delete [] this->Mfu_sfu_rtt;
    this->Mfu_sfu_rtt = Mfu_sfu_rtt2;
    Mfu_sfu_rtt_arraysize = newSize;
}

void gtc_header::setMfu_sfu_rtt(size_t k, double Mfu_sfu_rtt)
{
    if (k >= Mfu_sfu_rtt_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Mfu_sfu_rtt_arraysize, (unsigned long)k);
    this->Mfu_sfu_rtt[k] = Mfu_sfu_rtt;
}

void gtc_header::insertMfu_sfu_rtt(size_t k, double Mfu_sfu_rtt)
{
    if (k > Mfu_sfu_rtt_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Mfu_sfu_rtt_arraysize, (unsigned long)k);
    size_t newSize = Mfu_sfu_rtt_arraysize + 1;
    double *Mfu_sfu_rtt2 = new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Mfu_sfu_rtt2[i] = this->Mfu_sfu_rtt[i];
    Mfu_sfu_rtt2[k] = Mfu_sfu_rtt;
    for (i = k + 1; i < newSize; i++)
        Mfu_sfu_rtt2[i] = this->Mfu_sfu_rtt[i-1];
    delete [] this->Mfu_sfu_rtt;
    this->Mfu_sfu_rtt = Mfu_sfu_rtt2;
    Mfu_sfu_rtt_arraysize = newSize;
}

void gtc_header::appendMfu_sfu_rtt(double Mfu_sfu_rtt)
{
    insertMfu_sfu_rtt(Mfu_sfu_rtt_arraysize, Mfu_sfu_rtt);
}

void gtc_header::eraseMfu_sfu_rtt(size_t k)
{
    if (k >= Mfu_sfu_rtt_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Mfu_sfu_rtt_arraysize, (unsigned long)k);
    size_t newSize = Mfu_sfu_rtt_arraysize - 1;
    double *Mfu_sfu_rtt2 = (newSize == 0) ? nullptr : new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Mfu_sfu_rtt2[i] = this->Mfu_sfu_rtt[i];
    for (i = k; i < newSize; i++)
        Mfu_sfu_rtt2[i] = this->Mfu_sfu_rtt[i+1];
    delete [] this->Mfu_sfu_rtt;
    this->Mfu_sfu_rtt = Mfu_sfu_rtt2;
    Mfu_sfu_rtt_arraysize = newSize;
}

size_t gtc_header::getSfu_start_time_TC1ArraySize() const
{
    return Sfu_start_time_TC1_arraysize;
}

double gtc_header::getSfu_start_time_TC1(size_t k) const
{
    if (k >= Sfu_start_time_TC1_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_start_time_TC1_arraysize, (unsigned long)k);
    return this->Sfu_start_time_TC1[k];
}

void gtc_header::setSfu_start_time_TC1ArraySize(size_t newSize)
{
    double *Sfu_start_time_TC12 = (newSize==0) ? nullptr : new double[newSize];
    size_t minSize = Sfu_start_time_TC1_arraysize < newSize ? Sfu_start_time_TC1_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        Sfu_start_time_TC12[i] = this->Sfu_start_time_TC1[i];
    for (size_t i = minSize; i < newSize; i++)
        Sfu_start_time_TC12[i] = 0;
    delete [] this->Sfu_start_time_TC1;
    this->Sfu_start_time_TC1 = Sfu_start_time_TC12;
    Sfu_start_time_TC1_arraysize = newSize;
}

void gtc_header::setSfu_start_time_TC1(size_t k, double Sfu_start_time_TC1)
{
    if (k >= Sfu_start_time_TC1_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_start_time_TC1_arraysize, (unsigned long)k);
    this->Sfu_start_time_TC1[k] = Sfu_start_time_TC1;
}

void gtc_header::insertSfu_start_time_TC1(size_t k, double Sfu_start_time_TC1)
{
    if (k > Sfu_start_time_TC1_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_start_time_TC1_arraysize, (unsigned long)k);
    size_t newSize = Sfu_start_time_TC1_arraysize + 1;
    double *Sfu_start_time_TC12 = new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Sfu_start_time_TC12[i] = this->Sfu_start_time_TC1[i];
    Sfu_start_time_TC12[k] = Sfu_start_time_TC1;
    for (i = k + 1; i < newSize; i++)
        Sfu_start_time_TC12[i] = this->Sfu_start_time_TC1[i-1];
    delete [] this->Sfu_start_time_TC1;
    this->Sfu_start_time_TC1 = Sfu_start_time_TC12;
    Sfu_start_time_TC1_arraysize = newSize;
}

void gtc_header::appendSfu_start_time_TC1(double Sfu_start_time_TC1)
{
    insertSfu_start_time_TC1(Sfu_start_time_TC1_arraysize, Sfu_start_time_TC1);
}

void gtc_header::eraseSfu_start_time_TC1(size_t k)
{
    if (k >= Sfu_start_time_TC1_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_start_time_TC1_arraysize, (unsigned long)k);
    size_t newSize = Sfu_start_time_TC1_arraysize - 1;
    double *Sfu_start_time_TC12 = (newSize == 0) ? nullptr : new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Sfu_start_time_TC12[i] = this->Sfu_start_time_TC1[i];
    for (i = k; i < newSize; i++)
        Sfu_start_time_TC12[i] = this->Sfu_start_time_TC1[i+1];
    delete [] this->Sfu_start_time_TC1;
    this->Sfu_start_time_TC1 = Sfu_start_time_TC12;
    Sfu_start_time_TC1_arraysize = newSize;
}

size_t gtc_header::getSfu_grant_TC1ArraySize() const
{
    return Sfu_grant_TC1_arraysize;
}

double gtc_header::getSfu_grant_TC1(size_t k) const
{
    if (k >= Sfu_grant_TC1_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_grant_TC1_arraysize, (unsigned long)k);
    return this->Sfu_grant_TC1[k];
}

void gtc_header::setSfu_grant_TC1ArraySize(size_t newSize)
{
    double *Sfu_grant_TC12 = (newSize==0) ? nullptr : new double[newSize];
    size_t minSize = Sfu_grant_TC1_arraysize < newSize ? Sfu_grant_TC1_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        Sfu_grant_TC12[i] = this->Sfu_grant_TC1[i];
    for (size_t i = minSize; i < newSize; i++)
        Sfu_grant_TC12[i] = 0;
    delete [] this->Sfu_grant_TC1;
    this->Sfu_grant_TC1 = Sfu_grant_TC12;
    Sfu_grant_TC1_arraysize = newSize;
}

void gtc_header::setSfu_grant_TC1(size_t k, double Sfu_grant_TC1)
{
    if (k >= Sfu_grant_TC1_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_grant_TC1_arraysize, (unsigned long)k);
    this->Sfu_grant_TC1[k] = Sfu_grant_TC1;
}

void gtc_header::insertSfu_grant_TC1(size_t k, double Sfu_grant_TC1)
{
    if (k > Sfu_grant_TC1_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_grant_TC1_arraysize, (unsigned long)k);
    size_t newSize = Sfu_grant_TC1_arraysize + 1;
    double *Sfu_grant_TC12 = new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Sfu_grant_TC12[i] = this->Sfu_grant_TC1[i];
    Sfu_grant_TC12[k] = Sfu_grant_TC1;
    for (i = k + 1; i < newSize; i++)
        Sfu_grant_TC12[i] = this->Sfu_grant_TC1[i-1];
    delete [] this->Sfu_grant_TC1;
    this->Sfu_grant_TC1 = Sfu_grant_TC12;
    Sfu_grant_TC1_arraysize = newSize;
}

void gtc_header::appendSfu_grant_TC1(double Sfu_grant_TC1)
{
    insertSfu_grant_TC1(Sfu_grant_TC1_arraysize, Sfu_grant_TC1);
}

void gtc_header::eraseSfu_grant_TC1(size_t k)
{
    if (k >= Sfu_grant_TC1_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_grant_TC1_arraysize, (unsigned long)k);
    size_t newSize = Sfu_grant_TC1_arraysize - 1;
    double *Sfu_grant_TC12 = (newSize == 0) ? nullptr : new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Sfu_grant_TC12[i] = this->Sfu_grant_TC1[i];
    for (i = k; i < newSize; i++)
        Sfu_grant_TC12[i] = this->Sfu_grant_TC1[i+1];
    delete [] this->Sfu_grant_TC1;
    this->Sfu_grant_TC1 = Sfu_grant_TC12;
    Sfu_grant_TC1_arraysize = newSize;
}

size_t gtc_header::getSfu_start_time_TC2ArraySize() const
{
    return Sfu_start_time_TC2_arraysize;
}

double gtc_header::getSfu_start_time_TC2(size_t k) const
{
    if (k >= Sfu_start_time_TC2_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_start_time_TC2_arraysize, (unsigned long)k);
    return this->Sfu_start_time_TC2[k];
}

void gtc_header::setSfu_start_time_TC2ArraySize(size_t newSize)
{
    double *Sfu_start_time_TC22 = (newSize==0) ? nullptr : new double[newSize];
    size_t minSize = Sfu_start_time_TC2_arraysize < newSize ? Sfu_start_time_TC2_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        Sfu_start_time_TC22[i] = this->Sfu_start_time_TC2[i];
    for (size_t i = minSize; i < newSize; i++)
        Sfu_start_time_TC22[i] = 0;
    delete [] this->Sfu_start_time_TC2;
    this->Sfu_start_time_TC2 = Sfu_start_time_TC22;
    Sfu_start_time_TC2_arraysize = newSize;
}

void gtc_header::setSfu_start_time_TC2(size_t k, double Sfu_start_time_TC2)
{
    if (k >= Sfu_start_time_TC2_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_start_time_TC2_arraysize, (unsigned long)k);
    this->Sfu_start_time_TC2[k] = Sfu_start_time_TC2;
}

void gtc_header::insertSfu_start_time_TC2(size_t k, double Sfu_start_time_TC2)
{
    if (k > Sfu_start_time_TC2_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_start_time_TC2_arraysize, (unsigned long)k);
    size_t newSize = Sfu_start_time_TC2_arraysize + 1;
    double *Sfu_start_time_TC22 = new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Sfu_start_time_TC22[i] = this->Sfu_start_time_TC2[i];
    Sfu_start_time_TC22[k] = Sfu_start_time_TC2;
    for (i = k + 1; i < newSize; i++)
        Sfu_start_time_TC22[i] = this->Sfu_start_time_TC2[i-1];
    delete [] this->Sfu_start_time_TC2;
    this->Sfu_start_time_TC2 = Sfu_start_time_TC22;
    Sfu_start_time_TC2_arraysize = newSize;
}

void gtc_header::appendSfu_start_time_TC2(double Sfu_start_time_TC2)
{
    insertSfu_start_time_TC2(Sfu_start_time_TC2_arraysize, Sfu_start_time_TC2);
}

void gtc_header::eraseSfu_start_time_TC2(size_t k)
{
    if (k >= Sfu_start_time_TC2_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_start_time_TC2_arraysize, (unsigned long)k);
    size_t newSize = Sfu_start_time_TC2_arraysize - 1;
    double *Sfu_start_time_TC22 = (newSize == 0) ? nullptr : new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Sfu_start_time_TC22[i] = this->Sfu_start_time_TC2[i];
    for (i = k; i < newSize; i++)
        Sfu_start_time_TC22[i] = this->Sfu_start_time_TC2[i+1];
    delete [] this->Sfu_start_time_TC2;
    this->Sfu_start_time_TC2 = Sfu_start_time_TC22;
    Sfu_start_time_TC2_arraysize = newSize;
}

size_t gtc_header::getSfu_grant_TC2ArraySize() const
{
    return Sfu_grant_TC2_arraysize;
}

double gtc_header::getSfu_grant_TC2(size_t k) const
{
    if (k >= Sfu_grant_TC2_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_grant_TC2_arraysize, (unsigned long)k);
    return this->Sfu_grant_TC2[k];
}

void gtc_header::setSfu_grant_TC2ArraySize(size_t newSize)
{
    double *Sfu_grant_TC22 = (newSize==0) ? nullptr : new double[newSize];
    size_t minSize = Sfu_grant_TC2_arraysize < newSize ? Sfu_grant_TC2_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        Sfu_grant_TC22[i] = this->Sfu_grant_TC2[i];
    for (size_t i = minSize; i < newSize; i++)
        Sfu_grant_TC22[i] = 0;
    delete [] this->Sfu_grant_TC2;
    this->Sfu_grant_TC2 = Sfu_grant_TC22;
    Sfu_grant_TC2_arraysize = newSize;
}

void gtc_header::setSfu_grant_TC2(size_t k, double Sfu_grant_TC2)
{
    if (k >= Sfu_grant_TC2_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_grant_TC2_arraysize, (unsigned long)k);
    this->Sfu_grant_TC2[k] = Sfu_grant_TC2;
}

void gtc_header::insertSfu_grant_TC2(size_t k, double Sfu_grant_TC2)
{
    if (k > Sfu_grant_TC2_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_grant_TC2_arraysize, (unsigned long)k);
    size_t newSize = Sfu_grant_TC2_arraysize + 1;
    double *Sfu_grant_TC22 = new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Sfu_grant_TC22[i] = this->Sfu_grant_TC2[i];
    Sfu_grant_TC22[k] = Sfu_grant_TC2;
    for (i = k + 1; i < newSize; i++)
        Sfu_grant_TC22[i] = this->Sfu_grant_TC2[i-1];
    delete [] this->Sfu_grant_TC2;
    this->Sfu_grant_TC2 = Sfu_grant_TC22;
    Sfu_grant_TC2_arraysize = newSize;
}

void gtc_header::appendSfu_grant_TC2(double Sfu_grant_TC2)
{
    insertSfu_grant_TC2(Sfu_grant_TC2_arraysize, Sfu_grant_TC2);
}

void gtc_header::eraseSfu_grant_TC2(size_t k)
{
    if (k >= Sfu_grant_TC2_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_grant_TC2_arraysize, (unsigned long)k);
    size_t newSize = Sfu_grant_TC2_arraysize - 1;
    double *Sfu_grant_TC22 = (newSize == 0) ? nullptr : new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Sfu_grant_TC22[i] = this->Sfu_grant_TC2[i];
    for (i = k; i < newSize; i++)
        Sfu_grant_TC22[i] = this->Sfu_grant_TC2[i+1];
    delete [] this->Sfu_grant_TC2;
    this->Sfu_grant_TC2 = Sfu_grant_TC22;
    Sfu_grant_TC2_arraysize = newSize;
}

size_t gtc_header::getSfu_start_time_TC3ArraySize() const
{
    return Sfu_start_time_TC3_arraysize;
}

double gtc_header::getSfu_start_time_TC3(size_t k) const
{
    if (k >= Sfu_start_time_TC3_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_start_time_TC3_arraysize, (unsigned long)k);
    return this->Sfu_start_time_TC3[k];
}

void gtc_header::setSfu_start_time_TC3ArraySize(size_t newSize)
{
    double *Sfu_start_time_TC32 = (newSize==0) ? nullptr : new double[newSize];
    size_t minSize = Sfu_start_time_TC3_arraysize < newSize ? Sfu_start_time_TC3_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        Sfu_start_time_TC32[i] = this->Sfu_start_time_TC3[i];
    for (size_t i = minSize; i < newSize; i++)
        Sfu_start_time_TC32[i] = 0;
    delete [] this->Sfu_start_time_TC3;
    this->Sfu_start_time_TC3 = Sfu_start_time_TC32;
    Sfu_start_time_TC3_arraysize = newSize;
}

void gtc_header::setSfu_start_time_TC3(size_t k, double Sfu_start_time_TC3)
{
    if (k >= Sfu_start_time_TC3_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_start_time_TC3_arraysize, (unsigned long)k);
    this->Sfu_start_time_TC3[k] = Sfu_start_time_TC3;
}

void gtc_header::insertSfu_start_time_TC3(size_t k, double Sfu_start_time_TC3)
{
    if (k > Sfu_start_time_TC3_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_start_time_TC3_arraysize, (unsigned long)k);
    size_t newSize = Sfu_start_time_TC3_arraysize + 1;
    double *Sfu_start_time_TC32 = new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Sfu_start_time_TC32[i] = this->Sfu_start_time_TC3[i];
    Sfu_start_time_TC32[k] = Sfu_start_time_TC3;
    for (i = k + 1; i < newSize; i++)
        Sfu_start_time_TC32[i] = this->Sfu_start_time_TC3[i-1];
    delete [] this->Sfu_start_time_TC3;
    this->Sfu_start_time_TC3 = Sfu_start_time_TC32;
    Sfu_start_time_TC3_arraysize = newSize;
}

void gtc_header::appendSfu_start_time_TC3(double Sfu_start_time_TC3)
{
    insertSfu_start_time_TC3(Sfu_start_time_TC3_arraysize, Sfu_start_time_TC3);
}

void gtc_header::eraseSfu_start_time_TC3(size_t k)
{
    if (k >= Sfu_start_time_TC3_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_start_time_TC3_arraysize, (unsigned long)k);
    size_t newSize = Sfu_start_time_TC3_arraysize - 1;
    double *Sfu_start_time_TC32 = (newSize == 0) ? nullptr : new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Sfu_start_time_TC32[i] = this->Sfu_start_time_TC3[i];
    for (i = k; i < newSize; i++)
        Sfu_start_time_TC32[i] = this->Sfu_start_time_TC3[i+1];
    delete [] this->Sfu_start_time_TC3;
    this->Sfu_start_time_TC3 = Sfu_start_time_TC32;
    Sfu_start_time_TC3_arraysize = newSize;
}

size_t gtc_header::getSfu_grant_TC3ArraySize() const
{
    return Sfu_grant_TC3_arraysize;
}

double gtc_header::getSfu_grant_TC3(size_t k) const
{
    if (k >= Sfu_grant_TC3_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_grant_TC3_arraysize, (unsigned long)k);
    return this->Sfu_grant_TC3[k];
}

void gtc_header::setSfu_grant_TC3ArraySize(size_t newSize)
{
    double *Sfu_grant_TC32 = (newSize==0) ? nullptr : new double[newSize];
    size_t minSize = Sfu_grant_TC3_arraysize < newSize ? Sfu_grant_TC3_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        Sfu_grant_TC32[i] = this->Sfu_grant_TC3[i];
    for (size_t i = minSize; i < newSize; i++)
        Sfu_grant_TC32[i] = 0;
    delete [] this->Sfu_grant_TC3;
    this->Sfu_grant_TC3 = Sfu_grant_TC32;
    Sfu_grant_TC3_arraysize = newSize;
}

void gtc_header::setSfu_grant_TC3(size_t k, double Sfu_grant_TC3)
{
    if (k >= Sfu_grant_TC3_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_grant_TC3_arraysize, (unsigned long)k);
    this->Sfu_grant_TC3[k] = Sfu_grant_TC3;
}

void gtc_header::insertSfu_grant_TC3(size_t k, double Sfu_grant_TC3)
{
    if (k > Sfu_grant_TC3_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_grant_TC3_arraysize, (unsigned long)k);
    size_t newSize = Sfu_grant_TC3_arraysize + 1;
    double *Sfu_grant_TC32 = new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Sfu_grant_TC32[i] = this->Sfu_grant_TC3[i];
    Sfu_grant_TC32[k] = Sfu_grant_TC3;
    for (i = k + 1; i < newSize; i++)
        Sfu_grant_TC32[i] = this->Sfu_grant_TC3[i-1];
    delete [] this->Sfu_grant_TC3;
    this->Sfu_grant_TC3 = Sfu_grant_TC32;
    Sfu_grant_TC3_arraysize = newSize;
}

void gtc_header::appendSfu_grant_TC3(double Sfu_grant_TC3)
{
    insertSfu_grant_TC3(Sfu_grant_TC3_arraysize, Sfu_grant_TC3);
}

void gtc_header::eraseSfu_grant_TC3(size_t k)
{
    if (k >= Sfu_grant_TC3_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)Sfu_grant_TC3_arraysize, (unsigned long)k);
    size_t newSize = Sfu_grant_TC3_arraysize - 1;
    double *Sfu_grant_TC32 = (newSize == 0) ? nullptr : new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        Sfu_grant_TC32[i] = this->Sfu_grant_TC3[i];
    for (i = k; i < newSize; i++)
        Sfu_grant_TC32[i] = this->Sfu_grant_TC3[i+1];
    delete [] this->Sfu_grant_TC3;
    this->Sfu_grant_TC3 = Sfu_grant_TC32;
    Sfu_grant_TC3_arraysize = newSize;
}

int gtc_header::getOnuID() const
{
    return this->OnuID;
}

void gtc_header::setOnuID(int OnuID)
{
    this->OnuID = OnuID;
}

int gtc_header::getSfuID() const
{
    return this->SfuID;
}

void gtc_header::setSfuID(int SfuID)
{
    this->SfuID = SfuID;
}

int gtc_header::getMfuID() const
{
    return this->MfuID;
}

void gtc_header::setMfuID(int MfuID)
{
    this->MfuID = MfuID;
}

double gtc_header::getBufferOccupancyTC1() const
{
    return this->BufferOccupancyTC1;
}

void gtc_header::setBufferOccupancyTC1(double BufferOccupancyTC1)
{
    this->BufferOccupancyTC1 = BufferOccupancyTC1;
}

double gtc_header::getBufferOccupancyTC2() const
{
    return this->BufferOccupancyTC2;
}

void gtc_header::setBufferOccupancyTC2(double BufferOccupancyTC2)
{
    this->BufferOccupancyTC2 = BufferOccupancyTC2;
}

double gtc_header::getBufferOccupancyTC3() const
{
    return this->BufferOccupancyTC3;
}

void gtc_header::setBufferOccupancyTC3(double BufferOccupancyTC3)
{
    this->BufferOccupancyTC3 = BufferOccupancyTC3;
}

long gtc_header::getSeqID() const
{
    return this->SeqID;
}

void gtc_header::setSeqID(long SeqID)
{
    this->SeqID = SeqID;
}

class gtc_headerDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_Downlink,
        FIELD_Uplink,
        FIELD_Ext_pon,
        FIELD_Int_pon,
        FIELD_Olt_onu_rtt,
        FIELD_Onu_start_time_TC1,
        FIELD_Onu_grant_TC1,
        FIELD_Onu_start_time_TC2,
        FIELD_Onu_grant_TC2,
        FIELD_Onu_start_time_TC3,
        FIELD_Onu_grant_TC3,
        FIELD_Mfu_sfu_rtt,
        FIELD_Sfu_start_time_TC1,
        FIELD_Sfu_grant_TC1,
        FIELD_Sfu_start_time_TC2,
        FIELD_Sfu_grant_TC2,
        FIELD_Sfu_start_time_TC3,
        FIELD_Sfu_grant_TC3,
        FIELD_OnuID,
        FIELD_SfuID,
        FIELD_MfuID,
        FIELD_BufferOccupancyTC1,
        FIELD_BufferOccupancyTC2,
        FIELD_BufferOccupancyTC3,
        FIELD_SeqID,
    };
  public:
    gtc_headerDescriptor();
    virtual ~gtc_headerDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(gtc_headerDescriptor)

gtc_headerDescriptor::gtc_headerDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(gtc_header)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

gtc_headerDescriptor::~gtc_headerDescriptor()
{
    delete[] propertyNames;
}

bool gtc_headerDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<gtc_header *>(obj)!=nullptr;
}

const char **gtc_headerDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *gtc_headerDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int gtc_headerDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 25+base->getFieldCount() : 25;
}

unsigned int gtc_headerDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_Downlink
        FD_ISEDITABLE,    // FIELD_Uplink
        FD_ISEDITABLE,    // FIELD_Ext_pon
        FD_ISEDITABLE,    // FIELD_Int_pon
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_Olt_onu_rtt
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_Onu_start_time_TC1
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_Onu_grant_TC1
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_Onu_start_time_TC2
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_Onu_grant_TC2
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_Onu_start_time_TC3
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_Onu_grant_TC3
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_Mfu_sfu_rtt
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_Sfu_start_time_TC1
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_Sfu_grant_TC1
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_Sfu_start_time_TC2
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_Sfu_grant_TC2
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_Sfu_start_time_TC3
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_Sfu_grant_TC3
        FD_ISEDITABLE,    // FIELD_OnuID
        FD_ISEDITABLE,    // FIELD_SfuID
        FD_ISEDITABLE,    // FIELD_MfuID
        FD_ISEDITABLE,    // FIELD_BufferOccupancyTC1
        FD_ISEDITABLE,    // FIELD_BufferOccupancyTC2
        FD_ISEDITABLE,    // FIELD_BufferOccupancyTC3
        FD_ISEDITABLE,    // FIELD_SeqID
    };
    return (field >= 0 && field < 25) ? fieldTypeFlags[field] : 0;
}

const char *gtc_headerDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "Downlink",
        "Uplink",
        "Ext_pon",
        "Int_pon",
        "Olt_onu_rtt",
        "Onu_start_time_TC1",
        "Onu_grant_TC1",
        "Onu_start_time_TC2",
        "Onu_grant_TC2",
        "Onu_start_time_TC3",
        "Onu_grant_TC3",
        "Mfu_sfu_rtt",
        "Sfu_start_time_TC1",
        "Sfu_grant_TC1",
        "Sfu_start_time_TC2",
        "Sfu_grant_TC2",
        "Sfu_start_time_TC3",
        "Sfu_grant_TC3",
        "OnuID",
        "SfuID",
        "MfuID",
        "BufferOccupancyTC1",
        "BufferOccupancyTC2",
        "BufferOccupancyTC3",
        "SeqID",
    };
    return (field >= 0 && field < 25) ? fieldNames[field] : nullptr;
}

int gtc_headerDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "Downlink") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "Uplink") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "Ext_pon") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "Int_pon") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "Olt_onu_rtt") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "Onu_start_time_TC1") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "Onu_grant_TC1") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "Onu_start_time_TC2") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "Onu_grant_TC2") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "Onu_start_time_TC3") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "Onu_grant_TC3") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "Mfu_sfu_rtt") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "Sfu_start_time_TC1") == 0) return baseIndex + 12;
    if (strcmp(fieldName, "Sfu_grant_TC1") == 0) return baseIndex + 13;
    if (strcmp(fieldName, "Sfu_start_time_TC2") == 0) return baseIndex + 14;
    if (strcmp(fieldName, "Sfu_grant_TC2") == 0) return baseIndex + 15;
    if (strcmp(fieldName, "Sfu_start_time_TC3") == 0) return baseIndex + 16;
    if (strcmp(fieldName, "Sfu_grant_TC3") == 0) return baseIndex + 17;
    if (strcmp(fieldName, "OnuID") == 0) return baseIndex + 18;
    if (strcmp(fieldName, "SfuID") == 0) return baseIndex + 19;
    if (strcmp(fieldName, "MfuID") == 0) return baseIndex + 20;
    if (strcmp(fieldName, "BufferOccupancyTC1") == 0) return baseIndex + 21;
    if (strcmp(fieldName, "BufferOccupancyTC2") == 0) return baseIndex + 22;
    if (strcmp(fieldName, "BufferOccupancyTC3") == 0) return baseIndex + 23;
    if (strcmp(fieldName, "SeqID") == 0) return baseIndex + 24;
    return base ? base->findField(fieldName) : -1;
}

const char *gtc_headerDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_Downlink
        "bool",    // FIELD_Uplink
        "bool",    // FIELD_Ext_pon
        "bool",    // FIELD_Int_pon
        "double",    // FIELD_Olt_onu_rtt
        "double",    // FIELD_Onu_start_time_TC1
        "double",    // FIELD_Onu_grant_TC1
        "double",    // FIELD_Onu_start_time_TC2
        "double",    // FIELD_Onu_grant_TC2
        "double",    // FIELD_Onu_start_time_TC3
        "double",    // FIELD_Onu_grant_TC3
        "double",    // FIELD_Mfu_sfu_rtt
        "double",    // FIELD_Sfu_start_time_TC1
        "double",    // FIELD_Sfu_grant_TC1
        "double",    // FIELD_Sfu_start_time_TC2
        "double",    // FIELD_Sfu_grant_TC2
        "double",    // FIELD_Sfu_start_time_TC3
        "double",    // FIELD_Sfu_grant_TC3
        "int",    // FIELD_OnuID
        "int",    // FIELD_SfuID
        "int",    // FIELD_MfuID
        "double",    // FIELD_BufferOccupancyTC1
        "double",    // FIELD_BufferOccupancyTC2
        "double",    // FIELD_BufferOccupancyTC3
        "long",    // FIELD_SeqID
    };
    return (field >= 0 && field < 25) ? fieldTypeStrings[field] : nullptr;
}

const char **gtc_headerDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *gtc_headerDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int gtc_headerDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    gtc_header *pp = omnetpp::fromAnyPtr<gtc_header>(object); (void)pp;
    switch (field) {
        case FIELD_Olt_onu_rtt: return pp->getOlt_onu_rttArraySize();
        case FIELD_Onu_start_time_TC1: return pp->getOnu_start_time_TC1ArraySize();
        case FIELD_Onu_grant_TC1: return pp->getOnu_grant_TC1ArraySize();
        case FIELD_Onu_start_time_TC2: return pp->getOnu_start_time_TC2ArraySize();
        case FIELD_Onu_grant_TC2: return pp->getOnu_grant_TC2ArraySize();
        case FIELD_Onu_start_time_TC3: return pp->getOnu_start_time_TC3ArraySize();
        case FIELD_Onu_grant_TC3: return pp->getOnu_grant_TC3ArraySize();
        case FIELD_Mfu_sfu_rtt: return pp->getMfu_sfu_rttArraySize();
        case FIELD_Sfu_start_time_TC1: return pp->getSfu_start_time_TC1ArraySize();
        case FIELD_Sfu_grant_TC1: return pp->getSfu_grant_TC1ArraySize();
        case FIELD_Sfu_start_time_TC2: return pp->getSfu_start_time_TC2ArraySize();
        case FIELD_Sfu_grant_TC2: return pp->getSfu_grant_TC2ArraySize();
        case FIELD_Sfu_start_time_TC3: return pp->getSfu_start_time_TC3ArraySize();
        case FIELD_Sfu_grant_TC3: return pp->getSfu_grant_TC3ArraySize();
        default: return 0;
    }
}

void gtc_headerDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    gtc_header *pp = omnetpp::fromAnyPtr<gtc_header>(object); (void)pp;
    switch (field) {
        case FIELD_Olt_onu_rtt: pp->setOlt_onu_rttArraySize(size); break;
        case FIELD_Onu_start_time_TC1: pp->setOnu_start_time_TC1ArraySize(size); break;
        case FIELD_Onu_grant_TC1: pp->setOnu_grant_TC1ArraySize(size); break;
        case FIELD_Onu_start_time_TC2: pp->setOnu_start_time_TC2ArraySize(size); break;
        case FIELD_Onu_grant_TC2: pp->setOnu_grant_TC2ArraySize(size); break;
        case FIELD_Onu_start_time_TC3: pp->setOnu_start_time_TC3ArraySize(size); break;
        case FIELD_Onu_grant_TC3: pp->setOnu_grant_TC3ArraySize(size); break;
        case FIELD_Mfu_sfu_rtt: pp->setMfu_sfu_rttArraySize(size); break;
        case FIELD_Sfu_start_time_TC1: pp->setSfu_start_time_TC1ArraySize(size); break;
        case FIELD_Sfu_grant_TC1: pp->setSfu_grant_TC1ArraySize(size); break;
        case FIELD_Sfu_start_time_TC2: pp->setSfu_start_time_TC2ArraySize(size); break;
        case FIELD_Sfu_grant_TC2: pp->setSfu_grant_TC2ArraySize(size); break;
        case FIELD_Sfu_start_time_TC3: pp->setSfu_start_time_TC3ArraySize(size); break;
        case FIELD_Sfu_grant_TC3: pp->setSfu_grant_TC3ArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'gtc_header'", field);
    }
}

const char *gtc_headerDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    gtc_header *pp = omnetpp::fromAnyPtr<gtc_header>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string gtc_headerDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    gtc_header *pp = omnetpp::fromAnyPtr<gtc_header>(object); (void)pp;
    switch (field) {
        case FIELD_Downlink: return bool2string(pp->getDownlink());
        case FIELD_Uplink: return bool2string(pp->getUplink());
        case FIELD_Ext_pon: return bool2string(pp->getExt_pon());
        case FIELD_Int_pon: return bool2string(pp->getInt_pon());
        case FIELD_Olt_onu_rtt: return double2string(pp->getOlt_onu_rtt(i));
        case FIELD_Onu_start_time_TC1: return double2string(pp->getOnu_start_time_TC1(i));
        case FIELD_Onu_grant_TC1: return double2string(pp->getOnu_grant_TC1(i));
        case FIELD_Onu_start_time_TC2: return double2string(pp->getOnu_start_time_TC2(i));
        case FIELD_Onu_grant_TC2: return double2string(pp->getOnu_grant_TC2(i));
        case FIELD_Onu_start_time_TC3: return double2string(pp->getOnu_start_time_TC3(i));
        case FIELD_Onu_grant_TC3: return double2string(pp->getOnu_grant_TC3(i));
        case FIELD_Mfu_sfu_rtt: return double2string(pp->getMfu_sfu_rtt(i));
        case FIELD_Sfu_start_time_TC1: return double2string(pp->getSfu_start_time_TC1(i));
        case FIELD_Sfu_grant_TC1: return double2string(pp->getSfu_grant_TC1(i));
        case FIELD_Sfu_start_time_TC2: return double2string(pp->getSfu_start_time_TC2(i));
        case FIELD_Sfu_grant_TC2: return double2string(pp->getSfu_grant_TC2(i));
        case FIELD_Sfu_start_time_TC3: return double2string(pp->getSfu_start_time_TC3(i));
        case FIELD_Sfu_grant_TC3: return double2string(pp->getSfu_grant_TC3(i));
        case FIELD_OnuID: return long2string(pp->getOnuID());
        case FIELD_SfuID: return long2string(pp->getSfuID());
        case FIELD_MfuID: return long2string(pp->getMfuID());
        case FIELD_BufferOccupancyTC1: return double2string(pp->getBufferOccupancyTC1());
        case FIELD_BufferOccupancyTC2: return double2string(pp->getBufferOccupancyTC2());
        case FIELD_BufferOccupancyTC3: return double2string(pp->getBufferOccupancyTC3());
        case FIELD_SeqID: return long2string(pp->getSeqID());
        default: return "";
    }
}

void gtc_headerDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    gtc_header *pp = omnetpp::fromAnyPtr<gtc_header>(object); (void)pp;
    switch (field) {
        case FIELD_Downlink: pp->setDownlink(string2bool(value)); break;
        case FIELD_Uplink: pp->setUplink(string2bool(value)); break;
        case FIELD_Ext_pon: pp->setExt_pon(string2bool(value)); break;
        case FIELD_Int_pon: pp->setInt_pon(string2bool(value)); break;
        case FIELD_Olt_onu_rtt: pp->setOlt_onu_rtt(i,string2double(value)); break;
        case FIELD_Onu_start_time_TC1: pp->setOnu_start_time_TC1(i,string2double(value)); break;
        case FIELD_Onu_grant_TC1: pp->setOnu_grant_TC1(i,string2double(value)); break;
        case FIELD_Onu_start_time_TC2: pp->setOnu_start_time_TC2(i,string2double(value)); break;
        case FIELD_Onu_grant_TC2: pp->setOnu_grant_TC2(i,string2double(value)); break;
        case FIELD_Onu_start_time_TC3: pp->setOnu_start_time_TC3(i,string2double(value)); break;
        case FIELD_Onu_grant_TC3: pp->setOnu_grant_TC3(i,string2double(value)); break;
        case FIELD_Mfu_sfu_rtt: pp->setMfu_sfu_rtt(i,string2double(value)); break;
        case FIELD_Sfu_start_time_TC1: pp->setSfu_start_time_TC1(i,string2double(value)); break;
        case FIELD_Sfu_grant_TC1: pp->setSfu_grant_TC1(i,string2double(value)); break;
        case FIELD_Sfu_start_time_TC2: pp->setSfu_start_time_TC2(i,string2double(value)); break;
        case FIELD_Sfu_grant_TC2: pp->setSfu_grant_TC2(i,string2double(value)); break;
        case FIELD_Sfu_start_time_TC3: pp->setSfu_start_time_TC3(i,string2double(value)); break;
        case FIELD_Sfu_grant_TC3: pp->setSfu_grant_TC3(i,string2double(value)); break;
        case FIELD_OnuID: pp->setOnuID(string2long(value)); break;
        case FIELD_SfuID: pp->setSfuID(string2long(value)); break;
        case FIELD_MfuID: pp->setMfuID(string2long(value)); break;
        case FIELD_BufferOccupancyTC1: pp->setBufferOccupancyTC1(string2double(value)); break;
        case FIELD_BufferOccupancyTC2: pp->setBufferOccupancyTC2(string2double(value)); break;
        case FIELD_BufferOccupancyTC3: pp->setBufferOccupancyTC3(string2double(value)); break;
        case FIELD_SeqID: pp->setSeqID(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'gtc_header'", field);
    }
}

omnetpp::cValue gtc_headerDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    gtc_header *pp = omnetpp::fromAnyPtr<gtc_header>(object); (void)pp;
    switch (field) {
        case FIELD_Downlink: return pp->getDownlink();
        case FIELD_Uplink: return pp->getUplink();
        case FIELD_Ext_pon: return pp->getExt_pon();
        case FIELD_Int_pon: return pp->getInt_pon();
        case FIELD_Olt_onu_rtt: return pp->getOlt_onu_rtt(i);
        case FIELD_Onu_start_time_TC1: return pp->getOnu_start_time_TC1(i);
        case FIELD_Onu_grant_TC1: return pp->getOnu_grant_TC1(i);
        case FIELD_Onu_start_time_TC2: return pp->getOnu_start_time_TC2(i);
        case FIELD_Onu_grant_TC2: return pp->getOnu_grant_TC2(i);
        case FIELD_Onu_start_time_TC3: return pp->getOnu_start_time_TC3(i);
        case FIELD_Onu_grant_TC3: return pp->getOnu_grant_TC3(i);
        case FIELD_Mfu_sfu_rtt: return pp->getMfu_sfu_rtt(i);
        case FIELD_Sfu_start_time_TC1: return pp->getSfu_start_time_TC1(i);
        case FIELD_Sfu_grant_TC1: return pp->getSfu_grant_TC1(i);
        case FIELD_Sfu_start_time_TC2: return pp->getSfu_start_time_TC2(i);
        case FIELD_Sfu_grant_TC2: return pp->getSfu_grant_TC2(i);
        case FIELD_Sfu_start_time_TC3: return pp->getSfu_start_time_TC3(i);
        case FIELD_Sfu_grant_TC3: return pp->getSfu_grant_TC3(i);
        case FIELD_OnuID: return pp->getOnuID();
        case FIELD_SfuID: return pp->getSfuID();
        case FIELD_MfuID: return pp->getMfuID();
        case FIELD_BufferOccupancyTC1: return pp->getBufferOccupancyTC1();
        case FIELD_BufferOccupancyTC2: return pp->getBufferOccupancyTC2();
        case FIELD_BufferOccupancyTC3: return pp->getBufferOccupancyTC3();
        case FIELD_SeqID: return (omnetpp::intval_t)(pp->getSeqID());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'gtc_header' as cValue -- field index out of range?", field);
    }
}

void gtc_headerDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    gtc_header *pp = omnetpp::fromAnyPtr<gtc_header>(object); (void)pp;
    switch (field) {
        case FIELD_Downlink: pp->setDownlink(value.boolValue()); break;
        case FIELD_Uplink: pp->setUplink(value.boolValue()); break;
        case FIELD_Ext_pon: pp->setExt_pon(value.boolValue()); break;
        case FIELD_Int_pon: pp->setInt_pon(value.boolValue()); break;
        case FIELD_Olt_onu_rtt: pp->setOlt_onu_rtt(i,value.doubleValue()); break;
        case FIELD_Onu_start_time_TC1: pp->setOnu_start_time_TC1(i,value.doubleValue()); break;
        case FIELD_Onu_grant_TC1: pp->setOnu_grant_TC1(i,value.doubleValue()); break;
        case FIELD_Onu_start_time_TC2: pp->setOnu_start_time_TC2(i,value.doubleValue()); break;
        case FIELD_Onu_grant_TC2: pp->setOnu_grant_TC2(i,value.doubleValue()); break;
        case FIELD_Onu_start_time_TC3: pp->setOnu_start_time_TC3(i,value.doubleValue()); break;
        case FIELD_Onu_grant_TC3: pp->setOnu_grant_TC3(i,value.doubleValue()); break;
        case FIELD_Mfu_sfu_rtt: pp->setMfu_sfu_rtt(i,value.doubleValue()); break;
        case FIELD_Sfu_start_time_TC1: pp->setSfu_start_time_TC1(i,value.doubleValue()); break;
        case FIELD_Sfu_grant_TC1: pp->setSfu_grant_TC1(i,value.doubleValue()); break;
        case FIELD_Sfu_start_time_TC2: pp->setSfu_start_time_TC2(i,value.doubleValue()); break;
        case FIELD_Sfu_grant_TC2: pp->setSfu_grant_TC2(i,value.doubleValue()); break;
        case FIELD_Sfu_start_time_TC3: pp->setSfu_start_time_TC3(i,value.doubleValue()); break;
        case FIELD_Sfu_grant_TC3: pp->setSfu_grant_TC3(i,value.doubleValue()); break;
        case FIELD_OnuID: pp->setOnuID(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_SfuID: pp->setSfuID(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_MfuID: pp->setMfuID(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_BufferOccupancyTC1: pp->setBufferOccupancyTC1(value.doubleValue()); break;
        case FIELD_BufferOccupancyTC2: pp->setBufferOccupancyTC2(value.doubleValue()); break;
        case FIELD_BufferOccupancyTC3: pp->setBufferOccupancyTC3(value.doubleValue()); break;
        case FIELD_SeqID: pp->setSeqID(omnetpp::checked_int_cast<long>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'gtc_header'", field);
    }
}

const char *gtc_headerDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr gtc_headerDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    gtc_header *pp = omnetpp::fromAnyPtr<gtc_header>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void gtc_headerDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    gtc_header *pp = omnetpp::fromAnyPtr<gtc_header>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'gtc_header'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

