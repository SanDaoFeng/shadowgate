//updated base damage - Circe 4/29/04
#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_id(({"hammer","lucern hammer","pole arm","polearm",}));
    set_name("lucern hammer");
    set_short("A lucern hammer");
    set_long("This pole arm has a longe spear tip with a three-pronged, "+
       "sharpened hammer jutting from one side, and a spike "+
       "counterbalance on the other.  It looks like a good weapon for "+
       "smashing through armor.");
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
       set_damage_type("piercing");
       set_property("repairtype",({"weaponsmith"}));
}
