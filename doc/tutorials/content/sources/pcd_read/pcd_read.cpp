#include <iostream>
#include <cstdlib>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

using namespace std;

int
main (int argc, char** argv)
{
  string filePath;
  filePath=argv[1];
  //below is smart pointer
  //https://blog.innovotion.co.jp/2018/07/26/pcl%E3%81%AE%E7%82%B9%E7%BE%A4%E3%82%AA%E3%83%96%E3%82%B8%E3%82%A7%E3%82%AF%E3%83%88%E3%81%AE%E3%82%B9%E3%83%9E%E3%83%BC%E3%83%88%E3%83%9D%E3%82%A4%E3%83%B3%E3%82%BF/
 // pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGBNormal>);
  // if (pcl::io::loadPCDFile<pcl::PointXYZ> ("test_pcd.pcd", *cloud) == -1) //* load the file
  if (pcl::io::loadPCDFile<pcl::PointXYZRGBNormal> (filePath, *cloud) == -1) //* load the file
  // if (pcl::io::loadPCDFile<pcl::PointXYZ> (filePath, *cloud) == -1) //* load the file
  {
    PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
    return (-1);
  }
  std::cout << "Loaded "
            << cloud->width * cloud->height
            << " data points from test_pcd.pcd with the following fields: "
            << std::endl;

  // PointXYZRGBNormal point;
  // std::uint32_t rgb = *reinterpret_cast<int*>(&point.rgb);
  // std::uint8_t r = (rgb >> 16) & 0x0000ff;
  // std::uint8_t g = (rgb >> 8)  & 0x0000ff;
  // std::uint8_t b = (rgb)       & 0x0000ff;


  for (const auto& point: *cloud)
    std::cout << "    " << point.x
              << " "    << point.y
              << " "    << point.z
              // << " "    << point.rgb
              // << " "    << point.r
              << " "    << point.normal_x
              << " "    << point.normal_y
              << " "    << point.normal_z <<std::endl;            
              // << " "    << point.z << std::endl;

  return (0);
}
