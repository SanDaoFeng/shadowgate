#include <std.h>

inherit WEAPON;

void create(){
    ::create();
   set_id(({"heavy halberd","pole axe","halberd","pole arm","polearm"}));
   set_name("halberd");
   set_short("A heavy halberd");
    set_long(
   "This eight foot long pole axe looks very menacing and effective."
   "  Its convex axe blade is set at the perfect angle for cutting into someone before they could get to close."
    "  It's topped by a long spearhead and backed with a curved spike."
    );
    set_weight(10);
    set_size(3);
    set("value", 5);
    set_wc(3,4);
    set_large_wc(3,4);
    set_type("pierce");
    set_prof_type("polearm");
    set_weapon_prof("martial");
    set_weapon_speed(10);
    set_critical_threat_range(1);
    set_critical_hit_multiplier(3);
    set_damage_type("slashing");
    set_property("repairtype",({"weaponsmith"}));
}
