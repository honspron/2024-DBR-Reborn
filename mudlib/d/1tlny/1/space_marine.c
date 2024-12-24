#include "../a1.h"

//TLNY2020 Example of basic creatures
 
#include <std.h>

inherit MONSTER;
string mtlname;
string damage1;
string damage2;
int zlevel;

int is_mon() { return 1; }
init() {
  if( this_player()->query_race() == "tyranid" ) {
    force_me("kill tyranid"); //+this_player()->query_name());
  }
}
 
void create() {
   object ob;
   ::create();

    switch(random(14)){
      case 0:mtlname="iron";break;
      case 1:mtlname="steel";break;
      case 2:mtlname="boernerine";break;
      case 3:mtlname="mcgrail";break;
      case 4:mtlname="neorolite";break;
      case 5:mtlname="catoetine";break;
      case 6:mtlname="raysorite";break;
      case 7:mtlname="inniculmoid";break;
      case 8:mtlname="elrodnite";break;
      case 9:mtlname="mithril";break;
      case 10:mtlname="platnite";break;
      case 11:mtlname="mabril";break;
      case 12:mtlname="iysaughton";break;
      case 13:mtlname="laen";break;
    }
    switch(random(11)){
      case 0:damage1="crushing";break;
      case 1:damage1="cutting";break;
      case 2:damage1="impaling";break;
      case 3:damage1="impact";break;
      case 4:damage1="stress";break;
      case 5:damage1="fire";break;
      case 6:damage1="cold";break;
      case 7:damage1="vacuum";break;
      case 8:damage1="electricity";break;
      case 9:damage1="disruption";break;
      case 10:damage1="plasma";break;
    }
    switch(random(11)){
      case 0:damage2="crushing";break;
      case 1:damage2="cutting";break;
      case 2:damage2="impaling";break;
      case 3:damage2="impact";break;
      case 4:damage2="stress";break;
      case 5:damage2="fire";break;
      case 6:damage2="cold";break;
      case 7:damage2="vacuum";break;
      case 8:damage2="electricity";break;
      case 9:damage2="disruption";break;
      case 10:damage2="plasma";break;
    }

    zlevel = (36+random(5));

    set_level(zlevel);

   set_overall_ac(zlevel*5);
   set_property("magic resistance", zlevel*7);
   set_skill("resist stun", zlevel*7);
   set_property("enhance criticals",-1);

   set_melee_damage(([ "crushing" : zlevel,"plasma" : zlevel, "impact" : zlevel ]));

   set_money("gold", random(100)+5*zlevel); 

 set_name("Space Marine Captain");
   set("id", ({"marine", "space marine", "space marine captain", "captain"}) );
   set("long"," Space Marines, also known as the Adeptus Astartes, are superhuman warrior-monks who fight for the Imperium of Man. They wear mechanized suits of armor and have modified genomes that grant them superhuman abilities.");
   set_short("["+zlevel+"]Space Marine Captain");    
  
   set("race", "human");
   set_body_type("human");
   set_gender("male");
   set_alignment(100);

   set("gang bang", 1);
   // set("aggressive", 0);

   set_hp(zlevel*250 + zlevel*2);
   set_max_hp(zlevel*250 + zlevel*2);
 //set_hp(100);
 //set_max_hp(100);
    //set_max_mp(7000);
    //set_mp(7000);

    set_stats("strength", 10*zlevel);
    set_stats("dexterity", 10*zlevel);
    set_stats("constitution", 10*zlevel);
    set_stats("wisdom", 10*zlevel);
    set_stats("intelligence", 10*zlevel);
    set_stats("charisma", 10*zlevel);
    
    set_skill("attack", 11*zlevel);
    set_skill("two handed blade", 11*zlevel);
    set_skill("two handed blunt",  11*zlevel);
    set_skill("two handed flail", 11*zlevel);
    set_skill("two handed polearm", 11*zlevel);
    set_skill("two handed staff", 11*zlevel);
    set_skill("axe", 11*zlevel);
    set_skill("blade", 11*zlevel);
    set_skill("blunt", 11*zlevel);
    set_skill("knife",  11*zlevel);
    set_skill("flail", 11*zlevel);
    set_skill("melee", 11*zlevel);

    set_skill("parry", 11*zlevel);
    set_skill("dodge", 11*zlevel);
    set_skill("block", 11*zlevel);

    set_skill("combo", 11*zlevel);
    set_skill("reverse stroke", 11*zlevel);
    set_skill("perception", 11*zlevel);

    set_combat_chance(100);
/*
    set_skill("martial arts",11*zlevel);
    set_skill("shield bash", 11*zlevel);
    set_skill("reverse stroke", 11*zlevel); 
    set_skill("defense", 11*zlevel);
    set("see invis", 1);

    set_skill("concentrate", 11*zlevel);
    force_me("use concentrate");

  set_skill("conjuration", 8*zlevel);
   set_skill("prayer", 8*zlevel);
    set_spell_level("explosive fireball", 6);
   set_spell_level("internal flame",6);
    add_spell("explosive fireball","$A");
   add_spell("internal flame", "$A");

   set_skill("illusionism", 8*zlevel);
   set_skill("conjuration", 8*zlevel);
   set_skill("necromancy", 8*zlevel);
   set_skill("concentrate", 8*zlevel);
   add_spell("curse", "$A");
   set_spell_level("curse", 6);
   add_spell("lightning bolt", "$A");
   set_spell_level("lightning bolt", 6);
*/
    set_skill("elementalism", 8*zlevel);
    set_skill("electricity lore", 8*zlevel);
    force_me("use electricity lore");
    set_spell_level("greater elemental bolt", 5);
    add_spell("greater elemental bolt", "$A");
    set_spell_level("greater elemental storm", 5);
    add_spell("greater elemental storm", "$A"); 

    set_property("handedness", "right hand");

switch(random(4)){
case 0:ob = new("/d/damned/virtual/battle-axe_6.weapon");
    ob -> set("long", @EndText
A Power Axe is a Power Weapon taking the form of a single or double-edged battle axe. Power Axes vary in length and design, and have been known to be crafted from one of any number of different materials, though usually Adamantium. As with all Power Weapons, when its power field is activated, usually by operating a control located on the hilt, the blade is sheathed in a lethal corona of disruptive energy. This energy field allows the blade to carve through flesh, bone and most forms of armour plate alike, making a Power Axe a highly effective close combat weapon.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Power%^RESET%^ Axe");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Power%^RESET%^ Axe
EndText);
    ob->set_wc(zlevel+zlevel ,"plasma");
    ob->set_wc(zlevel , damage1);
    ob->set_wc(zlevel , damage2);
    ob->set_wc(zlevel+zlevel ,"impact");
    ob -> set_material("metal/"+mtlname);
    ob->move(this_object());
ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set("long", @EndText
A Storm Shield is a Power Shield that is used by the Space Marines and sometimes by Inquisitors of the Ordo Malleus to provide an extreme form of protection from ranged weapons fire and potent melee strikes.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Storm%^RESET%^ shield");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Storm%^RESET%^ shield
EndText);
    ob -> set_material("metal/laen");    
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());
    force_me("wear shield on left hand");
	break;
	case 1:ob = new("/d/damned/virtual/broad-sword_6.weapon");
    ob -> set("long", @EndText
Power Swords are used by all members of the Imperial armed forces, including the troops of the Astra Militarum and the Space Marines of the Adeptus Astartes, as well as their Chaos counterparts among the Lost and the Damned and the Chaos Space Marines. Xenos species such as the Aeldari, their evil kin the Drukhari and the Necrons are also known to make use of such weapons.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Power%^RESET%^ Sword");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Power%^RESET%^ Sword
EndText);
    ob->set_wc(zlevel+zlevel ,"plasma");
    ob->set_wc(zlevel , damage1);
    ob->set_wc(zlevel , damage2);
    ob->set_wc(zlevel+zlevel ,"impact");
    ob -> set_material("metal/"+mtlname);
    ob->move(this_object());
ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set("long", @EndText
A Storm Shield is a Power Shield that is used by the Space Marines and sometimes by Inquisitors of the Ordo Malleus to provide an extreme form of protection from ranged weapons fire and potent melee strikes.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Storm%^RESET%^ shield");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Storm%^RESET%^ shield
EndText);
    ob -> set_material("metal/laen");    
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());
    force_me("wear shield on left hand");
	break;
	case 2:ob = new("/d/damned/virtual/knife_6.weapon");
    ob -> set("long", @EndText
A Combat Knife is the ubiquitous back-up melee weapon for warriors all across the Imperium of Man, be they lowly hive city scum or the elite soldiers of a Planetary Governor. 
EndText);
    ob -> set_property("new desc", "%^BOLD%^Combat%^RESET%^ Knife");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Combat%^RESET%^ Knife
EndText);
    ob->set_wc(zlevel+zlevel ,"plasma");
    ob->set_wc(zlevel , damage1);
    ob->set_wc(zlevel , damage2);
    ob->set_wc(zlevel+zlevel ,"impact");
    ob -> set_material("metal/"+mtlname);
    ob->move(this_object());
ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set("long", @EndText
A Storm Shield is a Power Shield that is used by the Space Marines and sometimes by Inquisitors of the Ordo Malleus to provide an extreme form of protection from ranged weapons fire and potent melee strikes.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Storm%^RESET%^ shield");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Storm%^RESET%^ shield
EndText);
    ob -> set_material("metal/laen");    
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());
    force_me("wear shield on left hand");
	break;
	case 3:ob = new("/d/damned/virtual/hammer_6.weapon");
    ob -> set("long", @EndText
Many Battle-Brothers balance the clumsy nature of attempting to parry with a Thunder Hammer by pairing it with a Storm Shield which is surrounded by a glowing blue field of protective energy which emits crackling lightning when the Space Marine parries the blow. 
EndText);
    ob -> set_property("new desc", "%^BOLD%^Thunder%^RESET%^ Hammer");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Thunder%^RESET%^ Hammer
EndText);
    ob->set_wc(zlevel+zlevel ,"plasma");
    ob->set_wc(zlevel , damage1);
    ob->set_wc(zlevel , damage2);
    ob->set_wc(zlevel+zlevel ,"impact");
    ob -> set_material("metal/"+mtlname);
    ob->move(this_object());
ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set("long", @EndText
A Storm Shield is a Power Shield that is used by the Space Marines and sometimes by Inquisitors of the Ordo Malleus to provide an extreme form of protection from ranged weapons fire and potent melee strikes.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Storm%^RESET%^ shield");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Storm%^RESET%^ shield
EndText);
    ob -> set_material("metal/laen");    
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());
    force_me("wear shield on left hand");
	break;
}    

    ob = new("/d/damned/virtual/power-armour.armour");
    ob -> set_property("new desc", "%^BOLD%^Power%^RESET%^ armour");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Power%^RESET%^ armour
EndText);
    ob -> set_material("metal/laen");
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());

    ob = new("/d/damned/virtual/great-helm.armour");
    ob -> set_property("new desc", "%^BOLD%^Power%^RESET%^ helm");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Power%^RESET%^ helm
EndText);
    ob -> set("long", "The armoured reinforced headgear that protects an Astartes head.");
    ob -> set_material("metal/laen");
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());
    force_me("equip");
}

string query_element() { return "electricity"; }

void catch_tell(string str) {
  string who;
  object plyr, *inv;

  str = eliminate_colour(str);
  if(!this_object()->query_casting() && sscanf(str, "%s begins casting a
spell.", who)) {
    if(who == "Someone") {
      inv = all_inventory(environment());
      inv = filter_array(inv, (: call_other :), "is_player");
      inv = filter_array(inv, (: call_other :), "query_invis");
      inv = filter_array(inv, (: call_other :), "query_casting");
      if(!sizeof(inv)) {
        return;
      }
      plyr = inv[0];
    }
    else
      plyr = present(lower_case(who), environment());
    if(!plyr) {
      return;
    }
    if(plyr->is_player() && (int)plyr->query_level() > 15) {
      force_me("cast *5 greater elemental bolt at
"+(string)plyr->query_name());
    }
    return;
  }
  if(str == "YOU CAN MOVE AGAIN!!!" && !query_casting() &&
(inv=query_attackers())) {
    if(sizeof(inv) >= 3)
      force_me("cast *5 greater elemental storm");
    else if(sizeof(inv))
      force_me("cast *5 greater elemental bolt at "+
        (string)inv[0]->query_name());
  }
  return;
}

void die(object ob) {
   object ob1;
//NEW
 message("shout", "%^BOLD%^%^BLUE%^Space Marine shouts:%^RESET%^ "+
"You fools!  You have unleashed the Horde of Tyranid! Quick, run for yor lives!", users());
   new(MON+"carnifex1.c")->move(find_object_or_load("/d/daybreak/room/db_square"));
   new(MON+"lictor2.c")->move(find_object_or_load("/d/daybreak/room/db_square"));
   new(MON+"zoanthrope2.c")->move(find_object_or_load("/d/daybreak/room/db_square"));
   new(MON+"tyrant1.c")->move(find_object_or_load("/d/daybreak/room/db_square"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/db_square"));
   new(MON+"tyranid1.c")->move(find_object_or_load("/d/daybreak/room/db_square"));
   new(MON+"tyranid1.c")->move(find_object_or_load("/d/daybreak/room/db_square"));
   new(MON+"tyranid1.c")->move(find_object_or_load("/d/daybreak/room/db_square"));
   new(MON+"tyranid1.c")->move(find_object_or_load("/d/daybreak/room/db_square"));

   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbcc1"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbcc2"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbcc3"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbcc4"));
             
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbns2"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbns2"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbns4"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbns5"));

   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbew3"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbew5"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbew7"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbew9"));

   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbcc1"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbcc2"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbcc3"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbcc4"));
             
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbns2"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbns2"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbns4"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbns5"));

   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbew3"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbew5"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbew7"));
   new(MON+"stealer1.c")->move(find_object_or_load("/d/daybreak/room/dbew9"));

   ob1 = new(MON+"tyranid1.c");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbns1"));
   ob1 = new(MON+"tyranid1.c");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbew10"));
   ob1 = new(MON+"tyranid1.c");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbew1"));
   ob1 = new(MON+"tyranid1.c");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbbw1"));

   ob1 = new(MON+"tyranid1.c");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbbw2"));
   ob1 = new(MON+"tyranid1.c");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbbw3"));
   ob1 = new(MON+"tyranid1.c");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbns2"));
   ob1 = new(MON+"tyranid1.c");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbns2"));

   ob1 = new(MON+"tyranid1.c");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbns1"));
   ob1 = new(MON+"tyranid1.c");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbew10"));
   ob1 = new(MON+"tyranid1.c");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbew1"));
   ob1 = new(MON+"tyranid1.c");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbbw1"));

   ob1 = new(MON+"tyranid1.c");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbbw2"));
   ob1 = new(MON+"tyranid1.c");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbbw3"));
   ob1 = new(MON+"tyranid1.c");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbns2"));
   ob1 = new(MON+"tyranid1.c");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbns2"));
//END
switch(random(16)){

	case 0:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/great-helm.armour");
   ob->move(this_object());
    ob -> set("short", mtlname+" helm of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 1:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/gauntlet.armour");
   ob->move(this_object());
    ob -> set("short", mtlname+" gauntlet of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 2: 
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/chain-mail.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" mail of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 3:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/metal-boots.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" boots of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 4:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/large-shield.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" shield of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 5:  
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/plate-greaves.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" greaves of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 6:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" bracer of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 7:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());   
    ob = new("/d/damned/virtual/broad-sword_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" broad-sword of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 8:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/knife_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" knife of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 9:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/footman's-mace_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" footman's-mace of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 10: 
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object()); 
    ob = new("/d/damned/virtual/battle-axe_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" battle-axe of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 11:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/two-handed-sword_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" two-handed-sword of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 12:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/war-hammer_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" war-hammer of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 13:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/greate-axe_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" greate-axe of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 14:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());	
    ob = new("/d/damned/virtual/shod-staff_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" shod-staff of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 15:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
 ob = new("/std/diewarzau/obj/misc/ingot");
    ob->set_material("metal/"+mtlname);
   ob->move(this_object());
break;
    }
   ::die();
}

//SHIELD BASH based on heart beat random at target
/*
varargs void heart_beat(int flag) {
  if(query_current_attacker() && !random(4)) {
    force_me("use shield bash at "+(string)(query_current_attacker()->query_name()));

message("info", (string)this_player()->query_cap_name()+
			" %^B_RED%^uses shield bash%^RESET%^ at "+(string)(query_current_attacker()->query_name()), environment(this_player()),
			({ this_player() }) );

  }
  ::heart_beat(flag);
  return;
}
*/
