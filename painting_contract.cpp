#include <stdio.h>
#include <math.h>

int main() {
    int num_townships, num_houses;
    double total_hours = 0, total_accent_liters = 0, total_regular_liters = 0;
    double township_hours, township_accent_liters, township_regular_liters;
    int num_walls;

    // Read in the number of townships
    printf("Enter the number of townships: ");
    scanf("%d", &num_townships);

    // Loop through each township
    for (int i = 1; i <= num_townships; i++) {
        printf("\nTownship %d\n", i);
        township_hours = 0;
        township_accent_liters = 0;
        township_regular_liters = 0;

        // Read in the number of houses in the township
        printf("Enter the number of houses: ");
        scanf("%d", &num_houses);

        // Loop through each house
        for (int j = 1; j <= num_houses; j++) {
            printf("\nHouse %d\n", j);

            // Calculate the number of walls in the Victorian-style hall
            num_walls = 6;
            township_accent_liters += num_walls * 1.5 / 3;
            township_regular_liters += num_walls * 2.25 / 3;
            township_hours += num_walls * 2.5 + num_walls * 3.25;

            // Calculate the number of walls in the bedrooms on the roof
            num_walls = 3;
            township_accent_liters += num_walls * 1.5 / 3;
            township_regular_liters += num_walls * 2.25 / 3;
            township_hours += num_walls * 2.5 + num_walls * 3.25;

            // Calculate the number of walls in all other standard rooms
            num_walls = 4;
            township_accent_liters += num_walls * 1.5 / 3;
            township_regular_liters += num_walls * 2.25 / 3;
            township_hours += num_walls * 2.5 + num_walls * 3.25;
        }

        // Add the township totals to the overall totals
        total_hours += township_hours;
        total_accent_liters += township_accent_liters;
        total_regular_liters += township_regular_liters;

        // Print the township totals
        printf("\nTownship %d totals:\n", i);
        printf("Hours: %.2f\n", township_hours);
        printf("Accent paint: %.2f liters\n", township_accent_liters);
        printf("Regular paint: %.2f liters\n", township_regular_liters);
    }

    // Print the overall totals
    printf("\nOverall totals:\n");
    printf("Hours: %.2f\n", total_hours);
    printf("Accent paint: %.2f liters\n", total_accent_liters);
    printf("Regular paint: %.2f liters\n", total_regular_liters);

    return 0;
}

