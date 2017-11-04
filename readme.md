# For python:
## add some setting of rviz
add PointCloud in rviz

select the "/pcl_output" Topic

modify the Fixed Frame to odom

---

# For C++:
## catkin_create_pkg conti pcl_conversions pcl_ros roscpp rospy sensor_msgs std_msgs
## modify the package.xml to add
  <build_depend>libpcl-all-dev</build_depend>

  <run_depend>libpcl-all</run_depend>

## add the CMakeLists.txt
add_executable(pub_pcl src/pub_pcl.cpp)

target_link_libraries(pub_pcl ${catkin_LIBRARIES})

## add some setting of rviz
add PointCloud2 in rviz

select the "/pcl_output" Topic

modify the Fixed Frame to odom

---

# Refer:
http://wiki.ros.org/pcl/Tutorials

http://blog.csdn.net/ktigerhero3/article/details/70185651
