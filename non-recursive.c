#include <stdio.h>

struct max_profit_result {
    int first_index;
    int last_index;
    int max_profit;
};

struct max_profit_result find_max_profit(int input[], int input_size) {
    int sum = 0;
    int first_index = 0;
    int new_first_index = 0;
    int last_index = 0;
    int max_profit = 0;
    
    for (int i = 0; i < input_size; i++) {
        int temp = sum + input[i];
        if (temp <= 0) {
            sum = 0;
            new_first_index = i + 1;
        } else {
            sum = temp;
        }

        if (sum > max_profit) {
            max_profit = sum;
            last_index = i;
            first_index = new_first_index;
        }
    }

    struct max_profit_result result;
    result.first_index = first_index;
    result.last_index = last_index;
    result.max_profit = max_profit;
    return result;
}

int main() {
    int input_size;
    while(scanf("%i", &input_size) != EOF) {
        int input[input_size];
        for(int i = 0; i < input_size; i++) {
            scanf("%d", &input[i]);
        }
        struct max_profit_result result = find_max_profit(input, input_size);
        printf("%d %d %d\n", result.first_index, result.last_index, result.max_profit); 
    }
}