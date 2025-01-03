#include "../munitio.h"
inherit "/std/npc_shop";

void create() {
  object ob;

   ::create();
   set_name("feika");
   set("id", ({"feika the brutal", "shopkeeper", "shop keeper", "feika"}));
   add_money("gold", 5000);
   set_level(10);
   set_max_hp(200000);
   set_hp(200000);
   set_property("enhance criticals", -10);
   set_exp(3000000);
   set("short","Feika the Brutal, the Armourer");
   set("long",
"Feika is probably the first female scrag you've seen who's not tearing the face off of anything male and non-scrag. To make it as an armourer here, she must be very skilled. She looks pretty (tough) and she's really quite beautiful(ly good at ripping apart anyone who pisses her off).");
   set_gender("female");
   set_body_type("human");
   set("race", "scrag");
   set_property("melee damage", ([ "crushing" : 99 ]));
   set_overall_ac(666);
set_skill("elementalism", 75);
   set_spell_level("elemental storm", 6);
   add_spell("elemental storm", "");
  set_combat_chance(80);
   set_stats("strength", 405);
   set_stats("dexterity", 95);
   set_skill("two handed blade", 190);
   set_skill("dodge", 170);
   set_skill("parry", 180);
   set_skill("martial arts", 50);
   set_skill("perception", 70);
   set_languages(({"common", "stormspeak", "elvish", "yin", "dwarvish",
                "drow", "pix", "treefolk", "vr'krr", "middle-english",
                            "catfolk", "ogryn", "rachk", "gr'grr" }));
   set("storage room",ROOMS+"armour_store");
   set("markup", 70);
   set_property("handedness", "right hand");
   set("no sell", 0);
   set("pre sell function", (: call_other, this_object(), "only_weapon" :) );
   ob = new("/d/damned/virtual/two-handed-sword_5.weapon");
   ob->set_property("enchantment", 7);
   ob->move(this_object()); 
   ob = new("/d/damned/virtual/studded-leather-vest.armour");
   ob->move(this_object());
   ob = new("d/damned/virtual/studded-leather-glove.armour");
   ob->move(this_object());
   ob = new("d/damned/virtual/studded-leather-glove.armour");
   ob->move(this_object());
   ob = new("d/damned/virtual/leather-pants.armour");
   ob->move(this_object());
   force_me("wield sword in right hand and left hand");
   force_me("wear vest");
   force_me("wear glove on right hand");
   force_me("wear glove 2 on left hand");
   force_me("wear pants");
   return;
}

string only_weapon(object item) {
  if(!item->is_armour()) return "I only buy armour.";
  return 0;
}


int query_num_rounds() { return 3; }

string query_element() { return "vacid"; }
