#pragma once

#include <cstring>
#include <iostream>

namespace net
{
	class DataInputStream
	{
	private:
		const char* m_data;
		int m_pos;

	public:
		DataInputStream(const char* data) : m_data(data), m_pos(0) {}

		bool readBoolean();

		double readDouble();

		float readFloat();

		void readFully(char* buf, int len);

		std::string readUTF();

		void skipBytes(int len);

		char readByte();

		uint16_t readShort();

		uint32_t readInt();

		uint64_t readLong();
	};
}
