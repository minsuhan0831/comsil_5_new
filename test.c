#define CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int arr[] = { 1,2,3 };
//arr을 전역변수로서 선언, 동적 할당에 용이함
void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void print_arr(int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void permutation(int n, int r, int depth) {
	if (r == depth) {
		print_arr(depth);
		return;
	}
	for (int i = depth; i < n; i++) {
		swap(&arr[i], &arr[depth]);
		permutation(n, r, depth + 1);
		swap(&arr[i], &arr[depth]);
	}
}
int main(void) {
	permutation(sizeof(arr) / sizeof(int), 3, 0);
	return 0;

}