#include <benchmark/benchmark.h>

#include "Magnetron.h"

using namespace phycoub;

static void Magnetron_100Particle(benchmark::State& state) {
    Magnetron magnetron;
    magnetron.setLifeParticleCount(100);

    for (auto _ : state)
        magnetron.phyCoub();
}
// Register the function as a benchmark
BENCHMARK(Magnetron_100Particle);

static void Magnetron_500Particle(benchmark::State& state) {
    Magnetron magnetron;
    magnetron.setLifeParticleCount(500);

    for (auto _ : state)
        magnetron.phyCoub();
}
// Register the function as a benchmark
BENCHMARK(Magnetron_500Particle);

static void Magnetron_1000Particle(benchmark::State& state) {
    Magnetron magnetron;
    magnetron.setLifeParticleCount(1000);

    for (auto _ : state)
        magnetron.phyCoub();
}
BENCHMARK(Magnetron_1000Particle);

static void Magnetron_2500Particle(benchmark::State& state) {
    Magnetron magnetron;
    magnetron.setLifeParticleCount(2500);

    for (auto _ : state)
        magnetron.phyCoub();
}
BENCHMARK(Magnetron_2500Particle);

BENCHMARK_MAIN();