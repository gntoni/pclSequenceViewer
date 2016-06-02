#include "pcl_sequence_viewer.h"

int getdir (std::string dir, std::vector<std::string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL)
    {
        std::cout << "[PclSequenceViewer] Error(" << errno << ") opening " << dir << std::endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL)
    {
        if (std::string(dirp->d_name).find("cloud_") != std::string::npos)
        {
          files.push_back(dir + "/" + std::string(dirp->d_name));
        }
    }
    closedir(dp);
    return 0;
}

int main (int argc, char** argv)
{
  if(argc != 2)
  {
    std::cerr << "[PclSequenceViewer] Error: Enter as a parameter the folder where the pointclouds are stored" << std::endl;
    return -1;
  }

  std::string dir = argv[1];
  std::vector<std::string> files = std::vector<std::string>();

  getdir(dir,files);

  if(files.size() == 0)
  {
      std::cout << "[PclSequenceViewer] Error: No pointcloud files found."
                << "Make sure the files are in the correct folder and are named with the format \"cloud_\"" 
                << std::endl;
      return -1;
  }

  sequenceViewer viewer(files);
  viewer.run();
}
