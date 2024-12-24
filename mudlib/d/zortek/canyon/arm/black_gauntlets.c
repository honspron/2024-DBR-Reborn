inherit "/std/armour";
int used;

void init() {
  ::init();
  add_action("poof","invoke");
}

void create() {
  ::create();
  set_name("gauntlets");
  set("id", ({ "gauntlets", "gloves", "gauntlets of darkness" }) );
  set("short", "Gauntlets of Darkness");
  set("long",@TEXT
TEXT
);
  set_weight(75);
  set_value(38000);
  set_type("metal hand");
  set_limbs( ({ "right hand", "left hand" }) );
  set_ac(29);
  set_wear( (: call_other, this_object(), "extra_worn" :) );
  set_remove( (: call_other, this_object(), "extra_removed"  :) );
  set_property("no save", 1);
  used = 0;
}
int extra_worn() {
  object ob;
  if((int)this_player()->query_level() < 15 + random(10)) {
    write(@TEXT
Images of hellish nightmares flood your mind.  The screams that begin
to issue from your lungs are other worldly wails of pain and madness.
Before you lose consciousness, your heart explodes from its chest
cavity and the room is sprayed with a crimson mist.  The last image
you see is you body engulfed in darke flames...
TEXT
);
    this_player()->die();
    environment(this_object())->remove();
    this_object()->remove();
    return 0;
  }
  if((string)this_player()->query_class() == "thief" ||
     (string)this_player()->query_class() == "nightblade" ||
     (string)this_player()->query_race() == "troll" ||
     (string)this_player()->query_race() == "half-orc" ||
     (string)this_player()->query_race() == "storm-giant" ||
     (string)this_player()->query_race() == "hill-giant") {
    write(@TEXT
Your body is racked with agony as the footwear scorches and begins
to char your skin.  Before you can fully remove them you find you
have incurred substancial damage.
TEXT
);
    this_player()->severed_limb("right foot");
    this_player()->severed_limb("left foot");
    this_player()->add_hp(-1*((int)this_player()->query_hp()-1));
    return 0;
  }
  write(@TEXT
Power seems to surge up from the ground conducted by the boots
into your body and you can sense that there might be a power
within them that you can invoke.
TEXT
);
  return 1;
}

int extra_removed() {
  write(@TEXT
The boots do not seem easily removed...However, with a great amount
of force and determination you rip the boots off!  Unfortunately,
your feet remain within...
TEXT
);
  this_player()->severed_limb("right foot");
  this_player()->severed_limb("left foot");
  return 1;
}
 
int poof(string str) {
  if(!str || present(str, this_player()) != this_object()) {
    notify_fail("Invoke what?\n");
    return 0;
  }
  if(used) {
    write("You fail to invoke any power within the boots.\n");
    return 1;
  }
  write (@TEXT
TEXT
);
  seteuid(getuid());
  say(this_player()->query_cap_name()+" utters a foul WORD.\n", this_player());
  "/std/spells/improved_invisibility"->spell_func(this_player(),this_player(),15,"",0);
  used = 1;
  return 1;
}
