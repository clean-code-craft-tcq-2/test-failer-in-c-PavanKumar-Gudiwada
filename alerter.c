#include <stdio.h>
#include <assert.h>

#define FSW_ENVIRONMENT_REAL 0
#define FSW_ENVIRONMENT_TEST 1

#define FSW_ENVIRONMENT FSW_ENVIRONMENT_REAL

#define MAX_TEMPERATURE 180
#define MIN_TEMPERATURE 150

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if((celcius >= MIN_TEMPERATURE)&&(celcius <= MAX_TEMPERATURE))
    {
    	return 200;
    }else
    {
    	return 0;
	}
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
}

int networkAlert(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if((celcius >= MIN_TEMPERATURE)&&(celcius <= MAX_TEMPERATURE))
    {
    	return 200;
    }else
    {
    	return 0;
	}
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
}

#if(FSW_ENVIRONMENT == FSW_ENVIRONMENT_REAL)
	int (*networkAlerter)(float) = &networkAlert;
#else
	int (*networkAlerter)(float) = &networkAlertStub;
#endif

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = (*networkAlerter)(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
	alertInCelcius(338.0);
    assert(alertFailureCount==0);
    alertInCelcius(400.5);
    assert(alertFailureCount==1);
    alertInCelcius(303.6);
    assert(alertFailureCount==1);
    printf("%d alerts failed.\n", alertFailureCount);

    return 0;
}
