#include <random>

namespace sarah {
    int Roll(const std::default_random_engine& generator, int num_sides) {
        std::uniform_int_distribution<int> distribution(1, num_sides);
        return distribution(generator);
    }
}