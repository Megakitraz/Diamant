#pragma once

/* WINDOW CONSTANTS */
constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;
constexpr int WINDOW_TARGET_FPS = 60;

/* SPLASH SCREEN CONSTANTS */
constexpr int SPLASH_SCREEN_DURATION_MS = 500;

/* INGAME CONSTANTS */
constexpr int GAME_TREASURE_CARD = 15;
constexpr int GAME_DANGER_CARDS = 15;
constexpr int GAME_RELIC_CARDS = 5;
constexpr int GAME_CARDS_COUNT = GAME_TREASURE_CARD + GAME_DANGER_CARDS + GAME_RELIC_CARDS;

constexpr int GAME_BOT_COUNT = 3;
constexpr float GAME_BOT_WAIT_TIME_SEC = 2.0f;

constexpr int GAME_MIN_PLAYER = 1;
constexpr int GAME_MAX_PLAYER = 8;

constexpr int GAME_MIN_ROUND = 1;
constexpr int GAME_MAX_ROUND = 5;