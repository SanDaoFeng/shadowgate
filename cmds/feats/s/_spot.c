#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("GeneralCombat");
    feat_name("spot");
    feat_desc("The Spot skill is used primarily to detect characters or creatures who are hiding. Typically, your Spot check is opposed by the stealth check of the creature trying not to be seen. Spot increases your ability to passively percieve, removing panalty to perception when making passice rolls.

A Spot check result higher than 20 generally lets you become aware of an invisible creature near you, though you can’t actually see it.

Spot, like passive perception, is entirely deterministing in this game and offers no chances. It either work or doesn't.

%^BOLD%^See also:%^RESET%^ status effects");
    permanent(1);
    allow_blind(1);
}

int allow_shifted() { return 1; }

void execute_feat() {
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob) {
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob) {
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}
