#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace cv;
using namespace std;

stringstream data;
string dataStr;

void clear(vector<int> &v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it)
    {
        end = std::remove(it + 1, end, *it);
    }
    v.erase(end, v.end());
}

int c;
vector<int> colorsTxt;
void loadFile(string file)
{
    string line;
    ifstream inFile(file.c_str(), ios::in);
    if (inFile)
    {
        while (getline(inFile, line))
        {
            //cout << line << '\n';
            istringstream actualColor(line);
            actualColor >> c;
            //cout << c << endl;
            colorsTxt.push_back(c);
            actualColor.str("");
        }
        inFile.close();
    }
    else
        cout << "could not open file, creating a new one..." << endl;
}

void save(vector<int> newColors, string file)
{
    for (int i = 0; i < newColors.size(); i++)
    {
        colorsTxt.push_back(newColors[i]);
    }

    clear(colorsTxt);

    for (int i = 0; i < colorsTxt.size(); i++)
    {
        data << colorsTxt[i] << endl;
    }
    dataStr = data.str();

    ofstream outFile(file.c_str(), ios::out);
    if (outFile)
    {
        outFile << dataStr << endl;
        outFile.close();
    }
    else
        cout << "could not save file" << endl;
}

Mat image0, image;
int ffillMode = 1;
int loDiff = 44, upDiff = 37;
int connectivity = 4;
int isColor = true;
bool useMask = false;
int newMaskVal = 255;
static void onMouse(int event, int x, int y, int, void *)
{
    if (event != EVENT_LBUTTONDOWN)
        return;
    Point seed = Point(x, y);
    int lo = ffillMode == 0 ? 0 : loDiff;
    int up = ffillMode == 0 ? 0 : upDiff;
    int flags = connectivity + (newMaskVal << 8) +
                (ffillMode == 1 ? FLOODFILL_FIXED_RANGE : 0);
    int b = 0;   //(unsigned)theRNG() & 255;
    int g = 255; //(unsigned)theRNG() & 255;
    int r = 0;   //(unsigned)theRNG() & 255;
    int area;

    Rect ccomp;
    Scalar newVal = Scalar(b, g, r);
    Mat clusterized = image;
    Mat frame;
    image.copyTo(frame);
    

    area = floodFill(clusterized, seed, newVal, &ccomp, Scalar(lo, lo, lo),
                     Scalar(up, up, up), flags);

    imshow("image", clusterized);

    int R, G, B;
    int color;
    vector<int> colours;
    for (int y = 0; y < clusterized.rows; y++)
    {
        for (int x = 0; x < clusterized.cols; x++)
        {
            Vec3b colour = clusterized.at<Vec3b>(y, x);
            if (colour.val[0] == 0 && colour.val[1] == 255 && colour.val[2] == 0)
            {
                Vec3b colour = frame.at<Vec3b>(y, x);
                B = (int)colour.val[0];
                G = (int)colour.val[1];
                R = (int)colour.val[2];
                //cout << "B: " << B << " G: " << G << " R: " << R << endl;
                color = (B << 16) | (G << 8) | R;

                //cout << color << endl;
                colours.push_back(color);

                // char r = (cor >> 16) & 0xFF;
                // char g = (cor >> 8) & 0xFF;
                // char b = cor & 0xFF;
                // cout << "b: " << (int)b << " g: " << (int)g << " r: " << (int)r << endl;
            }
        }
    }
    clear(colours);
    loadFile("clustering.txt");
    save(colours, "clustering.txt");
}

int main(int argc, char **argv)
{
    cv::CommandLineParser parser(argc, argv,
                                 "{help h | | show help message}{@image|../data/fruits.jpg| input image}");
    if (parser.has("help"))
    {
        parser.printMessage();
        return 0;
    }
    string filename = parser.get<string>("@image");
    image0 = imread(filename, 1);
    if (image0.empty())
    {
        cout << "Image empty\n";
        parser.printMessage();
        return 0;
    }

    image0.copyTo(image);
    namedWindow("image", 0);
    createTrackbar("lo_diff", "image", &loDiff, 255, 0);
    createTrackbar("up_diff", "image", &upDiff, 255, 0);
    setMouseCallback("image", onMouse, 0);
    for (;;)
    {
        imshow("image", image);
        char c = (char)waitKey(0);
        if (c == 27)
        {
            cout << "Exiting ...\n";
            break;
        }
        switch (c)
        {
        case 'r':
            cout << "Original image is restored\n";
            image0.copyTo(image);
            break;
        case 's':
            cout << "Simple floodfill mode is set\n";
            ffillMode = 0;
            break;
        case 'f':
            cout << "Fixed Range floodfill mode is set\n";
            ffillMode = 1;
            break;
        case 'g':
            cout << "Gradient (floating range) floodfill mode is set\n";
            ffillMode = 2;
            break;
        case '4':
            cout << "4-connectivity mode is set\n";
            connectivity = 4;
            break;
        case '8':
            cout << "8-connectivity mode is set\n";
            connectivity = 8;
            break;
        }
    }
    return 0;
}
