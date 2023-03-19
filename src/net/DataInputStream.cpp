#include "DataInputStream.h"

namespace net
{
	bool DataInputStream::readBoolean()
	{
		return readByte() != 0;
	};
	double DataInputStream::readDouble()
	{
		double value;
		char* p = reinterpret_cast<char*>(&value);
		for (int i = 0; i < sizeof(double); i++)
		{
			p[i] = m_data[m_pos + sizeof(double) - i - 1];
		}
		m_pos += sizeof(double);
		return value;
	}

	float DataInputStream::readFloat()
	{
		float value;
		char* p = reinterpret_cast<char*>(&value);
		for (int i = 0; i < sizeof(float); i++)
		{
			p[i] = m_data[m_pos + sizeof(float) - i - 1];
		}
		m_pos += sizeof(float);
		return value;
	}

	void DataInputStream::readFully(char* buf, int len)
	{
		if (m_pos + len > std::strlen(m_data))
		{
			throw std::out_of_range("Not enough data left to read fully.");
		}
		memcpy(buf, &m_data[m_pos], len);
		m_pos += len;
	}

	std::string DataInputStream::readUTF()
	{
		uint16_t length = readShort();
		std::string str(&m_data[m_pos], length);
		m_pos += length;
		return str;
	}

	void DataInputStream::skipBytes(int len)
	{
		m_pos = std::min(m_pos + len, (int)std::strlen(m_data));
	}

	char DataInputStream::readByte()
	{
		char value = m_data[m_pos];
		m_pos += sizeof(char);
		return value;
	}

	uint16_t DataInputStream::readShort()
	{
		uint16_t value;
		char* p = reinterpret_cast<char*>(&value);
		for (int i = 0; i < sizeof(uint16_t); i++)
		{
			p[i] = m_data[m_pos + sizeof(uint16_t) - i - 1];
		}
		m_pos += sizeof(uint16_t);
		return value;
	}

	uint32_t DataInputStream::readInt()
	{
		uint32_t value;
		char* p = reinterpret_cast<char*>(&value);
		for (uint32_t i = 0; i < sizeof(uint32_t); i++)
		{
			p[i] = m_data[m_pos + sizeof(uint32_t) - i - 1];
		}
		m_pos += sizeof(uint32_t);
		return value;
	}

	uint64_t DataInputStream::readLong()
	{
		uint64_t value;
		char* p = reinterpret_cast<char*>(&value);
		for (int i = 0; i < sizeof(uint64_t); i++)
		{
			p[i] = m_data[m_pos + sizeof(uint64_t) - i - 1];
		}
		m_pos += sizeof(uint64_t);
		return value;
	}
}