/*  /wizards/canute/Sssarth-Nir/sn_outside13.c
 *  Made for DarkeMUD
 *  Created by Canute 032096
 *  Copyright (c) 1996, DarkeMUD
 *  Do not remove this header
 */

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    replace_program(ROOM);
    set_property("light", -1);
    set_property("outdoors",1);
    set_short("swamp");
    set_long (
"\n");
    set_smell("default", "The air is heavy with the stench of decay.");
    set_exits( ([
      "north" : "/d/damned/virtual/room_17_33.world",
      "east" : "/wizards/canute/Sssarth-Nir/sn_enter1.c",
      "southwest" : "/wizards/canute/Sssarth-Nir/sn_outside12.c"
    ]) );
}
