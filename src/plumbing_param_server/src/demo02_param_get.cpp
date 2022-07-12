#include "ros/ros.h"
using namespace std;


/**
 * 演示参数查询
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
    //设置编码
    setlocale(LC_ALL,"");
    //初始化ROS节点
    ros::init(argc,argv,"get_param_c");
    //初始化节点句柄
    ros::NodeHandle nh;
    //ros::NodeHande-------------------------------------


    //1. param
    double radius=nh.param("radius",0.5);//第二个参数是默认值
    ROS_INFO("得到的 radius 值为 %.2f",radius);

    //2. getParam
    double temp;
    bool result =nh.getParam("radius",temp);
    if(result)  ROS_INFO("获取的半径是 %.2f",temp);
    else    ROS_INFO("查询不到该变量...");

    //3. getParamCached(用法同 2 ，但提高了性能，一般测试下效果甚微)

    //4. getParamNames
    vector<string> names;
    nh.getParamNames(names);
    for(auto &&name:names)
    {
        ROS_INFO("遍历到的元素 %s",name.c_str());
    }

    //5. hasParam
    bool flag1=nh.hasParam("radius");
    if(flag1) ROS_INFO("radius 存在吗？%d",flag1);

    //6. searchParam
    string key;
    nh.searchParam("radius",key);
    ROS_INFO("搜索结果 %s",key.c_str());

    

    return 0;
}

