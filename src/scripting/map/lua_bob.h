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

#ifndef WL_SCRIPTING_MAP_LUA_BOB_H
#define WL_SCRIPTING_MAP_LUA_BOB_H

#include "logic/map_objects/bob.h"
#include "scripting/map/lua_map_object.h"

namespace LuaMaps {

class LuaBob : public LuaMapObject {
public:
	LUNA_CLASS_HEAD(LuaBob);

	LuaBob() = default;
	explicit LuaBob(Widelands::Bob& mo) : LuaMapObject(mo) {
	}
	explicit LuaBob(lua_State* L) : LuaMapObject(L) {
	}
	~LuaBob() override = default;

	/*
	 * Properties
	 */
	int get_field(lua_State*);
	int has_caps(lua_State*);

	/*
	 * Lua Methods
	 */

	/*
	 * C Methods
	 */
	CASTED_GET(Bob)
};

}  // namespace LuaMaps

#endif
