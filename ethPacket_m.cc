//
// Generated file, do not edit! Created by opp_msgtool 6.0 from ethPacket.msg.
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
#include "ethPacket_m.h"

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

Register_Class(ethPacket)

ethPacket::ethPacket(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

ethPacket::ethPacket(const ethPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

ethPacket::~ethPacket()
{
}

ethPacket& ethPacket::operator=(const ethPacket& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void ethPacket::copy(const ethPacket& other)
{
    this->GenerationTime = other.GenerationTime;
    this->WapArrivalTime = other.WapArrivalTime;
    this->WapDepartureTime = other.WapDepartureTime;
    this->SfuArrivalTime = other.SfuArrivalTime;
    this->SfuDepartureTime = other.SfuDepartureTime;
    this->OnuArrivalTime = other.OnuArrivalTime;
    this->OnuDepartureTime = other.OnuDepartureTime;
    this->OnuId = other.OnuId;
    this->SfuId = other.SfuId;
    this->MfuId = other.MfuId;
    this->TContId = other.TContId;
    this->FragmentCount = other.FragmentCount;
}

void ethPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->GenerationTime);
    doParsimPacking(b,this->WapArrivalTime);
    doParsimPacking(b,this->WapDepartureTime);
    doParsimPacking(b,this->SfuArrivalTime);
    doParsimPacking(b,this->SfuDepartureTime);
    doParsimPacking(b,this->OnuArrivalTime);
    doParsimPacking(b,this->OnuDepartureTime);
    doParsimPacking(b,this->OnuId);
    doParsimPacking(b,this->SfuId);
    doParsimPacking(b,this->MfuId);
    doParsimPacking(b,this->TContId);
    doParsimPacking(b,this->FragmentCount);
}

void ethPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->GenerationTime);
    doParsimUnpacking(b,this->WapArrivalTime);
    doParsimUnpacking(b,this->WapDepartureTime);
    doParsimUnpacking(b,this->SfuArrivalTime);
    doParsimUnpacking(b,this->SfuDepartureTime);
    doParsimUnpacking(b,this->OnuArrivalTime);
    doParsimUnpacking(b,this->OnuDepartureTime);
    doParsimUnpacking(b,this->OnuId);
    doParsimUnpacking(b,this->SfuId);
    doParsimUnpacking(b,this->MfuId);
    doParsimUnpacking(b,this->TContId);
    doParsimUnpacking(b,this->FragmentCount);
}

omnetpp::simtime_t ethPacket::getGenerationTime() const
{
    return this->GenerationTime;
}

void ethPacket::setGenerationTime(omnetpp::simtime_t GenerationTime)
{
    this->GenerationTime = GenerationTime;
}

omnetpp::simtime_t ethPacket::getWapArrivalTime() const
{
    return this->WapArrivalTime;
}

void ethPacket::setWapArrivalTime(omnetpp::simtime_t WapArrivalTime)
{
    this->WapArrivalTime = WapArrivalTime;
}

omnetpp::simtime_t ethPacket::getWapDepartureTime() const
{
    return this->WapDepartureTime;
}

void ethPacket::setWapDepartureTime(omnetpp::simtime_t WapDepartureTime)
{
    this->WapDepartureTime = WapDepartureTime;
}

omnetpp::simtime_t ethPacket::getSfuArrivalTime() const
{
    return this->SfuArrivalTime;
}

void ethPacket::setSfuArrivalTime(omnetpp::simtime_t SfuArrivalTime)
{
    this->SfuArrivalTime = SfuArrivalTime;
}

omnetpp::simtime_t ethPacket::getSfuDepartureTime() const
{
    return this->SfuDepartureTime;
}

void ethPacket::setSfuDepartureTime(omnetpp::simtime_t SfuDepartureTime)
{
    this->SfuDepartureTime = SfuDepartureTime;
}

omnetpp::simtime_t ethPacket::getOnuArrivalTime() const
{
    return this->OnuArrivalTime;
}

void ethPacket::setOnuArrivalTime(omnetpp::simtime_t OnuArrivalTime)
{
    this->OnuArrivalTime = OnuArrivalTime;
}

omnetpp::simtime_t ethPacket::getOnuDepartureTime() const
{
    return this->OnuDepartureTime;
}

void ethPacket::setOnuDepartureTime(omnetpp::simtime_t OnuDepartureTime)
{
    this->OnuDepartureTime = OnuDepartureTime;
}

int ethPacket::getOnuId() const
{
    return this->OnuId;
}

void ethPacket::setOnuId(int OnuId)
{
    this->OnuId = OnuId;
}

int ethPacket::getSfuId() const
{
    return this->SfuId;
}

void ethPacket::setSfuId(int SfuId)
{
    this->SfuId = SfuId;
}

int ethPacket::getMfuId() const
{
    return this->MfuId;
}

void ethPacket::setMfuId(int MfuId)
{
    this->MfuId = MfuId;
}

int ethPacket::getTContId() const
{
    return this->TContId;
}

void ethPacket::setTContId(int TContId)
{
    this->TContId = TContId;
}

int ethPacket::getFragmentCount() const
{
    return this->FragmentCount;
}

void ethPacket::setFragmentCount(int FragmentCount)
{
    this->FragmentCount = FragmentCount;
}

class ethPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_GenerationTime,
        FIELD_WapArrivalTime,
        FIELD_WapDepartureTime,
        FIELD_SfuArrivalTime,
        FIELD_SfuDepartureTime,
        FIELD_OnuArrivalTime,
        FIELD_OnuDepartureTime,
        FIELD_OnuId,
        FIELD_SfuId,
        FIELD_MfuId,
        FIELD_TContId,
        FIELD_FragmentCount,
    };
  public:
    ethPacketDescriptor();
    virtual ~ethPacketDescriptor();

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

Register_ClassDescriptor(ethPacketDescriptor)

ethPacketDescriptor::ethPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(ethPacket)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

ethPacketDescriptor::~ethPacketDescriptor()
{
    delete[] propertyNames;
}

bool ethPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ethPacket *>(obj)!=nullptr;
}

const char **ethPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ethPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ethPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 12+base->getFieldCount() : 12;
}

unsigned int ethPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_GenerationTime
        FD_ISEDITABLE,    // FIELD_WapArrivalTime
        FD_ISEDITABLE,    // FIELD_WapDepartureTime
        FD_ISEDITABLE,    // FIELD_SfuArrivalTime
        FD_ISEDITABLE,    // FIELD_SfuDepartureTime
        FD_ISEDITABLE,    // FIELD_OnuArrivalTime
        FD_ISEDITABLE,    // FIELD_OnuDepartureTime
        FD_ISEDITABLE,    // FIELD_OnuId
        FD_ISEDITABLE,    // FIELD_SfuId
        FD_ISEDITABLE,    // FIELD_MfuId
        FD_ISEDITABLE,    // FIELD_TContId
        FD_ISEDITABLE,    // FIELD_FragmentCount
    };
    return (field >= 0 && field < 12) ? fieldTypeFlags[field] : 0;
}

const char *ethPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "GenerationTime",
        "WapArrivalTime",
        "WapDepartureTime",
        "SfuArrivalTime",
        "SfuDepartureTime",
        "OnuArrivalTime",
        "OnuDepartureTime",
        "OnuId",
        "SfuId",
        "MfuId",
        "TContId",
        "FragmentCount",
    };
    return (field >= 0 && field < 12) ? fieldNames[field] : nullptr;
}

int ethPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "GenerationTime") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "WapArrivalTime") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "WapDepartureTime") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "SfuArrivalTime") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "SfuDepartureTime") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "OnuArrivalTime") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "OnuDepartureTime") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "OnuId") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "SfuId") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "MfuId") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "TContId") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "FragmentCount") == 0) return baseIndex + 11;
    return base ? base->findField(fieldName) : -1;
}

const char *ethPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "omnetpp::simtime_t",    // FIELD_GenerationTime
        "omnetpp::simtime_t",    // FIELD_WapArrivalTime
        "omnetpp::simtime_t",    // FIELD_WapDepartureTime
        "omnetpp::simtime_t",    // FIELD_SfuArrivalTime
        "omnetpp::simtime_t",    // FIELD_SfuDepartureTime
        "omnetpp::simtime_t",    // FIELD_OnuArrivalTime
        "omnetpp::simtime_t",    // FIELD_OnuDepartureTime
        "int",    // FIELD_OnuId
        "int",    // FIELD_SfuId
        "int",    // FIELD_MfuId
        "int",    // FIELD_TContId
        "int",    // FIELD_FragmentCount
    };
    return (field >= 0 && field < 12) ? fieldTypeStrings[field] : nullptr;
}

const char **ethPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *ethPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int ethPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ethPacket *pp = omnetpp::fromAnyPtr<ethPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ethPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ethPacket *pp = omnetpp::fromAnyPtr<ethPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ethPacket'", field);
    }
}

const char *ethPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ethPacket *pp = omnetpp::fromAnyPtr<ethPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ethPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ethPacket *pp = omnetpp::fromAnyPtr<ethPacket>(object); (void)pp;
    switch (field) {
        case FIELD_GenerationTime: return simtime2string(pp->getGenerationTime());
        case FIELD_WapArrivalTime: return simtime2string(pp->getWapArrivalTime());
        case FIELD_WapDepartureTime: return simtime2string(pp->getWapDepartureTime());
        case FIELD_SfuArrivalTime: return simtime2string(pp->getSfuArrivalTime());
        case FIELD_SfuDepartureTime: return simtime2string(pp->getSfuDepartureTime());
        case FIELD_OnuArrivalTime: return simtime2string(pp->getOnuArrivalTime());
        case FIELD_OnuDepartureTime: return simtime2string(pp->getOnuDepartureTime());
        case FIELD_OnuId: return long2string(pp->getOnuId());
        case FIELD_SfuId: return long2string(pp->getSfuId());
        case FIELD_MfuId: return long2string(pp->getMfuId());
        case FIELD_TContId: return long2string(pp->getTContId());
        case FIELD_FragmentCount: return long2string(pp->getFragmentCount());
        default: return "";
    }
}

void ethPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ethPacket *pp = omnetpp::fromAnyPtr<ethPacket>(object); (void)pp;
    switch (field) {
        case FIELD_GenerationTime: pp->setGenerationTime(string2simtime(value)); break;
        case FIELD_WapArrivalTime: pp->setWapArrivalTime(string2simtime(value)); break;
        case FIELD_WapDepartureTime: pp->setWapDepartureTime(string2simtime(value)); break;
        case FIELD_SfuArrivalTime: pp->setSfuArrivalTime(string2simtime(value)); break;
        case FIELD_SfuDepartureTime: pp->setSfuDepartureTime(string2simtime(value)); break;
        case FIELD_OnuArrivalTime: pp->setOnuArrivalTime(string2simtime(value)); break;
        case FIELD_OnuDepartureTime: pp->setOnuDepartureTime(string2simtime(value)); break;
        case FIELD_OnuId: pp->setOnuId(string2long(value)); break;
        case FIELD_SfuId: pp->setSfuId(string2long(value)); break;
        case FIELD_MfuId: pp->setMfuId(string2long(value)); break;
        case FIELD_TContId: pp->setTContId(string2long(value)); break;
        case FIELD_FragmentCount: pp->setFragmentCount(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ethPacket'", field);
    }
}

omnetpp::cValue ethPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ethPacket *pp = omnetpp::fromAnyPtr<ethPacket>(object); (void)pp;
    switch (field) {
        case FIELD_GenerationTime: return pp->getGenerationTime().dbl();
        case FIELD_WapArrivalTime: return pp->getWapArrivalTime().dbl();
        case FIELD_WapDepartureTime: return pp->getWapDepartureTime().dbl();
        case FIELD_SfuArrivalTime: return pp->getSfuArrivalTime().dbl();
        case FIELD_SfuDepartureTime: return pp->getSfuDepartureTime().dbl();
        case FIELD_OnuArrivalTime: return pp->getOnuArrivalTime().dbl();
        case FIELD_OnuDepartureTime: return pp->getOnuDepartureTime().dbl();
        case FIELD_OnuId: return pp->getOnuId();
        case FIELD_SfuId: return pp->getSfuId();
        case FIELD_MfuId: return pp->getMfuId();
        case FIELD_TContId: return pp->getTContId();
        case FIELD_FragmentCount: return pp->getFragmentCount();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ethPacket' as cValue -- field index out of range?", field);
    }
}

void ethPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ethPacket *pp = omnetpp::fromAnyPtr<ethPacket>(object); (void)pp;
    switch (field) {
        case FIELD_GenerationTime: pp->setGenerationTime(value.doubleValue()); break;
        case FIELD_WapArrivalTime: pp->setWapArrivalTime(value.doubleValue()); break;
        case FIELD_WapDepartureTime: pp->setWapDepartureTime(value.doubleValue()); break;
        case FIELD_SfuArrivalTime: pp->setSfuArrivalTime(value.doubleValue()); break;
        case FIELD_SfuDepartureTime: pp->setSfuDepartureTime(value.doubleValue()); break;
        case FIELD_OnuArrivalTime: pp->setOnuArrivalTime(value.doubleValue()); break;
        case FIELD_OnuDepartureTime: pp->setOnuDepartureTime(value.doubleValue()); break;
        case FIELD_OnuId: pp->setOnuId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_SfuId: pp->setSfuId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_MfuId: pp->setMfuId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_TContId: pp->setTContId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_FragmentCount: pp->setFragmentCount(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ethPacket'", field);
    }
}

const char *ethPacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr ethPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ethPacket *pp = omnetpp::fromAnyPtr<ethPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ethPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ethPacket *pp = omnetpp::fromAnyPtr<ethPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ethPacket'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

