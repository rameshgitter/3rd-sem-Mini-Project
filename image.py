import cv2
import numpy as np

# Load the noisy image
img = cv2.imread("/home/ramesh/Desktop/miniProject/noisy1.png", 0)  # Load as grayscale

# Check if the image is loaded successfully
if img is None:
    print("Error: Unable to read the image file.")
    exit()

# Define the size of the kernel (3x3)
kernel_size = 3

# Function for custom average filter
def custom_average_filter(image, kernel_size):
    kernel = np.ones((kernel_size, kernel_size), np.float32) / (kernel_size ** 2)
    return cv2.filter2D(image, -1, kernel)

# Function for custom median filter
def custom_median_filter(image, kernel_size):
    height, width = image.shape
    result = np.zeros_like(image)

    half_kernel = kernel_size // 2

    for y in range(half_kernel, height - half_kernel):
        for x in range(half_kernel, width - half_kernel):
            neighborhood = image[y - half_kernel:y + half_kernel + 1, x - half_kernel:x + half_kernel + 1]
            result[y, x] = np.median(neighborhood)

    return result

# Apply custom average filter
average_filtered = custom_average_filter(img, kernel_size)

# Apply custom median filter
median_filtered = custom_median_filter(img, kernel_size)

# Display the original image, average filtered image, and median filtered image
cv2.imshow("Original", img)
cv2.imshow("Custom Average Filter", average_filtered)
cv2.imshow("Custom Median Filter", median_filtered)

# Wait for a key press and then close all OpenCV windows
cv2.waitKey(0)
cv2.destroyAllWindows()
