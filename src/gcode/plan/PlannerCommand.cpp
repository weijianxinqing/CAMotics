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

#include "PlannerCommand.h"

#include <cbang/json/Sink.h>

using namespace GCode;
using namespace cb;


void PlannerCommand::restart(double length) {
  if (length) THROWS("Cannot restart from non-zero length " << length);
  setEntryVelocity(0);
}


void PlannerCommand::write(cb::JSON::Sink &sink) {
  sink.beginDict();

  sink.insert("type", getType());
  sink.insert("id", getID());

  insert(sink);

  sink.endDict();
}