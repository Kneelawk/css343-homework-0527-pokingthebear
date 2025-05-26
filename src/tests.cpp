//
// Created by cyan on 4/21/25.
//

#include "bear.h"
#include "ktest.hpp"

KTEST(bear_ctor) {
    const Bear bear;
    KASSERT_EQ(BearStates::INDIFFERENT, bear.state());
}

KTEST(bear_poke) {
    Bear bear;
    KASSERT_EQ(BearStates::INDIFFERENT, bear.state());
    KASSERT_EQ("The bear growls.", bear.doToBear(BearActions::POKE));
    KASSERT_EQ(BearStates::ANNOYED, bear.state());
    KASSERT_EQ("The bear gives you a nasty scratch.", bear.doToBear(BearActions::POKE));
    KASSERT_EQ(BearStates::ANGRY, bear.state());
    KASSERT_EQ("The bear gives you a savage bite.", bear.doToBear(BearActions::POKE));
    KASSERT_EQ(BearStates::VERY_ANGRY, bear.state());
    KASSERT_EQ("The bear gives you a severe mauling.", bear.doToBear(BearActions::POKE));
    KASSERT_EQ(BearStates::EXTREME_ANGER, bear.state());
    KASSERT_EQ("The bear reduces you to bits and pieces.\nFINAL: GAME OVER", bear.doToBear(BearActions::POKE));
    KASSERT_EQ(BearStates::ENRAGED, bear.state());
    KASSERT_EQ("FINAL: GAME OVER", bear.doToBear(BearActions::POKE));
    KASSERT_EQ(BearStates::ENRAGED, bear.state());
    KASSERT_EQ("FINAL: GAME OVER", bear.doToBear(BearActions::FEED));
    KASSERT_EQ(BearStates::ENRAGED, bear.state());
}

KTEST(bear_pet) {
    Bear bear;
    KASSERT_EQ(BearStates::INDIFFERENT, bear.state());
    KASSERT_EQ("The bear growls.", bear.doToBear(BearActions::POKE));
    KASSERT_EQ(BearStates::ANNOYED, bear.state());

    KASSERT_EQ("The bear calms down a bit.", bear.doToBear(BearActions::PET));
    KASSERT_EQ(BearStates::INDIFFERENT, bear.state());
}

KTEST(bear_feed) {
    Bear bear;
    KASSERT_EQ(BearStates::INDIFFERENT, bear.state());
    KASSERT_EQ("The bear growls.", bear.doToBear(BearActions::POKE));
    KASSERT_EQ(BearStates::ANNOYED, bear.state());
    KASSERT_EQ("The bear gives you a nasty scratch.", bear.doToBear(BearActions::POKE));
    KASSERT_EQ(BearStates::ANGRY, bear.state());

    KASSERT_EQ("The bear seems somewhat satisfied.", bear.doToBear(BearActions::FEED));
    KASSERT_EQ(BearStates::INDIFFERENT, bear.state());
}
