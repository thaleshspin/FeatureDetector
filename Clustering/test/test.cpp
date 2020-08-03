#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <fstream>

#define VIDEO

using namespace cv;

using namespace std;

#define VERDE ((0 << 16) | (255 << 8) | 0)

int c;

int *colorsTxt = new int[256 * 256 * 256];

void loadFile(string file)
{
    for (int i = 0; i < 256 * 256 * 256; i++)
    {
        colorsTxt[i] = -1;
    }
    string line;
    ifstream inFile(file.c_str(), ios::in);
    if (inFile)
    {
        while (getline(inFile, line))
        {
            //cout << line << '\n';
            istringstream actualColor(line);
            actualColor >> c;
            //cout << colorsTxt[c] << endl;
            colorsTxt[c] = VERDE;
            //cout << colorsTxt[c] << endl;

            actualColor.str("");
        }
        inFile.close();
    }
    else
        cout << "could not open file" << endl;
}

void clustering(Mat img)
{
    int R, G, B;
    int col;
    for (int y = 0; y < img.rows; y++)
    {
        for (int x = 0; x < img.cols; x++)
        {
            Vec3b color = img.at<Vec3b>(y, x);
            B = (int)color.val[0];
            G = (int)color.val[1];
            R = (int)color.val[2];
            col = (B << 16) | (G << 8) | R;

            if (colorsTxt[col] != -1)
            {
                color.val[0] = 0;
                color.val[1] = 255;
                color.val[2] = 0;
            }
            img.at<Vec3b>(y, x) = color;
        }
    }
    imshow("Clusterized", img);
}

int main(int argc, char **argv)
{
    loadFile("clustering.txt");

#ifndef VIDEO
    Mat img_rgb;
    img_rgb = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    clustering(img_rgb);

    waitKey(0); // Wait for a keystroke in the window

#endif

#ifdef VIDEO
    // Create a VideoCapture object and open the input file
    // If the input is the web camera, pass 0 instead of the video file name
    VideoCapture cap(argv[1]);

    // Check if camera opened successfully
    if (!cap.isOpened())
    {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }

    while (1)
    {

        Mat frame;
        // Capture frame-by-frame
        cap >> frame;

        // If the frame is empty, bre ak immediately
        if (frame.empty())
            break;
        clustering(frame);

        // Press  ESC on keyboard to exit
        char c = (char)waitKey(25);
        if (c == 27)
            break;
    }

    // When everything done, release the video capture object
    cap.release();

    // Closes all the frames
    destroyAllWindows();
#endif
    return 0;
}