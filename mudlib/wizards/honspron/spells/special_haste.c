inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","haste");
    set_property("skill","magery");
    set_property("casting time",10);
    set_property("base mp cost",41);
    set_property("dev cost", 57);
    set_property("fast dev cost", 150);
    set_property("spell level", 11);
    set_property("moon","luna");
    set_property("caster message","You cast special haste at $T.");
    set_property("target message","$C casts special haste at you.");
    set_property("observer message","$C casts haste at $T.");
    set_property("spell type",({ }));
    set_property("target type", "living");
    set_property("must be present", 1);
    set_property("duration", "until quit");
    set_property("stack key", "hste");
    set_property("stack num", 1);
    return;
}

void info() {
message("help",
"This spell gives the target an extra round in combat.  Power affects "
"only the duration.  It may only be cast once on a target.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;

  seteuid(getuid());
  if(at->query_haste()) {
    message("info", "A target may only receive one haste spell.",
      caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  
  at->set("hste #", (int)at->query("hste #") + 1);
  call_out("remove_stack", props["duration"], at);
  ::spell_func(caster, at, power, args, flag);
  
  ob = new("/std/spells/shadows/haste_shadow");
  ob->start_shadow(at, props["duration"], "%^CYAN%^A haste spell expires.");
  return;
}

void remove_stack(object at) {
  if(!objectp(at)) return;
  at->set("hste #", (int)at->query("hste #") - 1);
  remove();
  return;
}
