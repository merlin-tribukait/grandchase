#ifndef _COMMONPACKET_H_
#define _COMMONPACKET_H_

#include "Serializer/SerBuffer.h"

// Base packet class
class CommonPacket
{
public:
    CommonPacket() {}
    virtual ~CommonPacket() {}
    
    virtual void Serialize(SerBuffer& buffer) const {}
    virtual void Deserialize(SerBuffer& buffer) {}
    
    // Common packet types
    enum PacketType
    {
        PACKET_NONE = 0,
        PACKET_DATA = 1,
        PACKET_CONTROL = 2
    };
    
protected:
    PacketType type;
};

#endif // _COMMONPACKET_H_
