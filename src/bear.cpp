//
// Created by cyan on 5/26/25.
//

#include "bear.h"

std::string Bear::doToBear(const BearAction action) {
    if (state_ >= BearStates::ENRAGED) {
        return "FINAL: GAME OVER";
    }

    switch (action) {
        case BearActions::POKE:
            state_++;
            switch (state_) {
                case BearStates::INDIFFERENT:
                    return "How did you do that?";
                case BearStates::ANNOYED:
                    return "The bear growls.";
                case BearStates::ANGRY:
                    return "The bear gives you a nasty scratch.";
                case BearStates::VERY_ANGRY:
                    return "The bear gives you a savage bite.";
                case BearStates::EXTREME_ANGER:
                    return "The bear gives you a severe mauling.";
                case BearStates::ENRAGED:
                    return "The bear reduces you to bits and pieces.\nFINAL: GAME OVER";
                default:
                    return "FINAL: GAME OVER";
            }
        case BearActions::PET:
            if (state_ > BearStates::INDIFFERENT) {
                state_--;
            }

            return "The bear calms down a bit.";
        case BearActions::FEED:
            state_ = BearStates::INDIFFERENT;

            return "The bear seems somewhat satisfied.";
        default:
            return "Whaat?";
    }
}
