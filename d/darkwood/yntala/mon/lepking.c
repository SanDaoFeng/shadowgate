#include <std.h>
#include "/d/darkwood/yntala/yntala.h"
inherit MONSTER;

object obj;
void create (){

::create ();
   set_name("Maklakia, King of the Leprechauns");
   set_id(({"leprechaun","leprachaun","Maklakia","maklakia","king","king of the leprechauns"}));
   set_short("%^RESET%^%^GREEN%^A portly leprechaun wearing a %^YELLOW%^golden crown%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This is a small little creature"
" most commonly known as a leprechaun.  He wears a small green"
" jacket decorated with %^YELLOW%^golden %^RESET%^%^GREEN%^"
"clovers embroidered on it, and a pair of green pants with a"
" %^ORANGE%^brown %^GREEN%^belt to hold them up.  "
"%^BOLD%^%^BLACK%^Shiny black shoes %^RESET%^%^GREEN%^adorn his"
" small feet, and a %^YELLOW%^golden crown %^RESET%^%^GREEN%^is worn crookedly on his head.  He is"
" quite portly in build, with a small pot belly that shakes"
" whenever he laughs.  His cheeks are a bright cherry red, his"
" nose small, and his bright %^BOLD%^%^CYAN%^blue"
" %^RESET%^%^GREEN%^eyes %^RESET%^tw%^BOLD%^i%^RESET%^nkle %^GREEN%^mischieviously.%^RESET%^");
   set_race("leprechaun");
   set_gender("male");
   set_body_type("humanoid");
   set_hd(25,2);
   set_overall_ac(-10);
   set_size(1);
   set_stats("intelligence",18);
   set_stats("strength",18);
   set_stats("wisdom",15);
   set_stats("dexterity",18);
   set_stats("constitution",15);
   set_stats("charisma",11);
   set_money("gold",random(10000));
   set_money("silver",random(5000));
   set_money("copper",random(50));
   set_money("electrum",random(2000));
   set_class("mage");
   set_exp(5000);
   set_max_level(14);
   set_alignment(8);
   set_hp(random(200)+300);
   set_max_hp(query_hp());  
   set_property("full attacks",1);
   set_func_chance(60);
   set_funcs(({"cointoss","jig","cloverspin","rainbow"}));
   set("aggressive","aggfunc");
   set_mlevel("mage",25);
   set_guild_level("mage",25);
   set_spell_chance(95);
   set_spells(({"lightning bolt","fireball","hideous laughter","fireball","hideous laughter","scorcher","scorcher","burning hands","ray of enfeeblement","lower resistance","lower resistance","powerword stun","powerword stun","meteor swarm","chain lightning","ice storm","faithful phantom guardians"}));
   set_mob_magic_resistance("average");
   if(random(10) < 1){
      obj = new("/d/magic/scroll");
      obj->set_av_spell(8-random(1));
      obj->move(TO);
   }
   obj = new("/d/magic/scroll");
   obj->set_av_spell(6-random(1));
   obj->move(TO);
   new("/d/darkwood/yntala/obj/crown.c")->move(TO);
   command("wear crown");
   if(random(3) < 1){
     new("/d/laerad/obj/bracers5.c")->move(TO);
     command("wear bracers");
   }
}
int aggfunc() {
if(TP->query_level()<=16){
      force_me("emoteat "+TPQN+ " takes one look at $N and laughs out loud, causing his portly little belly to shake.");
      force_me("say %^GREEN%^Ye are to little for me to be picking on ye!  Me faithful followers will take care of ye!");
      force_me("emote %^GREEN%^disappears, leaving another small leprechaun in his place!");
      new("/d/darkwood/yntala/mon/lep.c")->move(ETO);
      call_out("dest_effect",1);
      return 1;
   }
   else if(TP->query_highest_level()>=17){
      force_me("emoteat "+TPQN+ " takes one look at $N and shakes his head slowly, his eyes gleaming with %^RED%^fury%^RESET%^.");
      force_me("say %^GREEN%^Ye've come to harm me faithful followers, now ye've me ta deal with!");
      call_out("spell_effect",1);
      force_me("kill "+TPQN+ "");
   return 1;
   }
}
void cointoss(object target) {
   if(!"daemon/saving_d"->saving_throw(target,"paralyzation_poison_death")) {
   tell_room(ETO,"%^RESET%^%^GREEN%^The leprechaun throws a coin at "+target->query_cap_name()+" and it hits "+target->query_objective()+" square on "+target->query_possessive()+" forhead, knocking "+target->query_objective()+" off of "+target->query_possessive()+" feet!",target);
   tell_object(target, "%^RESET%^%^GREEN%^The leprechaun cackles as he throws a coin at you and it hits you right between the eyes, knocking you off of your feet!");
   target->set_paralyzed(15,"You are trying to get to your feet.");
   return roll_dice(1,6)+1;
   return 1;
   }
   tell_room(ETO,"%^RESET%^%^GREEN%^The leprechaun throws a coin at "+target->query_cap_name()+" and it barely grazes "+target->query_possessive()+" head!",target);
   tell_object(target, "%^RESET%^%^GREEN%^The leprechaun cackles as he throws a coin that just barely grazes your head!");
   target->do_damage("torso",roll_dice(1,4));
   return 1;
}
void jig(object target) {
    if(!"daemon/saving_d"->saving_throw(target,"paralyzation_poison_death")) {
   tell_room(ETO,"%^RESET%^%^GREEN%^The leprechaun begins to dance a funny little jig and "+target->query_cap_name()+" starts waving "+target->query_possessive()+" arms wildly as "+target->query_subjective()+" begins to dance with him!",target);
   tell_object(target, "%^RESET%^%^GREEN%^The leprechaun begins dancing a funny little jig and you are compelled to join him!");
   target->set_paralyzed(15,"You are having to much fun dancing!");
   return 1;
   } 
   tell_room(ETO,"%^RESET%^%^GREEN%^The leprechaun begins to do a funny little dance but "+target->query_cap_name()+" turns away!",target);
   tell_object(target, "%^RESET%^%^GREEN%^You turn away just as the leprechaun begins to do a funny little dance!");
}
void cloverspin(object target) {
   if(!"daemon/saving_d"->saving_throw(target,"paralyzation_poison_death")) {
   tell_room(ETO,"%^RESET%^%^GREEN%^The leprechaun reaches into his jacket and pulls out an shining clover!  He throws it at "+target->query_cap_name()+" and it strikes "+target->query_objective()+" in the neck, spewing %^RED%^blood %^GREEN%^everywhere!",target);
   tell_object(target, "%^RESET%^%^GREEN%^The leprechaun reaches into his jacket and pulls out a shining clover.  He throws it at you and it strikes you in the neck, spewing %^RED%^blood %^GREEN%^everywhere!");
   target->set_paralyzed(15,"You are to busy trying to keep yourself from bleeding to death.");
   return roll_dice(1,6)+1;
   return 1;
   }
   tell_room(ETO,"%^RESET%^%^GREEN%^The leprechaun throws a clover at "+target->query_cap_name()+" but it misses!",target);
   tell_object(target, "%^RESET%^%^GREEN%^The leprechaun throws a clover at you, but it misses!");
   return 1;
}
void rainbow(object target) {
   tell_room(ETO,"%^YELLOW%^The leprechaun spreads out his hands creating a bright %^RED%^r%^YELLOW%^a%^CYAN%^i%^MAGENTA%^n%^BLUE%^b%^YELLOW%^o%^RED%^w %^YELLOW%^between them.  He then points his finger at "+target->query_cap_name()+", sending the bright %^RED%^c%^CYAN%^o%^BLUE%^l%^YELLOW%^o%^MAGENTA%^r%^RED%^s %^YELLOW%^flying at "+target->query_objective()+"!",target);
   tell_object(target, "%^YELLOW%^The leprechaun creates a bright %^RED%^r%^BLUE%^a%^CYAN%^i%^MAGENTA%^n%^RED%^b%^YELLOW%^o%^MAGENTA%^w %^YELLOW%^between his fingers and sends the %^RED%^c%^CYAN%^o%^BLUE%^l%^YELLOW%^o%^MAGENTA%^r%^RED%^s %^YELLOW%^ripping into you!");
   return roll_dice(1,8)+1;
}
void dest_effect(){
   if(!objectp(TO)) return;
   TO->move("/d/shadowgate/void");
   remove();
}
int spell_effect(){
   force_me("watch");
   new("/cmds/spells/b/_blink.c")->use_spell(TO, TO,25,100,"mage");
   new("/cmds/spells/s/_stoneskin.c")->use_spell(TO, TO,25,100,"mage");
}


