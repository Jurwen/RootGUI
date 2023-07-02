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

1. Navigate to the RootGUI/release package/ directory, and double click on the root_mesh_viewer.exe application. This will open the user interface. Click on select .ply and select .txt to load the outputs of TopoRoot.

![image](https://github.com/Jurwen/RootGUI/assets/46691179/7b2d47ef-40ef-40ac-896c-b60e0be5fe8a)

2. Switch to the Mesh tab, and click Select .off . Select the .off file with the same name as the .ply file (the name of your sample).

After clicking open, the surrounding shape (the result of topological simplification) will be loaded in.

![image](https://github.com/Jurwen/RootGUI/assets/46691179/d7862acc-722f-40bf-acb9-951e84387452)

Mouse controls:

- Rotate: drag left mouse button
- Translate: drag right mouse button
- Zoom: Click down on middle scroll of the mouse, and drag up and down.

3. To view the radius level of the skeleton, change the "Skeleton Color" option from Normal Coloring(Black) to Color by Radius. Cooler colors (dark blue) represent lower radius levels (thinner roots), while warmer colors (green, yellow, red, etc.) represent higher radius levels (thicker roots which are closer to the stem).

![image](https://github.com/Jurwen/RootGUI/assets/46691179/03932354-9e3f-41c4-82f8-5367a7d041cb)

4. To view the hierarchy level, change the "Skeleton Color" option from Normal Coloring(Black) to Color by Hierarchy. Cooler colors (dark blue) represent lower hierarchy levels (starting from the stem), while warmer colors (green, yellow, red, etc.) represent higher hierarchy levels (higher-order lateral roots).

![image](https://github.com/Jurwen/RootGUI/assets/46691179/9f5d0384-efdd-4a2b-add1-42a6ee262614)

5. To filter the view of the hierarchy, toggle the checkboxes in the left panel of the Skeleton tab. For example to only view the stem path uncheck the other boxes.

![image](https://github.com/Jurwen/RootGUI/assets/46691179/b773e952-d93c-4a5a-b1db-fc39e04d415e)

6. After loading in the annotation file, the GUI can visualize the locations of the soil pland and whorls. These can be toggled at the skeleton tab.

6.1 Soil Plane Visualization and Editing: 

6.2 Whorl Visualization and Editing: 

6.3 Soil Plane Visualization and Editing: 



Contact: 
- Dan Zeng (danzeng@wustl.edu)
- Yiwen Ju (yiwen.ju@wustl.edu)
- Tina Wang (xiaogewang2018@gmail.com)


