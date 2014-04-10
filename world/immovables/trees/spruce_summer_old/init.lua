dirname = path.dirname(__file__)

world:new_immovable_type{
   name = "spruce_summer_old",
   descname = _ "Spruce (Old)",
   category = "trees_coniferous",
   size = "small",
   attributes = { "tree" },
   programs = {
      program = {
         "animate=idle 1550000",
         "transform=deadtree3 24",
         "seed=spruce_summer_sapling",
      },
      fall = {
         "remove=",
      },
   },
   animations = {
      idle = {
         pictures = path.glob(dirname, "idle_\\d+.png"),
         player_color_masks = {},
         hotspot = { 15, 59 },
         fps = 10,
         sfx = {
            [0] = "sound/animals/bird3.ogg",
         },
      },
   },
}
