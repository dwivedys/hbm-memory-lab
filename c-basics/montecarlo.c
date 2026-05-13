#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    double starting_cash;
    double growth_rate;
    double shock;
    int years;
} Scenario;

typedef struct {
    double final_value;
    double max_value;
    double min_value;
} Result;

Result run_scenario(Scenario s) {
    double value = s.starting_cash;
    double max_value = value;
    double min_value = value;

    for(int year = 0; year < s.years; year++) {
        value = value * (1 + s.growth_rate) + s.shock;
        if(value > max_value) {
            max_value = value;
        }
        if (value < min_value) {
            min_value = value;
        }
    }
    Result r = {value, max_value, min_value};
    return r;
}

int main(void) {
    const int scenario_count = 1000;

    Scenario *scenarios = malloc(sizeof(Scenario) *scenario_count);
    Result *results = malloc(sizeof(Result) * scenario_count);

    if(!scenarios || !results) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for(int i = 0; i < scenario_count; i++) {
        scenarios[i].starting_cash = 1000.0;
        scenarios[i].growth_rate = 0.03 + 0.00001 * i;
        scenarios[i].shock = -10.0 + 02 * i;
        scenarios[i].years = 30;
    }

    for(int i = 0; i < scenario_count; i++) {
        results[i] = run_scenario(scenarios[i]);
    }
    
    FILE *file = fopen("results.csv", "w");
    if (!file) {
        fprintf(stderr, "Could not open results.csv\n");
        free(scenarios);
        free(results);
        return 1;
    }
    fprintf(file, "scenario,final_value,max_value,min_value\n");

    for (int i = 0; i < scenario_count; i++) {
        fprintf(file, "%d,%.2f,%.2f,%.2f\n",
                i,
                results[i].final_value,
                results[i].max_value,
                results[i].min_value);
    }

    fclose(file);

    free(scenarios);
    free(results);

    printf("Simulation complete. Results written to results.csv\n");
    return 0;


}