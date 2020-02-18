/**
 * shared/src/enum/propertytype.hpp
 *
 * This file is part of the traintastic source code.
 *
 * Copyright (C) 2019-2020 Reinder Feenstra
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

#ifndef SHARED_ENUM_ATTRIBUTENAME_HPP
#define SHARED_ENUM_ATTRIBUTENAME_HPP

#include <cstdint>

enum class AttributeName : uint16_t
{
  Visible = 0,
  Enabled = 1,
  Min = 2,
  Max = 3,
  Category = 4,
  ObjectEditor = 5,
  Values = 6,
  SubObject = 7,
};

#endif
