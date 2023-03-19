#pragma once

#include "../common.h"

#include <cstdint>
#include <map>
#include <string>

namespace models
{
    struct World
    {
        std::string m_name;
        uint16_t m_time_left;
        not_implemented_t m_game_mode = nullptr;
        uint8_t m_max_players;
        uint8_t m_players_ct;
        uint8_t m_spectators_ct;
        uint8_t m_tick;
        float m_map_raw_size;
        not_implemented_t m_map_size = nullptr;

        WORLD_OBJS<not_implemented_t> m_ejections;
        WORLD_OBJS<not_implemented_t> m_players;
        WORLD_OBJS<not_implemented_t> m_dots;
        WORLD_OBJS<not_implemented_t> m_items;
        WORLD_OBJS<not_implemented_t> m_spells;
        WORLD_OBJS<not_implemented_t> m_holes;
    };
}