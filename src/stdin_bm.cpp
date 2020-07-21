#define CELERO_STATIC
#include <iostream>
#include <stdio.h>

#include <celero/Celero.h>

int fastscan(int &x)
{
  bool neg=false;
  register int c;
  x =0;
  c=getchar();
  if(c=='-')
  {
    neg = true;
    c=getchar();
  }
  for(;(c>47 && c<58);c=getchar())
    x = 48  + (x<<1) + (x<<3) - c;
  if(!neg)
    x *=-1;
  return x; // added to prevent error with DoNotOptimizeAway
}

int fastscan_unlocked(int &x)
{
  bool neg=false;
  register int c;
  x =0;
  c=getchar_unlocked();
  if(c=='-')
  {
    neg = true;
    c=getchar_unlocked();
  }
  for(;(c>47 && c<58);c=getchar_unlocked())
    x = 48  + (x<<1) + (x<<3) - c;
  if(!neg)
    x *=-1;
  return x; // added to prevent error with DoNotOptimizeAway
}

CELERO_MAIN

// Set baseline to std::cin 
BASELINE(Input, cin, 30, 10000)
{
  int n;
  celero::DoNotOptimizeAway(std::cin>>n);
}

// Benchmark std::cin without sync
BENCHMARK(Input, cin_wo_sync, 30, 10000) {
  int n;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  celero::DoNotOptimizeAway(std::cin>>n);
}

// Benchmark scanf
BENCHMARK(Input, scanf, 30, 10000) {
  int n;
  celero::DoNotOptimizeAway(scanf("%i", &n));
}

// Benchmark fastscan
BENCHMARK(Input, fastscan, 30, 10000) {
  int n;
  celero::DoNotOptimizeAway(fastscan(n));
}

// Benchmark fastscan
BENCHMARK(Input, fastscan_unlocked, 30, 10000) {
  int n;
  celero::DoNotOptimizeAway(fastscan_unlocked(n));
}