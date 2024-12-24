// generic underdark room for Vishnu

#include <std.h>
#include <vishnu.h>

inherit ROOM;

create() {
    	::create();
    	set_property("light",-1);
    	set_property("indoors", 1);
	set("short", "A winding cavern passageway.");
	set("long",
		"The seemingly endless passage of caverns is dark and "
		"forboding.  The walls are a damp, slick limestone, and "
		"the ceiling is covered with stalactites.  All around you "
		"are various pillar-like columns of limestone.  They "
		"create somewhat of a maze"
		);
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"pillar", "pillars", "column", "columns"}) : "The giant "+
			"stalagmites tower above you, nearly reaching the ceiling.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
	set_listen("default",
			"The only thing heard is the sound of your heart beating"
		);
	set_smell("default",
			"You smell the musky limestone all around."
		);
	add_exit("a2","east");
	add_exit("b1","north");

}
void reset() {
	::reset();
	if(!present("drow")) {
	new(MON+"assassin.c")->move(this_object());
	}
}
