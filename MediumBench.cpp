#include "Medium.h"
#include "BenchIncludes.h"
#include<deque>
#include<map>
#include <unordered_map>


void operator1m( State &state )
{
    Medium medium{};
    Medium medium1{};;

    bool condition;
    for (auto _ : state )
    {
        condition = medium < medium1;
        DoNotOptimize(condition);
    }
}
BENCHMARK(operator1m)->RangeMultiplier(2)->Range(1,1024);

void operator2m( State &state )
{
    Medium medium{};
    Medium medium1{};;

    bool condition;
    for (auto _ : state )
    {
        condition = medium == medium1;
        DoNotOptimize(condition);
    }
}
BENCHMARK(operator2m)->RangeMultiplier(2)->Range(1,1024);


void operatorhashm( State &state )
{
    Medium medium{};
    struct std::hash<Medium> hasz{};
    for (auto _ : state )
    {
        hasz(medium);
    }
}
BENCHMARK(operatorhashm)->RangeMultiplier(2)->Range(1,1024);




void mdequeat( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;
    std::deque<Medium>deque(size);

    Medium medium{};
    *medium.data = '1';
    for (auto _ : state )
    {
        deque.at(0);

    }
    state.SetComplexityN(N);
}


BENCHMARK(mdequeat)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mdequeop( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Medium> deque(size);
    Medium medium{};
    *medium.data = '1';
    for (auto _ : state )
    {
        deque[0];

    }
    state.SetComplexityN(N);
}

BENCHMARK(mdequeop)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mdequefront( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Medium> deque(size);
    Medium medium{};
    *medium.data = '1';
    for (auto _ : state )
    {
        deque.front();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mdequefront)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mdequeback( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Medium> deque(size);
    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        deque.back();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mdequeback)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mdequesize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Medium> deque(size);
    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        deque.size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mdequesize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mdequeempty( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Medium> deque(size);
    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        deque.empty();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mdequeempty)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mdequemaxsize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Medium> deque(size);
    Medium small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        deque.max_size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mdequemaxsize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mdequeshrinktofit( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Medium> deque(size);
    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        deque.shrink_to_fit();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mdequeshrinktofit)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mdequeclear( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Medium> deque(size);
    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        deque.clear();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mdequeclear)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mdequeinsert( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Medium> deque(size);
    auto iter = deque.begin();
    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';

    for (auto _ : state )
    {
        deque.insert(iter,Medium{2});

    }
    state.SetComplexityN(N);
}


BENCHMARK(mdequeinsert)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mdequeerase( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Medium> deque(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    *medium.data = '3';
    *medium.data = '3';

    for (auto _ : state )
    {
        deque.erase(deque.begin(),deque.end());
    }
    state.SetComplexityN(N);
}

BENCHMARK(mdequeerase)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mdequepushback( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Medium> deque(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    *medium.data = '3';
    *medium.data = '3';

    for (auto _ : state )
    {
        deque.push_back(medium);
    }
    state.SetComplexityN(N);
}

BENCHMARK(mdequepushback)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mdequepushfront( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Medium> deque(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    *medium.data = '3';
    *medium.data = '3';

    for (auto _ : state )
    {
        deque.push_front(medium);
    }
    state.SetComplexityN(N);
}

BENCHMARK(mdequepushfront)->RangeMultiplier(2)->Range(1,1024)->Complexity();


void mdequepopback( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Medium> deque(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';

    for (auto _ : state )
    {
        deque.push_back(Medium{1});
        deque.pop_back();
    }
    state.SetComplexityN(N);
}

BENCHMARK(mdequepopback)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mdequepopfront( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Medium> deque(size);

    Medium medium{};
    *medium.data = '1';
;
    for (auto _ : state )
    {
        deque.push_front(medium);
        deque.pop_front();
    }
    state.SetComplexityN(N);
}
BENCHMARK(mdequepopfront)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mdequeresize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Medium> deque(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    *medium.data = '3';
    *medium.data = '3';

    for (auto _ : state )
    {
        deque.resize(2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(mdequeresize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mdequeswap( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Medium> deque(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    *medium.data = '3';
    *medium.data = '3';

    for (auto _ : state )
    {
        deque.swap(deque);
    }
    state.SetComplexityN(N);
}

BENCHMARK(mdequeswap)->RangeMultiplier(2)->Range(1,1024)->Complexity();

//=======================

void mmempty( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Medium> multimap;
    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        multimap.empty();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mmempty)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mmsize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Medium> multimap;
    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        multimap.size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mmsize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mmmaxsize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Medium> multimap;
    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        multimap.max_size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mmmaxsize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mmclear( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Medium> multimap;
    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        multimap.clear();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mmclear)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mminsert( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Medium> multimap;
    auto iter = multimap.begin();
    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        multimap.insert(iter, {1,Medium{2}});

    }
    state.SetComplexityN(N);
}

BENCHMARK(mminsert)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mmerase( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Medium> multimap;
    auto iter = multimap.begin();
    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        multimap.erase(multimap.begin(),multimap.end());

    }
    state.SetComplexityN(N);
}

BENCHMARK(mmerase)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mmswap( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Medium> multimap;

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        multimap.swap(multimap);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mmswap)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mmcount( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Medium> multimap;

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        multimap.count(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mmcount)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mmfind( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Medium> multimap;

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        multimap.find(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mmfind)->RangeMultiplier(2)->Range(1,1024)->Complexity();


void mmeqrange( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Medium> multimap;

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        multimap.equal_range(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mmeqrange)->RangeMultiplier(2)->Range(1,1024)->Complexity();


void mmlbound( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Medium> multimap;

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        multimap.lower_bound(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mmlbound)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mmubound( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Medium> multimap;

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        multimap.upper_bound(2);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mmubound)->RangeMultiplier(2)->Range(1,1024)->Complexity();

//================================

void mumempty( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Medium> unordered_map(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        unordered_map.empty();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mumempty)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mumsize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Medium> unordered_map(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        unordered_map.size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mumsize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mummaxsize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Medium> unordered_map(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        unordered_map.max_size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mummaxsize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mumclear( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Medium> unordered_map(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        unordered_map.clear();

    }
    state.SetComplexityN(N);
}

BENCHMARK(mumclear)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void muminsert( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Medium> unordered_map(size);
    auto iter = unordered_map.begin();
    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        unordered_map.insert(iter, {1,Medium{2}});

    }
    state.SetComplexityN(N);
}

BENCHMARK(muminsert)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mumerase( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Medium> unordered_map(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        unordered_map.erase(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mumerase)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mumswap( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Medium> unordered_map(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    for (auto _ : state )
    {
        unordered_map.swap(unordered_map);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mumswap)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mumat( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Medium> unordered_map(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';
    unordered_map.insert(unordered_map.begin(), {1,Medium{2}});
    for (auto _ : state )
    {
        unordered_map.at(1) = Medium{1};

    }
    state.SetComplexityN(N);
}

BENCHMARK(mumat)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mumop( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Medium> unordered_map(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';

    for (auto _ : state )
    {
        unordered_map[0];

    }
    state.SetComplexityN(N);
}

BENCHMARK(mumop)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mumcount( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Medium> unordered_map(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';

    for (auto _ : state )
    {
        unordered_map.count(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mumcount)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mumfind( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Medium> unordered_map(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';

    for (auto _ : state )
    {
        unordered_map.find(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mumfind)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mumeqr( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Medium> unordered_map(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';

    for (auto _ : state )
    {
        unordered_map.equal_range(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mumeqr)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mumreserve( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Medium> unordered_map(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';

    for (auto _ : state )
    {
        unordered_map.reserve(size);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mumreserve)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void mumrehash( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Medium> unordered_map(size);

    Medium medium{};
    *medium.data = '1';
    *medium.data = '2';

    for (auto _ : state )
    {
        unordered_map.rehash(size);

    }
    state.SetComplexityN(N);
}

BENCHMARK(mumrehash)->RangeMultiplier(2)->Range(1,1024)->Complexity();