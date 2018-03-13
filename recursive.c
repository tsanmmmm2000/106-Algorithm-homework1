#include <stdio.h>

struct max_profit_result {
    int first_index;
    int last_index;
    int max_profit;
};

struct max_profit_result find_max(struct max_profit_result a, struct max_profit_result b) {
    return (a.max_profit > b.max_profit) ? a : b;
}

struct max_profit_result find_max_profit(int input[], int left, int right) {
    struct max_profit_result result;
    result.first_index = left;
    result.last_index = right;
    result.max_profit = input[left];

    if (left == right)
        return result;

    int middle = (left + right) / 2;
    int left_left = left;
    int left_right = middle;
    int right_left = middle + 1;
    int right_right = right;
    
    struct max_profit_result left_result = find_max_profit(input, left_left, left_right);
    struct max_profit_result right_result = find_max_profit(input, right_left, right_right);

    int sum = 0;
    int first_index = left_right;
    int last_index = right_left;
    int left_max_profit = input[left_right];
    int right_max_profit = input[right_left];

    for(int i = left_right; i >= left_left; i--) {
        sum += input[i];
        if (sum > left_max_profit) {
            left_max_profit = sum;    
            first_index = i;
        }
    }

    sum = 0;
    for(int i = right_left; i <= right_right; i++) {
        sum += input[i];
        if (sum > right_max_profit) {
            right_max_profit = sum;
            last_index = i;
        }
    }

    result.first_index = first_index;
    result.last_index = last_index;
    result.max_profit = left_max_profit + right_max_profit;

    return find_max(find_max(left_result, right_result), result);
}

int main() {
    int input_size;
    while(scanf("%i", &input_size) != EOF) {
        int input[input_size];
        for(int i = 0; i < input_size; i++) {
            scanf("%d", &input[i]);
        }
        struct max_profit_result result = find_max_profit(input, 0, input_size - 1);
        printf("%d %d %d\n", result.first_index, result.last_index, result.max_profit);
    }
}