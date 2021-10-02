package main

import (
	"fmt"
	"math"
)

// Number up to which to get all primes
const N = 1000
var lim = int(math.Sqrt(N))

func main() {

	// All numbers are prime to begin with (i.e. false)
	sieve := make([]bool, N+1)
	sieve[0], sieve[1] = true, true

	for i:=2; i<=lim; i++ {
		// The number is prime
		if !sieve[i] {
			j := i * i
			// Exclude All multiples of i up to N
			for j <= N {
				sieve[j] = true
				j += i
			}
		}
	}

	// Keep only numbers that were'nt filtered out in the sieve
	primes := make([]int, 0)
	for i, filtered := range sieve {
		if ! filtered {
			primes = append(primes, i)
		}
	}

	fmt.Println(primes)

}