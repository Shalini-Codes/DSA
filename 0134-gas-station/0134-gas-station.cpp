class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0, curr_tank = 0, start = 0;
        int n = gas.size();

        for (int i = 0; i < n; i++) {
            total_tank += gas[i] - cost[i];
            curr_tank += gas[i] - cost[i];

            // If car cannot reach next station, reset starting point
            if (curr_tank < 0) {
                start = i + 1;
                curr_tank = 0;
            }
        }

        // If total gas is less than total cost, impossible to complete circuit
        return (total_tank >= 0) ? start : -1;
    }
};
