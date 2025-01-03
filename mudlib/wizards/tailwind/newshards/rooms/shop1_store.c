#include <std.h>
#include "../newshards.h"
#define MY_INV ({ "pack", "sextant", "vial", "press", "torch" })
#define MAX_INV 25

inherit "/std/vault";

void clone_once();

void create() {
    ::create();
    set_short("You probably shouldn't be here!");
    set_long(
      "This is the storage room for the Adventurer's General Store. Lots of "
      "valuable looking wares lie about.");
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no scry", 1);
    set_property("no summon", 1);
    set_property("no teleport", 1);
    set_property("storage room", 1);
    set_open("iron door", 0);
    set_locked("iron door", 1);
    set_lock_level("iron door", 22);
    return;
}

int my_inv_filter(object item) {
    int i;

    i = sizeof(MY_INV);
    while(i--) if(item->id(MY_INV[i])) return 1;
    return 0;
}

void remove_all(object *inv) {
    int i;

    i = sizeof(inv);
    while(i--) if(inv[i] && !living(inv[i]) && environment(inv[i]) == this_object()) inv[i]->remove();
    return;
}

void reset() {
    object bob, *inv;
    int i;

    ::reset();
    seteuid(getuid());
    inv = filter_array(all_inventory(this_object()), "my_inv_filter",
      this_object());
    call_out("remove_all", 5, inv);
    inv = all_inventory(this_object());
    if(sizeof(inv) > MAX_INV) {
	for(i=MAX_INV-1;i<sizeof(inv);i++) inv[i]->remove();
    }
    bob = present("shopkeeper", 
      find_object_or_load(ROOMS+"generalshop"));
    if(bob) {
	message("info", "Slim says in Common: Wait a second.  I've got a new "+
	  "shipment coming in...", environment(bob));
	call_out("finish_deliver", 4, bob);
    }
    clone_once();
    return;
}

void finish_deliver(object bob) {
    if(bob)
	message("info", "Slim says in Common: It's all here now.",
	  environment(bob));
    return;
}

void clone_once() {
    object ob;
    int i;

    seteuid(getuid());
    for(i=1; i <= 10; i++) {
	ob = new("/std/obj/torch");
	ob->move(this_object());
	ob = new("/std/obj/oil");
	ob->move(this_object());
	if(i <= 7) {
	    ob = new("/std/diewarzau/obj/misc/rations_pack");
	    ob->set_rations(10, 0);
	    ob->move(this_object());
	    ob = new("/std/diewarzau/obj/misc/rations_pack");
	    ob->set_rations(5, 1);
	    ob->move(this_object());
	    ob = new("/std/tailwind/obj/compass");
	    ob->move(this_object());
	}
	if(i <= 5) {
	    ob = new("/std/obj/lantern");
	    ob->move(this_object());
	}
	if(i <= 3){
	    ob = new("/d/damned/guilds/thief/magnify");
	    ob->move(this_object());
	}
    }
}
