#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_name("A flat mining shaft");
   set_short("%^BOLD%^%^BLACK%^A flat mining shaft%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^A flat mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"travels on a flat level to both the southwest and the north, where you can see a branch in the tunnel "
"ahead.%^RESET%^\n");
   set_exits(([
     "southwest":MINES"shaft2g",
     "north":MINES"shaft2b",
   ]));
}
