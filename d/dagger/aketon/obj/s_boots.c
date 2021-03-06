#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

int flag;

void create() {
   ::create();
   set_name("soft boots");
   set_id( ({"soft boots","boots"}) );
   set("short","Soft boots");
   set("long","This is a pair of soft walking boots.");
   set_type("clothing");
   set_limbs( ({"right foot","left foot"}) );
   set_weight(1);
   set_value(10);
   flag = 0;
}

void init() {
   ::init();
   if(flag)
      return;
   if(ETO == TP || (string)TP->query_race() == "elf") {
      if( !random(100) )
         set_ac(1);
      else if( !random(200) )
         set_ac(2);
      else if( !random(300) )
         set_ac(3);
      flag = 1;
   }
}
