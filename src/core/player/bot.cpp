#include "core/player/bot.h"

diamant::bot::bot(const std::string& name, float moving_forward_probability) : player(name), moving_forward_probability(moving_forward_probability) {}

void diamant::bot::play() {
    
    PlayerAction action = PlayerAction::MoveForward;

    /* Tirage du choix, proba : moving_forward_probability */
    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<> dist({moving_forward_probability,1-moving_forward_probability});
    int choice = dist(gen);
    if (choice == 0) {
        action = PlayerAction::MoveForward;
    } else {
        action = PlayerAction::Leave;
    }

    /*std::cout << "[ " << moving_forward_probability << " , " << 1-moving_forward_probability << " ]" << std::endl;
    std::cout << "dist : " << choice << std::endl;*/
    
    switch (action)
    {
    case PlayerAction::MoveForward:
        // réduire la probabilité de MoveForward
        diamant::player::continue_exploring();
        //std::cout << "bot continue" << std::endl;
        this->moving_forward_probability -= 0.02f;
        break;
    case PlayerAction::Leave:
        diamant::player::finish_exploring();
        //std::cout << "bot leave" << std::endl;
        this->moving_forward_probability = 1.f;
        break;
    default: break;
    }
}