#include "Small.h"
#include "BenchIncludes.h"
#include<deque>
#include<map>
#include <unordered_map>
// TODO: Add benchmarks for operator<. operator==, and hash

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

/* SEGMENTATION!!! */
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
        deque.pop_back();
    }
    state.SetComplexityN(N);
}

BENCHMARK(dequepopback)->RangeMultiplier(2)->Range(1,1024)->Complexity();

/* SEGMENTATION!!! */
void dequepopfront( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::deque<Small> deque(size);

    Small small{};
    *small.data = '1';
    deque.push_front(small);
    for (auto _ : state )
    {
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

void multimapempty( State &state )
{
    auto N = state.range(0);
    std::size_t size;
    size = (std::size_t)N;

    std::multimap<int,int> multimap(size,size);
    Small small{};
    *small.data = '1';
    *small.data = '2';
    for (auto _ : state )
    {
        multimap.empty();

    }
    state.SetComplexityN(N);
}

BENCHMARK(multimapempty)->RangeMultiplier(2)->Range(1,1024)->Complexity();