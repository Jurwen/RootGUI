 # Graphical User Interface for Maize Roots

This Graphical User Interface is intended for visualizing results from the following paper: 
TopoRoot: A method for computing hierarchy and fine-grained traits of maize roots from X-ray CT images
The paper can be found in here: https://rdcu.be/cC9Ng

The tool can be directly used by opening the exe file in the release package. In case for any need for customization, the source code is also included in this repository. The steps are the following: 

# How to build (windows only)

- All dependencies except QT is pre-shipped in the folder third-party. Thus, please download qt5.11.0, which can be found here: https://download.qt.io/new_archive/qt/5.11/5.11.0/
- After installation, to run the exe file, Go to This PC -> system settings -> advanced system settings -> advanced -> environment variables, and add bin file to the path variable. E.g: D:\Qt\Qt5.11.0\5.11.0\msvc2017_64\bin.
- To configure and build the code, define the environment variable QTDIR that points to the root dir of your QT. This way VS can pick up the QT headers and libs. 
- After these steps are completed, the VS .sln file should build, and the exe file can be run smoothly.
- Again, you do not need to build to use the tool. The release package has a ready-to-go file which is ready to run.

# How to use: 

- Navigate to the RootGUI/release package/ directory, and double click on the root_mesh_viewer.exe application. This will open the user interface. Click on select .ply and select .txt to load the outputs of TopoRoot.
![image](https://github.com/Jurwen/RootGUI/assets/46691179/ffa712a6-eb8c-4196-a816-014f9dc391fd)

  
- Load skeleton/mesh/annotation file accordingly. Once the mesh file is loaded, you can see the visualization on the right. 
- To change the perspective of viewing, please use your mouse. To rotation, drag with left button. To translate, drag with right button. To zoom in/out, use your middle button to scroll. 
- Once, the skeleton file and annotation file is loaded, you can have three ways to view the skeleton. Normal option means all black on the skeleton; Two other ways are coloring by radius or hierarchy. You can adjust radius range that you are interested once the skeleton is colored according to radius. All box options are only available when you loaded in a correct annotation file. Once they are marked, the according traits will appear. 
- Please remind that Once viewing the traits, have a correct correspondence between skeleton and annotation file. 

Contact: 
- Dan Zeng (danzeng@wustl.edu)
- Yiwen Ju (yiwen.ju@wustl.edu)
- Tina Wang (xiaogewang2018@gmail.com)


