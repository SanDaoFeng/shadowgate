//slide1.c

#include <std.h>

inherit ROOM;


void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",0);
	set_terrain(BEACH);
	set_travel(FRESH_BLAZE);
       set_short("%^RED%^The rugged terrain of %^WHITE%^A%^BOLD%^%^RED%^r%^BLACK%^a%^WHITE%^m%^RED%^a%^RESET%^n%^RED%^t%^BOLD%^h %^RESET%^%^RED%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^.");
        set_long("%^RED%^The rugged terrain of %^WHITE%^A%^BOLD%^%^RED%^r%^BLACK%^a%^WHITE%^m%^RED%^a%^RESET%^n%^RED%^t%^BOLD%^h %^RESET%^%^RED%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^.
%^RED%^You are splashed suddenly by seaspray as waves crash against a large stone barrier to your east.  An enormous stone cliff rises to the west and juts right out of the water.  This is a small, lonely stretch of beach.  Coarse sand at your feet is mixed with gravel-like fragments and large stones alike. %^CYAN%^The o%^BOLD%^%^WHITE%^ce%^RESET%^%^CYAN%^a%^BOLD%^n %^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^p%^CYAN%^rout%^RESET%^%^CYAN%^s en%^WHITE%^d%^BOLD%^%^CYAN%^le%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^s%^RESET%^%^CYAN%^ly %^BOLD%^%^WHITE%^b%^RESET%^%^CYAN%^e%^BOLD%^fo%^RESET%^%^CYAN%^r%^BOLD%^%^WHITE%^e %^RESET%^%^CYAN%^y%^BOLD%^ou%^RESET%^%^CYAN%^ to the east.
");
   set_listen("default", "Waves break against the rocky beach with a crash.");
       set_exits(([
   "north" : "/d/islands/common/aramanth/room13",
   "south" : "/d/islands/common/aramanth/room32",
]));
       set_items(([
    "formations" : "Jagged formations of natural rock tower all around you.",
    "netting" : "It is heavily rusted and was probably a heavy duty cargo net of some kind.",
    "rocks" : "The rocks here are very jagged.",
    "formation" : "It looks almost perfectly like a sobbing boy if you look at it from just the right angle.",
    "shale" : "Tiny sharp rock fragments and dust cover the ground.",
    "ground" : "Tiny sharp rock fragments and dust cover the ground."
]));
	
}
void init() {
  ::init();
  do_random_encounters(({"/d/islands/common/mon/scorpion.c", "/d/islands/common/mon/skeleton.c", "/d/islands/common/mon/uwarrior.c", "/d/islands/common/mon/spiritdancer.c", "/d/islands/common/mon/crab.c"}),30,3);
}
