#include <stdio.h>

// Function prototypes
int carArrived();  // Simulates a car arriving at a pump (returns a pump number)
void refillRequest(int tankNumber); // Simulates a refill request for a tank

int main() {
    // Initial capacities of the four tanks
    int tankCapacities[4] = {100, 75, 50, 150};
    
    // Infinite loop to continuously handle car arrivals
    while (1) {
        // Get the pump number where a car has arrived
        int pumpNumber = carArrived();

        // Each car takes 10 gallons from the respective tank
        if (pumpNumber >= 0 && pumpNumber < 4) {
            tankCapacities[pumpNumber] -= 10;
            
            // Print the current contents of all four tanks
            printf("Current tank levels:\n");
            for (int i = 0; i < 4; i++) {
                printf("Tank %d: %d gallons\n", i + 1, tankCapacities[i]);
            }
            
            // Check if the tank needs a refill
            if (tankCapacities[pumpNumber] < 20) {
                refillRequest(pumpNumber);
                // Reset the tank to full capacity after refill
                if (pumpNumber == 0) tankCapacities[pumpNumber] = 100;
                if (pumpNumber == 1) tankCapacities[pumpNumber] = 75;
                if (pumpNumber == 2) tankCapacities[pumpNumber] = 50;
                if (pumpNumber == 3) tankCapacities[pumpNumber] = 150;
                
                printf("Tank %d has been refilled.\n", pumpNumber + 1);
            }
        } else {
            printf("Invalid pump number received.\n");
        }
    }

    return 0;
}

// Function to simulate a car arriving at a pump
int carArrived() {
    int pump;
    printf("Enter the pump number (1-4) where a car has arrived: ");
    scanf("%d", &pump);
    return pump - 1; // Adjusting for zero-based index
}

// Function to simulate requesting a refill for a tank
void refillRequest(int tankNumber) {
    printf("Refill truck is refilling tank %d...\n", tankNumber + 1);
}
