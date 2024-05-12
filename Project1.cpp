#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

    Mat img;
    VideoCapture cap("Resources/VideoSample.mp4"); // Change the path to your video file

    CascadeClassifier plateCascade;
    plateCascade.load("Resources/plate_number.xml");

    if (plateCascade.empty()) {
        cout << "XML file not loaded" << endl;
        return -1;
    }

    vector<Rect> plates;

    while (true) {

        cap.read(img);
        if (img.empty()) {
            cout << "End of video" << endl;
            break;
        }

        // Resize the frame to half its size for display
        resize(img, img, Size(), 0.5, 0.5);

        // Convert the image to grayscale
        Mat gray;
        cvtColor(img, gray, COLOR_BGR2GRAY);

        // Equalize the histogram to improve contrast
        equalizeHist(gray, gray);

        // Detect plates with the Cascade Classifier
        plateCascade.detectMultiScale(gray, plates, 1.1, 3, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

        for (int i = 0; i < plates.size(); i++)
        {
            Mat imgCrop = img(plates[i]);

            // Save the cropped image of the number plate
            string filename = "Resources/Plates/" + to_string(i) + ".png";
            if (!imwrite(filename, imgCrop)) {
                cout << "Failed to save image: " << filename << endl;
            }

            rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 3);
        }

        imshow("Image", img);
        if (waitKey(30) == 27) // Press ESC to exit
            break;
    }

    return 0;
}

