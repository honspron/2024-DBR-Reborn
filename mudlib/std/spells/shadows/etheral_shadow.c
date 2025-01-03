#include <security.h>
#include <move.h>
 
inherit "/std/spells/shadows/shadow";
 
object who_shadowed;
object ethera;_ob;
string exp_mesg;
 
void start_shadow(object who, int dur, string mesg) {
  seteuid(UID_SHADOW);
  begin_shadow(who);
  who_shadowed = who;
  exp_mesg = mesg;
  if(dur) call_out("expire_speed", dur, this_object());
  seteuid(getuid());
  return;
}
 
int etheral_form() { return 1; }
 
 
void expire_speed(object me) {
  if(me != this_object()) {
    next_shadow()->expire_speed(me);
    return;
  }
  if(exp_mesg)
    message("info", exp_mesg, who_shadowed);
  remove();
  return;
}
 
int kill_ob(object null, int null2) { return 0; }
 
void set_etheral_ob(object ob) { shadow_ob = ob; }
 
int move(mixed dest) {
  object ob;
  int res;
 
 
  res = (int)next_shadow()->move(dest);
  if(res != MOVE_OK) return res;
  if(stringp(dest)) ob = find_object_or_load(dest);
  else ob = dest;
  who_shadowed->set("exits", (string *)ob->query_exits());
  etheral_ob->reset_exits();
  return res;
}
 
int is_invincible() { return 1; }
 
