# Dweem

Dweem  edward7 choudh1 khan6

Run Dweem2.cpp to use app.  Character information is saved into files like Character.txt.  Enemy stats are saved in Enemy.txt.
There are more yaml files in the repository that did not make it to the final cut.
Dweem2.cpp has the ability to equip armor and weapons that buff a characters stats.  This is shown in the character.txt file as increased stats.
Additionally, we had some yaml files the "fight_template.yaml" and the "story_template.yaml" that we wanted to use 
to create the rest of the story. We were starting to create classes/stacks/arrays to maybe make a story plot through that
but we didn't come up with a proper story while creating the basic funcionality.


SOME EXTRA NOTES: 
The Enchantment file did work at one point. The entity driver created a Human object which had a vector of Enchantment 
items that the player could use. It worked really well in the EnchantmentDriver, however now we're getting the error of 
underfined reference error, and we're unable to figure this out. The enchantment file would update user stats,
and additionally deletes items after use.

You will see a function in Dweem2.cpp called enemy_heckle.
This function was designed to have the enemy speak with you while you fought.  This function could also be used to have the character speak
with the enemy.  The version of Dweem2.cpp in the repository will now let the enemy heckle you while you fight.