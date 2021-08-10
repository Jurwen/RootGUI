#include "mainPage.h"
#include "glArea.h"

mainPage::mainPage(QWidget *parent)
    : QMainWindow(parent)
{	
	area = new glArea(this);
    ui->setupUi(this);
	ui->glLayout->addWidget(area, 1);
	QObject::connect(ui->showSkel, SIGNAL(stateChanged(int)), this, SLOT(showSkelCheckBox(int)));
	QObject::connect(ui->showMesh, SIGNAL(stateChanged(int)), this, SLOT(showMeshCheckBox(int)));
	QObject::connect(ui->alphaSlider, SIGNAL(valueChanged(int)), this, SLOT(alphaChanged(int)));
	QObject::connect(ui->meshColorRedSlider, SIGNAL(valueChanged(int)), this, SLOT(meshColorRedChanged(int)));
	QObject::connect(ui->meshColorGreenSlider, SIGNAL(valueChanged(int)), this, SLOT(meshColorGreenChanged(int)));
	QObject::connect(ui->meshColorBlueSlider, SIGNAL(valueChanged(int)), this, SLOT(meshColorBlueChanged(int)));
	QObject::connect(ui->skelWidthSlider, SIGNAL(valueChanged(int)), this, SLOT(skelWidthChanged(int)));
	QObject::connect(ui->radiusColor, SIGNAL(stateChanged(int)), this, SLOT(radiusColorCheckBox(int)));
	QObject::connect(ui->jetMinBox, SIGNAL(valueChanged(double)), this, SLOT(jetMinSpinChanged(double)));
	QObject::connect(ui->jetMaxBox, SIGNAL(valueChanged(double)), this, SLOT(jetMaxSpinChanged(double)));
	QObject::connect(ui->meshFileBrowseBtn, SIGNAL(clicked()), this, SLOT(browseMeshClicked()));
	QObject::connect(ui->meshFileBrowseBtn_obj, SIGNAL(clicked()), this, SLOT(browseMeshClicked_obj()));
	QObject::connect(ui->skelFileBrowseBtn, SIGNAL(clicked()), this, SLOT(browseSkelClicked()));
	QObject::connect(ui->annotationFileBrowseBtn, SIGNAL(clicked()), this, SLOT(browseAnnotationClicked()));
	QObject::connect(ui->hierarchyColor, SIGNAL(stateChanged(int)), this, SLOT(hierarchyColorCheckBox(int)));
	QObject::connect(ui->showLvl0Root, SIGNAL(stateChanged(int)), this, SLOT(showLvl0RootCheckBox(int)));
	QObject::connect(ui->showLvl1Root, SIGNAL(stateChanged(int)), this, SLOT(showLvl1RootCheckBox(int)));
	QObject::connect(ui->showLvl2Root, SIGNAL(stateChanged(int)), this, SLOT(showLvl2RootCheckBox(int)));
	QObject::connect(ui->showLvl3Root, SIGNAL(stateChanged(int)), this, SLOT(showLvl3RootCheckBox(int)));
	QObject::connect(ui->showLvlLaterRoot, SIGNAL(stateChanged(int)), this, SLOT(showLvlLaterRootCheckBox(int)));
	QObject::connect(ui->whorlBelow, SIGNAL(stateChanged(int)), this, SLOT(whorlBelowCheckBox(int)));
	QObject::connect(ui->whorlAbove, SIGNAL(stateChanged(int)), this, SLOT(whorlAboveCheckBox(int)));
	QObject::connect(ui->nodalRootBelow, SIGNAL(stateChanged(int)), this, SLOT(nodalRootBelowCheckBox(int)));
	QObject::connect(ui->nodalRootAbove, SIGNAL(stateChanged(int)), this, SLOT(nodalRootAboveCheckBox(int)));
	QObject::connect(ui->showPlane, SIGNAL(stateChanged(int)), this, SLOT(showPlaneCheckBox(int)));
	QObject::connect(ui->skeletonColor, SIGNAL(currentIndexChanged(int)), this, SLOT(skeletonColorComboBox(int)));
}

mainPage::~mainPage()
{
	delete ui;
}

void mainPage::showSkelCheckBox(int _s) {
	ui->statusBar->showMessage("changing the skeleton status");
	area->if_line = (_s == Qt::Checked);
}

void mainPage::showMeshCheckBox(int _s) {
	ui->statusBar->showMessage("changing the mesh status");
	area->if_face = (_s == Qt::Checked);
}

void mainPage::alphaChanged(int _s) {
	ui->statusBar->showMessage("changing the transparency");
	area->alpha = (ui->alphaSlider->maximum() - (float)_s) / (ui->alphaSlider->maximum() - ui->alphaSlider->minimum());
}

void mainPage::meshColorRedChanged(int _s) {
	ui->statusBar->showMessage("changing the mesh color");
	area->mesh_colorR = (ui->meshColorRedSlider->maximum() - (float)_s) / (ui->meshColorRedSlider->maximum() - ui->meshColorRedSlider->minimum());
}

void mainPage::meshColorGreenChanged(int _s) {
	ui->statusBar->showMessage("changing the mesh color");
	area->mesh_colorG = (ui->meshColorGreenSlider->maximum() - (float)_s) / (ui->meshColorGreenSlider->maximum() - ui->meshColorGreenSlider->minimum());
}

void mainPage::meshColorBlueChanged(int _s) {
	ui->statusBar->showMessage("changing the mesh color");
	area->mesh_colorB = (ui->meshColorBlueSlider->maximum() - (float)_s) / (ui->meshColorBlueSlider->maximum() - ui->meshColorBlueSlider->minimum());
}

void mainPage::skelWidthChanged(int _s) {
	ui->statusBar->showMessage("changing the line width");
	area->line_width = 0.01 + 2 * (ui->skelWidthSlider->maximum() - (float)_s) / (ui->skelWidthSlider->maximum() - ui->skelWidthSlider->minimum());
}

void mainPage::radiusColorCheckBox(int _s) {
	ui->statusBar->showMessage("changing the skeleton color with radius");
	if (_s == Qt::Checked) { 
		 
		ui->hierarchyColor->setCheckState(Qt::Unchecked);
		area->line_color = Jet;
	}
	else {
		area->line_color = Normal;
		ui->statusBar->showMessage("changing the skeleton color to normal");
	}
}

void mainPage::hierarchyColorCheckBox(int _s) {
	ui->statusBar->showMessage("changing the skeleton color with hierarchy");
	if (_s == Qt::Checked) { 
		
		ui->radiusColor->setCheckState(Qt::Unchecked);
		area->line_color = Hierarchy;
	}
	else {
		area->line_color = Normal;
		ui->statusBar->showMessage("changing the skeleton color to normal");
	}
}

void mainPage::jetMinSpinChanged(double _s)
{
	area->jet_min = _s;
}

void mainPage::jetMaxSpinChanged(double _s)
{
	area->jet_max = _s;
}

void mainPage::browseMeshClicked()
{
	QString shape_file = QFileDialog::getOpenFileName(this, "Select .off file", "", "*.off",
		NULL/*, QFileDialog::DontUseNativeDialog*/);
	ui->meshFileLabel->setText(shape_file);
	QByteArray shape_byteArray = shape_file.toLatin1();
	if (shape_byteArray.data() != "") {
		area->mesh = ReadOffFile(shape_byteArray.data());
		area->faceDisplayList += 2;
		area->draw_faces();
		area->if_face = true;
		area->adjustView();
	}
	else {
		ui->statusBar->showMessage("no mesh file is loaded");
	}
}

void mainPage::browseMeshClicked_obj()
{
	QString shape_file = QFileDialog::getOpenFileName(this, "Select .obj file", "", "*.obj",
		NULL/*, QFileDialog::DontUseNativeDialog*/);
	ui->meshFileLabel_obj->setText(shape_file);
	QByteArray shape_byteArray = shape_file.toLatin1();
	if (shape_byteArray.data() != "") {
		area->mesh = ReaderOBj(shape_byteArray.data());
		area->faceDisplayList += 2;
		area->draw_faces();
		area->if_face = true;
		area->adjustView();
	}
	else {
		ui->statusBar->showMessage("no mesh file is loaded");
	}
}

void mainPage::browseSkelClicked()
{
	QString skel_file = QFileDialog::getOpenFileName(this, "Select .ply file", "", "*.ply",
		NULL/*, QFileDialog::DontUseNativeDialog*/);
	ui->skelFileLabel->setText(skel_file);
	QByteArray skel_byteArray = skel_file.toLatin1();
	if (getSkeleton(area->vertexList, area->edgeList, skel_byteArray.data(), area->level, area->radius) == 1) {
		area->if_drawWhorlAbove = false;
		area->if_drawWhorlBelow = false;
		area->if_drawNodeAbove = false;
		area->if_drawNodeBelow = false;
		area->if_drawPlane = false;
		ui->whorlAbove->setChecked(false);
		ui->whorlBelow->setChecked(false);
		ui->nodalRootAbove->setChecked(false);
		ui->nodalRootBelow->setChecked(false);
		ui->showPlane->setChecked(false);
		cout << "Successfully initiated ply data... " << endl;
	}
	area->showLevels.clear();
	for (int i = 0; i < *max_element(area->level.begin(), area->level.end()); i++) {
		area->showLevels.push_back(1);
	}
	area->if_line = true;
	ui->jetMaxBox->setValue((double)*max_element(area->radius.begin(), area->radius.end()));
	ui->jetMinBox->setValue((double)*min_element(area->radius.begin(), area->radius.end()));
}

void mainPage::browseAnnotationClicked()
{
	QString annotation_file = QFileDialog::getOpenFileName(this, "Select .txt file", "", "*.txt",
		NULL/*, QFileDialog::DontUseNativeDialog*/);
	ui->annotationFileLabel->setText(annotation_file);
	QByteArray annotation_byteArray = annotation_file.toLatin1();
	if (readAnnotation(area->whorls, area->nodalRoots, annotation_byteArray.data(), area->cent, area->n) == 1) {
		area->if_drawWhorlAbove = false;
		area->if_drawWhorlBelow = false;
		area->if_drawNodeAbove = false;
		area->if_drawNodeBelow = false;
		area->if_drawPlane = false;
		ui->whorlAbove->setChecked(false);
		ui->whorlBelow->setChecked(false);
		ui->nodalRootAbove->setChecked(false);
		ui->nodalRootBelow->setChecked(false);
		ui->showPlane->setChecked(false);
		cout << "Successfully initiated annotation data... " << endl;
	}
	else {
		ui->statusBar->showMessage("no annotation file is loaded");
	}
}

void mainPage::showLvl0RootCheckBox(int _s)
{
	if (_s == Qt::Checked) {
		area->showLevels[0] = true;
	}
	else {
		area->showLevels[0] = false;
	}
}

void mainPage::showLvl1RootCheckBox(int _s)
{
	if (_s == Qt::Checked) {
		area->showLevels[1] = true;
	}
	else {
		area->showLevels[1] = false;
	}
}

void mainPage::showLvl2RootCheckBox(int _s)
{
	if (_s == Qt::Checked) {
		area->showLevels[2] = true;
	}
	else {
		area->showLevels[2] = false;
	}
}

void mainPage::showLvl3RootCheckBox(int _s)
{
	if (_s == Qt::Checked) {
		area->showLevels[3] = true;
	}
	else {
		area->showLevels[3] = false;
	}
}

void mainPage::showLvlLaterRootCheckBox(int _s)
{
	if (_s == Qt::Checked) {
		for (int i = 4; i < area->showLevels.size(); i++) {
			area->showLevels[i] = true;
		}
	}
	else {
		for (int i = 4; i < area->showLevels.size(); i++) {
			area->showLevels[i] = false;
		}
	}
}

void mainPage::whorlBelowCheckBox(int _s)
{
	if (_s == Qt::Checked) {
		area->if_drawWhorlBelow = true;
	}
	else {
		area->if_drawWhorlBelow = false;
	}
}

void mainPage::whorlAboveCheckBox(int _s)
{
	if (_s == Qt::Checked) {
		area->if_drawWhorlAbove = true;
	}
	else {
		area->if_drawWhorlAbove = false;
	}
}

void mainPage::nodalRootBelowCheckBox(int _s)
{
	if (_s == Qt::Checked) {
		area->if_drawNodeBelow = true;
	}
	else {
		area->if_drawNodeBelow = false;
	}
}

void mainPage::nodalRootAboveCheckBox(int _s)
{
	if (_s == Qt::Checked) {
		area->if_drawNodeAbove = true;
	}
	else {
		area->if_drawNodeAbove = false;
	}
}

void mainPage::showPlaneCheckBox(int _s) {
	ui->statusBar->showMessage("showing the plane");
	area->if_drawPlane = (_s == Qt::Checked);
}

void mainPage::skeletonColorComboBox(int _s)
{
	
	if (_s == 0) {
		area->line_color = Normal;
		ui->statusBar->showMessage("changing the skeleton color to normal");
	}
	else if (_s == 1){
		area->line_color = Hierarchy;
		ui->statusBar->showMessage("changing the skeleton color according to hierarchy");
	}
	else {
		area->line_color = Jet;
		ui->statusBar->showMessage("changing the skeleton color according to radius");

	}
}
