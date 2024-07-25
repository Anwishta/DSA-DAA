#include <stdio.h>
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    // If the total amount of gas is less than the total cost, it's impossible to complete the circuit
    int total_tank = 0;
    int current_tank = 0;
    int starting_station = 0;

    for (int i = 0; i < gasSize; ++i) {
        total_tank += gas[i] - cost[i];
        current_tank += gas[i] - cost[i];

        // If current_tank drops below 0, we cannot start from the previous starting_station
        if (current_tank < 0) {
            // Update starting_station to the next station
            starting_station = i + 1;
            // Reset current_tank
            current_tank = 0;
        }
    }

    return total_tank >= 0 ? starting_station : -1;
}

int main() {
    int gas[] = {1, 2, 3, 4, 5};
    int cost[] = {3, 4, 5, 1, 2};
    int gasSize = sizeof(gas) / sizeof(gas[0]);
    int costSize = sizeof(cost) / sizeof(cost[0]);

    int result = canCompleteCircuit(gas, gasSize, cost, costSize);
    printf("Starting gas station index: %d\n", result);  // Output should be 3

    return 0;
}
