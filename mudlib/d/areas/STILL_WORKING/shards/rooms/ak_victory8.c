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
    add_exit(ROOMS+"ak_bless4", "west");
    add_exit(ROOMS+"ak_bless3","east");
    add_exit(ROOMS+"ak_ngate","north");
    add_exit(ROOMS+"ak_victory7","south");
    set("short","Death's Crossing");
    set("long","It only takes a quick look to see that a great battle occured here. Tens of bodies are scattered about the place, most still in armor. Here and there, you spot a spell-caster's robe, torn and shred to bits. The street continues south, and is intersected by another road to the east and west. The western side of the road, however, looks a bit more destroyed than the rest of the town. The town gates are to your north.");
    
}
