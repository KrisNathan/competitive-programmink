# Rolling Hash

## Use Case

Used for efficient substring querying of a string $O(n)$

Without this you'd be doing around $O(n^2)$ because of an inner loop to check each characters.

## Equation

Hash of a string goes like this:

$$
h(k) = (a_1 p^{k-1} + a_2 p^{k-2} + ... + a_k p^0) \mod m
$$

- $k$ = length of string
- $p$ = base power; usually primes (e.g. 37)
- $m$ = mod; larger less collision probably

If you have string "abc"; where a = 1, b = 2, c = 3:

$$
h(3) = 1 p^2 + 2 p^1 + 3 p^0
$$

### Hashing The String

We will use 1-based indexing.

```
FUNCTION hash(s, k, p, m, pows, hashes)
  pows[0] = 1 % m
  hashes[0] = 0

  FOR i FROM 1 TO k
    pows[i] = (pows[i-1] * p) MOD m
    hashes[i] = (hashes * p + s[i]) MOD m
  END FOR
END FUNCTION
```

### Sliding Substring (Window)

Rabin-Karp String Search

Variables:

- $L$ = start idx of current substring
- $R$ = end idx of current string

Steps:

1. Subtract the contribution of the outgoing char ($s[L-1] * p^{k-1}$)
2. Multiply the remaining hash by $p$
3. Add the contribution of $s[R+1]$

## Example

### Obtaining hash of substring `[L..R]`  from a string

idx starts from 1

idx and str:

```
1 2 3 4 5
a b c d e
  L   R
```

L = 2
R = 4
len = R-L+1 = 4-2+1 = 3

$
h[R] = ap^3 + bp^2 + cp^1 + dp^0
$

We want: `b c d`; $bp^2 + cp^1 + dp^0$

$\therefore$ **OBJECTIVE**: Get rid of a

We want to get rid of $ap^3$ from $h[R]$:

$$
h[L-1] = a p^0
$$

$$
h[L-1] * \text{pow}[len=3] = ap^0 p^3 = ap^3
$$

$$
h[R] = ap^3 bp^2 cp^1 dp^0
$$

$$
h[R] - h[L-1]*\text{pow}[len=3] = ?
$$

This may cause underflowing, so we must slide the scope to the right using (mod):
$$
\begin{aligned}
&h[R] + m - h[L-1]*\text{pow}[len=3]\\&= .. + (ap^3 + bp^2 + cp^1 + dp^0) - ap^3\\
&= bp^2 + cp^1 + dp^0
\end{aligned}
$$

## TODO

- Double hash for reducing collision even further.