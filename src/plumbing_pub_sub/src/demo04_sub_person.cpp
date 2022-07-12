#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"


/**
 * 订阅方：订阅人的消息
 *  1. 包含头文件
 *  2. 初始化 ROS 节点
 *  3. 创建节点句柄
 *  4. 创建订阅者对象
 *  5. 编写订阅逻辑，发布数据
 *  6. spin()函数
 */

void doPerson(const plumbing_pub_sub::Person::ConstPtr &person)
{
    ROS_INFO("订阅人的信息:姓名%s，年龄%d，身高%.2f",person->name.c_str(),person->age,person->height);
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("订阅方实现");


    //  *  2. 初始化 ROS 节点
    ros::init(argc,argv,"jiazhang");

    
    //  *  3. 创建节点句柄
    ros::NodeHandle nb;
    



    //  *  4. 创建订阅者对象
    ros::Subscriber sub = nb.subscribe("chat",10,doPerson);


    //  *  5. 编写订阅逻辑，发布数据
    //  *  6. spin()函数
    ros::spin();

    return 0;
}
