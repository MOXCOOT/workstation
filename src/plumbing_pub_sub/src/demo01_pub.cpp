#include "ros/ros.h"
#include "std_msgs/String.h"

/*
    发布方实现：
        1. 包含头文件；
            ROS 中的文本类型--->stdmsgs/String.h
        2. 初始化 ROS 节点；
        3. 初始化节点句柄；
        4. 创建发布者对象；
        5. 编写发布逻辑并发布数据。
*/


int main(int argc, char *argv[])
{

    setlocale(LC_ALL,"");
    // 2. 初始化 ROS 节点
    ros::init(argc,argv,"erGouZi");

    //3. 初始化节点句柄
    ros::NodeHandle nh;


    //4. 创建发布者对象
    ros::Publisher pub=nh.advertise<std_msgs::String>("house",10);

    //5. 编写发布逻辑并发布数据
    //要求以10Hz的频率发布数据，并且文本后要添加编号
    //先创建被发布的消息
    std_msgs::String msg;
    //编写循环，循环发布消息
    //发布频率
    //设置编号
    int count = 0;
    ros::Rate rate(10);
    while (ros::ok())
    {
        count++;

        //msg.data="Hello";

        //实现字符串的拼接
        
        std::stringstream ss;
        ss<<"hello--->"<<count;
        msg.data=ss.str();

        pub.publish(msg);
        //添加日志
        ROS_INFO("添加的字符串是 %s",ss.str().c_str());
        rate.sleep();

    }
    



    
    return 0;
}
