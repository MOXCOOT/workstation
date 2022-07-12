#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"


/**
 * 客户端：需要提交两个整数，并处理响应的结果
 * 1. 包含头文件
 * 2. 初始化ros节点
 * 3. 创建节点句柄
 * 4. 创建一个客户对象
 * 5. 提交请求并处理响应
 * 6. spin()函数
 * 实现参数的动态提交
 *  1. 格式 ：rosrun 包名 节点名 12 34
 *  2. 节点执行时学要获取命令中的参数，并组织进 request
 * 问题
 *      如果先启动客户端，就会抛出异常
 * 需求
 *      先启动客户端，不抛异常，而是先挂起，等到服务器启动后，再正常请求
 * 解决
 *      ROS 中内置了相关函数，这些函数可以让客户端挂起，等待服务器启动
 *     client.waitForExistence();
 *     ros::service::waitForService("<服务话题>");
 **/




int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    //优化实现，获取命令中的参数
    if(argc != 3)
    {
        ROS_INFO("提交参数个数不对");
        return 0;
    }




    //  * 2. 初始化ros节点
    ros::init(argc,argv,"daBao");

    //  * 3. 创建节点句柄
    ros::NodeHandle nh;


    //  * 4. 创建一个客户对象
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("addInts");

    //  * 5. 提交请求并处理响应
    plumbing_server_client::AddInts ai;
    //  * 5.1 组织请求
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);

    //调同判断服务器状态的函数
    //client.waitForExistence();
    ros::service::waitForService("addInts");
    //  * 5.1 处理响应
    bool flag = client.call(ai);
    if(flag)
    {
        ROS_INFO("响应成功!");
        //获取结果
        ROS_INFO("响应结果 = %d",ai.response.sum);
    }else
    {
        ROS_INFO("处理失败...");
    }


    //  * 6. spin()函数




    
    return 0;
}
