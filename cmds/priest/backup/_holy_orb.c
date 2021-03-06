//Holy Orb
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

string query_cast_string() {
    return CASTER->query_cap_name()+" holds "+CASTER->QP+" hands out in "
        "front of "+CASTER->QO+" and calls for aid.";
}

void create() {
    ::create();
    set_spell_name("holy orb");
    set_spell_level(5);
    set_spell_type("priest");
    set_spell_domain("good");
    set_spell_sphere("combat");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
}

void spell_effect(int prof) {
    int damage;
    int i,j;
    object limb;
    object *foes;
    object *party;

    foes = all_living(place);
    foes = filter_array(foes, "is_non_immortal",FILTERS_D);

    if (caster->query_party()) {
        party =  PARTY_D->query_party_members(caster->query_party());
    } else {
        party = ({caster});
    }
    j = sizeof(foes);
    tell_room(place,"%^BOLD%^A sphere of power radiates out from "+CASTER->query_cap_name()+"'s hands!",CASTER);
    tell_object(CASTER,"%^BOLD%^A sphere of power radiates out from your hands.");
    for (i=0;i<j;i++) {
        if (!objectp(foes[i])) continue;
        if (foes[i] == caster) continue;
	if (foes[i]->query_is_mount()) continue;  // added by *Styx* per bug report 6/4/05
        if (member_array(foes[i],party) != -1) continue;
        if (interactive(foes[i]) && foes[i]->query_level() < 6) continue;
          limb = foes[i]->return_target_limb();
        damage = roll_dice(2,20)+roll_dice(5,CLEVEL)/2;//changed to lower damage on an area affect spell - Tsera 6/4/05
        if (ALIGN->is_evil(foes[i])) {
            tell_object(foes[i],"%^BOLD%^%^CYAN%^The power from "+CASTER->query_cap_name()+"'s sphere glows brightly as it engulfs you.");
            tell_object(CASTER,"%^BOLD%^%^CYAN%^The power from your sphere glows brightly as it engulfs "+foes[i]->query_cap_name()+".");
            tell_room(place,"%^BOLD%^%^CYAN%^The power from "+CASTER->query_cap_name()+"'s sphere glows brightly as it engulfs "+foes[i]->query_cap_name()+".",({foes[i],CASTER}));
            damage += roll_dice(1,CLEVEL);
/*
            if (!SAVING_D->saving_throw(foes[i],"spell",-2)) {
*/
            if(!do_save(foes[i],-2)) {
                damage_targ(foes[i],limb,damage);
            } else {
                damage_targ(foes[i],limb,damage/2);
            }
        } else if (ALIGN->is_neutral(foes[i])) {
            tell_object(foes[i],"%^BOLD%^The power from "+CASTER->query_cap_name()+"'s sphere glows as it engulfs you.");
            tell_object(CASTER,"%^BOLD%^The power from your sphere glows as it engulfs "+foes[i]->query_cap_name()+".");
            tell_room(place,"%^BOLD%^The power from "+CASTER->query_cap_name()+"'s sphere glows as it engulfs "+foes[i]->query_cap_name()+".",({foes[i],CASTER}));
/*
            if (!SAVING_D->saving_throw(foes[i],"spell",0)) {
*/
            if(!do_save(foes[i])) {
                damage_targ(foes[i],limb,damage);
            } else {
                damage_targ(foes[i],limb,damage/2);
            }
        } else if (ALIGN->is_good(foes[i])) {
            tell_object(foes[i],"%^CYAN%^The power from "+CASTER->query_cap_name()+"'s sphere pulses as it passes over you.");
            tell_object(CASTER,"%^CYAN%^The power from your sphere pulses as it passes over "+foes[i]->query_cap_name()+".");
            tell_room(place,"%^CYAN%^The power from "+CASTER->query_cap_name()+"'s sphere pulses as it passes over "+foes[i]->query_cap_name()+".",({foes[i],CASTER}));
            damage -= 2*(int)CLEVEL;
            if (damage>0) {
/*
                if (!SAVING_D->saving_throw(foes[i],"spell",2)) {
*/
            if(!do_save(foes[i],2)) {
                    damage_targ(foes[i],limb,damage);
                } else {
                    damage_targ(foes[i],limb,damage/2);
                }
            }
        }
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    TO->remove();
}

void help() {
    write(
@HELP
Spell  : Holy Orb
Level  : 5th Level
Sphere : Combat
Domain : Good
Syntax : chant holy orb

The orb is a spell normally granted to a priest who expects to
encounter enemies whose alignment opposes their own. When cast,
the spell streaks from the caster's hand to the desired point
of effect, where a sphere forms. The sphere drains the essence
of life from the targets in the area of effect. The sphere does
damage based on the alignment of the caster with respect to the
target.
HELP
);
    return;
}
