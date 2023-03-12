#include <stdio.h>
#include <stdlib.h>

// Define the data for each website
struct Website {
    char* name;
    int content;
    int images[4];
    int forms;
};

int main() {
    // Define the websites
    struct Website websites[] = {
        {"Website 1", 5, {5, 5, 5, 5}, 5},
        {"Website 2", 5, {5, 5, 5, 5}, 5},
        {"Website 3", 5, {5, 5, 0, 0}, 5},
        {"Website 4", 10, {5, 5, 0, 0}, 5},
        {"Website 5", 10, {5, 0, 0, 0}, 5},
    };
    int num_websites = sizeof(websites) / sizeof(websites[0]);

    // Sort the websites based on the number of images on the homepage
    for (int i = 0; i < num_websites - 1; i++) {
        for (int j = i + 1; j < num_websites; j++) {
            int num_images_i = 0, num_images_j = 0;
            for (int k = 0; k < 4; k++) {
                num_images_i += websites[i].images[k];
                num_images_j += websites[j].images[k];
            }
            if (num_images_i < num_images_j) {
                struct Website temp = websites[i];
                websites[i] = websites[j];
                websites[j] = temp;
            }
        }
    }

    // Serve each website in the sorted order
    for (int i = 0; i < num_websites; i++) {
        printf("Serving %s\n", websites[i].name);

        // Serve the homepage content
        int total_size = websites[i].content;

        // Serve the images on the homepage
        for (int j = 3; j >= 0; j--) {
            int image_size = websites[i].images[j];
            if (image_size > 0) {
                total_size += image_size;
                if (total_size > 120) {
                    printf("Stopping %s at %d MB\n", websites[i].name, total_size);
                    break;
                }
            }
        }
        if (total_size > 120) {
            continue;
        }

        // Serve the forms on the homepage
        total_size += websites[i].forms;
        if (total_size > 120) {
            printf("Stopping %s at %d MB\n", websites[i].name, total_size);
            continue;
        }

        printf("Finished serving %s at %d MB\n", websites[i].name, total_size);
    }

    return 0;
}

