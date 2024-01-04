#pragma once

#include <cstdint>
#include <vector>

class IPv4Datagram {
public:
    // 构造函数
    IPv4Datagram();
    IPv4Datagram(uint8_t version, uint8_t headerLength, uint16_t totalLength, uint16_t identification, uint16_t flagsFragmentOffset,
        uint8_t ttl, uint8_t protocol, uint16_t checksum, uint32_t sourceIP, uint32_t destinationIP,
        const std::vector<uint8_t>& payload);
    ~IPv4Datagram();

    // 获取版本号
    uint8_t getVersion() const;

    // 获取头部长度
    uint8_t getHeaderLength() const;

    // 获取总长度
    uint16_t getTotalLength() const;

    // 获取标识
    uint16_t getIdentification() const;

    // 获取标志和分段偏移
    uint16_t getFlagsFragmentOffset() const;

    // 获取TTL
    uint8_t getTTL() const;

    // 获取协议
    uint8_t getProtocol() const;

    // 获取校验和
    uint16_t getChecksum() const;

    // 获取源IP地址
    uint32_t getSourceIP() const;

    // 获取目标IP地址
    uint32_t getDestinationIP() const;

    // 获取负载数据
    const std::vector<uint8_t>& getPayload() const;

private:
    uint8_t version_;
    uint8_t headerLength_;
    uint16_t totalLength_;
    uint16_t identification_;
    uint16_t flagsFragmentOffset_;
    uint8_t ttl_;
    uint8_t protocol_;
    uint16_t checksum_;
    uint32_t sourceIP_;
    uint32_t destinationIP_;
    std::vector<uint8_t> payload_;
};