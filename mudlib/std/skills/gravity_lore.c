inherit "/std/skills/lore_skill";

void create() {
    ::create();
    set_property("element", "gravity");
    set_dev_cost(14);
    set_fast_dev_cost(42);
}
