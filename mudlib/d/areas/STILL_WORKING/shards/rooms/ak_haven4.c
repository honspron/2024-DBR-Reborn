#include "../shards.h"
inherit "std/room";

void reset() {
        ::reset();
        if(!present("demon"))
  new(MON+"demon")->move(this_object());
        }

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"ak_haven3", "west");
    add_exit(ROOMS+"ak_center", "east");
    add_exit(ROOMS+"ak_marknw", "north"); 
    add_exit(ROOMS+"ak_marksw", "south");
    set("short","The Western Side of the Square");
    set("long","You are on the West side of Market Square. "+
	"This must have been the market square at one point. The quiet is eerie, and disconcerting. What could have silenced this place? The main road is west of here, and the square expands in all other directions.");

}