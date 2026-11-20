#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	long long n, size[6], t, p, bundle_t = 0, bundle_p = 0, pen;

	scanf("%lld", &n);
	for (int i = 0; i < 6; i++) {
		scanf("%lld", &size[i]);
	}
	scanf("%lld %lld", &t, &p);

	for (int i = 0; i < 6; i++) {
		if (size[i] % t == 0) {
			bundle_t += size[i] / t;
		}
		else {
			bundle_t += size[i] / t + 1;
		}
	}
	bundle_p = n / p;
	pen = n % p;

	printf("%lld\n%lld %lld", bundle_t, bundle_p, pen);

	return 0;
}