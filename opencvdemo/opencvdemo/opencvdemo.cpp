// opencvdemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;

void draw_circle(int event, int x, int y, int flags, void* param)
{
    if (event == EVENT_LBUTTONDBLCLK)
    {
        Mat* img = (Mat*)param;
        circle(*img, Point(x, y), 100, Scalar(0, 255, 0), 5);
    }
}
//鼠标回调函数，暂时不做任何操作
void nothing(int ,void *)
{
    //这个回调函数是为了与滑条的回调机制兼容
}

int main()
{
    //图像入门-读取图像
    /*
    Mat img;
    img = imread("C:\\Users\\11419577\\Desktop\\1.jpg");

    namedWindow("imgW",WINDOW_FREERATIO);
    imshow("imgW", img);

    waitKey();
    destroyAllWindows();
    */

    //显示三通道图像
    /*
    Mat img;
    img = imread("C:\\Users\\11419577\\Desktop\\1.jpg");
    if (img.empty())
    {
        cout << "load img failed";
        return -1;
    }

    //split 3 channels
    vector<Mat> channels(3);
    split(img,channels);

    Mat bluechannel = channels[0];
    Mat greenchannel = channels[1];
    Mat redchannel = channels[2];

    imshow("blue", bluechannel);
    imshow("green", greenchannel);
    imshow("red", redchannel);

    //merge
    Mat mergeimg;
    merge(channels, mergeimg);
    imshow("merge", mergeimg);
    //write
    auto result= imwrite("2.jpg", mergeimg);
    if (result)
    {
        cout << "save image success."<<endl;
    }
    else
    {
        cout << "falied to save image.";
    }
    waitKey(3000);

    destroyAllWindows();
    */
    
    //视频捕获
    /*
    //open camera
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cerr << "unable to open camera."<<endl;
        return -1;
    }
    while (true)
    {
        Mat frame, gray;
        //捕获一帧
        cap >> frame;//或者使用cap.read(frame);
        if (frame.empty())
        {
            cerr << "捕获的视频帧为空" << endl;
            break;
        }

        //将视频帧转换成灰度图
        //cvtColor(frame,gray,COLOR_BGR2GRAY);
        //显示灰度图
        //imshow("frame", gray);

        imshow("frame", frame);

        if (waitKey(1) == 'q')
            break;


    }
    //释放Vediocapture对象和销毁所有窗口
    cap.release();
    destroyAllWindows();
    */
    
    //播放视频文件
    /*
    VideoCapture cap("C:\\Users\\11419577\\Desktop\\video.mp4");

    while (cap.isOpened())
    {
        Mat frame;
        cap >> frame;
        namedWindow("frame", WINDOW_FREERATIO);
        imshow("frame", frame);
        if (waitKey(25) == 'q')
            break;

    }
    cap.release();
    destroyAllWindows();
    */
    
    //保存视频文件
    /*
    VideoCapture cap(0);
    //获取视频帧的宽高
    int frame_width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));
    //声明视频编码器和输出文件
    VideoWriter out("video.avi", VideoWriter::fourcc('X','V','I','D'),20.0,Size(frame_width,frame_height));

    if (!out.isOpened())
    {
        cerr << "无法打开视频写入对象" << endl;
        return -1;
    }

    Mat frame,flipframe;
    while (true)
    {
        auto ret = cap.read(frame);
        if (!ret)
        {
            cerr << "无法读取摄像头帧"<<endl;
            break;
        }

        flip(frame, flipframe, 0);
        namedWindow("frame",WINDOW_FREERATIO );
        imshow("frame", flipframe);
        out.write(flipframe);

        if (waitKey(1) == 'q')
        {
            break;
        }
    }

    //释放资源
    cap.release();
    out.release();
    */
    
    //绘图功能  
    /*
     //Mat img=Mat::zeros(Size(512,512),CV_8UC3);
    ////画线
    //line(img,Point(0,0),Point(511,511),Scalar(255,0,0),6);
    ////画矩形
    //rectangle(img, Rect(Point(100, 100), Point(400, 300)),Scalar(0,255,0), 5);
    ////画圆
    //circle(img, Point(250, 250), 100, Scalar(0, 0, 255), 5);
    ////画椭圆
    //ellipse(img,Point(300,300),Size(200,100),0,90,450,Scalar(0,0,255),5);
    //画多边形
    //Point p[2][5] =
    //{
    //    {Point(50,50),Point(50,100),Point(50,150),Point(110,150),Point(200,200)},
    //    {Point(200,230),Point(230,100),Point(300,150),Point(300,150),Point(300,200)}
    //};

    //const Point *pp[] = { p[0],p[1] };
    //int n[] = { 5, 5 };
    //polylines(img,pp,n,2,true,Scalar(255,0,0),6);

    //namedWindow("img",WINDOW_AUTOSIZE);
    //imshow("img",img);


    //// 定义四个点
    //Point points[4] = { cv::Point(10, 5), cv::Point(20, 30), cv::Point(70, 20), cv::Point(50, 10) };

    //// 将点数组转为一个 vector，OpenCV 中的 polylines 需要 vector
    //vector<vector<Point>> pts;
    //pts.push_back(vector<Point>(points, points + 4));

    //// 使用 polylines 绘制多边形
    //polylines(img, pts, true, Scalar(0, 255, 255), 1);

    //// 显示结果图像
    //imshow("PolyLine", img);

    // 设置文本内容、字体、大小、颜色等
    std::string text = "Hello, OpenCV!";
    cv::Point org(50, 200);  // 文本的位置（左下角坐标）
    int fontFace = cv::FONT_HERSHEY_SIMPLEX;  // 字体类型
    double fontScale = 1;  // 字体大小
    cv::Scalar color(0, 255, 255);  // 文字颜色 (黄)
    int thickness = 2;  // 文字的粗细

    // 在图像上绘制文本
    cv::putText(img, text, org, fontFace, fontScale, color, thickness);

    // 显示图像
    cv::imshow("Text Drawing", img);
    
    */
    
    //鼠标事件
    /*
    Mat img = Mat::zeros(Size(512, 512), CV_8UC3);

    namedWindow("img",WINDOW_AUTOSIZE );
    setMouseCallback("img",draw_circle,&img );
    while (true)
    {
        imshow("img", img);
        if (waitKey(20) == 'q')
            break;
    }
    */

    //调色板
    /*
    // 创建一个黑色图像，大小为 300x512，3通道（BGR）
    Mat img = Mat::zeros(300, 512, CV_8UC3);
    namedWindow("image", WINDOW_AUTOSIZE);
    //创建滑动条 Trackbar
    createTrackbar("R", "image", 0, 255, nothing);
    createTrackbar("G", "image", 0, 255, nothing);
    createTrackbar("B", "image", 0, 255, nothing);

    //创建一个开关滑动条，开启或关闭功能
    int switchValue = 0;//0:off ,1:on
    createTrackbar("0:off \n1:on","image",&switchValue,1,nothing);

    while (true) {
        // 显示当前的图像
        cv::imshow("image", img);

        // 获取键盘输入
        int k = cv::waitKey(1) & 0xFF;

        // 按 'Esc' 键退出
        if (k == 27) {
            break;
        }

        // 获取当前滑动条的值
        int r = cv::getTrackbarPos("R", "image");
        int g = cv::getTrackbarPos("G", "image");
        int b = cv::getTrackbarPos("B", "image");

        // 获取开关的状态
        switchValue = cv::getTrackbarPos("0 : OFF \n1 : ON", "image");

        // 根据开关的值设置图像颜色
        if (switchValue == 0) {
            img.setTo(cv::Scalar(0, 0, 0)); // 黑色背景
        }
        else {
            img.setTo(cv::Scalar(b, g, r)); // 根据 RGB 设置图像颜色
        }
    }
    */
    
    //图像基本操作
    /*
       Mat img = imread("C:\\Users\\11419577\\Desktop\\1.jpg", IMREAD_COLOR);
    //检查图像是否加载成功
    if (img.empty())
    {
        cout << "unable to load image." << endl;
        return -1;
    }

    auto h = img.cols;
    auto w = img.rows;
    auto c = img.channels();

    cout << "the image height is:" << h << "\nthe image width is:" << w << "\nthe image channels is:" << c << endl;

    // 获取指定像素（100,100）的颜色通道值
    // 注意，OpenCV 默认按照 BGR 顺序存储图像数据
    Vec3b pixel = img.at<Vec3b>(100,100);
    // 打印 BGR 三个通道的像素值
    std::cout << "BGR通道值： " << (int)pixel[0] << ", " << (int)pixel[1] << ", " << (int)pixel[2] << std::endl;
    // 访问蓝色通道（B通道）
    int blue = pixel[0];  // 蓝色通道
    std::cout << "蓝色通道的像素值: " << blue << std::endl;

    // 访问绿色通道（G通道）
    int green = pixel[1];  // 绿色通道
    std::cout << "绿色通道的像素值: " << green << std::endl;

    // 访问红色通道（R通道）
    int red = pixel[2];  // 红色通道
    std::cout << "红色通道的像素值: " << red << std::endl;
    */

    //制作图像边界
    /*
    // 读取图像
    cv::Mat img1 = cv::imread("C:\\Users\\11419577\\Desktop\\1.jpg");

    // 检查图像是否加载成功
    if (img1.empty()) {
        std::cerr << "无法加载图像!" << std::endl;
        return -1;
    }

    // 定义边界扩展方式
    cv::Scalar BLUE = cv::Scalar(255, 0, 0); // BGR 格式

    cv::Mat replicate, reflect, reflect101, wrap, constant;

    // 使用不同的边界扩展方式
    cv::copyMakeBorder(img1, replicate, 10, 10, 10, 10, cv::BORDER_REPLICATE);
    cv::copyMakeBorder(img1, reflect, 10, 10, 10, 10, cv::BORDER_REFLECT);
    cv::copyMakeBorder(img1, reflect101, 10, 10, 10, 10, cv::BORDER_REFLECT_101);
    cv::copyMakeBorder(img1, wrap, 10, 10, 10, 10, cv::BORDER_WRAP);
    cv::copyMakeBorder(img1, constant, 10, 10, 10, 10, cv::BORDER_CONSTANT, BLUE);

    // 使用 OpenCV 显示图像
    cv::imshow("Original", img1);
    cv::imshow("Replicate", replicate);
    cv::imshow("Reflect", reflect);
    cv::imshow("Reflect_101", reflect101);
    cv::imshow("Wrap", wrap);
    cv::imshow("Constant", constant);
    */
    
    //图像的像素运算
    //插入logo
    /*
        //加载两张图片
    Mat img1 = imread("C:\\Users\\11419577\\Desktop\\dst.jpg");
    Mat imglogo = imread("C:\\Users\\11419577\\Desktop\\logo.png",IMREAD_UNCHANGED);
    
    //检查图像是否加载成功
    if (img1.empty() || imglogo.empty())
    {
        cout << "图像加载失败" << endl;
        return -1;
    }
     



    //调整logo图大小
    // 缩小比例
    double scale_factor = 1;  

    // 计算目标尺寸
    int new_width = static_cast<int>(imglogo.cols * scale_factor);
    int new_height = static_cast<int>(imglogo.rows * scale_factor);

    // 进行图像缩放
    cv::Mat img2;
    cv::resize(imglogo, img2, cv::Size(new_width, new_height));
 
    //获取logo图像的尺寸
    int rows = img2.rows;
    int cols = img2.cols;
    //创建一个roi，这个roi的宽高等于logo图的宽高
    Mat roi = img1(Rect(0,0,cols,rows));
    imshow("roi", roi);
    waitKey(0);

    //将logo图转换为灰度图
    Mat img2gray;
    cvtColor(img2,img2gray,COLOR_BGR2GRAY);
    imshow("img2gray", img2gray);
    waitKey(0);

    //创建掩码，反掩码
    Mat mask, mask_inv;
    threshold(img2gray,mask,10,255,THRESH_BINARY);
    bitwise_not(mask,mask_inv);
    imshow("mask", mask);
    imshow("mask_inv", mask_inv);
    waitKey(0);

    //使roi的区域变黑（保留背景）
    Mat img1_bg;
    bitwise_and(roi, roi, img1_bg, mask_inv);


    //提取logo区域
    Mat img2_fg;
    bitwise_and(img2,img2,img2_fg,mask);
    
    //在roi中放置logo并修改主图
    Mat dst;
    add(img1_bg,img2_fg,dst);

    dst.copyTo(img1(Rect(0,0,cols,rows)));

    //显示结果
    namedWindow("image",WINDOW_AUTOSIZE );
    imshow("image",img1 );
    */
    //打印图像数据
    /*
    ////加载两张图片
    //Mat img = imread("C:\\Users\\11419577\\Desktop\\sudoku.png",IMREAD_UNCHANGED);

    ////Mat logo = imread("C:\\Users\\11419577\\Desktop\\logo.png",IMREAD_UNCHANGED);

    //Mat roi = img(Rect(0,0,50,50));
    //imshow("roi",roi);
    //Mat gray; 
    //cvtColor(roi, gray, COLOR_BGR2GRAY);
    //imshow("gray",gray );
    ////打印灰度图
    //cout << "灰度图数据:"<<endl;
    //cout << gray << endl;

    //cout << "灰度图尺寸：" << gray.rows << "x" << gray.cols<<endl;

    ////打印原图
    //cout << "原图数据:" << endl;
    //cout << roi << endl;

    //cout << "原图尺寸：" << roi.rows << "x" << roi.cols << endl;


    // //split 3 channels
    //vector<Mat> channels(4);
    //split(roi, channels);

    //Mat bluechannel = channels[0];
    //Mat greenchannel = channels[1];
    //Mat redchannel = channels[2];
    //Mat achannel = channels[3];

    ////cout << "blue:" << bluechannel << endl;
    ////cout << "green:" << greenchannel << endl;
    ////cout << "red:" << redchannel << endl;
    //cout << "a:" << achannel << endl;


    //imshow("blue", bluechannel);
    //imshow("green", greenchannel);
    //imshow("red", redchannel);
    //imshow("a", achannel);
    */
    
    //捕获蓝色区域
    /*
        cv::VideoCapture cap(0);
    if (!cap.isOpened())
    {
        std::cout << "camera failed to open.";
        return -1;
    }

    cv::Mat frame,hsv,mask,res;
    while (1)
    {
        cap.read(frame);
        if (frame.empty())
        {
            std::cerr << "Unable to get frame.";
            break;
        }

        //将BGR转化为hsv
        cv::cvtColor(frame,hsv,COLOR_BGR2HSV);
        //定义蓝色范围的hsv值
        cv::Scalar lower_blue(110,50,50);
        cv::Scalar upper_blue(130,255,255);

        //使用inrange函数获取蓝色区域的掩码
        cv::inRange(hsv,lower_blue,upper_blue,mask);

        //按位与操作获取图像的蓝色区域
        cv::bitwise_and(frame,frame,res,mask);
        //cv::imshow("frame", frame);
        //cv::imshow("hsv", hsv);
        cv::imshow("mask", mask);
        cv::imshow("res",res);

        if (waitKey(50) == 'q')
            break;


    }
    */

    //获取HSV值
    //创建一个BGR图像（0，255，0）即绿色
    cv::Mat green = cv::Mat::zeros(1,1, CV_8UC3);
    green.at<cv::Vec3b>(0, 0) = cv::Vec3b(0,255,0);

    cv::Mat hsv_green;
    cv:cvtColor(green,hsv_green,COLOR_BGR2HSV);
    std::cout << hsv_green;
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;

}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
