#include <stdio.h>
#include <pthread.h>
#define THREAD_SIZE 5

pthread_mutex_t mutex;
pthread_cond_t cond;
int cnt=0;

void my_pthread_barrier_wait() {
	
	pthread_mutex_lock(&mutex);
	++cnt;
	if(cnt==THREAD_SIZE)
		pthread_cond_broadcast(&cond);
	else
		while(cnt<THREAD_SIZE) pthread_cond_wait(&cond, &mutex);
	pthread_mutex_unlock(&mutex);
}

void *func(void *arg) {

	my_pthread_barrier_wait();
	printf("Thread %lu running\n", (unsigned long)pthread_self());

	pthread_exit(NULL);
}

int main() {

	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);

	pthread_t threads[THREAD_SIZE];
	for(int i=0; i<THREAD_SIZE; ++i) {
		// Seems FreeBSD implementation will exec all statements in for before thread_create,
		// since all "Starting thread" will be printed out first no matter
		// pthread_barrier_wait() is called or not.
		// The thread schedule is applied while all thread functions are ready.
		printf("Starting thread %d\n", i);
		if(pthread_create(&threads[i], NULL, func, NULL)!=0) {
			fprintf(stderr, "Create thread[%d] error\n", i);
			return -1;
		}
	}

	for(int i=0; i<THREAD_SIZE; ++i)
		pthread_join(threads[i], NULL);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);

	return 0;
}
