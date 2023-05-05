
long long power(int base, int exponent) // function definition
{
	long long result = 1LL;
	for (int i = 1; i <= exponent; ++i) {
		result = result * base; // result *= base
	}
	return result;
}

