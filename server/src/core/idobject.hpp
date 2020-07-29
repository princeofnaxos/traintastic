/**
 * server/src/core/idobject.hpp
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

#ifndef TRAINTASTIC_SERVER_CORE_IDOBJECT_HPP
#define TRAINTASTIC_SERVER_CORE_IDOBJECT_HPP

#include "object.hpp"
#include "property.hpp"
#include <traintastic/enum/traintasticmode.hpp>

#define CREATE(T) \
  static std::shared_ptr<T> create(const std::weak_ptr<World>& world, std::string_view _id) \
  { \
    auto obj = std::make_shared<T>(world, _id); \
    obj->addToWorld(); \
    return obj; \
  }

class World;

class IdObject : public Object
{
  protected:
    std::weak_ptr<World> m_world;

    IdObject(const std::weak_ptr<World>& world, std::string_view _id);
    virtual void addToWorld();
    void worldEvent(WorldState state, WorldEvent event) override;

    void logDebug(const std::string& message);
    void logInfo(const std::string& message);
    void logNotice(const std::string& message);
    void logWarning(const std::string& message);
    void logError(const std::string& message);
    void logCritical(const std::string& message);
    void logFatal(const std::string& message);

  public:
    Property<std::string> id;

    ~IdObject() override;

    const std::weak_ptr<World>& world() const { return m_world; }
};

#endif
