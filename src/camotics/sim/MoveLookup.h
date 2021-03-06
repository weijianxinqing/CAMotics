/******************************************************************************\

    CAMotics is an Open-Source simulation and CAM software.
    Copyright (C) 2011-2017 Joseph Coffland <joseph@cauldrondevelopment.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

\******************************************************************************/

#pragma once

#include <gcode/Move.h>

#include <cbang/geom/Rectangle.h>


namespace CAMotics {
  class MoveLookup {
  public:
    virtual ~MoveLookup() {}

    virtual cb::Rectangle3D getBounds() const = 0;
    virtual void insert(const GCode::Move *move,
                        const cb::Rectangle3D &bbox) = 0;
    virtual bool intersects(const cb::Rectangle3D &r) const = 0;
    virtual void collisions(const cb::Vector3D &p,
                            std::vector<const GCode::Move *> &moves) const = 0;
    virtual void finalize() {}
    virtual void draw(bool leavesOnly = false) {}
  };
}
