// Bummed from shield bash  ++Drizzt 8/3/96

inherit "/std/skills/skill";

void create() {
    ::create();
    set_stat("strength");
    set_dev_cost(15);
    set_fast_dev_cost(30);
    set_property("target type", "living");
    set_property("must be present",1);
}

void info() {
message("help",
"This skill may be used against enemies in combat. "+
" You may only use this skill once every two combat rounds.",
this_player());
}

void skill_func(object from, object at, string arg) {
  int flag, i, diff;
  string *limbs;

  if((time() - (int)from->query_last_use("kick")) < 4)
    {
    message("info", "You are too tired to use this skill yet."
        , from);
    return;
  }
  if(environment(from) &&
    environment(from)->query_property("no attack")) {
    message("info", "Mystic forces prevent your action.", from);
    remove();
    return ;
  }
  if(at->shadow_form() || at->query_ghost()) {
    message("info", "You may not kick a target which is immaterial.",
            from);
    remove();
    return;
  }
  flag = 0;
  from->set_last_use("kick");
  at->kill_ob(from, 0);
  diff = props["skill level"] - at->query_skill("dodge");
  if ((random(100) + diff) < 35) {
        message("my_combat", "%^MAGENTA%^You attempt to kick but "+
            (string)at->query_cap_name()+ " dodges nimbly out of the way.%^RESET%^",
            from);
    message("other_combat", (string)from->query_cap_name() +
            " attempts to kick you, but you nimbly dodge out of the way.", at);
    message("other_combat", (string)from->query_cap_name() +
            " attempts to kick "+
            (string)at->query_cap_name()+", but " +
	    (string)at->query_cap_name()+" dodges.",
            all_inventory(environment(from)),
            ({ from, at }) );
    remove();
    return;
  }
  props["skill level"] -= (random(100) + 
		     at->query_current_protection("torso","crushing")/4 );
  if((int)props["skill level"] < -10) {
    message("my_combat", "%^MAGENTA%^You attempt to kick "+
	    (string)at->query_cap_name()+ " but miss miserably.%^RESET%^",
	    from);
    message("other_combat", (string)from->query_cap_name() +
	    " attempts to kick you.", at);
    message("other_combat", (string)from->query_cap_name() +
	    " attempts to kick "+(string)at->query_cap_name()+ ", but misses.",
	    all_inventory(environment(from)),
	    ({ from, at }) );
    remove();
    return;
  }
  message("my_combat", "%^MAGENTA%^You kick "+
	  (string)at->query_cap_name()+ " in the groin and "+
          (string)at->query_cap_name()+ " doubles over in pain.%^RESET%^",
	  from);
  message("other_combat", (string)from->query_cap_name() +
	  " kicks you in the groin and you double over in pain.", at);
  message("other_combat", (string)from->query_cap_name() +
	  " plants his foot in "+
	  (string)at->query_cap_name()+ " groin and "+
          (string)at->query_cap_name()+ " doubles over in pain.",
	  all_inventory(environment(from)),
          ({ from, at }) );
from->add_exp2(10 * props["skill level"]+(this_player()->query_level()*100));
  switch(props["skill level"]) {
  case -10..25:
    at->do_damage((string)at->return_target_limb(), random(8)+1);
    break;
  case 26..40:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)+1));
    do_critical(from, at, "crushing A");
    break;
  case 41..53:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)+1));
    do_critical(from, at, "crushing B");
    break;
  case 54..65:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)+1));
    do_critical(from, at, "crushing C");
    break;
  case 66..82:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)+1));
    do_critical(from, at, "crushing D");
    break;
  case 83..10000:
    at->do_damage((string)at->return_target_limb(), 2 * (random(6)+1));
    do_critical(from, at, "crushing E");
    break;
  }
  remove();
  return;
}

