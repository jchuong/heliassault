#ifndef __GAME_H__
#define __GAME_H__

enum BUTTON_STATE {
  NONE = 0,
  UP = 1,
  DOWN = 2,
  LEFT = 4,
  RIGHT = 8,
};

enum GAME_STATE {
  MENU = 0,
  PLAYING = 1,
  PAUSED = 2,
};

inline BUTTON_STATE operator|(BUTTON_STATE a, BUTTON_STATE b) {
  return static_cast<BUTTON_STATE>(static_cast<int>(a) | static_cast<int>(b));
}

inline BUTTON_STATE operator&(BUTTON_STATE a, BUTTON_STATE b) {
  return static_cast<BUTTON_STATE>(static_cast<int>(a) & static_cast<int>(b));
}

inline BUTTON_STATE operator^(BUTTON_STATE a, BUTTON_STATE b) {
  return static_cast<BUTTON_STATE>(static_cast<int>(a) ^ static_cast<int>(b));
}

inline BUTTON_STATE operator~(BUTTON_STATE a) {
  return static_cast<BUTTON_STATE>(~static_cast<int>(a));
}
#endif // __GAME_H__
