#include "network.h"
#include "mtcnn.h"
#include <time.h>

int main()
{
        Mat image = imread("5b.jpg");
        //mtcnn find(image.rows, image.cols);
        mtcnn find("Pnet.txt", "Rnet.txt", "Onet.txt", image.rows, image.cols);
        clock_t start;
        start = clock();
        find.findFace(image);
        imshow("result", image);
        imwrite("result.jpg",image);
        start = clock() -start;
        cout<<"time is  "<<start/10e3<<endl;

        waitKey(0);
        image.release();
        return 0;
}
