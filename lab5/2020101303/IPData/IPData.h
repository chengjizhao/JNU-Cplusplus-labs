#ifndef IPDATA_H
#define IPDATA_H

#include <cstdint>
#include <vector>
using namespace std;

class IPData
{
    private:
            uint8_t version_HeaderLength;
            uint8_t TOS;
            uint16_t TotalLength;
            uint16_t Identification;
            uint16_t Flag_FragmentationOffset;
            uint8_t TTL;
            uint8_t Protocol;
            uint8_t HeaderChecksum;
            uint32_t Source_IP_adress;
            uint32_t Destination_IP_adress;
            vector<uint8_t> Data;
    public:
            IPData();
            IPData(uint8_t m_version_HeaderLength, uint8_t m_TOS, uint16_t m_TotalLength, uint16_t m_Identification, 
            uint16_t m_Flag_FragmentationOffset, uint8_t m_TTL, uint8_t m_Protocol, uint8_t m_HeaderChecksum, uint32_t m_Source_IP_adress, 
            uint32_t m_Destination_IP_adress, const vector<uint8_t> m_Data);
            vector<uint8_t> getData() const;
};

#endif