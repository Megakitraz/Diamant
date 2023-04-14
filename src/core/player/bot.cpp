#include "core/player/bot.h"

diamant::bot::bot(float moving_forward_probability) : player(), moving_forward_probability(moving_forward_probability) {}

void diamant::bot::play() {
    
    PlayerAction action = PlayerAction::MoveForward;

    /* Tirage du choix, proba : moving_forward_probability */
    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<> dist({0.5,0.5});
    int choice = dist(gen);
    if (choice == 0) {
        action = PlayerAction::MoveForward;
        std::cout << "bot pick continue" << std::endl;
    } else {
        action = PlayerAction::Leave;
        std::cout << "bot pick leave" << std::endl;
    }
    
    switch (action)
    {
    case PlayerAction::MoveForward:
        // réduire la probabilité de MoveForward
        diamant::player::continue_exploring();
        std::cout << "bot continue" << std::endl;
        break;
    case PlayerAction::Leave:
        diamant::player::finish_exploring();
        std::cout << "bot leave" << std::endl;
        break;
    default: break;
    }
}