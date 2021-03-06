//Added color, per Kain's suggested submission - Octothorpe 6/8/09
//Coded by Bane//
#include <std.h>
inherit ARMOUR;
string owner;
void create(){
   ::create();
   set_id(({"boots","boots of speed","speed"}));
   set_name("leather boots");
   set_obvious_short("%^BOLD%^%^BLACK%^A pair of %^WHITE%^fine %^BOLD%^"+
      "%^BLACK%^leather boots%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Boots of Sp%^WHITE%^ee%^BOLD%^%^BLACK%^d%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^These boots are made of a fine quality "+
      "leather, and look to be quite expensive and nearly brand new.  "+
      "They weigh close to nothing and seem to have a %^RED%^sh%^BOLD%^"+
      "%^BLACK%^a%^BOLD%^%^RED%^dy haze %^BOLD%^%^BLACK%^around them, "+
      "making them look as if they are almost %^RESET%^%^GREEN%^shaking"+
      "%^BOLD%^%^BLACK%^.  You notice that whenever you try to lay your "+
      "hands on the boots, the %^BOLD%^%^BLUE%^v%^RESET%^%^BLUE%^i"+
      "%^BOLD%^%^BLUE%^br%^RESET%^%^BLUE%^a%^BOLD%^%^BLUE%^t%^RESET%^"+
      "%^BLUE%^io%^BOLD%^%^BLUE%^n %^BOLD%^%^BLACK%^is almost too "+
      "much.  A mysterious %^BOLD%^%^MAGENTA%^power %^BOLD%^%^BLACK%^"+
      "seems to be held within the boots.%^RESET%^");
   //Was too lazy to overcome my writer's block lore - Octothorpe
   set("lore","These boots are imbued with a magical property that allows their wearer to be much quicker than normal.");
   set_weight(5);
   set_value(5000);
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
   set_ac(0);
   set_property("enchantment",5);
   set_wear((:TO,"wield_me":));
   set_remove((:TO,"unwield_me":));
   set_heart_beat(1);
}

void wield_me(){
//adjusted so Vecna can wear them ~Circe~ 12/1/07
    if(interactive(TP) && (string)TPQN != owner){
         write("These are not your boots.");
        remove();
        return 0;
    }
    write("Your feet feel lighter than air, and as if you can run for miles.");
    return 1;
}
void unwield_me(){
    write("You feel tired and sluggish.");
    return 1;
}
void init(){
    ::init();
    if(interactive(TP) && TP == environment(TO) && !owner)
        owner = TPQN;
}
void heart_beat(){
    if(!living(ETO)) return 1;
    if(!TO->query_worn()) return 1;
    if(ETO->query_current_attacker()){
         if(!random(15)){
            tell_object(ETO,"%^BOLD%^The boots give you a burst of speed.");
            ETO->execute_attack();
        }
    }
}
