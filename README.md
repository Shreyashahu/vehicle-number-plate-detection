# Vehicle Number Plate Detection

An OpenCV-based system for real-time detection and recognition of vehicle number plates.

## Introduction

This project aims to detect and recognize vehicle number plates in a video stream using the OpenCV library. The system uses a Haar cascade classifier to detect the presence of number plates in each frame of the video and then extracts and processes the detected regions to recognize the characters on the plate.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/ShreyaShahu/vehicle-number-plate-detection.git
   ```

2. Install OpenCV if you haven't already. You can follow the [official OpenCV installation instructions](https://docs.opencv.org/master/d3/d52/tutorial_windows_install.html) for your operating system.

3. Compile the code using a C++ compiler. For example, using g++ on Linux:
   ```bash
   g++ -o Project1 Project1.cpp `pkg-config --cflags --libs opencv4`
   ```

## Usage

1. Place your video file (`Video-Sample.mp4`) in the same directory as the compiled executable (`Project1`).

2. Run the executable:
   ```bash
   ./Project1
   ```

3. The program will display the video stream with rectangles drawn around detected license plates. Press `ESC` to exit the program.

4. The cropped images of the detected license plates will be saved in the `Resources/Plates/` directory.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---
