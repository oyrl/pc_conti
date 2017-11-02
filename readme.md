catkin_create_pkg conti pcl_conversions pcl_ros roscpp rospy sensor_msgs std_msgs

modify the package.xml to add
  <build_depend>libpcl-all-dev</build_depend>
  <run_depend>libpcl-all</run_depend>

add the CMakeLists.txt
add_executable(example src/example.cpp)
target_link_libraries(example ${catkin_LIBRARIES})
