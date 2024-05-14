import streamlit as st
import cv2
import numpy as np

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

# Streamlit app
st.title("Denoising salt peper image ")

uploaded_file = st.file_uploader("Choose an image", type=["jpg", "jpeg", "png"])

if uploaded_file is not None:
    # Read the uploaded image
    file_bytes = np.asarray(bytearray(uploaded_file.read()), dtype=np.uint8)
    img = cv2.imdecode(file_bytes, cv2.IMREAD_GRAYSCALE)

    # Filter selection
    filter_type = st.selectbox("Filter Type", ("Average Filter", "Median Filter"))
    kernel_size = st.number_input("Kernel Size", min_value=3, step=2)

    if filter_type == "Average Filter":
        processed_img = custom_average_filter(img, kernel_size)
    else:
        processed_img = custom_median_filter(img, kernel_size)

    # Display original and processed images
    st.image([img, processed_img], caption=["Original Image", "Processed Image"])