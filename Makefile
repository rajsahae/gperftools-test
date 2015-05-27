default: fibonacci_test.c
	gcc -std=gnu99 -lprofiler -ofibtest fibonacci_test.c

profile:
	CPUPROFILE=fibtest.prof ./fibtest 80

clean:
	rm -vf fibtest fibtest.prof
