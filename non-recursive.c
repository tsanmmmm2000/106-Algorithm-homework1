#include <stdio.h>
#include <limits.h>

int find_max_sub_array(int input[], int input_size) {
    int sum = INT_MIN;
    int temp = 0;
    for (int i = 0; i < input_size; i++) {
        temp += input[i];
        if (temp > sum)
            sum = temp;
        if (temp < 0)
            temp = 0;
    }
    return sum;
}

int main() {
    int input[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -1, 12, -5, -22, 15, -4, 7};
    int input_size = sizeof(input) / sizeof(input[0]);
    int result = find_max_sub_array(input, input_size);
    printf("result: %d\n", result);
}