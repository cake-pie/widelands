--##########################################
--#      Campaign configuration - file     #
--##########################################

return {
   version = 9,
   --##########################################
   --#   Descriptions of difficulty levels    #
   --##########################################
   difficulties = {
      {
         -- This will be prefixed to any text that you might add in each
         -- campaign's difficulty description.
         -- TRANSLATORS: The difficulty level of a campign
         descname = _"Easy.",
         -- An image to represent the difficulty level
         image = "images/ui_fsmenu/easy.png",
      },
      {
         -- TRANSLATORS: The difficulty level of a campign
         descname = _"Medium.",
         image = "images/ui_fsmenu/medium.png",
      },
      {
         -- TRANSLATORS: The difficulty level of a campign
         descname = _"Hard.",
         image = "images/ui_fsmenu/hard.png",
      },
      {
         -- TRANSLATORS: The difficulty level of a campign
         descname = _"Challenging.",
         image = "images/ui_fsmenu/challenging.png",
      },
   },

   --##########################################
   --#        The campaigns themselves        #
   --##########################################
   campaigns = {
      {
         -- **** Barbarians Introduction ****
         -- The name the user sees on screen
         -- TRANSLATORS: The name of a Barbarian campign
         descname = _"The Second Empire",
         -- The internal name of the tribe that the user will be playing
         tribe = "barbarians",
         -- The difficulty of this campaign.
         -- Start counting at 1 in the "difficulties" table above
         -- TRANSLATORS: A short description of a campign
         difficulty = { level=1, description=_"Introduces the Barbarians." },
         -- An introduction story
         -- TRANSLATORS: A long description of a campign
         description = _"When Chat’Karuth died, he was an old man, father to three strong and ambitious sons, and warlord to an army that could match any enemy willing to rise against the ancient forests. Though at the end of his glorious reign, Chat’Karuth chose his eldest son, Thron, to succeed him as the tribe’s warlord – a decision that left his two brothers unsatisfied. The old warlord knew that. As his father instructed him, Thron left the capital of Al’thunran, the home of the Throne Among the Trees, and withdrew his forces to the high hills where he buried the corpse of his father. There he swore to the gods and his father’s spirit that he’d return to re-established order. While his brothers have raged blind war against Thron and the few forces he left to secure the borders of Al’thunran, the young warlord seeks to reunite his ambitious brothers and force the tribes to march once again under a common banner.",
         -- The campaign's scenarios. The first scenario is always visible if
         -- the campaign itself is visible.
         -- Paths to the scenarios are relative to data/campaigns
         -- Once a scenario has been marked as solved by calling
         -- `player:mark_scenario_as_solved`, the next scenario in the list will
         -- become visible.
         -- Also, campaigns that have a prerequisite scenario will be unlocked
         -- when the referenced scenario has been solved.
         scenarios = {
            "bar01.wmf",
            "bar02.wmf",
            "dummy.wmf"
         }
      },
      {
         -- **** Empire Introduction ****
         -- TRANSLATORS: The name of an Empire campign
         descname = _"The Months of Exile",
         tribe = "empire",
         -- TRANSLATORS: A short description of a campign
         difficulty = { level=2, description=_"Introduces the Empire." },
         -- TRANSLATORS: A long description of a campign
         description = _"Six months ago, Lutius – a young general of the Empire – was sent with 150 soldiers to the frontier beyond the northern forests where Barbarian tribes were crossing onto land held by the Empire. His task was to defend the Empire’s land. At first, everything was calm. He even talked to a few Barbarian children and thought about a peaceful life – side by side with this archaic folk. He began to feel safer and his army began to drop their attention off the potential enemy. That was their undoing. One night in March his unprepared army was attacked by 100 Barbarian footmen and was completely scattered. Only with his bare life he and a handful of his soldiers survived.",
         -- If `prerequisite` is present, the campaign is greyed out by default.
         -- The campaign will become unlocked when the referenced scenario has been solved.
         prerequisite = "bar02.wmf",
         scenarios = {
            "emp01.wmf",
            "emp02.wmf",
            "emp03.wmf",
            "emp04.wmf",
            "dummy.wmf"
         }
      },
      {
         -- **** Atlantean Introduction ****
         -- TRANSLATORS: The name of an Atlantean campign
         descname = _"The Run for the Fire",
         tribe = "atlanteans",
         -- TRANSLATORS: A short description of a campign
         difficulty = { level=3, description=_"Introduces the Atlanteans." },
         -- TRANSLATORS: A long description of a campign
         description = _"When their God lost faith in the Atlanteans and drowned their island, one woman’s struggle for justice and a second chance for her people would become the stuff of legends. Leading the remaining Atlanteans into a new future in a new part of the World, Jundlina became the most powerful human of her time, but at a high cost: her humanity and soul.",
         prerequisite = "emp02.wmf",
         scenarios = {
            "atl01.wmf",
            "dummy.wmf"
         }
      }
   }
}
