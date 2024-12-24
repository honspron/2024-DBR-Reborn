#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbns7", "north");
    add_exit(ROOMS+"dbns5","south");
//Basic mapping added by Tiny 1/19/2020 
    set("short","Daybreak Valley Road");
    set("long","Daybreak Valley Road runs north-south through Daybreak Ridge.\n   0\n   | \n   @   \n   | \n   0\n");
}
