#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string exp_mesg;
int lev;

void set_power(int x) { lev = x; }

void start_shadow(object who, int dur, string mesg) 
{
    seteuid(UID_SHADOW);
    begin_shadow(who);
    who_shadowed = who;
    seteuid(getuid());
    exp_mesg = mesg;
    call_out("expire_just", dur, this_object());
    return;
}

int query_divine_protection() { return 1; }


int do_damage(string limb, int amt) 
{
    int res;
    object prev;
    int x = random(3) + 1;

    if(previous_object() && living(previous_object()))
    {
	res = (int)next_shadow()->do_damage(limb, amt / x);
	return res;
    }
    res = (int)next_shadow()->do_damage(limb, amt);
    return res;
}

void expire_just(object me) 
{
    if(me != this_object()) 
    {
	next_shadow()->expire_just(me);
	return;
    }
    if(exp_mesg)
	message("info", exp_mesg, who_shadowed);
    remove();
    return;
}


