//    Skill training room for guilds.
//
//    DarkeLIB 0.1
//    -Diewarzau 8/8/95

#include "/adm/include/std.h"

inherit ROOM;

static mapping skill_list;
static string join_room;

int calc_skill_inc(object who, string skill);
int dev_cost(object who, string skill);
int prereq_check(object who, string str);

void create() {
  ::create();
    if(!query_property("train verb"))
      set_property("train verb", "train");
    if(!query_property("train noun"))
      set_property("train noun", "skills");
    skill_list = ([]);
}

void set_join_room(string str) { join_room = str; }

int is_skill_room() { return 1; }

void set(string what, mixed arg) {
  if((what == "long" || what == "day long" || what == "night long") &&
     stringp(arg))
    arg += "\nType '"+query_property("train verb")+" <skill>' to train your level in that skill.\n"+
      "Type 'list "+query_property("train noun")+"' to list all skills available to you at your level.\n";
      //"Type 'all "+query_property("train noun")+"' to list all skills available to you.\n";
  ::set(what, arg);
  return;
}

void init() {
  ::init();
    if(!query_property("train verb")) set_property("train verb", "train");
    add_action("train_skill", (string)query_property("train verb"));
    add_action("list_skills", "list");
    add_action("all_skills", "all");
    return;
}

/*
int receive_objects() {
  object who;

  who = previous_object();
  if(!who) return 0;
  if(!who->is_player()) return ::receive_objects();
  if(!join_room) {
    write("BUG!  Join_room not found");
    return 1;
  }
  if(wizardp(who) || !who->is_player()) return ::receive_objects();
  if(environment(who) && member_array("std/guilds/spell_room.c", deep_inherit_list(environment(who)))
    >= 0) return ::receive_objects();
  if(join_room->is_member((string)who->query_name())) return 1;
  if((string)join_room->query_member_status((string)who->query_name()) ==
     "allow train") {
    join_room->kick_member((string)who->query_name());
    return 1;
  }
  write("You must be either a member of this guild or have special permission from "+
	"the guildmaster to train here.");
  return 0;
}
*/
int train_skill(string str) {
  int cost, my_dev, my_lev;
  object who;
//HONSPRON 2 GUILD TRAINING
  who=this_player();
  if(!str) return 0;
  my_dev = (int)this_player()->query_property("dev points");
  my_lev = (int)this_player()->query_level();
  str = lower_case(str);
  if(!str) return 0;
    if(((string)join_room->query_member_status((string)who->query_name()) == "member")){
    //write("You are not a member of this guild, you can't train here.");
    //return 0;
  } else if
  (((string)join_room->query_member_status((string)who->query_name()) == "allow train")) {
  }	else {
	  write("You cannot train in this guild.");
	  return 1;
  }
//HONSPRON END  
  
//ADD TLNY 2023

  if((string)who->query_class() != (string)join_room->query_class_name()) {	  
	if(member_array((string)who->query_class(), (string *)join_room->
			query_no_guilds()) >= 0) {
    write("This is not a guild you can train at");
    return 1;
    }
}

//END
  if(!skill_list[str]) {
    write("There is no such skill in this guild.");
    return 1;
  }
  if(!prereq_check(this_player(), str))
  {
    write("Your prerequisite skill is not high enough.");
    return 1;
  }
  if(skill_list[str]["level"] > my_lev) {
    write("That skill is not available at your level.");
    return 1;
  }
  cost = dev_cost(this_player(), str);
  if( !this_player()->query_property("UNPURE") )
     cost = cost * 9 / 10;
  if(cost > my_dev) {
    write("You need "+cost+" development points to train that skill.\n"+
	  "You only have "+my_dev+".");
    return 1;
  }
  this_player()->add_dev(-1 * cost);
  this_player()->set_skill(str, (int)this_player()->query_base_skill(str) +
			   calc_skill_inc(this_player(), str));
  this_player()->set_last_dev(str, my_lev);
  write("You now have "+str+" at "+(int)this_player()->query_skill(str)+"%");
  write("It will cost you "+dev_cost(this_player(), str)+
        " development points to advance this skill further.");
  write("You have "+sprintf("%d", (my_dev - cost)) + 
	" development points left.");
  return 1;
}
/* Zortek: 031996 Rewrote list_skills to eliminate the
 * need for file creation and removal via call_out.
 */  
int list_skills(string str) {
  int i, j, lev, skil;
  string *foo, *list, col;
//TLNY2023 ADD
  object who;

  who=this_player();
//END
  if(!str || str != (string)query_property("train noun")) return 0;
     if(((string)join_room->query_member_status((string)this_player()->query_name()) != "member")&&!this_player()&&!wizardp(this_player())){
    write("You are not a member of this guild, you can't train here.");
    return 1;
  }
//ADD TLNY 2023
  if((string)who->query_class() != (string)join_room->query_class_name()) {	  
	if(member_array((string)who->query_class(), (string *)join_room->
			query_no_guilds()) >= 0) {
    write("This is not a guild you can train at");
    return 1;
    }
}
//END
  //lev = 10000; //TLNY can show all skills but it took away the fun of the surprise
  lev = this_player()->query_level(); 
  foo = ({"%^BOLD%^-=-=-=-=-=-=-=-=-=-=  %^BLUE%^Skill Listing%^RESET%^BOLD%^  =-=-=-=-=-=-=-=-=-=-%^RESET%^"});
  if(member_array("bad standing", (string *)join_room->query_member_privs((string)this_player()->query_name())) >= 0)
    foo += ({ "%^RED%^%^BOLD%^-=-=-=-=-=-=-=-=-=-=  %^RESET%^%^BLUE%^Bad Standing%^RESET%^RED%^%^BOLD%^  =-=-=-=-=-=-=-=-=-=-%^RESET%^"});
  for(i=1;i <= lev; i++) {
    list = filter_array(keys(skill_list), "skill_filter", this_object(), i);
    if(!list || !sizeof(list)) continue;
    j = sizeof(list);
    foo += ({"%^BOLD%^Level "+sprintf("%2d",i)+" ------------------- Cost to Increase ---- Rating%^RESET%^"});
    while(j--) {
      skil = dev_cost(this_player(), list[j]);
      col = "%^BOLD%^GREEN%^";
      if(skil > this_player()->query_property("dev points") ) col = "%^RED%^";
      foo += ({ sprintf("    %-25s %s%-6d%%^RESET%%^ %6d%% %9d%%",
                list[j],
                col,
                skil,
			    calc_skill_inc(this_player(), list[j]),
			    (int)this_player()->query_skill(list[j])) });
    }
  }
  foo += ({"%^BOLD%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^"});
  this_player()->more(foo);
  return 1;
}

int all_skills(string str) {
  int i, j, lev, skil;
  string *foo, *list, col;

  if(!str || str != (string)query_property("train noun")) return 0;
     if(((string)join_room->query_member_status((string)this_player()->query_name()) != "member")&&!this_player()&&!wizardp(this_player())){ // TLNY2020 removed to make cross traing
    write("You are not a member of this guild, you can't train here.");
    return 1;
  }
  lev = 10000; //TLNY can show all skills but it took away the fun of the surprise
  //lev = this_player()->query_level(); 
  foo = ({"%^BOLD%^-=-=-=-=-=-=-=-=-=-=  %^BLUE%^Skill Listing%^RESET%^BOLD%^  =-=-=-=-=-=-=-=-=-=-%^RESET%^"});
  if(member_array("bad standing", (string *)join_room->query_member_privs((string)this_player()->query_name())) >= 0)
    foo += ({ "%^RED%^%^BOLD%^-=-=-=-=-=-=-=-=-=-=  %^RESET%^%^BLUE%^Bad Standing%^RESET%^RED%^%^BOLD%^  =-=-=-=-=-=-=-=-=-=-%^RESET%^"});
  for(i=1;i <= lev; i++) {
    list = filter_array(keys(skill_list), "skill_filter", this_object(), i);
    if(!list || !sizeof(list)) continue;
    j = sizeof(list);
    foo += ({"%^BOLD%^Level "+sprintf("%2d",i)+" ------------------- Cost to Increase ---- Rating%^RESET%^"});
    while(j--) {
      skil = dev_cost(this_player(), list[j]);
      col = "%^BOLD%^GREEN%^";
      if(skil > this_player()->query_property("dev points") ) col = "%^RED%^";
      foo += ({ sprintf("    %-25s %s%-6d%%^RESET%%^ %6d%% %9d%%",
                list[j],
                col,
                skil,
			    calc_skill_inc(this_player(), list[j]),
			    (int)this_player()->query_skill(list[j])) });
    }
  }
  foo += ({"%^BOLD%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^"});
  this_player()->more(foo);
  return 1;
}


void delete_file(string file) {
  seteuid(getuid());
  rm(file);
  return;
}

int skill_filter(string skill, int lev) {
  if(!skill_list || !skill_list[skill]) return 0;
  return (skill_list[skill]["level"] == lev);
}

int dev_cost(object who, string skill) {
  string file;
  int times, mult, cost;
  int subt = (int)who->query_property("dev cost");

  if(!who || !who->is_player()) return 0;
  if(!skill) return 0;
  if(!skill_list[skill] || !skill_list[skill]["secondary"])
    mult = 1;
  else mult = 2;
//add TLNY2020 add new code

  if((string)who->query_class() != (string)join_room->query_class_name()) {	  
	if(member_array((string)who->query_class(), (string *)join_room->
			query_no_guilds()) >= 0) {
      mult *= 100; }

    if(member_array((string)who->query_class(), (string *)join_room->
		    query_hated_guilds()) >= 0) {
      mult *= 16; }
	if(member_array((string)who->query_class(), (string *)join_room->
		    query_odd_guilds()) >= 0) {
      mult *= 8; }
	if(member_array((string)who->query_class(), (string *)join_room-> 
			query_other_guilds()) >= 0) {
      mult *= 5; }
	if(member_array((string)who->query_class(), (string *)join_room-> 
		    query_related_guilds()) >= 0) {
      mult *= 2; }
//TLNY2024 change
     //else {mult *= 5;}
     else {mult *= 1;}
  }
	 
 

    if((string)who->query_class() != (string)join_room->query_class_name()) {
    if(member_array((string)who->query_class(), (string *)join_room->
		    query_related_guilds()) >= 0)
      mult *= 3;
    else mult *= 4;
  }

  if((int)who->query_base_skill(skill) >= 80) mult *= 2;
  if((int)who->query_base_skill(skill) >= 100) mult *= 2;
  if((int)who->query_base_skill(skill) >= 150) mult *= 2;
  if(member_array("bad standing", (string *)join_room->query_member_privs((string)this_player()->query_name())) >= 0)
    mult *= 3;
  file = "/std/skills/"+replace_string(skill, " ", "_")+".c";
  if(!file_exists(file)) return 0;
  file = replace_string(file, ".c", "");
  times = (int)who->query_dev_times(skill, (int)who->query_level());
  if(!times) cost = (mult * (int)file->query_dev());
  else cost = (mult * times * (int)file->query_fast_dev());
  if(subt < 0) cost += subt;
  if(cost < 1) cost = 1;
  return cost;
}

//ADD TLNY2024
int prereq_check(object who, string str)
{
    object skill;
    string prereq;

    // Find the skill object
    skill = find_object("/std/skills/" + replace_string(str, " ", "_"));
    if (!skill) {
        return 1; // If the skill object doesn't exist, assume no prerequisites.
    }

    // Get the prerequisite skill
    prereq = skill->query_property("prereq");
    if (!prereq) { 
        return 1; // If no prerequisite is defined, return success.
    }

    // Check the prerequisite skill level
    if (who->query_base_skill(str) >= who->query_base_skill(prereq)) { 
        return 0; // Prerequisite met.
    } else { 
        return 1; // Prerequisite not met.
    }
}
//END
/* //TLNY2024 throwing errors made new code to see if we still get errors
int prereq_check(object who, string str)
{
object skill;
string prereq;
skill = find_object("/std/skills/"+replace_string(str, " ", "_"));

if(!prereq = skill->query_property("prereq")){ return 1; }
if(who->query_base_skill(str) >= who->query_base_skill(prereq)) { return 0; }
else { return 1; }
}
*/

string *query_all_skills() {
  if(!skill_list) return ({});
  return keys(skill_list);
}

varargs void add_skill(string skill, int lvl, int flag) {
  skill_list[skill] = ([]);
  skill_list[skill]["level"] = lvl;
  if(flag) skill_list[skill]["secondary"] = flag;
  return;
}

int calc_skill_inc(object who, string skill) {
  int base;

  if(!who || !skill) return 0;
  base = (int)who->query_base_skill(skill);
  switch(base) {
  case 0..25:
    return 5;
  case 26..40:
    return 3;
  case 41..59:
    return 2;
  case 60..10000:
    return 1;
  }
  return 1;
}


