#include <std.h>

inherit DAEMON;

int cmd_bury(string str) {
   object ob, attacker;
   ob = present("corpse", environment(this_player()));
   attacker = this_player()->query_attackers();
   if(attacker != ({})) {
      write("You have to finish what you're doing.");
      return 1;
   }
   if(!str) {
      write("What would you like to bury?");
      return 1;
   }
   if(str != "corpse") {
      write("What would you like to bury?");
      return 1;
   }
   if(!ob) {
      write("There is no corpse in this area!");
      return 1;
   }
   write("You gather debris from your surroundings to bury this corpse.");
   tell_room(ETP,TPQCN+" gathers debris from "+TP->query_possessive()+" "+
             "surroundings to bury the deceased.",TP);
   this_player()->add_hp(random(4) + 1);
   ob->remove();
   write("You gather your thoughts in the process.");
   return 1;
}

void help() {
   write(
"
%^CYAN%^NAME%^RESET%^

bury - bury a corpse for tiny amout of hp

%^CYAN%^SYNTAX%^RESET%^

bury %^ORANGE%^%^ULINE%^CORPSE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Will bury %^ORANGE%^%^ULINE%^CORPSE%^RESET%^ for modest (1d4) amount of hp.

%^CYAN%^SEE ALSO%^RESET%^

heal, offerall, offer
"
       );
}
