#pragma once

/* WINDOW CONSTANTS */
constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;
constexpr int WINDOW_TARGET_FPS = 60;

/* SPLASH SCREEN CONSTANTS */
constexpr int SPLASH_SCREEN_DURATION_MS = 500;

/* PANEL CONSTANTS */
constexpr int PANEL_HEIGHT = 400;
constexpr int PANEL_MAX_ROW = 5;

/* CARDS CONSTANTS */
constexpr int CARD_WIDTH = 200;
constexpr int CARD_HEIGHT = 200;
constexpr int CARD_PADDING = 10;

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