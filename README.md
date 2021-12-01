# Big_Int

Hello people,👋👋


This repo contains a single file header only C++ implementation of BigInteger / BigNum / unlimited size integers and rational numbers
The Datatype made is called :"Num" here.

Supported features on Num DataType:-<br>
```diff
- Artithmetic: `+, -, *, /, +=, -=, *=, /=, %=`
+ Comparison: `==, !=, <=, >=, <, >`
! Bit ops: `get_bit, set_bit, clr_bit`
- Shifts: `<<, >>, <<=, >>=`
+ Fancy stuff: `gcd, sqrt, pow, mod_pow, div_mod`
```
<br>

Base conversion:

```cpp
Num a("539", 16);

std::vector<char> c;
a.print(c, 2);
puts(&c[0]); // 10100111001
```
