#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit JUNG_ROOM + "jung_base.c";


void create() {
  ::create();

}


string short_desc(){
  return "%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle";
}


string long_desc(){

return base_desc();

}

