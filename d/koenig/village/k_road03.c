//k_road03.c - Road to the new Koenig - coded by Circe 10/3/03
#include <std.h>
#include "../koenig.h"
inherit KROAD;

void create() {
   ::create();
   set_exits(([
      "west" : VILROOMS"k_road02",
      "east" : VILROOMS"k_road04"
   ]));
}