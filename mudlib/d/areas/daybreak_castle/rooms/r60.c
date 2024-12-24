#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void reset() {
        ::reset();
if (!present("dirty peasant")) 
new(MON+"peasant.c")->move(this_object());
new(MON+"mage.c")->move(this_object());
new(MON+"mage.c")->move(this_object());
new(MON+"mage.c")->move(this_object());
}

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set_property("indoors", 1);

    //set_property("no attack", 1); 
    //set_property("no cast", 1);
    //set_property("no scry", 1);
    //set_property("no teleport", 1);
    //set_property("no summon", 1);
    set( "short", "Pathway." );
    set( "day long", @EndText
You are standing in a pathway that used to be lit by torches along the walls. now its being lit by small camp fires the peasants made to cook their meals.
	
	
EndText);

    set( "night long", @EndText
You are standing in a pathway that used to be lit by torches along the walls. now its being lit by small camp fires the peasants made to cook their meals.
EndText);

add_exit(PATH+"r76.c", "north");
//add_exit(PATH+"r108.c", "east");
add_exit(PATH+"r8.c", "south");
add_exit(PATH+"r75.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
