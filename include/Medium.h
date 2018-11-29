#pragma once

#include <random>

struct Medium {

    constexpr static unsigned SIZE = 256u;
    int data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void randomize() {
        static std::random_device rd{};
        static std::mt19937 gen{rd()};
        static std::uniform_int_distribution<int> dis{};

        for (int &i : data)
            i = dis(gen);
    }
    void print( const Medium &rhs )
    {
        for( int i = 0; i < SIZE/32; i++ )
            printf(" %d\n", rhs.data[i] );
    }
    bool operator<(const Medium &rhs) const {

        // TODO: Implement me!
        for( int i = 0; i < SIZE; i++ )
            data[i] < rhs.data[i];
        return false;
    }

    bool operator==(const Medium &rhs) const {

        // TODO: Implement me!
        for( int i = 0; i < SIZE; i++ )
            data[i] == rhs.data[i];
        return true;
    }
};

namespace std {
    template<>
    struct hash<Medium> {
        std::size_t operator()(const Medium &d) const {

            // TODO: Implement me!
            return 0;
        }
    };
}