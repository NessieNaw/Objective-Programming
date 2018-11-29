#include "Large.h"
#include "BenchIncludes.h"
#include <deque>
#include <map>
#include <unordered_map>


void operator1l( State &state )
{
    Large large{};
    Large large1{};;

    bool condition;
    for (auto _ : state )
    {
        condition = large < large1;
        DoNotOptimize(condition);
    }
}
BENCHMARK(operator1l)->RangeMultiplier(2)->Range(1,1024);

void operator2l( State &state )
{
    Large large{};
    Large large1{};;

    bool condition;
    for (auto _ : state )
    {
        condition = large == large1;
        DoNotOptimize(condition);
    }
}
BENCHMARK(operator2l)->RangeMultiplier(2)->Range(1,1024);


void operatorhashl( State &state )
{
    Large large{};
    struct std::hash<Large> hasz{};
    for (auto _ : state )
    {
        hasz(large);
    }
}
BENCHMARK(operatorhashl)->RangeMultiplier(2)->Range(1,1024);




void ldequeat( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;
    std::deque<Large>deque(size);

    Large large{};
    *large.data = '1';
    for (auto _ : state )
    {
        deque.at(0);

    }
    state.SetComplexityN(N);
}


BENCHMARK(ldequeat)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void ldequeop( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Large> deque(size);
    Large large{};
    *large.data = '1';
    for (auto _ : state )
    {
        deque[0];

    }
    state.SetComplexityN(N);
}

BENCHMARK(ldequeop)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void ldequefront( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Large> deque(size);
    Large large{};
    *large.data = '1';
    for (auto _ : state )
    {
        deque.front();

    }
    state.SetComplexityN(N);
}

BENCHMARK(ldequefront)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void ldequeback( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Large> deque(size);
    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        deque.back();

    }
    state.SetComplexityN(N);
}

BENCHMARK(ldequeback)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void ldequesize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Large> deque(size);
    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        deque.size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(ldequesize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void ldequeempty( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Large> deque(size);
    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        deque.empty();

    }
    state.SetComplexityN(N);
}

BENCHMARK(ldequeempty)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void ldequemaxsize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Large> deque(size);
    Large small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        deque.max_size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(ldequemaxsize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void ldequeshrinktofit( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Large> deque(size);
    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        deque.shrink_to_fit();

    }
    state.SetComplexityN(N);
}

BENCHMARK(ldequeshrinktofit)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void ldequeclear( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Large> deque(size);
    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        deque.clear();

    }
    state.SetComplexityN(N);
}

BENCHMARK(ldequeclear)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void ldequeinsert( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Large> deque(size);
    auto iter = deque.begin();
    Large large{};
    *large.data = '1';
    *large.data = '2';

    for (auto _ : state )
    {
        deque.insert(iter,Large{2});

    }
    state.SetComplexityN(N);
}


BENCHMARK(ldequeinsert)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void ldequeerase( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Large> deque(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';
    *large.data = '3';
    *large.data = '3';

    for (auto _ : state )
    {
        deque.erase(deque.begin(),deque.end());
    }
    state.SetComplexityN(N);
}

BENCHMARK(ldequeerase)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void ldequepushback( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Large> deque(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';
    *large.data = '3';
    *large.data = '3';

    for (auto _ : state )
    {
        deque.push_back(large);
    }
    state.SetComplexityN(N);
}

BENCHMARK(ldequepushback)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void ldequepushfront( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Large> deque(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';
    *large.data = '3';
    *large.data = '3';

    for (auto _ : state )
    {
        deque.push_front(large);
    }
    state.SetComplexityN(N);
}

BENCHMARK(ldequepushfront)->RangeMultiplier(2)->Range(1,1024)->Complexity();


void ldequepopback( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Large> deque(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';

    for (auto _ : state )
    {
        deque.push_front(Large{1});
        deque.pop_back();
    }
    state.SetComplexityN(N);
}

BENCHMARK(ldequepopback)->RangeMultiplier(2)->Range(1,1024)->Complexity();


void ldequepopfront( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Large> deque(size);

    Large large{};
    *large.data = '1';

  ;
    for (auto _ : state )
    {
        deque.push_front(large);
        deque.pop_front();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ldequepopfront)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void ldequeresize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Large> deque(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';
    *large.data = '3';
    *large.data = '3';

    for (auto _ : state )
    {
        deque.resize(2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(ldequeresize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void ldequeswap( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Large> deque(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';
    *large.data = '3';
    *large.data = '3';

    for (auto _ : state )
    {
        deque.swap(deque);
    }
    state.SetComplexityN(N);
}

BENCHMARK(ldequeswap)->RangeMultiplier(2)->Range(1,1024)->Complexity();

//=======================

void lmempty( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Large> multimap;
    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        multimap.empty();

    }
    state.SetComplexityN(N);
}

BENCHMARK(lmempty)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lmsize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Large> multimap;
    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        multimap.size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(lmsize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lmmaxsize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Large> multimap;
    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        multimap.max_size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(lmmaxsize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lmclear( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Large> multimap;
    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        multimap.clear();

    }
    state.SetComplexityN(N);
}

BENCHMARK(lmclear)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lminsert( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Large> multimap;
    auto iter = multimap.begin();
    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        multimap.insert(iter, {1,Large{2}});

    }
    state.SetComplexityN(N);
}

BENCHMARK(lminsert)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lmerase( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Large> multimap;
    auto iter = multimap.begin();
    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        multimap.erase(multimap.begin(),multimap.end());

    }
    state.SetComplexityN(N);
}

BENCHMARK(lmerase)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lmswap( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Large> multimap;

    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        multimap.swap(multimap);

    }
    state.SetComplexityN(N);
}

BENCHMARK(lmswap)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lmcount( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Large> multimap;

    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        multimap.count(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(lmcount)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lmfind( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Large> multimap;

    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        multimap.find(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(lmfind)->RangeMultiplier(2)->Range(1,1024)->Complexity();


void lmeqrange( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Large> multimap;

    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        multimap.equal_range(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(lmeqrange)->RangeMultiplier(2)->Range(1,1024)->Complexity();


void lmlbound( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Large> multimap;

    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        multimap.lower_bound(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(lmlbound)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lmubound( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,Large> multimap;

    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        multimap.upper_bound(2);

    }
    state.SetComplexityN(N);
}

BENCHMARK(lmubound)->RangeMultiplier(2)->Range(1,1024)->Complexity();

//================================

void lumempty( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Large> unordered_map(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        unordered_map.empty();

    }
    state.SetComplexityN(N);
}

BENCHMARK(lumempty)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lumsize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Large> unordered_map(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        unordered_map.size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(lumsize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lummaxsize( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Large> unordered_map(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        unordered_map.max_size();

    }
    state.SetComplexityN(N);
}

BENCHMARK(lummaxsize)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lumclear( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Large> unordered_map(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        unordered_map.clear();

    }
    state.SetComplexityN(N);
}

BENCHMARK(lumclear)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void luminsert( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Large> unordered_map(size);
    auto iter = unordered_map.begin();
    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        unordered_map.insert(iter, {1,Large{2}});

    }
    state.SetComplexityN(N);
}

BENCHMARK(luminsert)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lumerase( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Large> unordered_map(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        unordered_map.erase(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(lumerase)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lumswap( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Large> unordered_map(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';
    for (auto _ : state )
    {
        unordered_map.swap(unordered_map);

    }
    state.SetComplexityN(N);
}

BENCHMARK(lumswap)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lumat( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Large> unordered_map(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';
    unordered_map.insert(unordered_map.begin(), {1,Large{2}});
    for (auto _ : state )
    {
        unordered_map.at(1) = Large{1};

    }
    state.SetComplexityN(N);
}

BENCHMARK(lumat)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lumop( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Large> unordered_map(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';

    for (auto _ : state )
    {
        unordered_map[0];

    }
    state.SetComplexityN(N);
}

BENCHMARK(lumop)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lumcount( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Large> unordered_map(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';

    for (auto _ : state )
    {
        unordered_map.count(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(lumcount)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lumfind( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Large> unordered_map(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';

    for (auto _ : state )
    {
        unordered_map.find(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(lumfind)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lumeqr( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Large> unordered_map(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';

    for (auto _ : state )
    {
        unordered_map.equal_range(1);

    }
    state.SetComplexityN(N);
}

BENCHMARK(lumeqr)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lumreserve( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Large> unordered_map(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';

    for (auto _ : state )
    {
        unordered_map.reserve(size);

    }
    state.SetComplexityN(N);
}

BENCHMARK(lumreserve)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void lumrehash( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::unordered_map<int,Large> unordered_map(size);

    Large large{};
    *large.data = '1';
    *large.data = '2';

    for (auto _ : state )
    {
        unordered_map.rehash(size);

    }
    state.SetComplexityN(N);
}

BENCHMARK(lumrehash)->RangeMultiplier(2)->Range(1,1024)->Complexity();