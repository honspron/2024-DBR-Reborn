#include <colors.h>
inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","dark quest");
    set_property("skill","rifting");
    set_property("casting time",4);
    set_property("base mp cost",27);
    set_property("dev cost",145);
    set_property("fast dev cost",398);
    set_property("spell level", 35);
    set_property("moon","luna");
    set_property("caster message", "You cast dark quest.");
    set_property("target message","");
    set_property("observer message", "$C casts dark quest.");
    set_property("spell type",({  }));
    set_property("duration", 0);
    set_property("no target", 1);
    return;
}

void info() {
    message("help",
      "This spell enables a demon master to travel to and from the world of the demons.",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
    string troom;
    object ob = environment(caster);
    string ow_room = "/d/damned/virtual/room_8_9.world";
    string uw_room = "/d/damned/virtual/room_15_15.underworld";

    at = caster;

    if(flag){
	message("info", CBOLD + CRED +
	  "You go somewhere you didn't expect!",at);
	at->move("/std/diewarzau/rooms/warp");
	remove();
	return;
    }

    if(!ob->query_terrain()){
	message("info","You are not on the world map.",
	  at);
    }
    if(ob->query_is_overworld())
	at->move(uw_room);
    else
    if(ob->query_is_underworld())
	at->move(ow_room);
    else {
	message("info","You are not on the world map.",
	  at);
	remove();
	return;
    }

    message("info",
      CBOLD + CGREEN + " turns completely black and disappears." + CRESET,
      caster);
    message("info",
      CBOLD + CGREEN + caster->query_short() + " turns completely black and disappears."
      + CRESET, all_inventory(ob));
    remove();
    return;
}

