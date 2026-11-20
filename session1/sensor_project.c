#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

typedef struct {
	int32_t raw;
	int32_t adjusted;
	uint32_t timestamp_ms;
	uint8_t status;

} SensorReading;

void mark_valid(SensorReading *reading);

void calibrate_buffer(SensorReading readings[], size_t count, int32_t baseline);

void find_extremes(const SensorReading readings[], size_t count, int32_t *minimum, int32_t *maximum);

int main(void) {
SensorReading readings[] = {
	{84250,0,0,0},
	{84100,0,10,0},
	{84000,0,20,0},
	{83950,0,30,0},
	{84300,0,40,0}
	};

	printf("%u\n", readings[0].raw);

	for	(size_t i = 0; i < sizeof(readings)/sizeof(readings[0]); ++i) {
		mark_valid(&readings[i]);
		printf("Reading Stats for Reading %zu: \n", i);
		printf("Raw - %" PRId32 "\n", readings[i].raw);
		printf("Timestamp - %" PRIu32 "\n", readings[i].timestamp_ms);
		printf("Status - %" PRIu8 "\n\n", readings[i].status);
	}
	
	calibrate_buffer(readings, sizeof(readings)/sizeof(readings[0]), 84000);

	for (size_t i = 0; i < sizeof(readings)/sizeof(readings[0]); ++i) {
		printf("Updated Stats for Reading %zu: \n",i);
		printf("Adjusted - %" PRId32 "\n", readings[i].adjusted);
		printf("Status - %" PRIu8 "\n\n", readings[i].status);
	}

	int32_t minimum = 0;
	int32_t maximum = 0;
	
	find_extremes(readings, sizeof(readings)/sizeof(readings[0]), &minimum, &maximum);

	printf("Minimum adjusted reading: %" PRId32 "\n", minimum);
	printf("Maximim adjusted reading: %" PRId32 "\n", maximum);


	return 0;
}

void mark_valid(SensorReading *reading) {
	reading->status |= 1u;
}

void calibrate_buffer(SensorReading readings[], size_t count, int32_t baseline) {
	for (size_t i =0; i < count; ++i) {
		readings[i].adjusted = readings[i].raw - baseline;
		readings[i].status |= 2u;
	}
}

void find_extremes(const SensorReading readings[], size_t count, int32_t *minimum, int32_t *maximum) {
	*minimum = readings->adjusted;
	*maximum = readings->adjusted;
	for (size_t i = 1; i < count; ++i) {
		if (readings[i].adjusted > *maximum) {
			*maximum = readings[i].adjusted;
		}
		if (readings[i].adjusted <= *minimum) {
			*minimum = readings[i].adjusted;
		}
	}
}
