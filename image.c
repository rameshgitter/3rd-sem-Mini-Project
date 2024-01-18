#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <opencv2/opencv.hpp>

// Function to apply a 3x3 average filter to an image
void averageFilter(int *input_image, int *output_image, int width, int height) {
    int filter_size = 3;
    float kernel_value = 1.0f / 9.0f; // 1/9 to normalize the sum

    // Iterate over the image
    for (int y = filter_size / 2; y < height - filter_size / 2; y++) {
        for (int x = filter_size / 2; x < width - filter_size / 2; x++) {
            float weighted_sum = 0.0f;

            // Iterate over the neighborhood
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int pixel_value = input_image[(y + i) * width + (x + j)];
                    weighted_sum += pixel_value * kernel_value;
                }
            }

            // Set the pixel in the output
            output_image[y * width + x] = (int)weighted_sum;
        }
    }
}

// Function to apply a 3x3 median filter to an image
void medianFilter(const uint8_t *input_image, uint8_t *output_image, int width, int height) {
    int filter_size = 3;

    // Iterate over the image
    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            uint8_t neighborhood[9]; // 3x3 neighborhood

            int index = 0;

            // Iterate over the 3x3 neighborhood
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    neighborhood[index++] = input_image[(y + i) * width + (x + j)];
                }
            }

            // Sort the neighborhood values (bubble sort)
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8 - i; j++) {
                    if (neighborhood[j] > neighborhood[j + 1]) {
                        // Swap values
                        uint8_t temp = neighborhood[j];
                        neighborhood[j] = neighborhood[j + 1];
                        neighborhood[j + 1] = temp;
                    }
                }
            }

            // Set the pixel in the output to the median value
            output_image[y * width + x] = neighborhood[4]; // Median is the middle value
        }
    }
}


int main() {
    // Load the image
    IplImage* image = cvLoadImage("C:\\Users\\haris\\Pictures\\Saved Pictures\\noisy1.jpg", CV_LOAD_IMAGE_COLOR);

    if (image != NULL) {
        // Get the width (length) and height (breadth) of the image
        int width = image->width;
        int height = image->height;

        printf("Image Width (Length): %d pixels\n", width);
        printf("Image Height (Breadth): %d pixels\n", height);

        // Allocate memory for input and output images (assuming grayscale)
        uint8_t *input_image = (uint8_t *)malloc(width * height * sizeof(uint8_t));
        uint8_t *output_image = (uint8_t *)malloc(width * height * sizeof(uint8_t));

        // Populate input_image with your image data (you should load your image here)
        // Assuming the image is grayscale, copy pixel values from the image to input_image
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                input_image[y * width + x] = CV_IMAGE_ELEM(image, uchar, y, x * image->nChannels);
            }
        }

        // Convert input_image to int* before passing to averageFilter
        int *int_input_image = (int *)malloc(width * height * sizeof(int));
        for (int i = 0; i < width * height; i++) {
            int_input_image[i] = (int)input_image[i];
        }

        // Apply the average filter
        averageFilter(int_input_image, output_image, width, height);

        // Output image is now in output_image array

        // Don't forget to free allocated memory
        free(input_image);
        free(output_image);
        free(int_input_image);

        // Release the image
        cvReleaseImage(&image);
    } else {
        printf("Image not loaded. Check the file path.\n");
    }

    return 0;
}
