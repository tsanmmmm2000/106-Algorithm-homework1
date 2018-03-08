#include <stdio.h>
#include <limits.h>

int find_max(int a, int b) {
    return a > b ? a : b;
}

int find_max_crossing_sub_array(int input[], int middle, int left, int right) {
    int temp = 0;

    // cannot initialize with 0 because negative result is valid
    int left_max = INT_MIN;
    int right_max = INT_MIN;

    for(int i = middle; i >= left; i--) {
        temp += input[i];
        if (temp > left_max)
            left_max = temp;
    }

    temp = 0;
    for(int i = middle + 1; i <= right; i++) {
        temp += input[i];
        if (temp > right_max)
            right_max = temp;
    }
    return left_max + right_max;
}

int find_max_sub_array(int input[], int left, int right) {

    if (left == right)
        return input[0];
    
    int middle = (left + right) / 2;
    int left_max = find_max_sub_array(input, left, middle);
    int right_max = find_max_sub_array(input, middle + 1, right);

    return find_max(find_max(left_max, right_max), 
        find_max_crossing_sub_array(input, middle, left, right));
}

int main() {
    int input[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -1, 12, -5, -22, 15, -4, 7};
    int input_size = sizeof(input) / sizeof(input[0]);
    int result = find_max_sub_array(input, 0, input_size - 1);
    printf("result: %d\n", result);
}