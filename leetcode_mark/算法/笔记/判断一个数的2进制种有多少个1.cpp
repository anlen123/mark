int ss(int n) {
	sum = 0;
	while (n) {
		n = (n - 1)&n;
		sum++;
	}
	return sum;
}