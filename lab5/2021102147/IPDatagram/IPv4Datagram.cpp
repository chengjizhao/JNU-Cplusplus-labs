#include "IPv4Datagram.h"

#include <iostream>
#include <cstdint>
#include <vector>
#include <iomanip>


IPv4Datagram::IPv4Datagram()
    : version_(4), 
    headerLength_(5), 
    totalLength_(20), 
    identification_(0), 
    flagsFragmentOffset_(0), 
    ttl_(0), protocol_(0), 
    checksum_(0), 
    sourceIP_(0), 
    destinationIP_(0)
{}

IPv4Datagram::~IPv4Datagram()
{}

uint8_t IPv4Datagram::getVersion() const {
    return version_;
}

uint8_t IPv4Datagram::getHeaderLength() const {
    return headerLength_;
}

uint16_t IPv4Datagram::getTotalLength() const {
    return totalLength_;
}

uint16_t IPv4Datagram::getIdentification() const {
    return identification_;
}

uint16_t IPv4Datagram::getFlagsFragmentOffset() const {
    return flagsFragmentOffset_;
}

uint8_t IPv4Datagram::getTTL() const {
    return ttl_;
}

uint8_t IPv4Datagram::getProtocol() const {
    return protocol_;
}

uint16_t IPv4Datagram::getChecksum() const {
    return checksum_;
}

uint32_t IPv4Datagram::getSourceIP() const {
    return sourceIP_;
}

uint32_t IPv4Datagram::getDestinationIP() const {
    return destinationIP_;
}

const std::vector<uint8_t>& IPv4Datagram::getPayload() const {
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
