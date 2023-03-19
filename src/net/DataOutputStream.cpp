#include "DataOutputStream.h"

namespace net
{
	const char* DataOutputStream::getData() const
	{
		return m_data;
	}

	uint16_t DataOutputStream::getPosition() const
	{
		return m_pos;
	}

	uint32_t DataOutputStream::getSize() const
	{
		return m_size;
	}

	void DataOutputStream::flush()
	{
		m_pos = 0;

		for (uint32_t i = 0; i < m_size; i++)
		{
			m_data[i] = 0;
		}
	}

	void DataOutputStream::writeBoolean(bool value)
	{
		writeByte(value ? 1 : 0);
	}

	void DataOutputStream::writeDouble(double value)
	{
		char* p = reinterpret_cast<char*>(&value);
		for (int i = 0; i < sizeof(double); i++)
		{
			m_data[m_pos + i] = p[sizeof(double) - i - 1];
		}
		m_pos += sizeof(double);
	}

	void DataOutputStream::writeFloat(float value)
	{
		char* p = reinterpret_cast<char*>(&value);
		for (int i = 0; i < sizeof(float); i++)
		{
			m_data[m_pos + i] = p[sizeof(float) - i - 1];
		}
		m_pos += sizeof(float);
	}

	void DataOutputStream::writeFully(const char* buf, uint32_t len)
	{
		if (m_pos + len > m_size)
		{
			throw std::out_of_range("DataOutputStream buffer overflow");
		}
		memcpy(&m_data[m_pos], buf, len);
		m_pos += len;
	}

	void DataOutputStream::writeByte(char value)
	{
		m_data[m_pos++] = value;
	}

	void DataOutputStream::writeShort(uint16_t value)
	{
		char* p = reinterpret_cast<char*>(&value);
		for (int i = 0; i < sizeof(uint16_t); i++)
		{
			m_data[m_pos + i] = p[sizeof(uint16_t) - i - 1];
		}
		m_pos += sizeof(uint16_t);
	}

	void DataOutputStream::writeInt(uint32_t value)
	{
		char* p = reinterpret_cast<char*>(&value);
		for (uint32_t i = 0; i < sizeof(uint32_t); i++)
		{
			m_data[m_pos + i] = p[sizeof(uint32_t) - i - 1];
		}
		m_pos += sizeof(uint32_t);
	}

	void DataOutputStream::writeLong(uint64_t value)
	{
		char* p = reinterpret_cast<char*>(&value);
		for (uint32_t i = 0; i < sizeof(uint64_t); i++)
		{
			m_data[m_pos + i] = p[sizeof(uint64_t) - i - 1];
		}
		m_pos += sizeof(uint64_t);
	}

	void DataOutputStream::writeUTF(const std::string& str)
	{
		uint32_t length = static_cast<uint32_t>(str.length());
		writeShort(length);
		writeFully(str.c_str(), length);
	}

	void DataOutputStream::skipBytes(const int32_t len)
	{
		m_pos = std::min(m_pos + len, m_size);
	}
}