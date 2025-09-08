#include <stdio.h>

int main() {
    int arr[100], n, even = 0, odd = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    printf("Even: %d, Odd: %d\n", even, odd);
    return 0;
}
