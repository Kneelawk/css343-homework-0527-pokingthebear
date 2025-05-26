//
// Created by cyan on 5/26/25.
//

#ifndef BEAR_H
#define BEAR_H
#include <algorithm>
#include <functional>
#include <string>

typedef int BearState;
typedef int BearAction;

namespace BearStates {
    constexpr BearState INDIFFERENT = 0;
    constexpr BearState ANNOYED = 1;
    constexpr BearState ANGRY = 2;
    constexpr BearState VERY_ANGRY = 3;
    constexpr BearState EXTREME_ANGER = 4;
    constexpr BearState ENRAGED = 5;
}

namespace BearActions {
    constexpr BearAction OTHER = 0;
    constexpr BearAction POKE = 1;
    constexpr BearAction PET = 2;
    constexpr BearAction FEED = 3;
}

inline std::string bearStateToString(const BearState state) {
    switch (state) {
        default:
            return "Indifferent";
        case BearStates::ANNOYED:
            return "Annoyed";
        case BearStates::ANGRY:
            return "Angry";
        case BearStates::VERY_ANGRY:
            return "Very Angry";
        case BearStates::EXTREME_ANGER:
            return "Extreme Anger";
        case BearStates::ENRAGED:
            return "Enraged";
    }
}

inline BearAction parseBearAction(const std::string &str) {
    std::string lower = str;
    std::transform(lower.begin(), lower.end(), lower.begin(), [](const char c) {
        return std::tolower(c);
    });

    if (lower == "poke") {
        return BearActions::POKE;
    }
    if (lower == "pet") {
        return BearActions::PET;
    }
    if (lower == "feed") {
        return BearActions::FEED;
    }
    return BearActions::OTHER;
}

class Bear {
    BearState state_ = BearStates::INDIFFERENT;

public:
    std::string doToBear(BearAction action);

    BearState state() const {
        return state_;
    }
};


#endif //BEAR_H
