#include "IP.h"

#include <iostream>
#include <cstdint>
#include <vector>
#include <iomanip>



uint8_t IPv4Datagram::getVersion() 
{
    return version_;
}

uint8_t IPv4Datagram::getHeaderLength()
{
    return headerLength_;
}

uint16_t IPv4Datagram::getTotalLength() 
{
    return totalLength_;
}

uint16_t IPv4Datagram::getIdentification() 
{
    return identification_;
}

uint16_t IPv4Datagram::getFlagsFragmentOffset() 
{
    return flagsFragmentOffset_;
}

uint8_t IPv4Datagram::getTTL()  {
    return ttl_;
}

uint8_t IPv4Datagram::getProtocol()  {
    return protocol_;
}

uint16_t IPv4Datagram::getChecksum()  {
    return checksum_;
}

uint32_t IPv4Datagram::getSourceIP()  {
    return sourceIP_;
}

uint32_t IPv4Datagram::getDestinationIP()  {
    return destinationIP_;
}

const std::vector<uint8_t>& IPv4Datagram::getPayload()  {
    return payload_;
}



IPv4Datagram::IPv4Datagram(uint8_t version, uint8_t headerLength, uint16_t totalLength, uint16_t identification, uint16_t flagsFragmentOffset,
    uint8_t ttl, uint8_t protocol, uint16_t checksum, uint32_t sourceIP, uint32_t destinationIP,
    const std::vector<uint8_t>& payload)
    : version_(version),
    headerLength_(headerLength),
    totalLength_(totalLength),
    identification_(identification),
    flagsFragmentOffset_(flagsFragmentOffset),
    ttl_(ttl),
    protocol_(protocol),
    checksum_(checksum),
    sourceIP_(sourceIP),
    destinationIP_(destinationIP),
    payload_(payload)
{};