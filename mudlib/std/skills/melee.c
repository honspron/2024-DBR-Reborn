inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("strength");
    set_dev_cost(4);
    set_fast_dev_cost(16);
}

void info() {
message("help",
"This is a skill of unarmed hand-to-hand combat.  High skill gives you "
"better damage and sometimes more attacks.",
this_player());
}

