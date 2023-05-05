
static int seed;

void my_srand(int s)
{
	seed = s;
}

int my_rand(void)
{
	seed = seed * 1103515245 + 12345;
	return ((unsigned int)(seed / 65536) % 32768);
}
