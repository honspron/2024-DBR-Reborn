//    Actually containing the function called by heal potion drinking.
//TLNY 2022 updated

#include <std.h>
#include <clock.h>
#include <def.h>

#include <daemons.h>

int last_used;

int healing_potion(object who, int strength) {
   object ob;
	

  if(!strength) return notify_fail("Potion BUG BUG BUG!");
  who->heal(strength);
  return 1;   
}


int mana_potion(object who, int strength) {
	
   
  if(!strength) return notify_fail("Potion BUG BUG BUG!");
  who->heal(strength);
  who->add_mp(strength);
  return 1;
}


int alabaster_potion(object who, int strength) {
	
   
  if(!strength) return notify_fail("Potion BUG BUG BUG!");
  who->heal(strength);
  who->add_mp(strength / 2);
  while(who->query_paralyzed()) who->remove_paralyzed();
  DAMAGE_D->stop_cont_damage(who);
  if(who->query_poisoning())
    who->add_poisoning(-1 * (int)who->query_poisoning());
  return 1;
}

