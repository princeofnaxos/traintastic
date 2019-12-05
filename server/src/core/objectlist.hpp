/**
 * server/src/core/objectlist.hpp
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

#ifndef SERVER_CORE_OBJECTLIST_HPP
#define SERVER_CORE_OBJECTLIST_HPP

#include "idobject.hpp"
#include "table.hpp"

template<typename T>
class ObjectListTableModel;

template<typename T>
class ObjectList : public IdObject, public Table
{
  friend class ObjectListTableModel<T>;

  static_assert(std::is_base_of<IdObject, T>::value);

  public:
    using Items = std::vector<std::shared_ptr<T>>;
    using const_iterator = typename Items::const_iterator;

  protected:
    Items m_items;
    std::vector<ObjectListTableModel<T>*> m_models;

    void rowCountChanged()
    {
      const auto size = m_items.size();
      length = size;
      for(auto& model : m_models)
        model->setRowCount(size);
    }

  public:

    Property<uint32_t> length;

    ObjectList(const std::weak_ptr<World>& world, const std::string& _id) :
      IdObject{world, _id},
      length{this, "length", 0, PropertyFlags::AccessRRR}
    {
    }

    inline const_iterator begin() const noexcept { return m_items.begin(); }
    inline const_iterator end() const noexcept { return m_items.end(); }

    ObjectPtr getObject(uint32_t index)
    {
      assert(index < m_items.size());
      return std::static_pointer_cast<Object>(m_items[index]);
    }

    const std::shared_ptr<T>& operator[](uint32_t index)
    {
      assert(index < m_items.size());
      return m_items[index];
    }

    void add(const std::shared_ptr<T>& object)
    {
      m_items.push_back(object);
      rowCountChanged();
    }

    void remove(const std::shared_ptr<T>& object)
    {
      auto it = std::find(m_items.begin(), m_items.end(), object);
      if(it != m_items.end())
      {
        m_items.erase(it);
        rowCountChanged();
      }
    }
};

#endif
