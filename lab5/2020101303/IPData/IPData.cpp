#include "IPData.h"
#include <cstdint>
#include <vector>
using namespace std;

IPData::IPData()
{
    version_HeaderLength = 0b00101010; //随便设的默认值
    TOS = 0;
    TotalLength = 0;
    Identification = 0;
    Flag_FragmentationOffset = 0;
    TTL = 0;
    Protocol = 0;
    HeaderChecksum = 0;
    Source_IP_adress = 0;
    Destination_IP_adress = 0;
}

IPData::IPData(uint8_t m_version_HeaderLength, uint8_t m_TOS, uint16_t m_TotalLength, uint16_t m_Identification, 
              uint16_t m_Flag_FragmentationOffset, uint8_t m_TTL, uint8_t m_Protocol, uint8_t m_HeaderChecksum, uint32_t m_Source_IP_adress, 
              uint32_t m_Destination_IP_adress, const vector<uint8_t> m_Data)
{
    version_HeaderLength = m_version_HeaderLength;
    TOS = m_TOS;
    TotalLength = m_TotalLength;
    Identification = m_Identification;
    Flag_FragmentationOffset = m_Flag_FragmentationOffset;
    TTL = m_TTL;
    Protocol = m_Protocol;
    HeaderChecksum = m_HeaderChecksum;
    Source_IP_adress = m_Source_IP_adress;
    Destination_IP_adress = m_Destination_IP_adress;
    Data = m_Data;
}

vector<uint8_t> IPData::getData() const
{
    return Data;
}