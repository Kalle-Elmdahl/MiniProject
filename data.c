#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"

uint8_t text[DISPLAY_ROWS][DISPLAY_WIDTH];
const uint8_t const font[128][CHAR_WIDTH] = {
	{0, 0, 0, 0, 0, 0, 0}, // Null
	{0, 0, 0, 0, 0, 0, 0}, // SOH
	{0, 0, 0, 0, 0, 0, 0}, // STX
	{0, 0, 0, 0, 0, 0, 0}, // ETX
	{0, 0, 0, 0, 0, 0, 0}, // EOT
	{0, 0, 0, 0, 0, 0, 0}, // ENQ
	{0, 0, 0, 0, 0, 0, 0}, // ACK
	{0, 0, 0, 0, 0, 0, 0}, // BEL
	{0, 0, 0, 0, 0, 0, 0}, // BS
	{0, 0, 0, 0, 0, 0, 0}, // TAB
	{0, 0, 0, 0, 0, 0, 0}, // LF
	{0, 0, 0, 0, 0, 0, 0}, // VT
	{0, 0, 0, 0, 0, 0, 0}, // FF
	{0, 0, 0, 0, 0, 0, 0}, // CR
	{0, 0, 0, 0, 0, 0, 0}, // SO
	{0, 0, 0, 0, 0, 0, 0}, // SI
	{0, 0, 0, 0, 0, 0, 0}, // DLE
	{0, 0, 0, 0, 0, 0, 0}, // DC1
	{0, 0, 0, 0, 0, 0, 0}, // DC2
	{0, 0, 0, 0, 0, 0, 0}, // DC3
	{0, 0, 0, 0, 0, 0, 0}, // DC4
	{0, 0, 0, 0, 0, 0, 0}, // NAK
	{0, 0, 0, 0, 0, 0, 0}, // SYN
	{0, 0, 0, 0, 0, 0, 0}, // ETB
	{0, 0, 0, 0, 0, 0, 0}, // CAN
	{0, 0, 0, 0, 0, 0, 0}, // EM
	{0, 0, 0, 0, 0, 0, 0}, // SUB
	{0, 0, 0, 0, 0, 0, 0}, // ENC
	{0, 0, 0, 0, 0, 0, 0}, // FS
	{0, 0, 0, 0, 0, 0, 0}, // GS
	{0, 0, 0, 0, 0, 0, 0}, // RS
	{0, 0, 0, 0, 0, 0, 0}, // US
	{0, 0, 0, 0, 0, 0, 0}, // Space, p, d
	{92, 0, 0}, // !
	{4, 3, 4, 3, 0, 0}, // "
	{36, 126, 36, 36, 126, 36, 0}, // #
	{36, 74, 255, 82, 36, 0, 0}, // $
	{70, 38, 16, 8, 100, 98, 0}, // %
	{52, 74, 74, 52, 32, 80, 0}, // &
	{4, 3, 0, 0}, // '
	{126, 129, 0, 0}, // (
	{129, 126, 0, 0}, // )
	{42, 28, 62, 28, 42, 0, 0}, // *
	{8, 8, 62, 8, 8, 0, 0}, // +
	{128, 96, 0, 0}, // ,
	{8, 8, 8, 8, 8, 0, 0}, // -
	{96, 0, 0, }, // .
	{64, 32, 16, 8, 4, 2, 0}, // /
	{62, 65, 73, 65, 62, 0, 0}, // 0
	{68, 124, 64, 0, 0}, // 1
	{72, 100, 84, 72, 0}, // 2
	{34, 73, 73, 54, 0, 0}, // 3 
	{14, 8, 127, 8, 0, 0}, // 4
	{35, 69, 69, 57, 0, 0}, // 5
	{62, 73, 73, 50, 0}, // 6
	{1, 97, 25, 7, 0, 0}, // 7
	{54, 73, 73, 54, 0, 0}, // 8
	{6, 9, 9, 126, 0, 0}, // 9
	{102, 0, 0}, // :
	{128, 102, 0, 0}, // ;
	{8, 20, 34, 65, 0, 0}, // <
	{20, 20, 20, 20, 0}, // =
	{65, 34, 20, 8, 0, 0}, // >
	{2, 1, 81, 9, 6, 0, 0}, // ?
	{28, 34, 89, 89, 82, 12, 0}, // @
	{120, 36, 36, 120, 0, 0}, // A
	{124, 84, 84, 40, 0, 0}, // B
	{56, 68, 68, 40, 0, 0}, // C
	{124, 68, 68, 56, 0, 0}, // D
	{124, 84, 84, 0, 0, 0}, // E
	{124, 20, 20, 0, 0, 0}, // F
	{56, 68, 84, 48, 0, 0}, // G
	{124, 16, 124, 0, 0}, // H
	{68, 124, 68, 0, 0}, // I
	{32, 64, 64, 63, 0, 0}, // J
	{124, 16, 40, 68, 0, 0}, // K
	{124, 64, 0, 0}, // L
	{124, 4, 8, 4, 124, 0, 0}, // M
	{124, 8, 16, 124, 0, 0}, // N
	{56, 68, 68, 56, 0, 0}, // O
	{124, 20, 20, 8, 0, 0}, // P
	{62, 65, 97, 126, 64, 0}, // Q
	{124, 20, 52, 72, 0, 0}, // R
	{72, 84, 84, 36, 0}, // S
	{4, 124, 4, 0, 0}, // T
	{60, 64, 64, 60, 0, 0}, // U 
	{12, 48, 64, 48, 12, 0, 0}, // V
	{124, 32, 16, 32, 124, 0, 0}, // W
	{108, 16, 16, 108, 0, 0}, // X
	{12, 16, 112, 16, 12, 0, 0}, // Y
	{100, 20, 12, 4, 0, 0}, // Z
	{127, 65, 65, 0, 0}, // [
	{2, 4, 8, 16, 32, 64, 0}, // backslash
	{65, 65, 127, 0, 0}, // ]
	{4, 2, 1, 2, 4, 0, 0}, // ^
	{64, 64, 64, 64, 64, 64, 0}, // _
	{1, 2, 4, 0, 0}, // `
	{120, 36, 36, 120, 0, 0}, // a
	{124, 84, 84, 40, 0, 0}, // b
	{56, 68, 68, 40, 0, 0}, // c
	{124, 68, 68, 56, 0, 0}, // d
	{124, 84, 84, 0, 0, 0}, // e
	{124, 20, 20, 0, 0, 0}, // f
	{56, 68, 84, 48, 0, 0}, // g
	{124, 16, 124, 0, 0}, // h
	{68, 124, 68, 0, 0}, // i
	{32, 64, 64, 63, 0, 0}, // j
	{124, 8, 20, 68, 0, 0}, // k
	{124, 64, 0, 0}, // l
	{124, 4, 8, 4, 124, 0, 0}, // m
	{124, 8, 16, 124, 0, 0}, // n
	{56, 68, 68, 56, 0, 0}, // o
	{124, 20, 20, 8, 0, 0}, // p
	{62, 65, 97, 126, 64, 0}, // q
	{124, 20, 52, 72, 0, 0}, // r
	{72, 84, 84, 36, 0}, // s
	{4, 124, 4, 0, 0}, // t
	{60, 64, 64, 60, 0, 0}, // u
	{12, 48, 64, 48, 12, 0, 0}, // v
	{124, 32, 16, 32, 124, 0, 0}, // w
	{108, 16, 16, 108, 0, 0}, // x
	{12, 16, 112, 16, 12, 0, 0}, // y
	{100, 20, 12, 4, 0, 0}, // z
	{8, 28, 34, 65, 0, 0}, // {
	{255, 0, 0, 0, 0, 0}, // |
	{65, 34, 28, 8, 0, 0}, // }
	{4, 2, 4, 2, 0, 0}, // ~
	{120, 68, 66, 68, 120, 0} // Delete
};

// Image for lever_up
// Displayed for example in menu (indicating to initate play)
const uint8_t const lever_up[16][9] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Image for lever_down
// Shown for example when game begins
const uint8_t const lever_down[16][9] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1}
};

const uint8_t const arrow_left[5][3] = {
    {0, 0, 1},
    {0, 1, 1},
    {1, 1, 1},
    {0, 1, 1},
    {0, 0, 1},
};

const uint8_t const arrow_right[5][3] = {
    {1, 0, 0},
    {1, 1, 0},
    {1, 1, 1},
    {1, 1, 0},
    {1, 0, 0},
};

const uint8_t const arrow_up[3][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
};

const uint8_t const arrow_down[3][5] = {
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0},
};

const uint8_t const check_box[5][6] = {
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 1, 0},
    {1, 1, 0, 1, 0, 0},
    {0, 1, 1, 0, 0, 0},
};

const uint8_t const apple_icon[3][3] = {
    {0, 1, 0},
    {1, 1, 1},
    {0, 1, 0},
};

const uint8_t const sq_obstacle[5][5] = {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1},
	{0, 1, 1, 1, 0},
};

const uint8_t const sq_obstacle_animation[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {1, 0, 0, 0, 1},
	{0, 1, 0, 1, 0},
	{0, 1, 1, 1, 0},
};