/**
 * server/src/enum/xpressnetcommandstation.hpp
 *
 * This file is part of the traintastic source code.
 *
 * Copyright (C) 2019 Reinder Feenstra
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef SERVER_ENUM_XPRESSNETCOMMANDSTATION_HPP
#define SERVER_ENUM_XPRESSNETCOMMANDSTATION_HPP

#include <enum/xpressnetcommandstation.hpp>
#include <nlohmann/json.hpp>
#include "../lua/enum.hpp"

NLOHMANN_JSON_SERIALIZE_ENUM(XpressNetCommandStation,
{
  {XpressNetCommandStation::Custom, "custom"},
  {XpressNetCommandStation::Roco10764, "roco_10764"},
})

LUA_ENUM(XpressNetCommandStation, 2,
{
  {XpressNetCommandStation::Custom, "CUSTOM"},
  {XpressNetCommandStation::Roco10764, "ROCO_10764"},
})

#endif
