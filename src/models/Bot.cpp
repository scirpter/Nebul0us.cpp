#include "Bot.h"

namespace models
{
    Bot::Bot(const uint8_t uniquifier, const std::string name, const std::string ticket, const std::string ip, const uint16_t port) : m_uniquifier(uniquifier)
    {
        p_control = new specific::Control{};
        p_blob_data = new specific::BlobData{name, ticket};
        p_net = new specific::Net{ip, port};
    }
}