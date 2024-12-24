inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "elemental burst");
    set_property("skill", "elemental magic");
    set_property("casting time", 6);
    set_property("dev cost", 68);
    set_property("fast dev cost", 199);
    set_property("spell level", 14);
    set_property("moon", "warzau");
    set_property("caster message", "You create an explosion of elemental energy!");
    set_property("target message", "");
    set_property("observer message", "$C creates an explosion of elemental energy.");
    set_property("damage multiplier", 12+(this_player()->query_level()/3));
    set_property("spell type", ({ "area damage" }));
    set_property("must be present", 1);
    set_property("no target", 1);
    return;
}

void info() {
    message("help", "Energy mass units required for spell: 25\n\nThis spell by drawing power directly from an energy mass will create a considerable elemental explosion. This explosion will deal notable damage to all targets in the room, much more than a lesser elemental burst would cause. This spell will not affect those in your party and will not hurt your energy mass. This spell requires energy units drawn from a mass to cast, not mp. The element(s) this spell will contain is determined by the element(s) present in the mass. When casting this spell, no target need be supplied.\n\nSyntax: 'cast *6 elemental burst'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object *inv;
    mapping dmg;
    object obmass;
    string lorename1, lorename2, lorename3, lorename4;
    int loreskill1, loreskill2, loreskill3, loreskill4;
    int i;

    inv = all_inventory(environment(caster));

    inv = filter_array(inv, "filter_fun");
    for(i = 0;i < (sizeof(inv));i++) {
	if(inv[i]->query_property("owner name") == (string)caster->query_name()) {
	    if(inv[i]->query_property("energy units") >= 25) {
		inv[i]->set_property("energy units", ((inv[i]->query_property("energy units")) - 25));
		lorename1 = (string)inv[i]->query_property("lore name");
		loreskill1 = (int)inv[i]->query_property("lore power");
		lorename2 = (string)inv[i]->query_property("lore name two");
		loreskill2 = (int)inv[i]->query_property("lore power two");
		lorename3 = (string)inv[i]->query_property("lore name three");
		loreskill3 = (int)inv[i]->query_property("lore power three");
		lorename4 = (string)inv[i]->query_property("lore name four");
		loreskill4 = (int)inv[i]->query_property("lore power four");
		if(loreskill1 > 120) {
		    loreskill1 = 120;
		}
		if(loreskill2 > 120) {
		    loreskill2 = 120;
		}
		if(loreskill3 > 120) {
		    loreskill3 = 120;
		}
		if(loreskill4 > 120) {
		    loreskill4 = 120;
		}
		if(inv[i]->query_property("lore name")) {
		    dmg = ([ ""+lorename1+"" : loreskill1/3 ]);
		    set_property("damage types", ([ ""+lorename1+"" : loreskill1/3 ]));
		    if(inv[i]->query_property("lore name two") != 0) {
			dmg = ([ ""+lorename1+"" : loreskill1/3, ""+lorename2+"" : loreskill2/3 ]);
			set_property("damage types", ([ ""+lorename1+"" : loreskill1/3, ""+lorename2+"" : loreskill2/3 ]));
			if(inv[i]->query_property("lore name three") != 0) {
			    dmg = ([ ""+lorename1+"" : loreskill1/3, ""+lorename2+"" : loreskill2/3, ""+lorename3+"" : loreskill3/3 ]);
			    set_property("damage types", ([ ""+lorename1+"" : loreskill1/3, ""+lorename2+"" : loreskill2/3, ""+lorename3+"" : loreskill3/3 ]));
			    if(inv[i]->query_property("lore name four") != 0) {
				dmg = ([ ""+lorename1+"" : loreskill1/3, ""+lorename2+"" : loreskill2/3, ""+lorename3+"" : loreskill3/3, ""+lorename4+"" : loreskill4/3 ]);
				set_property("damage types", ([ ""+lorename1+"" : loreskill1/3, ""+lorename2+"" : loreskill2/3, ""+lorename3+"" : loreskill3/3, ""+lorename4+"" : loreskill4/3 ]));
			    }
			}
		    }
		}
		message("info", "%^RED%^You expend %^RESET%^25 %^RED%^energy units to cast the spell.%^RESET%^", caster);
		obmass = inv[i];
		obmass->move("/d/damned/arena/trashroom");
		::spell_func(caster, at, power, args, flag);
		obmass->move(environment(caster));
		obmass->force_me("use stalk at "+ caster->query_cap_name());
		remove();
		return;
	    }
	    if(inv[i]->query_property("energy units") < 25) {
		message("info", "There is not enough power left in your energy mass to cast this spell.", caster);
		remove();
		return;
	    }
	}
    }
    message("info", "There is no energy mass present owned by you that you can draw power from.", caster);
    remove();
    return;
}

int filter_fun(object ob) {
    if(ob->query_name() == "energy mass") return 1;
    else return 0;
}
