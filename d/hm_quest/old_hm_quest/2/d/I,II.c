#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(2);
  set_exits( ([
                "north" : MAZEDIR+"2/d/I,I",
                "south" : MAZEDIR+"2/d/I,III",
                "east"  : MAZEDIR+"2/d/II,II",
                "west"  : pass_exit("1","IV,II")
           ]) );
  set_pre_exit_functions( ({"west"}) , ({"go_west"}) );
}

int go_west()
{
  set_exits( ([
                "north" : MAZEDIR+"2/d/I,I",
                "south" : MAZEDIR+"2/d/I,III",
                "east"  : MAZEDIR+"2/d/II,II",
                "west"  : pass_exit("1","IV,II")
           ]) );
  return 1;
}
