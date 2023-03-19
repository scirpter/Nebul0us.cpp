#pragma once

#include "../common.h"

#include <cstdint>
#include <string>

namespace specifications
{
    struct Control
    {
        uint8_t m_speed;
        uint8_t m_cached_speed;
        uint8_t m_angle;
        uint8_t m_cached_angle;
        uint8_t m_eject_ct;
        uint8_t m_split_ct;
        uint8_t m_drop_ct;
    };

    struct BlobData
    {
        std::string name;
        std::string ticket;
        not_implemented_t m_skin = nullptr;
        not_implemented_t m_rainbow_cycle = nullptr;
        not_implemented_t m_name_font = nullptr;
        not_implemented_t m_halo = nullptr;
        not_implemented_t m_hat = nullptr;
        not_implemented_t m_particle = nullptr;
        not_implemented_t m_visibility = nullptr;
        not_implemented_t m_eject_skin = nullptr;
    };
}

namespace models
{
    class Bot
    {
    };
}
