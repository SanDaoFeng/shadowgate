#include <std.h>
#include "/d/common/common.h"

inherit SHEATH_INHERIT ;

mixed query_property(string str) { return ::query_property(str); }

void create(){
  ::create();
  remove_property("can_hold");
  set_property("can_hold",({ "short blades","small blades","fan","knuckles","rapier", "wand"}));
  remove_property("can_wear_limbs");
  set_property("can_wear_limbs",({ "waist" , "torso", "right arm", "left arm", "left leg", "right leg"}));
  remove_property("sheath_size");
  remove_property("original_weight");
  set_property("sheath_size",1);
  set_property("original_weight",1);
  set_name("small blade sheath");
  set_id(({"sheath", "small sheath","small sheaths","small Sheaths","small Sheath", "weapsheath"}));


  set_short("A small sheath");
  set_long(
@GARRETT
This is a weapons sheath. It is meant to hold a single small bladed weapon,
and has adjustable straps to hold it on your body. The straps could be
easily adjusted to hold the sheath in more than one location, allowing
easy access for the weapon that it holds.
GARRETT
);

  set_max_internal_encumbrance(10);
}
