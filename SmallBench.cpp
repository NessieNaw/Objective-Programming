#include "Small.h"
#include "BenchIncludes.h"
#include<deque>
#include<map>
#include <unordered_map>


void operator1( State &state )
{
    Small small{};
    Small small2{};;

    bool condition;
    for (auto _ : state )
    {
        condition = small < small2;
        DoNotOptimize(condition);
    }
}
BENCHMARK(operator1)->RangeMultiplier(2)->Range(1,1024);

void operator2( State &state )
{
    Small small{};
    Small small2{};;

    bool condition;
    for (auto _ : state )
    {
        condition = small == small2;
        DoNotOptimize(condition);
    }
}
BENCHMARK(operator2)->RangeMultiplier(2)->Range(1,1024);


void operatorhash( State &state )
{
    Small small{};
    struct std::hash<Small> hasz{};
    for (auto _ : state )
    {
        hasz(small);
    }
}
BENCHMARK(operatorhash)->RangeMultiplier(2)->Range(1,1024);




void dequeat( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;
    std::deque<Small>deque(size);

    Small small{};
    *small.data = '1';
    for (auto _ : state )
    {
        deque.at(0);

    }
    state.SetComplexityN(N);
}


BENCHMARK(dequeat)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void dequeop( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);
    Small small{};
    *small.data = '1';
    for (auto _ : state )
    {
        deque[0];

    }
    state.SetComplexityN(N);
}

BENCHMARK(dequeop)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void dequefront( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);
    Small small{};
    *small.data = '1';
    for (auto _ : state )
    {
        deque.front();

    }
    state.SetComplexityN(N);
}

BENCHMARK(dequefront)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void dequeback( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);
    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        deque.back();

    }
    state.SetComplexityN(N);
}

BENCHMARK(dequeback)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void dequesize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);
    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        deque.size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(dequesize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void dequeempty( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);
    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        deque.empty();

    }
    state.SetComplexityN(N);
}

BENCHMARK(dequeempty)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void dequemaxsize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);
    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        deque.max_size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(dequemaxsize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void dequeshrinktofit( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);
    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        deque.shrink_to_fit();

    }
    state.SetComplexityN(N);
}

BENCHMARK(dequeshrinktofit)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void dequeclear( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);
    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        deque.clear();

    }
    state.SetComplexityN(N);
}

BENCHMARK(dequeclear)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void dequeinsert( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);
    auto iter = deque.begin();
    Small small{};
    *small.data = '1';
    *small.data = '2';

    for (auto _ : state )
    {
        deque.insert(iter,Small{2});

    }
    state.SetComplexityN(N);
}


BENCHMARK(dequeinsert)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void dequeerase( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';
    *small.data = '3';
    *small.data = '3';

    for (auto _ : state )
    {
        deque.erase(deque.begin(),deque.end());
    }
    state.SetComplexityN(N);
}

BENCHMARK(dequeerase)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void dequepushback( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';
    *small.data = '3';
    *small.data = '3';

    for (auto _ : state )
    {
        deque.push_back(small);
    }
    state.SetComplexityN(N);
}

BENCHMARK(dequepushback)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void dequepushfront( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';
    *small.data = '3';
    *small.data = '3';

    for (auto _ : state )
    {
        deque.push_front(small);
    }
    state.SetComplexityN(N);
}

BENCHMARK(dequepushfront)->RangeMultiplier(2)->Range(1,1024)->Complexity();


void dequepopback( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';


    for (auto _ : state )
    {
        deque.push_back(Small{1});
        deque.pop_back();
    }
    state.SetComplexityN(N);
}

BENCHMARK(dequepopback)->RangeMultiplier(2)->Range(1,1024)->Complexity();


void dequepopfront( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);

    Small small{};
    *small.data = '1';

    for (auto _ : state )
    {
        deque.push_back(Small{1});
        deque.pop_front();
    }
    state.SetComplexityN(N);
}
BENCHMARK(dequepopfront)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void dequeresize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';
    *small.data = '3';
    *small.data = '3';

    for (auto _ : state )
    {
        deque.resize(2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(dequeresize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void dequeswap( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';
    *small.data = '3';
    *small.data = '3';

    for (auto _ : state )
    {
        deque.swap(deque);
    }
    state.SetComplexityN(N);
}

BENCHMARK(dequeswap)->RangeMultiplier(2)->Range(1,1024)->Complexity();

//=======================

void mempty( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Small> multimap;
    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        multimap.empty();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mempty)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void msize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Small> multimap;
    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        multimap.size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(msize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mmaxsize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Small> multimap;
    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        multimap.max_size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mmaxsize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mclear( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Small> multimap;
    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        multimap.clear();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mclear)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void minsert( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Small> multimap;
    auto iter = multimap.begin();
    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        multimap.insert(iter, {1,Small{2}});

    }
    state.SetComplexityN(N);
}

BENCHMARK(minsert)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void merase( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Small> multimap;
    auto iter = multimap.begin();
    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        multimap.erase(multimap.begin(),multimap.end());

    }
    state.SetComplexityN(N);
}

BENCHMARK(merase)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mswap( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Small> multimap;

    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        multimap.swap(multimap);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mswap)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mcount( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Small> multimap;

    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        multimap.count(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mcount)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mfind( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Small> multimap;

    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        multimap.find(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mfind)->RangeMultiplier(2)->Range(1,1024)->Complexity();


void meqrange( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Small> multimap;

    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        multimap.equal_range(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(meqrange)->RangeMultiplier(2)->Range(1,1024)->Complexity();


void mlbound( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Small> multimap;

    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        multimap.lower_bound(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mlbound)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mubound( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Small> multimap;

    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        multimap.upper_bound(2);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mubound)->RangeMultiplier(2)->Range(1,1024)->Complexity();

//================================

void umempty( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Small> unordered_map(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        unordered_map.empty();

    }
    state.SetComplexityN(N);
}

BENCHMARK(umempty)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void umsize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Small> unordered_map(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        unordered_map.size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(umsize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void ummaxsize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Small> unordered_map(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        unordered_map.max_size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(ummaxsize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void umclear( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Small> unordered_map(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        unordered_map.clear();

    }
    state.SetComplexityN(N);
}

BENCHMARK(umclear)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void uminsert( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Small> unordered_map(size);
    auto iter = unordered_map.begin();
    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        unordered_map.insert(iter, {1,Small{2}});

    }
    state.SetComplexityN(N);
}

BENCHMARK(uminsert)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void umerase( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Small> unordered_map(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        unordered_map.erase(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(umerase)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void umswap( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Small> unordered_map(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        unordered_map.swap(unordered_map);

    }
    state.SetComplexityN(N);
}

BENCHMARK(umswap)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void umat( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Small> unordered_map(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';
    unordered_map.insert(unordered_map.begin(), {1,Small{2}});
        for (auto _ : state )
    {
        unordered_map.at(1) = Small{1};

    }
    state.SetComplexityN(N);
}

BENCHMARK(umat)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void umop( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Small> unordered_map(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';

    for (auto _ : state )
    {
        unordered_map[0];

    }
    state.SetComplexityN(N);
}

BENCHMARK(umop)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void umcount( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Small> unordered_map(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';

    for (auto _ : state )
    {
        unordered_map.count(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(umcount)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void umfind( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Small> unordered_map(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';

    for (auto _ : state )
    {
        unordered_map.find(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(umfind)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void umeqr( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Small> unordered_map(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';

    for (auto _ : state )
    {
        unordered_map.equal_range(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(umeqr)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void umreserve( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Small> unordered_map(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';

    for (auto _ : state )
    {
        unordered_map.reserve(size);

    }
    state.SetComplexityN(N);
}

BENCHMARK(umreserve)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void umrehash( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Small> unordered_map(size);

    Small small{};
    *small.data = '1';
    *small.data = '2';

    for (auto _ : state )
    {
        unordered_map.rehash(size);

    }
    state.SetComplexityN(N);
}

BENCHMARK(umrehash)->RangeMultiplier(2)->Range(1,1024)->Complexity();