#pragma once

#include <cstring>
#include <iostream>

namespace net
{
	class DataOutputStream
	{
	private:
		char* m_data;
		uint32_t m_pos;
		uint32_t m_size;

	public:
		DataOutputStream(uint32_t size) : m_data(new char[size]), m_pos(0), m_size(size) {}

		~DataOutputStream()
		{
			delete[] m_data;
		}

		const char* getData() const;

		uint16_t getPosition() const;

		uint32_t getSize() const;

		void flush();

		void writeBoolean(bool value);

		void writeDouble(double value);

		void writeFloat(float value);

		void writeFully(const char* buf, uint32_t len);

		void writeByte(char value);

		void writeShort(uint16_t value);

		void writeInt(uint32_t value);

		void writeLong(uint64_t value);

		void writeUTF(const std::string& str);

		void skipBytes(const int32_t len);
	};
}
