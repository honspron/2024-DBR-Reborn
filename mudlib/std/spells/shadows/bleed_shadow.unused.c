#include <security.h>

inherit "/std/spells/shadows/shadow";

int count = 0;
int dur_count = 0;
object who_shadowed;
string exp_mesg;

int bleed_level = 1;
int bleed_interval = 8;

int query_bleed_shadow(){
    return 1;
}

string query_bleed_stats(){
    return 
    sprintf("rate : %d interval : %d duration : %d",
      bleed_level, bleed_interval, dur_count);
}

int add_bleeding(int b_rate, int b_level, int b_duration){
    bleed_interval += b_rate;
    bleed_level += b_level;
    dur_count += b_duration;
}

void create() {
}

void set_bleeding_rate(int x){
    bleed_level = x;
}

void set_bleeding_interval(int x){
    bleed_interval = x;
}

void start_shadow(object who, int dur, string mesg) {
    seteuid(UID_SHADOW);
    begin_shadow(who);
    who_shadowed = who;
    seteuid(getuid());
    exp_mesg = mesg;
    set_heart_beat(1);
    dur_count = dur;
    return;
}


void expire(object me) {
    if(me != this_object()) {
	next_shadow()->expire(me);
	return;
    }
    message("info", exp_mesg, who_shadowed);
    remove();
    return;
}

void bleed(){
    int hp_lost;
    object ob;
    message("info", "%^BOLD%^" + "%^RED%^" + 
      "You bleed from your wounds!", who_shadowed);
    message("info", "%^BOLD%^" + "%^RED%^" + 
      (string)who_shadowed->query_cap_name() +
      " bleeds.",
      all_inventory(environment(who_shadowed)), 
      ({ who_shadowed }) );

    hp_lost = who_shadowed->query_max_hp();
    hp_lost = hp_lost*bleed_level / 100;

    if(hp_lost > 1)
	who_shadowed->add_hp(-1*hp_lost);
}

void heart_beat() {

    if(dur_count < count)
	expire(this_object());

    if(count % bleed_interval == 0)
	bleed();

    count++;
    return;
}


void revive() {
    next_shadow()->revive();
    remove();
    return;
}

