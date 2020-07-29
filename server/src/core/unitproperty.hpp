/**
 * server/src/core/unitproperty.hpp
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


#ifndef TRAINTASTIC_SERVER_CORE_UNITPROPERTY_HPP
#define TRAINTASTIC_SERVER_CORE_UNITPROPERTY_HPP

#include "abstractproperty.hpp"//"interfaceitem.hpp"
#include "valuetypetraits.hpp"
#include "to.hpp"

template<typename T, typename Unit>
class UnitProperty : public AbstractProperty//InterfaceItem
{
  static_assert(value_type<T>::value == ValueType::Integer || value_type<T>::value == ValueType::Float);

  protected:
    T m_value;
    Unit m_unit;

  public:
    UnitProperty(Object& object, const std::string& name, T value, Unit unit, PropertyFlags flags) :
      AbstractProperty(object, name, value_type<T>::value, flags),//InterfaceItem(object, name),
      m_value{value},
      m_unit{unit}
    {
    }

    inline T value() const
    {
      return m_value;
    }

    void setValue(T value)
    {
      assert(isWriteable());
      if(m_value == value)
        return;
      else if(!isWriteable())
        throw not_writable_error();
      else //if(!m_onSet || m_onSet(value))
      {
        m_value = value;
        //if(m_onChanged)
        //  m_onChanged(m_value);
        //changed();
      }
      //else
      //  throw invalid_value_error();
    }

    void setValueInternal(T value)
    {
      if(m_value != value)
      {
        m_value = value;
        changed();
      }
    }

    inline Unit unit() const
    {
      return m_unit;
    }

    std::string_view unitEnumName() const
    {
      return EnumName<T>::value;
    }

    inline T getValue(Unit _unit) const
    {
      return convertUnit(m_value, m_unit, _unit);
    }

    std::string_view enumName() const final
    {
      assert(false);
      return "";
    }

    std::string_view setName() const final
    {
      assert(false);
      return "";
    }

    bool toBool() const final
    {
      throw conversion_error();
    }

    int64_t toInt64() const final
    {
      return to<int64_t>(m_value);
    }

    double toDouble() const final
    {
      return to<double>(m_value);
    }

    std::string toString() const final
    {
      return to<std::string>(m_value);
    }

    ObjectPtr toObject() const final
    {
      throw conversion_error();
    }

    nlohmann::json toJSON() const final
    {
      nlohmann::json v;
      v["value"] = m_value;
      v["unit"] = m_unit;
      return v;//{"value" = m_value, "unit" = m_unit};
    }

    void fromBool(bool value) final
    {
      throw conversion_error();
    }

    void fromInt64(int64_t value) final
    {
      setValue(to<T>(value));
    }

    void fromDouble(double value) final
    {
      setValue(to<T>(value));
    }

    void fromString(const std::string& value) final
    {
      setValue(to<T>(value));
    }

    void fromObject(const ObjectPtr& value) final
    {
      throw conversion_error();
    }

    void load(const nlohmann::json& value) final
    {
      m_value = to<T>(value["value"]);
      m_unit = value["unit"];
    }

    void load(const ObjectPtr& value) final
    {
      throw conversion_error();
    }
};

#endif
