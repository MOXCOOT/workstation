#include "ros/ros.h"

/**
 * 演示参数的删除
 * ros::NodeHandle
 *          deleteParam()
 * ros::param
 *          del();
 */

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");


    ros::init(argc,argv,"param_del_c");

    ros::NodeHandle nh;

    //删除
    //Nodehandle----------------------
    bool flag1 = nh.deleteParam("radius");
    if(flag1) ROS_INFO("已成功删除");
    else ROS_INFO("删除失败");

    //ros::Param----------------------
    bool flag2 = ros::param::del("radius_param");
    if(flag2) ROS_INFO("radius_param 删除成功");
    else ROS_INFO("radius_param 删除失败");


    
    return 0;
}
