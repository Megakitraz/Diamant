#pragma once

/* WINDOW CONSTANTS */
constexpr int WINDOW_WIDTH = 1500;
constexpr int WINDOW_HEIGHT = 800;
constexpr int WINDOW_TARGET_FPS = 60;

/* SPLASH SCREEN CONSTANTS */
constexpr int SPLASH_SCREEN_DURATION_MS = 1500;

/* PANEL CONSTANTS */
constexpr int PANEL_HEIGHT = 400;
constexpr int PANEL_MAX_ROW = 5;

/* CARDS CONSTANTS */
constexpr int CARD_WIDTH = 220;
constexpr int CARD_HEIGHT = 220;
constexpr int CARD_PADDING = 12;

constexpr int CARD_TREASURE_COUNT = 15;
constexpr int CARD_DANGER_TYPE = 5;
constexpr int CARD_DANGER_OCCURENCE = 3;
constexpr int CARD_DANGER_COUNT = CARD_DANGER_TYPE * CARD_DANGER_OCCURENCE;
constexpr int CARD_RELIC_COUNT = 5;
constexpr int CARDS_COUNT = CARD_TREASURE_COUNT + CARD_DANGER_COUNT + CARD_RELIC_COUNT;

/* GAME CONSTANTS */
constexpr double GAME_TURN_WAIT = 1.0;

constexpr int GAME_BOT_COUNT = 3;
constexpr int GAME_BOT_CIRCLE_RADIUS = 30;

constexpr int GAME_MIN_PLAYER = 1;
constexpr int GAME_MAX_PLAYER = 8;

constexpr int GAME_MIN_ROUND = 1;
constexpr int GAME_MAX_ROUND = 5;

/* ASSETS CONSTANTS */
constexpr char ASSETS_PATH[] = "../../assets/";