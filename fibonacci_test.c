#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int fibonacci(int num);
uint64_t fibonacci_cached(int num, uint64_t* cache);

// Will accept any integer between 0 and 90 and compute the fibonacci number
int main(int argc, char** argv) {

  int fib_target = 12; // default target
  uint64_t cache[91];

  for ( int i = 0; i < 90; i++ )
    cache[i] = -1;


  if ( argc > 1)
    fib_target = atoi(argv[1]);

  printf("Fibonacci number %d (without caching): %d\n", fib_target / 2, fibonacci(fib_target / 2));
  printf("Fibonacci number %d (with caching)   : %" PRId64 "\n", fib_target / 2, fibonacci_cached(fib_target / 2, cache) );
  printf("Fibonacci number %d (with caching)   : %" PRId64 "\n", fib_target, fibonacci_cached(fib_target, cache) );

  return 0;
}

// fibonacci not cached
int fibonacci(int num) {
  if ( num <= 0 )
    return 0;
  else if ( num == 1 )
    return 1;
  else // ( num > 2 )
    return fibonacci(num - 1) + fibonacci(num - 2);
}

// fibonacci cached
uint64_t fibonacci_cached(int num, uint64_t* cache){
  // printf("cached value: %d -> %" PRId64 "\n", num, cache[num]);

  if ( *(cache + num) == -1 ) {
    if ( num <= 0 )
      cache[num] = 0;
    else if ( num == 1 )
      cache[num] = 1;
    else // ( num > 2 )
      cache[num] = fibonacci_cached(num - 1, cache) + fibonacci_cached(num - 2, cache);
  }

  return cache[num];
}
