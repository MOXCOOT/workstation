#include "ros/ros.h"

/**
 * 需要实现参数的新增和修改
 * 需求
 *      设置机器人的共享参数：类型+半径(0.15m)
 *      修改半径(0.2m)
 * 实现
 *      ros::NodeHandle
 *      ros::Param
 * 修改
 *      继续调用 setaram 或者 set ，保证键是已经存在的，使得对应的值覆盖
 **/

int main(int argc, char *argv[])
{
    //初始化ROS节点
    ros::init(argc,argv,"set_param_c");
    //创建节点句柄
    ros::NodeHandle nh;
    //参数增加----------------------
    //方案一 nh
    nh.setParam("type","yellow");
    nh.setParam("radius",0.15);

    //方案二 ros::param
    ros::param::set("type_param","white");
    ros::param::set("radius_param",0.15);
    //参数修改----------------------
    //方案一 nh
    nh.setParam("radius",0.2);   //参数覆盖


    
    //方案二 ros::param
    ros::param::set("radius_param",0.25);//覆盖之前的结果
    return 0;
}
