#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbbw1","east");
    add_exit(ROOMS+"dbbw3","west");
//Basic mapping added by Tiny 1/19/2020
    set("short","Blessing Way");
    set("long","Blessing Way runs east-west through Daybreak Ridge\n   \n    \n0--@--0\n    \n   \n");
}
