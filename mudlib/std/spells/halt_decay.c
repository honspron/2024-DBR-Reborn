#include <move.h>

inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","halt decay");
    set_property("skill","alchemy");
    set_property("casting time",5);
    set_property("base mp cost",18);
    set_property("dev cost", 8);
    set_property("fast dev cost", 19);
    set_property("spell level", 2);
    set_property("moon","luna");
    set_property("caster message","You cast halt decay at $T.");
    set_property("target message","");
    set_property("observer message","$C casts halt decay at $T.");
    set_property("spell type",({  }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("duration", "variable (see below)");
    return;
}

void info() {
    message("help",
      "This spell embalms a corpse for a longer period of time, allowing a "
      "player more time to be resurrected without the penalty associated with "
      "the loss of a corpse.  If cast a high power level, it may preserve "
      "the corpse permanently.",
      this_player());
}

void spell_func(object caster, object at, int pow, string args, int flag) {
    object *inv;
    int i, roll;

    if(!at->id("corpse")) {
	message("info", "You must cast this spell on a corpse.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    if(flag) {
	message("my_action", "You accidently crumble the corpse to dust!",
	  caster);
	inv = all_inventory(at);
	if(inv && (i = sizeof(inv)))
	    while(i--) inv[i]->move(environment(at));
	message("other_action", (string)caster->query_cap_name() +
	  " accidentally crumbles the corpse to dust!",
	  environment(caster), ({ caster }) );
	at->remove();
	remove();
	return;
    }
    if(random(6) < pow) {
	at->preserve_me();
	message("info", "You have permanently preserved the corpse.", caster);
	remove();
	return;
    }
    message("info", "You fail to preserve the corpse.",
      caster);
    remove();
    return;
}

