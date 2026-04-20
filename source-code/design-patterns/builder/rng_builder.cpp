#include "rng_builder.h"

Rng_builder& Rng_builder::reset() {
    a_ = a_default_;
    b_ = b_default_;
    seed_ = 0;
    seeded_ = false;
    return *this;
}
