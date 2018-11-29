#pragma once

#include <random>

struct Small {

    constexpr static unsigned SIZE = 1u;
    char data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void randomize() {
        static std::random_device rd{};
        static std::mt19937 gen{rd()};
        static std::uniform_int_distribution<char> dis{-128, 127};

        for (char &i : data)
            i = dis(gen);
    }
    void print( const Small &rhs )
    {
        printf(" %d\n", *rhs.data );
    }


    bool operator<(const Small &rhs) const {

        if(*data < *rhs.data)
            return false;
        else
            return true;
    }

    bool operator==(const Small &rhs) const {

        if (*data == *rhs.data)
            return true;
        else
            return false;
    }
};

namespace std {
    template<>
    struct hash<Small> {

        std::size_t operator()(const Small &d) const {

            // TODO: Implement me!
            std::hash<char> hash;

          // hash(*d.data) == *d.data;

            //return 0;
            return hash(*d.data) << 1;
        }
    };
}
