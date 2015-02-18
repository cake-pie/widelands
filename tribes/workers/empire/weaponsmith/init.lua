dirname = path.dirname(__file__)

animations = {
   idle = {
      pictures = path.list_directory(dirname, "idle_\\d+.png"),
      hotspot = { 8, 24 }
   }
}
add_worker_animations(animations, "walk", dirname, "walk", {8, 24}, 10)
add_worker_animations(animations, "walkload", dirname, "walkload", {8, 24}, 10)


tribes:new_worker_type {
   name = "empire_weaponsmith",
   -- TRANSLATORS: This is a worker name used in lists of workers
   descname = _"Weaponsmith",
   icon = dirname .. "menu.png",
   vision_range = 2,

   buildcost = {
		empire_carrier = 1,
		hammer = 1
	},

	-- TRANSLATORS: Helptext for a worker: Weaponsmith
   helptext = _"Produces weapons for the soldiers.",
   animations = animations,
}
