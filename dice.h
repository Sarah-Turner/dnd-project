#pragma once
#include <random>
namespace sarah {
    // Generates a random number from a dice with num_sides sides. Generator should be re-used for all rolls.
    int Roll(std::default_random_engine& generator, int num_sides);
}