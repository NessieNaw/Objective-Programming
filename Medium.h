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

       for( int i = 0; i < SIZE; i++ )
            if( data[i] >= rhs.data[i] )
                return false;
        return true;
    }

    bool operator==(const Medium &rhs) const {

        for( int i = 0; i < SIZE; i++ )
            if( data[i] != rhs.data[i] )
                return false;
        return true;
    }
};

namespace std {
    template<>
    struct hash<Medium> {
        std::size_t operator()(const Medium &d) const {
            std::hash<char> hash;

            // TODO: Implement me!
            return( hash(*d.data) + hash(*d.data) )<< 1;
        }
    };
}