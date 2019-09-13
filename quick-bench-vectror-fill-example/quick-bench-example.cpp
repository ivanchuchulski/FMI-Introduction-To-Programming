static void F1(benchmark::State& state) {
  // Code inside this loop is measured repeatedly
  std::vector<float> v;
    constexpr size_t N = 10000000;
  for (auto _ : state) {
    
    // 1
    v.resize(N, 0.0f);
    benchmark::DoNotOptimize(v);
    v.resize(0);
    // 2
    //v.resize(N); std::fill(v.begin(), v.end(), 0.0f);

    //3 
    //v.resize(N); for (auto&f: v) f = 0.0f;

    // 4
    //v.resize(N); for (size_t i = 0, n = v.size(); i < n; ++i) v[i] = 0.0f;
  }
}

static void F2(benchmark::State& state) {
  // Code inside this loop is measured repeatedly
  std::vector<float> v;
    constexpr size_t N = 10000000;
  for (auto _ : state) {
    v.resize(N); std::fill(v.begin(), v.end(), 0.0f);
    benchmark::DoNotOptimize(v);
  }
}
// Register the function as a benchmark

BENCHMARK(F1);
BENCHMARK(F2);
