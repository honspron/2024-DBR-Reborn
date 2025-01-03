#include <std.h>

inherit OBJECT;

int writes;

int query_is_bloodbag(){
    return 1;
}

void set_charges(int x){
    writes = x;
}

int query_charges(){
    return writes;
}

void decay(){
    writes--;
    if(writes < 1){
	message("The empty pouch disintegrates", this_player());
	remove();
    }
}

int drink_func(string str){
    if(!str || str != "blood"){
	message("info", "Consume what?", this_player());
	return 0;
    }
    message("info", "You consume the blood.", this_player());
    say(this_player()->query_cap_name() + " drinks a liquid from a skin pouch, wipes blood from " + this_player()->query_objective() + " lips, and smiles.",
      this_player());
    this_player()->add_stuffed(100);
    this_player()->add_quenched(100);
    decay();  
    return 1;
}

void init() {
    add_action("drink_func", "consume");
}

void create() {
    ::create();
    set_name("pouch");
    set_id( ({ "pouch", "skin pouch", "blood" }) );
    set_short("A skin pouch");
    set_long("A pouch made out of skin with blood in it.  \n" +
      "You may 'consume' the blood from it.\n");
    set_weight(5);
    set_value(0);
}

string query_short() {
    switch(writes){
    case 0:
	return "An empty skin pouch";
    case 1:
	return "An almost empty skin pouch";
    case 2..3:
	return "A pouch of skin";
    case 4:
	return "A half full skin pouch";
    case 5:
	return "A mostly full skin pouch";
    case 6..10:
	return "A full skin pouch";
    }
    return "A skin pouch";
}

