#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>

#include <fstream>
#include <vector>
#include <std_msgs/String.h>
//#include <string>
//#include <iostream>

std::vector<std::string> split(std::string str, char delimiter) {
    std::vector<std::string> internal;
    std::stringstream ss(str); // Turn the string into a stream.
    std::string tok;
  
    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
  }
  
  return internal;
}

main (int argc, char **argv)
{
    ros::init (argc, argv, "pcl_create");

    ros::NodeHandle nh;
    ros::Publisher pcl_pub = nh.advertise<sensor_msgs::PointCloud2> ("pcl_output", 1);
    pcl::PointCloud<pcl::PointXYZ> cloud;
    sensor_msgs::PointCloud2 output;
/*
    // Fill in the cloud data
    cloud.width  = 100;
    cloud.height = 1;
    cloud.points.resize(cloud.width * cloud.height);

    for (size_t i = 0; i < cloud.points.size (); ++i)
    {
        cloud.points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
        cloud.points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
        cloud.points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);
    }
*/
    std::ifstream fp;
    fp.open("/home/ohy/workspace/conti/plane", std::ios::in);
//    fp.open("/home/ohy/workspace/conti/test", std::ios::in);
    std::string inputStr;
    std::vector<std::string> inputContent;
    while(getline(fp, inputStr)){
        inputContent.push_back(inputStr);
    }
    fp.close();

//    cloud.width  = 100;
//    cloud.height = 1;
//    cloud.points.resize(cloud.width * cloud.height);
    cloud.points.resize(inputContent.size());

    for (size_t i = 0; i < cloud.points.size (); ++i)
    {
        std::string tmp = inputContent[i];
        //std::cout << tmp << std::endl;
//        std::vector<std::string> tmp_2 = split(tmp, ' ');
//        std::cout << tmp_2[0] << " " << tmp_2[1] << std::endl;
        std::vector<std::string> tmp_2 = split(tmp, ' ');
        cloud.points[i].x = ::atof(tmp_2[1].c_str());
        cloud.points[i].y = ::atof(tmp_2[0].c_str());
        cloud.points[i].z = 1;
    }


    //Convert the cloud to ROS message
    pcl::toROSMsg(cloud, output);
    output.header.frame_id = "odom";

//    ros::Rate loop_rate(1);
    ros::Rate loop_rate(1);
    while (ros::ok())
    {
        pcl_pub.publish(output);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
