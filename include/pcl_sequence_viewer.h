/*
 * Copyright 2016, Toni Gabas"
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * @Author 
 * Toni Gabas, Research Student
 * AIST, (Advanced Institute of Science and Technology)
 * AIST Tsukuba Central 2, 1-1-1 Umezono, Tsukuba, Ibaraki 305-8568, Japan
 * */
#include <iostream>
#include <vector>
#include <string>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/console/print.h>
#include <pcl/console/parse.h>
#include <pcl/console/time.h>
#include <pcl/io/ply_io.h>

class sequenceViewer
{
public:
        sequenceViewer(std::vector<std::string> files);
        ~sequenceViewer();
        void run();
private:
        // Parameters
        unsigned int nFiles_;
        unsigned int currentFile_;
        std::vector<std::string> files_;
        pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_;
        boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_;

        // Functions
        void KeyboardEventOccurred(const pcl::visualization::KeyboardEvent &event, void * data);
};
