//------------------------------------------------------------------------------
//  SoundGen.cc
//------------------------------------------------------------------------------
#include "Pre.h"
#include "SoundGen.h"

namespace Oryol {
namespace SoundGen {

// see here: http://www.lomont.org/Software/Games/PacMan/PacmanEmulation.pdf
const char NamcoVoice::WaveData[NamcoVoice::NumWaves][NamcoVoice::NumWaveSamples] = {
    {
        // Pacman wave0
        7, 9, 10, 11, 12, 13, 13, 14, 14, 14, 13, 13, 12, 11, 10, 9,
        7, 5,  4,  3,  2,  1,  1,  0,  0,  0,  1,  1,  2,  3,  4, 5
    },
    {
        // Pacman wave1
        7, 12, 14, 14, 13, 11,  9, 10, 11, 11, 10,  9,  6,  4,  3,  5,
        7,  9, 11, 10,  8,  5,  4,  3,  3,  4,  5,  3,  1,  0,  0,  2
    },
    {
        // Pacman wave2
        7, 10, 12, 13, 14, 13, 12, 10,  7,  4,  2,  1,  0,  1,  2,  4,
        7, 11, 13, 14, 13, 11,  7,  3,  1,  0,  1,  3,  7,  14,  7, 0
    },
    {
        // Pacmane wave3
        7, 13, 11, 8, 11, 13, 9, 6, 11, 14, 12, 7, 9, 10, 6, 2,
        7, 12, 8, 4, 5, 7, 2, 0, 3, 7, 5, 1, 3, 6, 3, 1
    },
    {
        // Pacman wave4
        0,  8, 15,  7, 1,  8, 14,  7, 2,  8, 13,  7, 3,  8, 12,  7,
        4,  8, 11,  7, 5,  8, 10,  7, 6,  8,  9,  7, 7,  8,  8,  7
    },
    {
        // Pacman wave5
        7, 8, 6, 9, 5, 10, 4, 11, 3, 12, 2, 13, 1, 14, 0, 15,
        0, 15, 1, 14, 2, 13, 3, 12, 4, 11, 5, 10, 6, 9, 7, 8
    },
    {
        // Pacman wave6
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
    },
    {
        // Pacman wav7
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
    }
};

} // namespace SoundGen
} // namespace Oryol