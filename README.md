# Image Denoising with Filters

## Overview
This mini-project focuses on basic image processing techniques to reduce salt and pepper noise from a noisy image. It provides implementations of two filters:
1. Median Filter
2. Average Filter

## Usage
To use the code:
1. Set the path of your noisy image in the `img` variable.
2. Adjust the kernel size to control the level of smoothing in the output image.

# How to Run the frontend code
You can deploy this code using Streamlit. Users can upload a noisy image, select the kernel size and filter type, and view the denoised output image.

### Instructions
## Usage

To use the code:
1. Clone the repository.
2. Install the required dependencies (`streamlit`, `opencv-python`, `numpy`).
3. Run the Streamlit app using the command `streamlit run app.py`.
4. Upload a noisy image.
5. Select the filter type (Average or Median) and adjust the kernel size.
6. View the denoised output image.

## Features

- **Custom Filters**: Users can choose between an Average Filter and a Median Filter.
- **Adjustable Kernel Size**: Users can adjust the kernel size to control the level of denoising.
- **Streamlit App**: The code is deployed using Streamlit, allowing users to upload a noisy image and view the denoised output interactively.


### Example
Here's a sample usage of the code:
```python
streamlit run frontend.py
```
The sample output is like this
```python
  You can now view your Streamlit app in your browser.

  Local URL: http://localhost:8501
  Network URL: http://192.168.146.54:8501
```

