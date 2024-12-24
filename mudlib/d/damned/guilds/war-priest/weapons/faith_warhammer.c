inherit "/std/weapon";

void create() {
    ::create();
    set("id", ({ "war-hammer", "war-hammer of faith", "faith war-hammer" }));
    set_name("war-hammer");
    set("short", "The %^BOLD%^War-Hammer%^RESET%^ of %^BOLD%^%^YELLOW%^Faith%^RESET%^");
    set("long", "This war-hammer is beautiful. It shines white and gold. The handle is made from desper wood.");
    set_weight(70);
    set_type("two handed blunt");
    set_material("blessed gold");
    set_ac(10);
    set_parry_bonus(10);
    set_property("no save", 1);
    set_quality(4);
    set_property("no add quality", 1);
    set_property("no decay", 1);
    set_decay_rate(1500);
    set_value(0);
    set_wield( (: call_other, this_object(), "wield_warhammer" :) );
    set_verb("punish");
}

int wield_warhammer() {

   if(this_player()->is_player() && (int)this_player()->query_level() < 10) {
     write("%^BOLD%^%^CYAN%^Only War-Priests of level 10 or higher may use this holy weapon.");
    return 0;
}

   if((string)this_player()->query_class() != "war-priest") {
      write("%^BOLD%^%^CYAN%^Only War-Priests may use this holy weapon.");
    return 0;
  }
return 1;
}

