#include "CommonPacket.h"

void CommonPacket::Serialize(SerBuffer& buffer) const
{
    buffer << type;
}

void CommonPacket::Deserialize(SerBuffer& buffer)
{
    buffer >> type;
}
