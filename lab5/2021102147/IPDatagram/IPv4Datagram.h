#pragma once

#include <cstdint>
#include <vector>

class IPv4Datagram {
public:
    // ���캯��
    IPv4Datagram();
    IPv4Datagram(uint8_t version, uint8_t headerLength, uint16_t totalLength, uint16_t identification, uint16_t flagsFragmentOffset,
        uint8_t ttl, uint8_t protocol, uint16_t checksum, uint32_t sourceIP, uint32_t destinationIP,
        const std::vector<uint8_t>& payload);
    ~IPv4Datagram();

    // ��ȡ�汾��
    uint8_t getVersion() const;

    // ��ȡͷ������
    uint8_t getHeaderLength() const;

    // ��ȡ�ܳ���
    uint16_t getTotalLength() const;

    // ��ȡ��ʶ
    uint16_t getIdentification() const;

    // ��ȡ��־�ͷֶ�ƫ��
    uint16_t getFlagsFragmentOffset() const;

    // ��ȡTTL
    uint8_t getTTL() const;

    // ��ȡЭ��
    uint8_t getProtocol() const;

    // ��ȡУ���
    uint16_t getChecksum() const;

    // ��ȡԴIP��ַ
    uint32_t getSourceIP() const;

    // ��ȡĿ��IP��ַ
    uint32_t getDestinationIP() const;

    // ��ȡ��������
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