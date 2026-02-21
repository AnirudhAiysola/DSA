#include <bits/stdc++.h>
using namespace std;

/**
 * @class Solution
 * @brief Counts integers in a range whose set bit count is a prime number.
 * 
 * This solution efficiently counts how many numbers between 'left' and 'right'
 * (inclusive) have a prime number of set bits in their binary representation.
 * 
 * @method countBits(int n)
 * @brief Counts the number of set bits (1s) in the binary representation of n.
 * @param n The integer to count set bits for.
 * @return The count of set bits in n.
 * @complexity Time: O(32) = O(1), Space: O(1)
 * 
 * @method sieve(int n)
 * @brief Generates a boolean vector identifying all prime numbers up to n using Sieve of Eratosthenes.
 * @param n The upper limit for prime generation.
 * @return A vector where isPrime[i] = true if i is prime, false otherwise.
 * @complexity Time: O(n log log n), Space: O(n)
 * 
 * @method countPrimeSetBits(int left, int right)
 * @brief Counts numbers in [left, right] range with a prime number of set bits.
 * @param left The starting number of the range (inclusive).
 * @param right The ending number of the range (inclusive).
 * @return The count of numbers in [left, right] whose set bit count is prime.
 * @complexity Time: O(n log log n + (right - left) * 32), Space: O(right)
 * 
 * @example
 * Solution sol;
 * int result = sol.countPrimeSetBits(6, 10);  // Returns 4
 * // 6 (110) has 2 set bits (prime)
 * // 7 (111) has 3 set bits (prime)
 * // 9 (1001) has 2 set bits (prime)
 * // 10 (1010) has 2 set bits (prime)
 */
class Solution
{
public:
    int countBits(int n)
    {
        int count = 0;

        for (int i = 0; i < 32; i++)
        {
            if ((1 << i) & n)
                count++;
        }
        return count;
    }
    vector<bool> sieve(int n)
    {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++)
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
        return isPrime;
    }

public:
    int countPrimeSetBits(int left, int right)
    {
        int ans = 0;

        vector<bool> isPrime = sieve(right);
        for (int i = left; i <= right; i++)
        {
            int count = countBits(i);
            if (isPrime[count])
                ans++;
        }
        return ans;
    }
};