#include <std.h>
#include "../valley.h"
inherit DRUIDA;

void create()
{
	::create();
// set_property wasn't controlling them, needs to be set_unique.  *Styx* 6/2002
//	set_property("unique",1);
	set_unique(1);
	set_name("Alobrylla");
	set_id(({"druid","dragon","bear","wolf","drake","wolverine","great bear","grizzly bear","alobrylla","Alobryalla"}));
	set_short("Alobrylla, a druid of the Vale");
	set_long(
	"Alobrylla is a young druid, dedicated to restoring the balance of Moonstone Vale,"+
	" which has sorely been over-run by evil. She wears a robe of some rough looking"+
	" material, dyed a deep green. A rope belt is tied around her waist and she has a"+
	" pouch filled with herbs. Although bare handed, she is far from defenseless."+
	" This woman is actually rather plain for a druid. There is nothing at all"+
	" remarkable about her dark brown hair, or her lighter brown eyes. She has a"+
	" nice tan, probably from being out in the sun all the time. Her smile is the"+
	" only thing that draws your attention at all, and it seems warm and loving."+
	" You can't imagine that there's a creature on this earth that this woman doesn't"+
	" like, she seems so friendly."
	);
	set_speed(20);
	set_race("half-elf");
	set_body_type("humanoid");
	set_max_hp(random(100)+150);
	set_hp(query_max_hp());
	set_size(2);
	set_overall_ac(-3);
	set_attack_limbs(({"left hand","right hand"}));
	set_attacks_num(2);
	set_base_damage_type("thiefslashing");
	set_damage(1,6);
	set_spells(({
		"call lightning",
		"hold person",
		"cause blindness",
		"limb attack",
		"cause serious wounds",
	}));
	set_spell_chance(80);
	if(!present("pouch")) {
		new(OBJ+"belt_pouch")->move(TO);
	}
	if(!present("belt")) {
		new(OBJ+"rope_belt")->move(TO);
		command("wear belt");
	}
	switch(random(2)) {
		case 0:
			new(OBJ+"herb")->move(TO);
			break;
		case 1:
			new(OBJ+"herb2")->move(TO);
			break;
	}
}
