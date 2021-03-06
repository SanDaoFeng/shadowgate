//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//koboldcaptain.c - updated to use current code by Circe - 8/27/03
#include <std.h>
#include "/d/common/common.h"
#include "/d/shadow/room/cave/ddcaves.h"

inherit MONSTER;

void create() {
   ::create();
   set_name("kobold captain");
   set_id(({"kobold","captain","kobold captain","monster","cave kobold","dirty kobold captain"}) );
   set_race("kobold");
   set_gender("male");
   set_short("%^RESET%^%^RED%^A dirty kobold captain");
   set_long(
      "This small reptillian humanoid stands just over three feet "+
      "tall.  He has scaly skin that's a deep rusty brown color, and "+
      "two small horns on his canine head.  His beady eyes glitter red "+
      "with malice, and it seems he enjoys nothing more than inflicting "+
      "pain on others.  He is dressed in rags that were once bright red, "+
      "though they have faded now to brown.  His overwhelming stench suggests "+
      "that this pitiful creature has never heard of a bath.  This kobold "+
      "barks orders in a yapping, dog-like voice, and his tail twitches constantly."
   );
   set_level(8);
   set_hd(8, 1);
   set_hp(random(15)+60);
   set_body_type("human");
   set("aggressive",18);
   set_alignment(3);
   set_class("thief");
   set_mlevel("thief",8);
   add_search_path("/cmds/thief");
   set_guild_level("thief",8);
   set_scrambling(1);
   set_size(1);
   set_overall_ac(6);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",16);
   set_stats("charisma",3);
   set_stats("dexterity",16);
   set_stats("constitution",7);
   set_max_hp(query_hp());
   set_wielding_limbs( ({ "right hand", "left hand"}) );
   new(CWEAP"dagger")->move(TO);
   command("wield dagger in right hand");
   new(CWEAP"dagger")->move(TO);
   command("wield dagger in left hand");
   new(CARMOR"leather")->move(TO);
   command("wear leather");
   add_money("silver",random(50));
   add_money("gold",random(50)+20);
   add_money("electrum",random(100));
   //set_exp(500);
//   set_exp(3000);
   set_new_exp(8,"normal");
   set_max_level(12);
   set_monster_feats(({
	  "dodge",
      "mobility",
	  "evasion",
	  "combat reflexes"
   }));
   switch(random(20)){
      case 0: new(DDOBJ"electrumring")->move(TO);
              command("wear ring");
              break;
      case 1: new(DDOBJ"leatherring")->move(TO);
              command("wear ring");
              break;
      case 2: new(DDOBJ"lightningring")->move(TO);
              command("wear ring");
              break;
      case 3: new(DDOBJ"glassmedallion")->move(TO);
              command("wear medallion");
              break;
      case 4: new(DDOBJ"rosemedallion")->move(TO);
              command("wear medallion");
              break;
      case 5: new(DDOBJ"lavamedallion")->move(TO);
              command("wear medallion");
              break;
      case 6: new(DDOBJ"platinumwand")->move(TO);
              break;
      case 7: new(DDOBJ"granitewand")->move(TO);
              break;
      case 8: new(DDOBJ"stormwand")->move(TO);
              break;
      default: break;
   }
}
