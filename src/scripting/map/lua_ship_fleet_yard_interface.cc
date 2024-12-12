/*
 * Copyright (C) 2006-2024 by the Widelands Development Team
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
 * along with this program; if not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "scripting/map/lua_ship_fleet_yard_interface.h"

#include "logic/player.h"
#include "scripting/factory.h"
#include "scripting/globals.h"

namespace LuaMaps {

/* RST
ShipFleetYardInterface
----------------------

.. class:: ShipFleetYardInterface

   .. versionadded:: 1.2

   This represents an interface between a shipyard and a ship fleet.

   More properties are available through this object's
   :class:`MapObjectDescription`, which you can access via :any:`MapObject.descr`.
*/

const char LuaShipFleetYardInterface::className[] = "ShipFleetYardInterface";
const MethodType<LuaShipFleetYardInterface> LuaShipFleetYardInterface::Methods[] = {
   {nullptr, nullptr},
};
const PropertyType<LuaShipFleetYardInterface> LuaShipFleetYardInterface::Properties[] = {
   PROP_RO(LuaShipFleetYardInterface, building),
   {nullptr, nullptr, nullptr},
};

/*
 ==========================================================
 PROPERTIES
 ==========================================================
 */
/* RST
   .. attribute:: owner

      (RO) The :class:`wl.game.Player` who owns this object.
*/
int LuaShipFleetYardInterface::get_owner(lua_State* L) {
	get_factory(L).push_player(L, get(L, get_egbase(L))->get_owner()->player_number());
	return 1;
}

/* RST
   .. attribute:: building

      (RO) The shipyard this interface belongs to.
*/
int LuaShipFleetYardInterface::get_building(lua_State* L) {
	upcasted_map_object_to_lua(L, get(L, get_egbase(L))->get_building());
	return 1;
}

/*
 ==========================================================
 LUA METHODS
 ==========================================================
 */

/*
 ==========================================================
 C METHODS
 ==========================================================
 */

}  // namespace LuaMaps
