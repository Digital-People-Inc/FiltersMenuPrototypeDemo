#include <iostream>
#include <opencv2/videoio.hpp>  //video io
#include <opencv2/highgui/highgui.hpp>  //cam display
#include <opencv2/imgproc.hpp>  //edge detection

void onButtonClicked(int state, void* userData)
{
    // Cast the userData pointer to a button label
    std::string* buttonLabel = static_cast<std::string*>(userData);

    // Change the button label
    if (state == cv::QT_PUSH_BUTTON)
    {
        *buttonLabel = "Button Clicked!";
    }
    else
    {
        *buttonLabel = "Click Me";
    }
}

int main()
{
    cv::VideoCapture capL(0, cv::CAP_ANY); //Gstreamer backend
    //cv::VideoCapture capR(0, cv::CAP_ANY); 

    cv::Mat frameL, edgesL;
    cv::namedWindow("Video Capture", cv::WINDOW_AUTOSIZE);

    //cv::Mat frameR, edgesR;
    //cv::namedWindow("Video Cap R", cv::WINDOW_AUTOSIZE);

    while (true) {
        // Capture a new frame
        capL >> frameL;
        //capR >> frameR;

        // Check if the frame is empty
        if (frameL.empty() /*|| frameR.empty()*/) {
            std::cerr << "Error: Blank frame grabbed" << std::endl;
            break;
        }


        cv::Canny(frameL, edgesL, 50, 150);    //apply edge detection to both
        //cv::Canny(frameR, edgesR, 50, 150);

        // Display the frame
        cv::imshow("Video Cap L", edgesL);
        //cv::imshow("Video Cap R", edgesR);

        // Break the loop if 'q' is pressed
        char c = (char)cv::waitKey(25);
        if (c == 'q' || c == 27) {
            break;
        }
    }


    // Create a window
    cv::namedWindow("Window");

    // Button label
    std::string buttonLabel = "Click Me";

    // Create a button in the window
	cv::createButton("Button", onButtonClicked, &buttonLabel, cv::QT_PUSH_BUTTON);
    while (true)
    {
        // Display the button label in the window
        cv::imshow("Window", cv::Mat::zeros(100, 300, CV_8UC3));
        cv::displayOverlay("Window", buttonLabel);

        // Wait for a key event
        int key = cv::waitKey(10);

        // Exit the loop if 'q' is pressed
        if (key == 'q')
            break;
    }




    // Destroy the window
    cv::destroyAllWindows();

    return 0;
}

