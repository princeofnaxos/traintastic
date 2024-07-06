/**
 * client/src/widget/outputmapwidget.hpp
 *
 * This file is part of the traintastic source code.
 *
 * Copyright (C) 2021,2024 Reinder Feenstra
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

#ifndef TRAINTASTIC_CLIENT_WIDGET_OUTPUTMAPWIDGET_HPP
#define TRAINTASTIC_CLIENT_WIDGET_OUTPUTMAPWIDGET_HPP

#include <QWidget>
#include "../network/objectptr.hpp"

class QTableWidget;
class Method;
class MethodAction;
class AbstractProperty;
class AbstractVectorProperty;
class ObjectVectorProperty;
class Property;

class OutputMapWidget : public QWidget
{
  Q_OBJECT

  protected:
    ObjectPtr m_object;
    const bool m_hasUseColumn;
    const int m_columnCountNonOutput;
    AbstractVectorProperty* m_addresses;
    Property* m_ecosObject;
    ObjectVectorProperty* m_items;
    QTableWidget* m_table;
    std::vector<ObjectPtr> m_itemObjects;
    std::vector<std::vector<ObjectPtr>> m_actions;
    int m_getItemsRequestId;
    int m_dummy;

    void updateTableOutputActions(ObjectVectorProperty& property, int row);
    void updateItems(const std::vector<ObjectPtr>& items);
    void updateTableOutputColumns();

  public:
    explicit OutputMapWidget(ObjectPtr object, QWidget* parent = nullptr);
};

#endif
