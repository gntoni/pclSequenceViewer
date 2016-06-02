#include "pcl_sequence_viewer.h"

sequenceViewer::sequenceViewer(std::vector<std::string> files) 
:
cloud_(new pcl::PointCloud<pcl::PointXYZRGB>),
viewer_(new pcl::visualization::PCLVisualizer("3D Viewer"))
{
    files_       = files;
    nFiles_      = files.size();
    currentFile_ = 0;
}

void sequenceViewer::KeyboardEventOccurred(const pcl::visualization::KeyboardEvent &event, void * data)
{
    std::string pressed = event.getKeySym();
    sequenceViewer *params = (sequenceViewer*)data;
    if(event.keyDown ())
    {
        if(pressed == "n")
        {
            params->currentFile_++;
            if(params->currentFile_ >= params->nFiles_)
            {
                // TODO show message
                params->currentFile_ = 0;
            }
            if (pcl::io::loadPLYFile<pcl::PointXYZRGB> (params->files_[currentFile_], *params->cloud_) == -1) //* load the file
            {
                PCL_ERROR ("Couldn't read file %s \n", params->files_[currentFile_]);
                return;
            }

           std::cout << "Loaded "
                     << cloud_->width * cloud_->height
                     << " data points from: "
                     << params->files_[currentFile_] 
                     << std::endl;

            std::cout << "New Frame" << std::endl << std::flush;
            params->viewer_->spinOnce();
            pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(params->cloud_);
            params->viewer_->updatePointCloud<pcl::PointXYZRGB> (params->cloud_, rgb, "frame cloud");
        }
    }
}

void sequenceViewer::run()
{
    cloud_->sensor_orientation_.w() =  0.0;
    cloud_->sensor_orientation_.x() =  1.0;
    cloud_->sensor_orientation_.y() =  0.0;
    cloud_->sensor_orientation_.z() =  0.0;

    pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(cloud_);
    viewer_->addPointCloud<pcl::PointXYZRGB>(cloud_, rgb, "frame cloud");
    viewer_->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "frame cloud");
    viewer_->registerKeyboardCallback(&sequenceViewer::KeyboardEventOccurred,*this, (void*)this);
    viewer_->setBackgroundColor (0, 0, 0);
    viewer_->addCoordinateSystem (1.0);
    viewer_->initCameraParameters ();


    while(!viewer_->wasStopped())
    {
        viewer_->spinOnce ();
    }
    return;
}

sequenceViewer::~sequenceViewer()
{
}
