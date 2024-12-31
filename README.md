### code for paper Compact Rejection Sampling and Its Applications to Fiat-Shamir Signatures in Lattices

---

The code for sampling from the centered binomial distribution that we used is cited in the link https://github.com/tpoeppelmann/newhope, which is the implementation of the paper “post-quantum key exchange–a new hope” (USENIX Security 2016).
. 
Our algorithm for sampling one polynomial in R_q from the centered binomial distribution is defined as “poly_getnoise()” in the above link. It can be found in the files “newhope/ref/poly.h”, and the implementation is in “newhope/ref/poly.c”. By our computer with Intel(R) Core(TM) i5-8500 CPU @ 3.00GHz×4, it requires 27021 cycles. Concretely, we provide the code of our implementation as follows:


