#pragma once

#include <random>

struct Large {

    constexpr static unsigned SIZE = 128u*1024u;

    double data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void randomize() {
        static std::random_device rd{};
        static std::mt19937 gen{rd()};
        static std::uniform_real_distribution<> dis{};

        for (double &i : data) {
            i = dis(gen);
        }
    }

    bool operator<(const Large &rhs) const {

        // TODO: Implement me!
        for( int i = 0; i < SIZE; i++ )
            if( data[i] >= rhs.data[i] )
                return false;
        return true;
    }

    bool operator==(const Large &rhs) const {

        // TODO: Implement me!
        for( int i = 0; i < SIZE; i++ )
            if( data[i] != rhs.data[i] )
                return false;
        return true;
    }
};

namespace std {
    template<>
    struct hash<Large> {
        std::size_t operator()(const Large &d) const {

            std::hash<char> hash;

            // TODO: Implement me!
            return hash(*d.data) + hash(*d.data) << 1;
        }
    };
}
