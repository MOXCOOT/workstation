#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"hello_c");

    //解决乱码问题
    setlocale(LC_ALL,"");

    ROS_INFO("hello将哈");

    /* code */
    return 0;
}
