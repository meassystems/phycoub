#include <benchmark/benchmark.h>

#include "Magnetron.h"

using namespace phycoub;

static void BM_100Particle(benchmark::State& state) {
    Magnetron magnetron;
    magnetron.setLifeParticleCount(100);

    for (auto _ : state)
        magnetron.phyCoub();
}
// Register the function as a benchmark
BENCHMARK(BM_100Particle);

static void BM_500Particle(benchmark::State& state) {
    Magnetron magnetron;
    magnetron.setLifeParticleCount(500);

    for (auto _ : state)
        magnetron.phyCoub();
}
// Register the function as a benchmark
BENCHMARK(BM_500Particle);

static void BM_1000Particle(benchmark::State& state) {
    Magnetron magnetron;
    magnetron.setLifeParticleCount(1000);

    for (auto _ : state)
        magnetron.phyCoub();
}
BENCHMARK(BM_1000Particle);

static void BM_2500Particle(benchmark::State& state) {
    Magnetron magnetron;
    magnetron.setLifeParticleCount(2500);

    for (auto _ : state)
        magnetron.phyCoub();
}
BENCHMARK(BM_2500Particle);

static void BM_5000Particle(benchmark::State& state) {
    Magnetron magnetron;
    magnetron.setLifeParticleCount(5000);

    for (auto _ : state)
        magnetron.phyCoub();
}
BENCHMARK(BM_5000Particle);

BENCHMARK_MAIN();