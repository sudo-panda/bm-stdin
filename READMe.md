# Benchmarking method to take input from `stdin` 



This repository was made to measure the performance of these methods to take integer input from `stdin` in C++:

- `std::cin`
- `std::cin` with sync_with_stdio set to false
- `scanf()`
- `fastscan()` - takes characters using `getchar()` and converts it into an integer
- `fastscan_unlocked()` - takes character using `getchar_unlocked()` and converts it into an integer



## Results

The results are available in the `result` directory and also given below.

| Group | Experiment        | Problem Space        | Samples | Iterations | Failure | Baseline | us/Iteration | Iterations/sec | Min (us) | Mean (us) | Max (us) | Variance | Standard Deviation | Skewness   | Kurtosis  | Z Score |
| ----- | ----------------- | -------------------- | ------- | ---------- | ------- | -------- | ------------ | -------------- | -------- | --------- | -------- | -------- | ------------------ | ---------- | --------- | ------- |
| Input | cin               | -9223372036854775808 | 30      | 10000      | 0       | 1        | 0.2602       | 3.8432e+06     | 2602     | 2687.6    | 2907     | 6323.9   | 79.523             | 1.14606    | 0.346018  | 1.07642 |
| Input | cin_wo_sync       | -9223372036854775808 | 30      | 10000      | 0       | 0.38432  | 0.1          | 1e+07          | 1000     | 1064.97   | 1265     | 3227.9   | 56.8146            | 2.64303    | 6.71072   | 1.14349 |
| Input | scanf             | -9223372036854775808 | 30      | 10000      | 0       | 0.37548  | 0.0977       | 1.02354e+07    | 977      | 1003.63   | 1056     | 387.413  | 19.6828            | 0.619739   | 0.242751  | 1.35313 |
| Input | fastscan          | -9223372036854775808 | 30      | 10000      | 0       | 0.13259  | 0.0345       | 2.89855e+07    | 345      | 352.967   | 367      | 29.6195  | 5.44238            | 0.364405   | -0.238015 | 1.46382 |
| Input | fastscan_unlocked | -9223372036854775808 | 30      | 10000      | 0       | 0.112606 | 0.0293       | 3.41297e+07    | 293      | 307.1     | 327      | 116.99   | 10.8162            | 0.00513204 | -1.36834  | 1.3036  |



## How to use

You can use the `./gen_result.sh` to generate the results on your device. 



## Compiler and Device Specs
| Component | Specification              |
|-----------|----------------------------|
| Compiler  | GNU 7.5.0                  |
| Processor | Intel(R) Core(TM) i5-9300H |
| RAM       | 8 GB                       |
