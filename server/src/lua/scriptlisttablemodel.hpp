/**
 * server/src/lua/scriptlisttablemodel.hpp
 *
 * This file is part of the traintastic source code.
 *
 * Copyright (C) 2020 Reinder Feenstra
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

#ifndef SERVER_LUA_SCRIPTLISTTABLEMODEL_HPP
#define SERVER_LUA_SCRIPTLISTTABLEMODEL_HPP

#include "../core/objectlisttablemodel.hpp"
#include "script.hpp"

namespace Lua {

class ScriptList;

class ScriptListTableModel : public ObjectListTableModel<Script>
{
  friend class ScriptList;

  protected:
    void propertyChanged(AbstractProperty& property, uint32_t row) final;

  public:
    CLASS_ID("lua.script_list_table_model")

    static bool isListedProperty(const std::string& name);

    ScriptListTableModel(ScriptList& list);

    std::string getText(uint32_t column, uint32_t row) const final;
};

};

#endif
